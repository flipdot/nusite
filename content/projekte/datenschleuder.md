+++
title = "Datenschleuder"
+++

Die *Datenschleuder* (oder *Daten\--(sch)\--l\--(e)\--uder*) ist unser
kleines, aber feines NAS. Mit 4TB sollte Sie erstmal genügend
Speicherplatz bieten. Zu erreichen ist sie in unserem Netzwerk unter
`datenschleuder.fd`.

## Zugang

Du kannst auf das Gerät über
[SFTP](https://en.wikipedia.org/wiki/SSH_File_Transfer_Protocol)
zugreifen, insofern du schon einen Account hast. Falls nicht, helfen dir
gerne [feliks](feliks), [malled](malled) oder
[oboro](oboro) bei der Erstellung. Hierfür werden lediglich
dein Benutzername und dein öffentlicher SSH-Schlüssel benötigt. Falls du
noch keinen solchen Schlüssel haben solltest, kann du hier nachlesen,
wie man so einen erstellt:
[Windows](https://www.digitalocean.com/community/tutorials/how-to-create-ssh-keys-with-putty-to-connect-to-a-vps),
[Unixoide
Betriebssysteme](https://help.github.com/articles/generating-ssh-keys/)

## Nutzung

Um komfortabel auf Datenschleuder zuzugreifen, stehen dir verschiedene
Möglichkeiten zur Verfügung.

### Einbinden als Dateisystem

Unter unixoiden Betriebssystemen kannst du mit dem Werkzeug `sshfs`
eine SFTP-Verbindung aussehen lassen wie einen lokalen Ordner. Dafür
musst du über deinen Paketmanager das Paket `sshfs` installieren (kann
sein, dass es einen etwas anderen Namen hat, abhängig von deinem
Betriebssystem).

Mit folgendem Befehl kannst du die Datenschleuder einbinden:

    sshfs benutzername@datenschleuder.fd:/ /dein/lokaler/ordner

Und so kannst du das Ganze wieder aushängen:

    fusermount -u /dein/lokaler/ordner

### (S)FTP Client

Mit Hilfe von FileZilla (oder ähnlichen
SFTP-fähigen Programmen) kannst du dich zur *Datenschleuder* mit
folgenden Angaben verbinden:

    Benutzername: deinname
    Port:         22
    Adresse:      datenschleuder.fd
    Verzeichnis:  /

Vergiss dabei nicht, dass du deinen öffentlichen SSH-Schlüssel dafür
noch angeben musst, wie
[hier](https://superuser.com/questions/180221/connect-to-server-using-sftp-and-public-ssh-key-using-filezilla-on-windows)
beschrieben.

### Kommandozeile

Wenn du auf die Datenschleuder über die Kommandozeile zugreifen willst,
kannst du das mit dem Programm `sftp` machen. Hiermit lässt sich auch
einfach testen, ob eine Verbindung scheitern sollte.

## Daten

Alle Daten im `/home`-Verzeichnis sind lesbar von **allen Benutzern**
(bis auf die SSH-Schlüssel). Du solltest also also keine privaten Daten
auf der *Datenschleuder* speichern. Dein eigenes Verzeichnis
(`/home/deinname`) kann nur von dir beschrieben werden, allerdings von
allen gelesen. Im gemeinsamen Verzeichnis `/home/datenschleuder` kann
jeder lesen und schreiben, wie er lustig ist. Daten werden dort
anonymisiert erstellt, sodass nicht festgestellt werden kann, wer die
Daten dort hochgeladen hat.

## Administration

### Neuer Nutzer

Zur Erstellung eines neuen Nutzers eignet sich das Skript
`~/adduser.sh`, welches lediglich einen Benutzernamen und einen
öffentlichen SSH-Schlüssel benötigt. Wird es ohne Parameter aufgerufen
fragt es interaktiv danach, allerdings kann es auch wie folgt aufgerufen
werden:

    ~/adduser.sh USERNAME SSH-KEY

### Debugging

Wenn mal eine Verbindung nicht klappen sollte, sind Folgendes häufige
Fehlerquellen:

- Falsche Nutzerrechte für die Datei `/home/user/.ssh/authorized_keys`
- Falsch geschriebener SSH-Key (Zeilenumbrüche!)
- Nutzer verwendet falschen SSH-Key zum verbinden

*TODO: Speicherplatz prüfen (warum sind das nur 2TB)*

*TODO: ACL einrichten, um Daten zu anonymisieren*

*TODO: Darstellung der Daten auf dem Fernseher/Grafana?*
