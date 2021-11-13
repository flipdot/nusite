+++
title = "IoT-Hardware: Messungen"
+++

## Messungen, Hardwarestand 0.4

330 µF Elko an der Batterie und 100 nF Kunsstoffolienkondensator direkt
am ESP.

### Betriebsspannung nach der Schottky-Diode (Leitung BATT_LOW) DC Coupling

<!-- [{{attachment:Supply_DC_coupling.bmp|attachment:Supply_DC_coupling.bmp|width="600"}}](attachment:Supply_DC_coupling.bmp) -->
Bei abgeschaltetem ESP und Attiny im Sleep Mode ist die Stromaufnahme so
gering, dass an der Diode keine nennenswerte Spannung abfällt. Mit
aktiviertem Attiny und ESP sinkt die Spannung nach der Diode um ~ 0,3 V,
die Schwellspannung der Diode.

### Betriebsspannung nach der Schottky-Diode (Leitung BATT_LOW) AC Coupling

<!-- [{{attachment:Supply_AC_coupling.bmp|attachment:Supply_AC_coupling.bmp|width="600"}}](attachment:Supply_AC_coupling.bmp) -->
Die Betriebsspannung bricht beim Verbindungsaufbau zyklisch um ca 50 mV
ein, in der Übertragungsphase um ca 100 mV.

Mit 10 µF Kerko an der Batterie und 100 nF Kunsstoffolienkondensator
direkt am ESP: Die Betriebsspannung bricht max. um ca 200 mV ein.

## Messungen zur Akkulaufzeit

### Nur ESP im Deep Sleep

<!-- [{{attachment:20170125_164320.jpg|attachment:20170125_164320.jpg|width="400"}}](attachment:20170125_164320.jpg) -->

Im Vorlauf haben wir eine einfache Schaltung verwendet, bei der der ESP
im Deep Sleep Modus ca. 300 µA Strom aufnimmt. An einer Haustür
angebracht wurde die Schaltung im Mittel ca. sechs mal am Tag aktiviert.
Der Verlauf der Akkuspannung läßt einen Betrieb für ein Jahr ohne
Akkuwechsel möglich erscheinen. Das Auf und Ab der Akkuspannung
korreliert mit dem Temperaturverlauf am Montageort - wärmer => höhere
Zellenspannung.

### Eneloop Akkutest

<!-- [{{attachment:Eneloop-Test.jpg|attachment:Eneloop-Test.jpg}}](attachment:Eneloop-Test.jpg) -->

## Messungen zum Stromverbrauch

- Attiny 45V-10SU
- Versorgung 3 x Eneloop AA via Schottky Diode
- Messung mit Hameg HM 8011-3

Laut Datenblatt zieht der Attiny im Power-down Mode: 0,1 μA at 1.8V.

Gemessen habe ich 0,12 µA bei 3,92 V Akkuspannung, 3,91 V am Tiny (keine
nennenswerte Schwellspannung an der Schottky Diode bei dem kleinen
Strom). Sobald der ESP arbeitet, sinkt die Spannung an Tiny und ESP auf
ca. 3,2 V.

<!-- [{{attachment:current.bmp|attachment:current.bmp|width="600"}}](attachment:current.bmp) -->

Messung über einen 1 Ohm Shunt, 50 mV entspricht 50 mA. Ähnlich wie
andernorts im Netz beschrieben ist der Verbrauch des Digitalteils ca. 70
mA, Stromspitzen durch den Transceiver ~ 270 mA.
 