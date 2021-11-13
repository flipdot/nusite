+++
title = "USV"
+++

*Unterbrechungsfreie Stromversorgung*

## "DIE USV"℠

Eine große
[USV](https://de.wikipedia.org/wiki/Unterbrechungsfreie_Stromversorgung)
(aka. "DIE USV"℠) soll dazu dienen, den [Server](Server)
mit Notstrom zu versorgen, damit dieser ~~(sanft herunterfahren kann)~~
im Notbetrieb ~~(mind. 12h)~~ ca 20-40min weiterläuft und Services
unterbrechungsfrei zur Verfügung stellt (z.B. [Internet](Neuland/Internet)
in der Nachrichtenmeisterei). Generell ist bei einer USV das Ziel, die
Systeme bei kurzen (<10min) Stromausfällen am Laufen zu halten - und bei
längeren Stromausfällen (>20min) die Systeme geordnet herunterzufahren
(und eventuell danach die Core-Infrastruktur für einige Zeit weiter am
Laufen zu halten - vorausgesetzt diese benötigt nicht zu viel Energie).

Folgende Systeme müssen möglichst lang am Leben gehalten werden:

- Türschloss (inkl. GSM Modul)
- Telefon (Anrufbeantworter)
- Alarmanlage (Sensoren und Aktoren)!
- Internet, Core-Netzwerk, Server
- Notbeleuchtung (über 12V-LED-Strips? Oder einfach ein paar 12V-MR16
  Leuchten nehmen? Oder rote GU10-240V-Leuchten?)

### APC

[typ_o](typ_o) hat noch eine alte USV bei sich zu Hause, die
er dafür spenden wollte. Es handelt sich wohl um eine
[SmartUPS1000](SmartUPS1000) von APC.

Die USV hier ist wohl nicht die, die [typ_o](typ_o) hat? Oder
wurde das von [typ_o](typ_o) bestätigt?
<https://img.conrad.de/medias/global/ce/9000_9999/9700/9730/9738/973893_LB_00_FB.EPS_1000.jpg>
\| [SmartUPS1000](SmartUPS1000) von APC\|height="200px"

- TODO: USV vor Bestellung von den Akkus nochmal testen!

### Akku-Kapazität

Kommentar Wolfi: Die Berechnungen die hier waren sind alle für die
Tonne, u.a. wenn man davon ausgeht, dass die USV laut Herstellerspecs
betrieben werden soll. Dann passt nämlich nur ein Akkutyp. Man kann
nicht einfach jede x-beliebige USV mit nem (externen) XXL-Akku versehen
und davon ausgehen, dass das ohne Rauchzeichen dann einfach "länger auf
Akku durchhält"....

## die usvs

Andere Systeme mögen es ebenfalls nicht, wenn sie "hart" ausgeschaltet
werden, sie benötigen ein sanftes Herunterfahren:

- Beamer
  - *Kommentar von Wolfi: Der kommt mir aber nicht mit an "DIE USV"℠...*
- Raspberry Pis (z.b. Blinkenlights)
  - *Kommentar von Wolfi: Es können gerne alle Raspis die in der
    Nähe ~~(vom Netzwerkschrank)~~ der USV montiert sind mit über
    "DIE USV"℠ versorgt werden. Wenn habe ich sowieso vor da noch
    \'n Ein-Netzteil-Für-Alles aka modifiziertes ATX-Netzteil für
    die Versorgung von allen 12V/5V/3.3V Dingen zu basteln, welches
    dann auch mit an der USV hängen wird. Das aber erst, wenn das
    mit der Elektroinstallation fertig ist.*
  - *kssoz: Für das Herunterfahren der Pis wurde von typ_o über
    dezentrale USV geredet. Ich halte das für sinnvoll, weil einige
    Pi Projekte kommen und gehen, ohne zentralistische Planung.*

*siehe auch andere [Projekte](Projekte)*

## Hacker

- typ_o
- malled
- Wolfi
