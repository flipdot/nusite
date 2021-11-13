+++
title = "MPD"
+++

Im Space wird aktuelle per `mpd` ([Music Player
Daemon](https://de.wikipedia.org/wiki/Music_Player_Daemon))
Musik gehört. Um dich damit zu verbinden, brauchst du einen
entsprechenden Client.
[Hier](http://mpd.wikia.com/wiki/Clients) gibt es eine lange
Liste an möglichen Clients.

## ncmpcpp

Das unaussprechliche `ncmpcpp` ist ein Kommandozeilen-Client für MPD.
Der Vorteil darin besteht, dass es (wie ein paar andere Clients auch)
mehrere Configs lesen kann.

Lege die Config `~/.ncmpcpp/config-pixelfun` für den flipdot mit
folgendem Inhalt an:

    mpd_host = pixelfun.fd
    mpd_port = 6600

Nun kannst du, solange du im flipdot-Netzwerk bist `ncmpcpp` mit dem
MPD-Server verbinden mit folgendem Befehl:

    ncmpcpp -c ~/.ncmpcpp/config-pixelfun

## Windows-Client

<https://auremo.codeplex.com/>

    mpd_host = pixelfun.fd
    mpd_port = 6600
