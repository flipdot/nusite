+++
title = "Knock-sensor for GSM doorlock, details"
date = 2013-01-18T06:42:52
author = "typ_o"
+++
![](https://flipdot.org/blog/uploads/amp_kl.jpg)  
  
Amplifier for piezo to detect structure-borne sound if member knocks on
the door from outside. Complete GSM doorlock see
[wiki](http://flipdot.org/wiki/index.php?title=Zugangssystem).  
  
Der Piezo hat einen 1M Widerstand, um ihn schneller zu entladen, sonst
bleibt ggf. eine Restladung eine Weile auf der Sensorkapazität. Über
einen Kondensator wird in den Spannunsgteiler eingekoppelt, der dem
Signal 1/2 Betriebsspannung DC-Anteil bringt. Die 4V7 Z-Diode kappt vom
Sensor erzeugte Spannungen größer 4,7 V und größer -0,7 V, bevor das
Signal in den OP geht.  
  
Der OP hat eine Verstärkung von 470/10 + 1 also ca. 48. Mit dem 100n
Kondensator im Gegenkoppelnetzwerk wird die Verstärkung für DC = 0, ohne
Klopfsignal ist die Ausgangsspannung gleich 1/2 Betriebsspannung.  
  
Über die Diode und den 1k5 Widerstand kann der 0µ47 Kondensator
lediglich geladen werden, entladen wird er über die 560k - das geschieht
langsamer und macht das Entprellen. Zur Signalformung gehts nochmal
durch einen Komparator, der einen Open Collector Treiber am
Controllereingang ansteuert.
