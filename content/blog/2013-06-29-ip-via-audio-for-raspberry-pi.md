+++
title = "IP via audio for Raspberry Pi"
date = 2013-06-29T18:23:18Z
author = "typ_o"
path = "/blog/2013/06/29/ip-via-audio-for-raspberry-pi"
+++
A simple Python script uses some mp3 files to tell you the IP address of
your Raspberry without stuff like nmap or peeking into your router.

Audio aktivieren:  
sudo apt-get install alsa-utils  
sudo apt-get install mpg321

Die mp3s habe ich hiermit: <http://ctrlq.org/listen/> erzeugt und mit
[audacity](http://audacity.sourceforge.net/?lang=de) zerschnibbelt.
Soundfiles und Script aus diesem
[zip](https://flipdot.org/blog/uploads/Raspberry_sagt_IP.zip "Raspberry_sagt_IP.zip")
auspacken und in ein Verzeichnis deiner Wahl legen, und mit crontab das
script beim booten aufrufen:

crontab -e  
@reboot python say\_ip\_on\_boot.py
