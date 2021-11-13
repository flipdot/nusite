+++
title = "Arduino: Puls und Blut-Sauerstoff"
+++

Mit dem Arduino kann man ein Puls und Sauerstoff Meßgerät bauen, das per
OLED-Display die Werte ausgibt.

Hier der Versuch: Arduino Puls und Blutsauerstoff Meßgerät OLED-Display,
[MAX30102](MAX30102) Sensor, Arduino Nano

- Anleitung:
  <https://create.arduino.cc/projecthub/jeffreymagee/attiny85-pulse-oximeter-and-photoplethysmograph-e3f907>
- \* Quellcode <https://github.com/jeffmer/tinyPulsePPG#readme> Für
  Nano
  <https://github.com/jeffmer/tinyPulsePPG/tree/master/nanoPulsePPG>
  - Probleme mit den Projekt Dateien von Github: Verweis Arduino.h
    und wire.h machte Probleme auf Raspberry Arduino-IDE.
    Nachverfolgen ob Fehler im Code oder in der IDE-Installation.

-> Fehlermeldung beheben: `#include "Arduino.h"` statt `#include <arduino.h>` in `MAX30102.h`
