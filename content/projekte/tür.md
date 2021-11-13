+++
title = "Tür"
+++

## Schloss in der Nachrichtenmeisterei

### How-To Tuer

- Account im LDAP erstellen kann jeder Member für dich tun
- <https://ldap.flipdot.space> nur im space erreichbar
- nach drittem Mitgliedsbeitrag beim Kassenwart (@cfstras) melden
- dann schaltet er dich frei

#### Öffnungsmethoden

Webinterface

- <https://door.flipdot.space>

SSH-Public-Key auf <https://ldap.flipdot.space> eintragen, und dann

```
#!bash
ssh opendoor@door.fd
```

RFID-Karte

- Dazu melde dich bitte bei @typ_o oder @malled

## Technische Details

(Teils veraltet)

<!-- [`{{attachment:schloss.jpg}}`{=mediawiki}](http://flipdot.org/blog/archives/345-Das-Auge-schliesst-mit!.html) -->

### Anforderungen

- Per Schlüssel (welcher Technik auch immer) die Außentür öffnen
- Aktivierung des elektromagnetischen Türöffners (aka Summer) in der Südtür
- Ggf. auch Klingelfunktion hoch in den Space (könnte via GSM gemacht
  werden, wenn oben sowieso ein GSM Spacetelefon benutzt wird)
- Ggf. auch Sprechverbundung zwische Klingelndem und Leuten im Space.

### Ideen

- Verwendung der Aussparung in der Außenwand links neben der
  Eingangstür (dort könnte Elektronik mit einer Frontplatte eingebaut
  werden)
  - (Klingel-) Taster
  - LCD
  - ggf Eingabemöglichkeit für numerische Schließcodes
- Identifikation an der Tür oben:
  - Biometrie-Fake
  - Okular, eine Ziffer auf Display, random(0..9)
  - Auswahl über riesigen Not-Aus-Buzzer-Taster

### Umsetzung

- GSM Türschloss installiert
- Türsummer an der Südtür wird zum schließen über Relais mit 8 V AC versorgt
- Lösung für Räume oben: [ToDo](ToDo)

## Alte Schlossimplementationen

### RFID

Die erste Schloßvariante lief mit einem RFID-Reader, der nach einer
Weile aber zickte.

### Bluetooth

Der RFID Reader wurde durch ein Bluetooth-Modul ersetzt, was ein Jahr
seinen Dienst tat. Nachteilig war, dass iOS User nicht öffnen konnten,
da iOS kein BT-Profil zur seriellen Datenübetragung unterstützt. Auch
Benutzer älterer Mobiles waren ausgeschlossen.

### GSM

Als dritte Lösung haben wir deshalb jetzt ein GSM-Modul.

#### Caller-ID

Erste Variante: Bei einem eingehenden Anruf wird die Caller ID an einen
uC gesendet, der diese in einer Tabelle der zulässigen Nummern sucht,
und anschließend auf ein Klopfzeichen an der Tür wartet (um ein
versehentliches Aufschließen mit einem nicht verriegelten Telefon aus
der Hosentasche auszuschließen).

Im Controller (Atmega168) werkeln ein paar kB Code, in
[Bascom](http://www.mcselec.com/index.php?option=com_content&task=view&id=14&Itemid=41)
geschrieben.

Der Klopfsensor ist ein kleiner Piezo - Speaker von Pollin mit einer
aufgeklebten Mutter, um nur den Körperschall der Tür aufzunehmen,
anschließend etwas OP, um das Signal aufzuhübschen.

Zum Debugging war noch ein kleiner VGA-Adapter angeschlossen,
Hersteller micro-vga.

#### SMS - Schliesscode

Caller IDs sollen sich mit Voip Systemen auch für Mobilfunknummern faken
lassen, deswegen sind wir auf SMS + Schliesscode gewechselt.

### SSH

Parallel gab es noch einen public key authentifizierten Zugang zu einem
Pi, der dann via Schaltkontakt die Schloßelektronik zum Aufschließen
bewegen konnte.

### Türstatus icons für spaceapi

<!--
\|\|[geschlossen](attachment:fdclosed.png) \|\|
`{{attachment:fdclosed.png|closed}}`{=mediawiki}\|\|
\|\|[offen](attachment:fdclosed.png) \|\|
`{{attachment:fdopen.png|open}}`{=mediawiki}\|\|
-->
