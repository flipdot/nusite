+++
title = "IoT: Software"
+++

Das "Internet of Dings" Setup im flipdot gruppiert sich um einen
zentralen MQTT Server, den Broker. Es gibt ein benutzerfreundliches
Web-Fontend und Schnittstellen in den IRC und zur Space API.

# Fertige Software

## Mosquitto

Zentraler MQTT Broker

-   Läuft auf power-pi.fd

## [NodeRed](NodeRed)

Stell das GUI für die wesentlichen Funktionen des Space bereit.
Einfaches Web-Frontend, einfache "Programmierung" der Funktionen in
Form einer Flow basierten Verdrahtung.

-   Läuft auf power-pi.fd

# Unser selbst geschriebener Kram

## iod-esp8266-sensor

Software für selbst gebaustelte Sensoren. Sendet Status ins Netz,
nachdem der ESP von einem Attiny aufgeweckt wurde (siehe auch
iod-nodes).

-   Repo: <https://github.com/flipdot/iot-esp8266-sensor>
-   Verwendete Technik: C++, Arduino
-   Läuft auf den einzelnen Sensor-Platinen

## iod-nodes

Software für selbst gebaustelte Sensoren. Wartet im Standby, bis
Schalter An oder Aus geht. Schaltet dann den größeren, stromhungrigeren,
WLAN-fähigen [ESP8266](ESP8266) ein um die Statusänderung zu
übermitteln. Nimmt schließlich nach der Übertragung den Strom wieder weg
und legt sich schlafen.

-   Repo: <https://github.com/flipdot/iod-nodes>
-   Verwendete Technik: C++, Arduino
-   Läuft auf den einzelnen Sensor-Platinen

## drinks-storage-mqtt

Wertet Messungen von Getränkewaagen aus.

-   Repo: <https://github.com/flipdot/drinks-storage-mqtt>
-   Verwendete Technik: Python 3

## drinks-storage-state

Führt Waagen-Messungen durch und schickt die Ergebnisse ins Netz.

-   Repo: <https://github.com/flipdot/drinks-storage-state>
-   Verwendete Technik: C++, platform.io

## flipbot

Unser IRC-Bot. Seit einer Weile auch ans IoD-Netz angeschlossen. Lauscht
auf \`actors/all/flipbot\` und leitet alle Nachrichten von dort in
unseren IRC-Channel weiter.

-   Repo: <https://github.com/flipdot/sopel-modules>
-   Verwendete Technik: Python (FIXME: Version?)

## iod-api-bridge

Sammelt Daten im MQTT-Netz und schickt sie zu
<https://api.flipdot.org/>.

-   Repo: <https://github.com/flipdot/iod-api-bridge>
-   Verwendete Technik: Python 3

## iod-error-spam

Empfängt Fehlermeldungen anderer MQTT-Teilnehmer und spammt damit den
IRC zu (via sopel). Jetzt auch mit Rate Limiting! Zusätzlich bald auch
persistente, einfacher zu durchsuchende Logs.

-   Repo: <https://github.com/flipdot/iod-error-spam>
-   Verwendete Technik: Rust
