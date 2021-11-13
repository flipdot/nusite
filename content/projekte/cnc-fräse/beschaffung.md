+++
title = "CNC-Fräse: Beschaffung"
+++

### Tasks beim Aufbau

- ~~(Fräse holen)~~
  - ~~(Dateblatt einfordern)~~ (Eckard angeschrieben),
  - Verfahrwege, *Steps / mm!* BZT: 1 Umdrehung / 5 mm Verfahrweg auf allen Achsen
- ~~(Tisch im Keller frei räumen)~~
- ~~(Tisch an die Wand dübeln)~~ nicht nötig, alles ruhig
- ~~(Elektro bis in die Tischecke legen )~~
  - ~~(Anzahl Steckdosen festlegen )~~
  - ~~(Verlängerungs-Steckerleisten an die Wand dübeln )~~
- ~~(Licht. Viel Licht)~~
- Netzwerk aus dem Space in den Keller (nice to have)
  - ca 60 m Kabel nötig
- ~~(G-Code Interpreter (GRBL) aufbauen)~~
- ~~(Motortreiber und G-Gode Interpreter verbinden)~~
- ~~(Stromversorgung für die beiden Komponenten )~~
- ~~(Testlauf mit extra Motoren auf dem Tisch ohne Fräsenmechanik)~~
- ~~(alles schön in ein Gehäuse & verkabel)~~
- ~~(Fräse elektrisch anschließen an Treiber)~~
- ~~(Platz für Steuerung unter dem Fräsentisch (Lüftung?)
  Schubladenauszug?!)~~
- ~~(Notaus-Kette bauen)~~ könnte noch einer dazu, wenn das Pendant
  fertig ist
- ~~(GRBL auf die Maschinenphysik einstellen)~~
- ~~(nach geeigneter CAM Software suchen)~~ ESTLCAM
- ~~(einen Rechner auswählen / vorbereiten)~~
  - Dell NB
  - An die Wand? Schublade? Schwenkarm?
- Datenlogger für Feuchte bauen und im Keller deponieren - wirds da rosten?

### Kaufen / besorgen / erbitten:

- ~~(Doppelklebeband )~~
- ~~(Spachtel )~~
- ~~(Opferplatte 3 x MDF und passende, längere Maschinenschrauben)~~
  - Nächstes mal kein MDF nehmen, fusselt und quillt, sondern
    Siebdruckplatten!
- ~~(Fräser (Material? HSS? .. Jan fragen!) )~~
- ~~(Bohrersatz (Holz und Metall) )~~
- ~~(Schieblehre )~~
- Stahllineal
- ~~(Werkzeug für Nutenstein-Schrauben & Spannzangen )~~
  - ~~(Inbusschlüsselsatz )~~
  - ~~(Gabelschlüsselsatz )~~
- Flachzange
- Seitenschneider
- Kreuz- und Flachschraubendreher
- ~~(Akkuschrauber)~~
- Säge:
  - Einstreich- oder Fuchsschwanz
  - ~~(Metall-Bügelsäge)~~
- Feilen
  - ~~(Schlüsselfeilen)~~
  - Schlichtfeilen
- Werkbank-Schraubstock, Beilagen

### Betrieb

