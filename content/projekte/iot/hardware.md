+++
title = "IoT: Hardware"
+++

Unter-Seiten:

* [Change Requests](change-requests/)
* [Messungen](messungen/)
* [Platine Löten](platine-löten/)

*Entwurf*

Knoten (= Sensoren oder Aktoren)

## Brainstroming

<!-- [`{{attachment:IoD_V0.3.jpg|attachment:IoD_V0.3.jpg|width="600"}}`{=mediawiki}](attachment:IoD_V0.3.jpg) -->

- [ESP8266](ESP8266)-01 (billigster Typ), ggf. [Whitty
  Cloud](http://www.schatenseite.de/2016/04/22/esp8266-witty-cloud-modul/)
  Modul (schick)
- Batterieversorgung Alkaline / Eneloop (ggf. ergänzt durch PV)
- Jumper für Dauerstrom (Platz für Low Drop Regler vorsehen?)
- Stromsparen durch
  - Deepsleep (~ 200 µA)
  - *oder* separater Attiny zum Aufwecken (Interrupt on Port change) (~ 0,2 µA)
  - *oder* Taster in der Vcc Leitung, der von MOSFET durch ESP
    überbrückt wird (vermutlich \<\< 0,1 µA)
- ESP Module möglichst ohne Modifikation verwenden (Ausser LED für
  Betriebsspannungsanzeige auslöten)
- Einfache Gehäusemontage (Tropfenlöcher zum Einhängen o.Ä.)
- Vorhandene Gehäuse? Diese zweiteiligen Schraubdosen von DMB?
- Einfacher Batterietausch

## Schaltung

<!-- {{attachment:knoten-sch0.4.png}} -->

## Funktion

<!-- [`{{attachment:20170125_164320.jpg|attachment:20170125_164320.jpg|width="400"}}`{=mediawiki}In](attachment:20170125_164320.jpg) -->
In einem ersten Muster haben wir den ESP in Ruhe im Sleep Mode betrieben,
und über seine Reset Leitung geweckt (In [Messungen](messungen/)
Details zur Akkulaufzeit). An einer Tür ist dazu ein Schleifkontakt
nötig, der sowohl bei geschlossener als auch bei offener Tür nicht
aktiviert ist, und nur z.B. während der Öffnungsbewegung ein mal
aktiviert wird, und den ESP damit weckt.

Nachteil: Der ESP weiss nicht, ober die Tür nach dem schließen des
Kontaktes offen oder geschlossen ist. Gut geeignet ist diese Methode
jedoch zb. als Einbruchsalarm. Leider kann man den ESP nicht über Port
Change Interrupts wecken. Deswegen haben wir den Attiny vorgesehen, der
sowohl bei steigender als auch bei fallender Flanke geweckt wird, und
dem ESP die aktuelle Schalterstellung melden kann. Als weiteren Vorteil
bekommen wir so einen deutlich geringeren Ruhestromverbrauch, da der ESP
komplett abgeschaltet werden kann - nur der Attiny bleibt im Deep Sleep
an der Batterie.

## Betriebszustände

Ruhezustand:

- Der Attiny befindet sich im Sleep-Mode
- ESP ist abgeschaltet

Aufwachen:

- Attiny wird durch Interrupt on Port Change aufgeweckt
- und schaltet über den Mosfet den ESP ein

Daten übertragen:

- Der ESP stellt mit einer festen IP-Adresse (Schneller als DNS) eine
  Verbindung zum Access Point her
- und überträgt die aktuelle Schalterstellung des Sensors, die er über
  SWITCH_STATE vom Attiny gemeldet bekommt, zum Server
- Am Ende der Übertragung prüft der Attiny, ob die Schalterstellung
  noch mit jener zu Beginn des Aufwachzyklus identisch ist
- Wenn ja: Schlafen. Wenn nein (d.h., die Tür wurde nur ganz kurz
  geöffnet und sofort wieder geschlossen) wird 5 sec gewartet und die
  dann herrschende Schalterstellung erneut übertragen. So wird
  inkonsistente Information über Türzustand vermieden

Abschalten / schlafen gehen

- Nach erfolgreicher Übertragung bittet der ESP den Attiny über die
  Leitung SHUTDOWN, ihn abzuschalten
- Attiny schaltet den Mosfet und damit den ESP ab
- und legt sich selber wieder schlafen

## Bestückungs- und Funktionsvarianten

- ESP in Ruhe abgeschaltet:
  - Jumper 1 Pwr_Ctrl: 2-3 gesteckt
  - Jumper 2: offen
  - Jumper 5: RST via Attiny offen
- ESP in Ruhe im Sleep Mode
  - Jumper 1 Pwr_Ctrl: 1-2 gesteckt
  - Jumper 2: gesteckt
  - Jumper 5: RST via Attiny gesteckt

ESP in Ruhe abgeschaltet: Geringer Ruhestromverbrauch (ca. 0,2 µA),
jedoch längere Zeit beim Verbindungsaufbau. Geeignet bei selten
betätigten Knoten.

ESP in Ruhe im Sleep Mode: Höherer Ruhestromverbrauch (ca. 200 µA),
deutlich kürzere Zeit beim Verbindungsaufbau. Geeignet bei häufig
betätigten Knoten.

## Stromverbrauch

Der Verwendete Attiy 45V-10SU (Final 25V-10SU) ist
[spezifiziert](http://www.atmel.com/Images/Atmel-2586-AVR-8-bit-Microcontroller-ATtiny25-ATtiny45-ATtiny85_Datasheet-Summary.pdf)
mit Power-down Mode: 0,1 μA at 1.8V, Operating Voltage -- 1.8 - 5.5V und
Speed Grade 0 -- 4 MHz @ 1.8 - 5.5V, 0 - 10 MHz @ 2.7 - 5.5V.

## Stromversorgungsvarianten

Die Schaltung ist für Betrieb mit drei AA Eneloop Zellen konzipiert.
Eneloops haben eine sehr geringe Selbstentladung und versprechen nach
einem Versuch über knapp 200 Tage einen Betrieb in Jahresfrist ohne
Akkuwechsel. Dazu wird die Spannung der Eneloops am Pin BATT_HIGH
eingespeist. Eine Schottkydiode in Serie verhindert, dass bei frisch
geladenen Zellen Vcc max des ESP überschritten wird.

Alternativ kann die Schaltung mit zwei AA Alkaline-Zellen betrieben
werden. Da diese im neuen Zustand nur wenig mehr als 1,5 V je Zelle
liefern, ist die Diode unnötig, und die Batteriespannung wird an
BATT_LOW eingespeist

## Bestückungsplan Hardwareversion 0.41

<!-- {{attachment:Bestueckung-v0.41.png}} -->

## Material

\|\|\<tablewidth="100%"\>**Anzahl** \|\|**Bezeichnung** \|\|**Preis**
\|\|**Bestell-Link** \|\| \|\|1 \|\|ESP8266-01 \|\|1,41
\|\|[ESP-01](https://www.aliexpress.com/item/Free-shipping-ESP8266-serial-WIFI-wireless-module-wireless-transceiver/32267651506.html)
\|\| \|\|1 \|\|AO 3413, MOSFET P-CH, 20V, 3A, SOT-23 (Schaltet ESP ein)
\|\|0,21 \|\|[AO
3413](https://www.reichelt.de/AO-BTS-Transistoren/AO-3413/3/index.html?ACTION=3&LA=5&ARTICLE=166493&GROUPID=7161&artnr=AO+3413)
\|\| \|\|1 \|\|ATTINY 25V-10 SU :: Atmel AVR-RISC-Controller, SOIC-8
\|\|1,30 \|\|[ATTINY
25V-10SU](https://www.reichelt.de/Atmel-Attiny-AVRs/ATTINY-25V-10-SU/3/index.html?ACTION=3&GROUPID=2958&ARTICLE=69298&OFFSET=75&)
\|\| \|\|1 \|\|B 140 F, SMD-Schottky-Diode, DO214AC/SMA, 40V, 1A
\|\|0,08 \|\|[B 140
F](https://www.reichelt.de/BA-BAY-BB-Dioden/B-140-F/3/index.html?ACTION=3&LA=5&ARTICLE=95199&GROUPID=2988&artnr=B+140+F)
\|\| \|\|4 \|\|12 kOhm, SMD Widerstand 0805, 100 mW, 1% \|\|0,01
\|\|[RND 0805 1
12K](https://www.reichelt.de/SMD-0805-von-1-bis-910-kOhm/RND-0805-1-12K/3/index.html?ACTION=3&LA=5&ARTICLE=183253&GROUPID=7971&artnr=RND+0805+1+12K)
\|\| \|\|1 \|\|SMD-Kerko, 1210, 100µF, 6,3V, 20%, MLCC \|\|0,25 \|\|[X5R
1210 DB
100U](https://www.reichelt.de/Vielschicht-SMD-G1210/X5R-1210-DB-100U/3/index.html?ACTION=3&GROUPID=3167&ARTICLE=194475&OFFSET=75&)
\|\| \|\|3 \|\|Vielschicht-Kerko, 100nF, 50V (Alternativ in
[0603](https://www.reichelt.de/Vielschicht-SMD-G0603/KEM-Y5V0603-100N/3/index.html?ACTION=3&GROUPID=3166&ARTICLE=207005&OFFSET=75&))
\|\|0,02 \|\|[KEM [X7R0805](X7R0805)
100N](https://www.reichelt.de/Vielschicht-SMD-G0805/KEM-X7R0805-100N/3/index.html?ACTION=3&GROUPID=8048&ARTICLE=207073&OFFSET=75&)
\|\| \|\|0,5 \|\|2x10pol. Buchsenleiste, gerade, RM 2,54 (Halbiert für
ESP Anschluß) \|\|0,56 \|\|[BL 2X10G
2,54](https://www.reichelt.de/Buchsenleisten/BL-2X10G-2-54/3/index.html?ACTION=3&GROUPID=7435&ARTICLE=6074&OFFSET=75&)
\|\| \|\|3 \|\|Batteriehalter, 1x Mignon "AA" \|\|0,24 \|\|[HALTER
1XAAK](https://www.reichelt.de/Batteriehalter-fuer-Mignon/HALTER-1XAAK/3/index.html?ACTION=3&LA=5&ARTICLE=113154&GROUPID=4255&artnr=HALTER+1XAAK)
\|\| \|\|0,1 \|\|Jumper 40pol. Stiftleiste, gewinkelt, RM 2,54 (Jumper
für Aktivierung des Wifi Manager im Betrieb) \|\|0,22 \|\|[SL 1X40W
2,54](https://www.reichelt.de/Stiftleisten/SL-1X40W-2-54/3/index.html?ACTION=3&GROUPID=7434&ARTICLE=19507&OFFSET=75&)
\|\| \|\|1 \|\|Kurzschlussbrücke, rot, mit Grifflasche (Jumper für
Aktivierung des Wifi Manager im Betrieb) \|\|0,04 \|\|[JUMPER 2,54GL
RT](https://www.reichelt.de/Stiftleisten/JUMPER-2-54GL-RT/3/index.html?ACTION=3&GROUPID=7434&ARTICLE=9018&OFFSET=75&)
\|\| \|\|1 \|\|Stiftleiste 2,54 mm, 2X03, gerade (Für ISP Anschluß)
\|\|0,14 \|\|[MPE
087-2-006](https://www.reichelt.de/Stiftleisten/MPE-087-2-006/3/index.html?ACTION=3&GROUPID=7434&ARTICLE=119893&OFFSET=75&)
\|\| \|\|1 \|\|Stiftleiste 2,54 mm, 1X06, gerade (für Batterie und
Schalter Anschluß, die drei Pins für Schalter werden nachträgl. um 90°
gebogen) \|\|0,14 \|\|[MPE
087-1-006](https://www.reichelt.de/Stiftleisten/MPE-087-1-006/3/index.html?ACTION=3&GROUPID=7434&ARTICLE=119883&OFFSET=75&)
\|\| \|\|1 \|\|MPE 094-1-003 :: Buchsenleisten 2,54 mm, 1X03, gerade
(Schalter Anschluß, kommt am die Leitung zum Schalter) \|\|0,13 \|\|[MPE
094-1-003](https://www.reichelt.de/Buchsenleisten/MPE-094-1-003/3/index.html?ACTION=3&GROUPID=7435&ARTICLE=119912&OFFSET=75&)
\|\| \|\| \|\|1 \|\|Platine (0,20 Basismaterial, 0,10 Chemie geschätzt)
\|\|0,30 \|\| \|\| \|\| \|\| \|\|**Summe ca.** \|\|**5,00** \|\| \|\|
\|\|

## Änderungen für kommende Hardware Revision 0.5

- Elko 330 µF ersetzt durch Kerko 100 µF
- Zusätzlicher Kerko 100 nF am Reset Pin Attiny (Fix für
  Startprobleme)
- Kerko 100 nF an Vcc Attiny ersetzt durch Kerko 10 µF (Fix für
  Startprobleme)
