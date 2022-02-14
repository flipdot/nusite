+++
title = "Raspberry zeigt an, ob der Space offen oder geschlossen ist"
date = 2013-04-04T18:58:10Z
author = "typ_o"
path = "/blog/2013/04/04/raspberry-zeigt-an-ob-der-space-offen-oder-geschlossen-ist"
aliases = ["/blog/archives/189-Raspberry-zeigt-an,-ob-der-Space-offen-oder-geschlossen-ist.html"]
+++
![](/media/spaceopen1.jpg)

Der Status des Schliessystems wird von den Endschaltern via Optokoppler
an den Raspberry gegeben. Ein Cronjob fragt alle Minute einen GPIO Pin
ab (wiringPi) und ein Shellscript ruft via wget auf dem Flipdot Server
ein PHP-Script auf, das ein Bild umkopiert, je nach dem Türstatus.
("Simple & Stupid")