Kress Spindel
[Service](http://www.kress-elektrik.com/Kundendienst-Kundencenter.267.0.html)

### Entscheidung

- [triple Beast incl.
  NT](http://www.sorotec.de/shop/CNC-Steuerungstechnik/DriveSets/DriveSet-Triple-BEAST.html)
- [BZT-PFL-3
  0604](http://www.bzt-cnc.de/de/shop/cnc-fraesmaschinen/82-baureihe-pfl-3/724-pfl-3-0604)
  incl. Zubehör und [Kress
  Spindel](http://www.bzt-cnc.de/de/shop/hf-spindeln/85-kress/507-fraes-spindel-kress-1050-w-oder-5000-25000-rpm)
- Mach3 via parallele Schnittstelle
- Dell NB

Das Setup mit Mach 3 ist für den Anfang gedacht, später könnte ein GRBL
Interpreter auf einem AVR und quelloffene Software günstiger sein.

<http://www.precifast.de/triple-beast/>
<http://www.precifast.de/pc-fuer-mach-3-vorbereiten/>

### Feature requests

- Bearbeitbares Material: Bis 2,5mm Al,
- Arbeitsbereich >= 400 x 600, Z?
- Saugeranschluß
- Spindel besser als Proxxon, Kress Fräse oder gleich HF Spindel
- Steuerung: So simpel wie möglich, weil hier der meiste Lernaufwand
  und Hürde füe Neulinge liegt (vgl. grbl Steuerung aus c\'t Hacks)

### Bauen, Bausatz, Fertig?

- soll schnell fertig sein
- niemand der viel Zeit zum konstruieren hat
- mechanische Skills begrenzt
- Werkzeug extrem begrenzt

================

Fertig kaufen

### Etat

- 1k Spende
- 1,5k Eigenmittel

### Links

- [1](https://www.stepcraft-systems.com/)
- [2](http://www.ebay.de/itm/NEU-3-ACHSEN-6040-CNC-ROUTER-GRAVIERGERAT-BOHREN-FRASEN-GRAVURMASCHINE-b8-/290771237919)
- [3](http://www.sorotec.de/shop/index.php)
- [4](http://www.cnc-kompakt.de/index.php)
- [5](http://www.erz-fraesmaschinen.de/)
- [6](http://www.team-haase.de/)
- [7](http://cnc-modellbau.net/html/cnc-maschinen.html)
- [8](http://www.openbuilds.com/builds/openbuilds-ox-cnc-machine.341/)
- [9](http://www.openbuilds.com/builds/routy-cnc-router-v-slot-belt-pinion.101/)
- [10](http://myhobby-cnc.de/?Projekte:WoodPecker_ALU)

### Vergleich

\|\|\<#fbe380>Hersteller \|\|\<#fbe380>Modell
\|\|\<#fbe380>Arbeitsbereich \|\|\<#fbe380>Arbeitsspindel
\|\|\<#fbe380>Kosten \|\|\<#fbe380>Kommentar \|\| \|\|Stepcraft
\|\|[600](https://www.stepcraft-systems.com/cnc-3d-systeme/stepcraft-600)
\|\|420 x 600 x 80 \|\|keine \|\|1200 Bausatz \|\| \|\| \|\|Stepcraft
\|\|[600 CK RTR mit
USB](https://www.stepcraft-systems.com/cnc-3d-systeme/stepcraft-600)
\|\|420 x 600 x 80 \|\|keine \|\|1500 fertig \|\| \|\| \|\|China
\|\|[6040](http://www.ebay.de/itm/NEU-3-ACHSEN-6040-CNC-ROUTER-GRAVIERGERAT-BOHREN-FRASEN-GRAVURMASCHINE-b8-/290771237919)
\|\|750 x 450 x 20 \|\|0.8KW VFD spindle \|\|1000 + 640 Versand?
\|\|Ungenaue Teile, Probleme beim Zusammenbau, mechanisch weich \|\|
\|\|BZT
\|\|[BZT-PF750-P](http://www.sorotec.de/shop/product_info.php/info/p2759_bzt-pf750-p---kugelumlaufspindeln.html)
\|\|650 x 430 x 110 \|\|keine \|\|2380 \|\|In der ct Hacks recht gut
besprochen\<\
\>cncecke
[1](http://www.cncecke.de/forum/showpost.php?p=606959&postcount=25),
[2](http://www.cncecke.de/forum/showpost.php?p=377197&postcount=5)
\|\| \|\|ERZ \|\|[NC
500](http://www.erz-fraesmaschinen.de/html/erz-nc_500.html)
\|\|620 x 420 x 120 \|\|keine \|\|1900 \|\| \|\| \|\|Haase \|\|[CUT
2500M](http://www.team-haase.de/maschinen/cut2500) \|\|600 x
420 x 110 \|\|keine \|\|2600 Bausatz ohne Elektronik \|\| \|\|
\|\|Pro-Basic \|\|[H
06/05](http://www.cnc-modellbau.net/shop/product_info.php?pName=portal-fräse-probasic-h-0605-fertig-aufgebaut&cName=cncmaschinen-probasic-0605)
\|\|600 x 500 x 100 \|\|keine \|\|2100 \|\|Pro-Basic mechanisch weich
(Forum) \|\| \|\|Pro-Basic \|\|[H
10-05](http://www.cnc-modellbau.net/shop/product_info.php?pName=probasich-1005-montiert&cName=cncmaschinen-probasic-1005)
\|\|1000 x 500 x 100 \|\|keine \|\|2150 \|\| \|\|

### Motorsteuerungen

Empfehlung von M aus der Kommune: [Triple
Beast](http://benezan-electronics.de/shop/product_info.php?cPath=8&products_id=61)
