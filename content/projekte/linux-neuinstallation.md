+++
title = "Linux-Neuinstallation"
+++

Sammlung:

**Hibernate aktivieren**: (Stromloses Speichern und pausieren momentaner
Arbeitsvorgänge, nötig für Laptops ohne Akku)

a\) Swap datei für Hibernate **vor Installation** (auch SSD ...)

b\) ???? funktioniert nicht ganz?  
Nachträglich aktivieren <http://www.linuxandubuntu.com/home/how-to-enable-hibernate-in-ubuntu-linux>  
startet trotzdem nur neu, Lösung <https://askubuntu.com/questions/548015/ubuntu-14-04-sudo-pm-hibernate-doesnt-work>

**Grub Boot Reihenfolge ändern:**

editieren: `gksu gedit /etc/default/grub`

danach updaten: `sudo update-grub2`

<https://www.howtogeek.com/196655/how-to-configure-the-grub2-boot-loaders-settings/>

**Automatisches Login beim ersten Start** (Sicherer als kein
Passwort...)

Mint: Settings -\> login window (suchen )
