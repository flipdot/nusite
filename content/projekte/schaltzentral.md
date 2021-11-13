+++
title = "Schaltzentral"
+++

Schaltzentral ist unser Setup von Zigbee und WLAN Lampen, koordiniert
über einen MQTT Broker, gesteuert über ein Android Tablet.

## MQTT Broker

- <https://mosquitto.org/> installieren (apt install mosquitto,
  fertig!)

## Zigbee Ikea Leuchten

- An einem Raspberry ein Zigbee Modul anschließen (TODO: Was für ein Modul?)
- <https://www.zigbee2mqtt.io/> auf dem Raspberry installieren

## WLAN Sonoff Lampen

- Tasmota Firmware draufflashen
- Mit nmap Netzwerk scannen und IP direkt im Browser eingeben
  (Standard Port 80). Im UI Hostname vom MQTT Broker eingeben

## Android Tablet

- <https://play.google.com/store/apps/details?id=net.routix.mqttdash&hl=de>
  installieren
- Tablet an die Wand motieren
- Konfiguration lässt sich mit dieser App direkt über metrics/exchange
  teilen oder hier herunterladen:
  <https://gist.github.com/soerface/7c5cef151a4973614899d39787afa382>

## FAQ

### Wie füge ich eine neue Zigbee Lampe hinzu?

- Halte die Lampe ca. 3cm vom Zigbee Sender entfernt
- Schalte sie ein
- [Hol dir die device
  config](https://www.zigbee2mqtt.io/information/mqtt_topics_and_message_structure.html#zigbee2mqttbridgeconfigdevicesget),
  indem du:
  - Horche auf die device config: `mosquitto_sub -t
    "zigbee2mqtt/bridge/config/devices" -h mqtt.fd`
  - Lass dir eine device config schicken: `mosquitto_pub -t
    "zigbee2mqtt/bridge/config/devices/get" -m "" -h mqtt.fd`
    - Tipp: Schreibe dir die config in eine Datei (`> config.json` am Ende des
      Befehls).Du kannst dir eine Funktion
      [jless](https://gist.github.com/soerface/8e44ebd495be72aee481d65c1003a015)
      definieren oder
      [jq](https://stedolan.github.io/jq/) verwenden,
      dann `jless config.json`
- Suche aus der config die neue Lampe heraus. Benutze den
  friendly_name ("0x..."). Versuche, die Lampe ein- und
  auszuschalten: `mosquitto_pub -t "zigbee2mqtt/FRIENDLY_NAME/set"
  -m "ON" -h mqtt.fd`
- Wenn du die richtige Lampe gefunden hast,
  [ändere](https://www.zigbee2mqtt.io/information/mqtt_topics_and_message_structure.html#zigbee2mqttbridgeconfigrename)
  den "friendly_name" auf etwas sinnvolles:
  - `mosquitto_pub -t "zigbee2mqtt/bridge/config/rename" -m
    \'{"old": "OLD_FRIENDLY_NAME", "new":
    "NEW_FRIENDLY_NAME"}\' -h mqtt.fd`

### Wie steuere ich die Tasmota Lampen via MQTT?

Am Beispiel "tasmota/buntsofa". Der Name der Lampe wird über das
Webinterface der Lampe geändert.

- An: `mosquitto_pub -t "cmnd/tasmota/buntsofa/power" -m "ON" -h
  mqtt.fd`
- Aus: `mosquitto_pub -t "cmnd/tasmota/buntsofa/power" -m "OFF"
  -h mqtt.fd`
- Farbe: `mosquitto_pub -t "cmnd/tasmota/buntsofa/color" -m
  "#ff0000" -h mqtt.fd`
- Kalt-weiß volle Helligkeit: `mosquitto_pub -t
  "cmnd/tasmota/buntsofa/color" -m "#000000ff00" -h mqtt.fd`
- Warm-weiß volle Helligkeit: `mosquitto_pub -t
  "cmnd/tasmota/buntsofa/color" -m "#00000000ff" -h mqtt.fd`
- Dimmer (Farbe ändern hat gleichen Effekt): `mosquitto_pub -t
  "cmnd/tasmota/buntsofa/dimmer" -m "100" -h mqtt.fd`

### Wie finde ich das Webinterface der Tasmota Lampen?

`nmap -sP 192.168.3.0/24`, der Hostname der Lampen ist by default
tasmota, wir haben aber zwei bereits in "buntsofa" und "buntkino"
umbenannt. Das Webinterface lauscht auf dem Standard HTTP Port 80, also
einfach die IP Adresse im Browser eingeben.

### Wie liste ich alle Tasmota Lampen auf?

Nutze folgendes Python Skript:

    #!/usr/bin/env python3
    import json
    import sys
    import paho.mqtt.client as mqtt

    MQTT_HOST = 'mqtt.fd'
    MQTT_PORT = 1883
    TOPIC_BASE = 'zigbee2mqtt/bridge/config/devices'
    TOPIC_GET = f'{TOPIC_BASE}/get'

    def on_connect(client, userdata, flags, rc):
        client.subscribe(TOPIC_BASE)
        client.publish(TOPIC_GET)

    def on_message(client, userdata, msg):
        things = json.loads(msg.payload.decode('utf-8'))
        for thing in things:
            if thing['type'] == 'Router':
                print(thing['friendly_name'])
        sys.exit(0)

    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message
    client.connect(MQTT_HOST, MQTT_PORT, 60)
    client.loop_forever()

### Wie spiele ich einen Regenbogen auf allen Lampen ab?

Wenn du obiges Python-Skript als `asdf.py` gespeichert hast und es
ausführbar ist, kannst du mit folgendem Bash-Oneliner steil gehen:

    for c in {0..360..10}; do col=$(python3 -c "import colorsys; print('#' + ''.join([f'{int(c * 255):02x}'.upper() for c in colorsys.hsv_to_rgb($c / 360, 1, 1)]))"); while read -r lamp; do echo "$lamp $col"; mosquitto_pub -t "cmnd/tasmota/$lamp/color" -h mqtt.fd -m "$col"; sleep 1; done <<< $(./asdf.py); done
