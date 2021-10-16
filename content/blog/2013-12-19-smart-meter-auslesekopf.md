+++
title = "Smart Meter Auslesekopf"
date = 2013-12-19T21:41:00Z
author = "typ_o"
path = "/blog/2013/12/19/smart-meter-auslesekopf"
+++
Kommt auch mit zum 30C3, der
[SmartMeter](https://wiki.volkszaehler.org/basics)

Schaltung des Infrarot-Empfängers mit einem Transistor zur
Impulsformung. Betriebsspannung = Versorgungsspannung des Prozessors, an
den die Daten gehen, dann stimmt der Pegel automatisch.

![](/media/smeter01.jpg)

Der Fototransistor sitzt in dem klaren LED-Gehäuse und blickt auf den
Opto-Ausgang des Zählers:

![](/media/smeter04.jpg)

Signal an der Schnittstelle zum uC:

![](/media/smeter03.jpg)

Zählerausgabe, Terminal setting: 9600, 7E1.
[Protokoll](https://wiki.volkszaehler.org/software/obis)

![](/media/smeter02.jpg)
