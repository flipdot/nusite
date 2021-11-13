+++
title = "CAN-Raspi"
+++

<!-- {{attachment:Canberry.jpg}} -->

Über der Eingangstür ist auf einer langen DIN-Hutschine installiert:

- sieben Relais
- ein Raspberry Pi
- ein Raspberry nach CAN-Adapter mit Optokoppler (Der Adapter passt
  nur die Buspegel an und enthält keine Logik)
- ein Steckernetzteil 5 V für den Raspberry
- Ein Hutschinennetzteil 24 V für die Relais
- Ein Hutschinennetzteil 12 V für die Spannung auf dem CAN Bus

Der Raspberry sendet auf seiner seriellen Schnittstelle in einem simplen
Protokoll im Klartext lesbare Befehle in ASCII an die Clients auf dem
CAN Bus (AVR uC mit CAN BUs Adapter)

Die Ankopplung des CAN Busadapters ist über Optokoppler realisiert.

Auf dem Bus wird auch eine Mit 2 A belastbare Spannung von 12 V
mitgeführt, aus dieser Spannung machen sich die CAN Bus Clients ihre
Betriebsspannung. Vom Pi auf den Bus gesendete Bits werden direkt sofort
auch wieder vom Pi empfangen, weil der Bus für Hin- und Rückweg nur
einen Kanal hat.

[Github](https://github.com/flipdot/Spacecontrol)

<!-- {{attachment:CANBerry Aufbau.jpg}} -->

## Client Befehle

### Digitale outputs setzen

     :clientname setport n m
     n [0..7] Pornummer
     m [0..1] Portzustand

Antwort

     n [0..1] Portzustand

### Digitale inputs lesen

     :clientname getport n
     n [0..7] Pornummer

Antwort

     n [0..1] Portzustand

### Analoge inputs lesen

     :clientname getana n
     n [0..7] Pornummer

Antwort

     n [0..1023] Spannungswert in 5V / 1024, Uref = Ub Controllerboard

### Temperatur lesen

     :clientname gettemp

Antwort

     n [-200..800] m [-200..800] o [-200..800] Temperatur in 1/10 °C, max drei Sensoren [[DS18B20]] pro Controller

### RGB Lampe

     :clientname setrgb n m o
     n [0..255] roter Helligkeitswert, linear, Gammakorrektur im Controller
     m [0..255] grüner Helligkeitswert, linear, Gammakorrektur im Controller
     o [0..255] blauer Helligkeitswert, linear, Gammakorrektur im Controller

Antwort

     ok

### Servos

     :setservo n m
     n [1..5] Servonummer (### Wird noch auf 0..4 geändert)
     m [0..255] Servoposition, typischer Weise mit engeren Grenzen

Antwort

     ok

## Busankopplung [RasPi](RasPi) - CAN

Optokoppler: 4N25

<!-- {{attachment:CAN-Busankopplung_2.jpg}} -->
