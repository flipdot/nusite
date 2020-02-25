+++
title = "Smart Meter Auslesekopf"
date = 2013-12-19T21:41:00Z
author = "typ_o"
path = "/blog/2013/12/19/smart-meter-auslesekopf"
+++
Kommt auch mit zum 30C3, der
[SmartMeter](http://wiki.volkszaehler.org/basics)  
  
Schaltung des Infrarot-Empfängers mit einem Transistor zur
Impulsformung. Betriebsspannung = Versorgungsspannung des Prozessors, an
den die Daten gehen, dann stimmt der Pegel automatisch.  
  
![](https://flipdot.org/blog/uploads/smeter01.jpg)  
  
Der Fototransistor sitzt in dem klaren LED-Gehäuse und blickt auf den
Opto-Ausgang des Zählers:  
  
![](https://flipdot.org/blog/uploads/smeter04.jpg)  
  
Signal an der Schnittstelle zum uC:  
  
![](https://flipdot.org/blog/uploads/smeter03.jpg)  
  
Zählerausgabe, Terminal setting: 9600, 7E1.
[Protokoll](http://wiki.volkszaehler.org/software/obis)  
  
![](https://flipdot.org/blog/uploads/smeter02.jpg)
