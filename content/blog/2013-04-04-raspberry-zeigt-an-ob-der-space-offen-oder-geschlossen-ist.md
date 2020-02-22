+++
title = "Raspberry zeigt an, ob der Space offen oder geschlossen ist"
date = 2013-04-04T18:58:10
author = "typ_o"
+++
![](https://flipdot.org/blog/uploads/spaceopen1.jpg)  
  
Der Status des Schliessystems wird von den Endschaltern via Optokoppler
an den Raspberry gegeben. Ein Cronjob fragt alle Minute einen GPIO Pin
ab (wiringPi) und ein Shellscript ruft via wget auf dem Flipdot Server
ein PHP-Script auf, das ein Bild umkopiert, je nach dem Türstatus.
("Simple & Stupid")
