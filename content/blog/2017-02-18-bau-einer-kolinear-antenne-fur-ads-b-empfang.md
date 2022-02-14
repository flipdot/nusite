+++
title = "Bau einer kolinear-Antenne für ADS-B-Empfang"
date = 2017-02-18T05:43:00Z
author = "typ_o"
path = "/blog/2017/02/18/bau-einer-kolinear-antenne-fur-ads-b-empfang"
aliases = ["/blog/archives/366-Bau-einer-kolinear-Antenne-fuer-ADS-B-Empfang.html"]
+++
Zivile Flugzeuge senden ein Signal: [Automatic Dependent Surveillance
ADS-B](https://de.wikipedia.org/wiki/Automatic_Dependent_Surveillance).
Dies ist ein System der Flugsicherung zur Anzeige der Flugbewegungen im
Luftraum.

Die Luftfahrzeuge bestimmen selbständig ihre Position, z.B. via GPS. Die
Position und andere Flugdaten, wie Flugnummer, Flugzeugtyp, Zeitsignal,
Geschwindigkeit, Flughöhe und geplante Flugrichtung werden
kontinuierlich – typischerweise einmal pro Sekunde – ungerichtet auf
1090 MHz abgestrahlt.

Diese Anleitung beschreibt den Bau eines Rundstrahlers (Der hier als
Empfangsantenne eingesetzt wird) mit Antennengewinn - also besseren
Empfangseigenschaften als bei einem einfachen Dipol.

Mit einem DVB-T-Stick gibt es dann die Möglichkeit diese Sendesignale zu
empfangen und via SDR (Software-Defined-Radio) anzuzeigen. Software:
[1](https://osmocom.org/projects/sdr/wiki/rtl-sdr),
[2](https://github.com/steve-m/librtlsdr),
[3](https://github.com/MalcolmRobb/dump1090),
[4](https://aur.archlinux.org/packages/dump1090-git/).

**Materialien**

- Koaxialkabel (SAT-Empfang überbleibsel) bspw. Typ:
  "[Koaxkabel](https://satco-europe.eu/de/Koaxkabel/Koaxkabel-KTH-94-100 m-EasyBox2)
  KTH 94" Länge: ~2 m
- Installationrohr (80ct aus dem Baumarkt) Länge: 2 m
- Heißklebepistole plus Schmelzkleber
- Geeignete Anschlussbuchse, hier Koaxial-Stecker plus evtl. Adapter
- DVB-T-Dongle mit RTL2838U-Chip entsprechendem Tuner wie E4000,
  FC0012, FC0013 oder R820T
- PC/Laptop

**Aufbau**

Eine gerade Anzahl von Koaxialkabel-Stücken, also 4,6 oder 8, wird
senkrecht übereinander gestapelt, und bildet die Antenne. Ich habe acht
verwendet. Mehr Elemente erhöhen den Gewinn, verringern aber auch den
vertikalen Öffnungswinkel der Antenne. Die Länge der Stücke beträgt
lambda/2 - die Hälfte der Wellenlänge bei der benutzten
Empfangsfrequenz.

An den Verbindungsstellen werden die Koax-Stücke überaschenderweise
verpolt verbunden: Also Mantel an Seele,und Seele an Mantel.

Am unteren Ende wird die Speiseleitung ebenso verpolt mit dem ersten
Koax-Stück verbunden. Am oberen Ende wird das Koax-Kabel stumpf
abgeschnitten und bleibt offen.

**Arbeitsschritte**

1) Skizzen schaden nie: Worum es gehen soll

[![](/media/antennen_schema.serendipityThumb.png)](/media/antennen_schema.png).

2) Ein wenig Mathematik zum Einstieg. Die Wellenlänge \[lambda\] ist
gleich Lichtgeschwindigkeit c durch Frequenz f (hier 1090 MHz). Die reale
Länge L unserer Koax-Stücke ist noch um einen Verkürzungsfaktor kleiner
(Der Faktor steht in der Kabelspezifikation des Koax-Kabels, bei mir
0.8). So erhielt ich eine Länge von etwa L=110 mm pro Koax-Stück.

3) Herstellen der Koax-Stücke: Vom Koaxkabel Stücke von der Länge L aus
Schritt zwei abschneiden, mit einer Zugabe von etwa 4 cm, denn die Seele
soll unter dem Mantel auf jeder seite etwa 2 cm herausschauen, wobei der
unbeschädigte Mantel eine Länge von L haben sollte. Also acht Stücke zu
15 cm abschneiden.

4) Abisolieren der Seele: Auf jeder Seite der zugeschnittenen Stücke
etwa 2 cm lang alles bis auf den Leiter der Seele entfernen, also äußere
Schutzhülle, dann Mantel und Dielektrikum abschneiden, so dass ~2 cm der
Seele auf beiden Seiten steht.

[![](/media/antennen_vermessung.serendipityThumb.png)](/media/antennen_vermessung.png)

Entscheidend ist die Länge des Mantel-Drahtgeflechtes, also bei uns die
11 cm.

5) Herstellung der Verbindung zwischen Seelen und Mantel der
benachbarten Glieder: Zuerst ein Stück Isolierband auf die erste Seele
aufspießen, dann auch mit der Seele des benachbarten Gliedes
aufspießen:

