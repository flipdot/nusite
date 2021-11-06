+++
title = "IoT: ToDo"
+++

# Mech

- \--(Leitungs-Einlaß für Sensor auf Gehäuseunterseite verlegen)\--
- \--(Zugang zum Wifi-Manager-Jumper auf Gehäuse Unterseite
  schaffen)\--
- \--(Alternative Deckelmontage ohne Magnete? (Ggf 2 x M3 ins
  Holz))\--
- Schild (Sensorname, Topic, IP, Batteriewechseldatum)

# Elektro

- Stromverbrauch Messen bei 0.4
- Platinenvariante (bzw. Rework-Anleitung) für Betrieb ohne Attiny
  machen - ESP hält sich Vcc über MOSFET selber
- Platinenvariante für Wemos ESP Platine machen - Schottky raus, mehr
  Vcc -\> LDO auf dem Wemos
- [Variante mit 6 fach Schmitt
  Trigger](https://github.com/tstoegi/microWakeupper).
  Ruhestrom für den CMOS Chip 20nA.
  ([Datasheet](http://www.ti.com/lit/ds/symlink/cd40106b.pdf))

# Software

- Modul, das Fehlermeldungen der anderen MQTT-Teilnehmer abfängt und
  in IRC postet / irgendwem als Email schickt
  - Niedriger Batteriestand **(must)**
  - Schlechte Feldstärke / häufige Abrüche (nice to have)
  - Ausbleiben zyklischer I\'m alive Meldungen kritischer
    MQTT-Teilnehmer (für Knoten, die dauernd online sind / sein
    müssen, dazu sinnvoll: Topic nur für diese Meldungen)
- Modul, das die Meldungen kritischer MQTT-Teilnehmer auswertet und
  auf dem Leuchtmelder-Tableau an der Ausgangstür anzeigt (Also
  Dachluken, Fenster, Raum4, etc.) **(must)**
  - Lesen kritischer MQTT-Teilnehmer-Topics
  - Lesen des Space Status
  - Wenn Space Status von offen -\> geschlossen wechselt, und
    kritische Nodes noch offene Türen etc. melden, lauter Alarm über
    \$Gerät (Leuchtmelder-Tableau) **(must)**
- Modul, das Verknüpfungen realisieren kann
  - Klingelknopf außen bewirkt Türöffnung wenn Spacestatus = offen
    (nice to have)
  - Sensor Klopapier alle bewirkt Bestellung bei Amazon (cherz) \...
    Aber Eintrag in eine Einkaufsliste?! (nice to have)
- Modul, das Steuerung von Aktoren im IoD Netz von außen sicher
  realisiert. Aktoren:
  -   Heizung
- Modul, das Daten aus dem MQTT Netz nach Grafana liefert. Was soll
  aufgezeichnet werden?
  ([Liste](http://github.com/freifunkks/salt-conf/blob/master/state/graphite/fd-spacestats.py#L44-L92))

## Attiny

- \--(Interrupt Glitch abstellen)\-- Waren tatsächlich mal wieder zu
  wenig Angstkondensatoren.
- \--(Alle unnötinen Peripherials auf dem Chip abschalten)\--
  [1](https://playground.arduino.cc/Learning/ArduinoSleepCode)
  [2](http://www.arduino-hausautomation.de/2014/emils-ampel-attiny45-im-tiefschlaf/)
  [3Strombedarf](https://learn.sparkfun.com/tutorials/reducing-arduino-power-consumption)
  entspricht jetzt den Specs aus dem Datasheet.

## ESP

- Codevariante für Betrieb ohne Attiny machen - ESP hält sich Vcc über
  MOSFET selber
- Prüfen, welchen Unterschied die interne Vcc Messung im ESP mit und
  ohne Radio macht
- \--(MQTT Client bauen, der Topics abonnieren kann, und die Inhalte
  auf WS2811 LED String anzeigt (für Display an der Tür) )\--

## GetränkeKistenStatistik - Mikrocontroller-Mess-Software (drinks-storage-state)

- WebGUI
  - ESP ID \[r\]
  - Netzwerk-SSID, Passwort \[rw\]
  - MQTT host \[rw\]

## GetränkeKistenStatistik - Messwert-KistenAnzahl-Konvertierung (drinks-storage-mqtt)

- crate_count per Getränke-Art zählen, nicht per Stapel
  - Aktuell gibt es keine Getränkesorten, für die mehrere Stapel benötigt werden
