+++
title = "Raspberry telefoniert nach draussen"
date = 2013-02-02T00:48:20Z
author = "typ_o"
+++
![](https://flipdot.org/blog/uploads/raspi-small.jpg)  
  
Den Raspberry im Netz zu exponieren schien mir keine gute Idee: Keine
Performance bei vielen Zugriffen, die Mühe den Webserver auf ihm sicher
zu machen, und den dyndns-Ärger wegen NAT.  
  
![](https://flipdot.org/blog/uploads/rasp_schema.jpg)  
  
Ich habe jetzt auf dem Pi einen Cronjob, alle 30 sec. Messdaten von
einem angeschlossenen uC nach draussen auf einen Server schiebt, wo man
sie sich anschauen kann. Hier kann man auch Strings für den RasPi
ablegen, die beim Pollen abgeholt werden. Der String geht dann zurück an
den angeschlossenen uC. [Näheres im flipdot
wiki](http://flipdot.org/wiki/index.php?title=Raspberry_telefoniert_nach_draussen).
