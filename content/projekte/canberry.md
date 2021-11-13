+++
title = "CANberry"
+++

<!-- {{attachment:Canberry.jpg|CANberry}} -->

Am [CANberry](CANberry) auf der Hutschiene hängt an seiner
seriellen Schnittstelle via Optokoppler ein CAN-Bus Receiver. Auf dem
Bus wird auch 12 V mitgeführt, aus dieser Spannung machen sich die CAN
Bus Clients ihre Betriebsspannung. Vom Pi auf den Bus gesendete Bits
werden direkt sofort auch wieder vom Pi empfangen, weil der Bus für Hin-
und Rückweg nur einen Kanal hat.

- [Spacecontrol @
  github](https://github.com/flipdot/Spacecontrol)

## Client Befehle

### Digitale outputs setzen

    :clientname setport n m n [0..7] Pornummer m [0..1] Portzustand

Antwort

    n [0..1] Portzustand

### Digitale inputs lesen

    :clientname getport n n [0..7] Pornummer

Antwort

    n [0..1] Portzustand

### Analoge inputs lesen

    :clientname getana n n [0..7] Pornummer

Antwort

    n [0..1023] Spannungswert in 5V / 1024, Uref = Ub Controllerboard

### Temperatur lesen

    :clientname gettemp

Antwort

    n [-200..800] m [-200..800] o [-200..800] Temperatur in 1/10 °C, max drei Sensoren [[DS18B20]] pro Controller

### RGB Lampe

    :clientname setrgb n m o n [0..255] roter Helligkeitswert, linear, Gammakorrektur im Controller m [0..255] grüner Helligkeitswert, linear, Gammakorrektur im Controller o [0..255] blauer Helligkeitswert, linear, Gammakorrektur im Controller

Antwort

    ok

### Servos

    :setservo n m n [1..5] Servonummer (### Wird noch auf 0..4 geändert) m [0..255] Servoposition, typischer Weise mit engeren Grenzen

Antwort

    ok

### Heizung

Clientname: theemin

Aktuelle Temperatur auslesen. Angabe in 1/100C

    :theemin getActTemp

Aktuelle Soll Temperatur auslesen. Anagebe in 1/100C

    :theemin getTargetTemp

Soll Temperatur setzen. Param xx: ((soll)\*2) in hex. Alle Hexwerte in
Kleinbuchstaben. z.B. Soll = 20C. 20\*2 = 40; 40=28h

    :theemin setTargetTemp xx

## Busankopplung [RasPi](RasPi) - CAN

Optokoppler: 4N25
<!-- `{{attachment:CAN-Busankopplung_2.jpg|CAN Busankopplung}}` -->