[![](/media/antennen_spiess_2.serendipityThumb.png)](/media/antennen_spiess_2.png)

Dies sorgt für eine Isolierung zwischen den Manteln der benachbarten
Glieder. Dann derart die beiden Glieder ineinander schieben, dass die
Seele des linken Gliedes Kontakt mit dem Mantel des rechten Gliedes hat
und umgekehrt:

[![](/media/antennen_mantel_2.serendipityThumb.png)](/media/antennen_mantel_2.png)

(Es ist hilfreich nach jedem Wiederholen dieses Schrittes mit einem
Multimeter den Widerstand zwischen Seele und Mantel zu messen - hier
darf keine niederohmige Verbindung bestehen)

6) Großzügiges fixieren der benachbarten Glieder durch Verwendung von
einer guten Menge Klebeband

7) Wiederholung bis alle acht Abschnitte (oder so viele man eben möchte)
verbunden sind, das unterste und das oberste Glied haben dabei
allerdings nur ein benachbartes Glied, während alle anderen genau zwei
benachbarte Glieder besitzen.

8) Vom restlichen Kabel die Zuleitung zum Empfänger abschneiden.
Anmerkung: Ohne Verwendung eines Verstärkers die Speiseleitung so kurz
wie möglich halten, denn eine längere Speiseleitung führt zu erhöhter
Dämpfung des empfangen Signals => die Empfangsqualität leidet.

9) Nach dem gleichen Prinzip wie oben nun die Speiseleitung mit dem
untersten Glied verbinden und fixieren. (Auch hier ist die Überprüfung
mit einem Multimeter zielführend)

10) Am oberen Glied kann nun die überstehende Seele entfernt werden, da
sie nicht benötigt wird. Das obere Ende sollte mit Isolierband vor einer
unerwünschten elektrischen Verbindung zwischen Mantel und Seele
geschützt werden.

11) Am freien Ende der Speiseleitung kann nun die Buchse angebracht
werden.

12) Theoretisch und praktisch ist nun ein erster Test der Antenne
möglich.

13) Kürzen des Installationsrohres auf die Länge der Antenne, so dass
alle Glieder und ein Stück der Speiseleitung im Rohr enthalten bleiben
können.

14) Die Antenne kann durch Verwendung von Heißkleber nun im Rohr fixiert
werden.

15) Nach belieben kann die obere und die untere Öffnung der Antenne nun
mit Klebeband noch mal geschützt werden. Am besten macht man oben auf
das Installationsrohr eine passende Abdeckkappe, gibt es ebenfalls im
Baumarkt. Wenn die Antenne draußen montiert wird, muß diese Abdeckung
oben absolut dicht sein - dringt Wasser in die Antenne ein, wird der
Empfang sofort extrem schlecht.

**Mögliche Verfeinerungen**

- Erweitern um eine Erdung zum Schutz vor Blitzschlag
- Zur besseren Kontaktherstellung der Glieder untereinander können die
entsprechenden Mäntel mit den zugehörigen Seelen verlötet werden

[![](/media/3782.serendipityThumb.jpg)](/media/3782.jpg)

- Mit einem Verstärker, der entsprechend für 1090 MHz ausgelegt ist, kann
noch mehr aus dem Signal geholt werden.
- variation der Anzahl der verbauten Glieder (Anmerkung: es muss jedoch
eine gerade Anzahl an Gliedern sein)

Zu beachten:

- Technisch und geologisch bedingt können aufgrund der Erdkrümmung
Transpondersignale nur knapp in einem Radius von bis zu 450km um den
Antennenstandort empfangen werden.
