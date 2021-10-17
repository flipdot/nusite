+++
title = "ESC identifizieren"
date = 2018-05-22T22:03:42Z
author = "Baustel"
path = "/blog/2018/05/22/esc-identifizieren"
+++
![](/media/ESC-584x438.jpg)

Manchmal habe ich auf dem Tisch Technik liegen, zu der ich erst mal kaum
Informationen habe. Diese Technik stammt z.B. aus ganz alten
Bestellungen, war ein Giveaway, aus einer Wanderkiste, war mal ein
Geschenk, wurde irgendwo ausgebaut usw. usf. In solchen Fällen muss man
dann etwas Aufwand investieren, um etwas mehr Informationen
herauszufinden. In diesem Artikel geht es um einen ESC (Electronic Speed
Controller), bzw. etwas, was 8 Leitungen hat, in Schrumpfschlauch
eingeschweißt ist und mit einem „20A“ Aufkleber. Hintergrund des Ganzen
ist, dass mir empfohlen wurde, die [SimonK
Firmware](https://github.com/sim-/tgy) auf die ESCs zu flashen. In dem
eingeschweißten Zustand, kommt man aber noch nicht mal an die
Programmierschnittstelle dran. Also muss der Schrumpfschlauch ab.

![](/media/ESC_Controller-584x438.jpg)

![](/media/ESC_Kuehlkoerper-584x438.jpg)

Auf der einen Seite der Platine kommen dann der Controller und die
Spannungsregler zum Vorschein, und auf der anderen Seite, ein Kühlkörper
und ein Aufdruck „DDT-30A-02". Ein Aufdruck ist schon oft eine große
Hilfe. Anhand des Aufdrucks konnte ich im Netz raus finden, dass die
SimonK Firmware mit meinem ESC höchstwahrscheinlich kompatibel ist.
Aber, wie so oft, gibt es ein Aber. Bei meiner Recherche konnte ich auch
raus finden, dass die Platine mit der Bezeichnung DDT-30A-02 beliebtes
Platinenlayout für viele ESCs ist, jedoch kann die Bestückung abweichen.
Je nach Bestückung, kann es sich um 30, 20 oder auch 10 Ampere Version
handeln. Welche man nun hat, erfährt man, wenn man den Kühlkörper
abmacht. Je nach Ausführung, ob 10, 20 oder 30A, werden die Platinen mit
6, 12 oder 15 MOS-FETs bestückt. Nachdem ich den Kühlkörper abgemacht
habe, konnte ich 12 MOS-FETs auf der Platine sehen. Also 20A Version,
was auch mit dem „20A"-Aufkleber auf dem Schrumpfschlauch übereinstimmen
würde. Ich bin auch auf einen Tipp gestoßen, einen Blick in die Liste
der kompatiblen ESCs mit der SimonK Firmware rein zu werfen ([Google Docs
Link](https://docs.google.com/spreadsheets/d/13tMlu5ldLNpZXwbe6UhDHJhcgTVuljm8HDiDp9WO9Pk/edit#gid=0)).
Die Liste besteht aus über 200 Einträgen. Es ist also besser, wenn man
bei der Menge der Einträge mit Filtern arbeitet.

In der zweiten Spalte findet man die Angaben zum Maximalstrom und wie
ich ja raus finden konnte, liegt dieser bei meinem ESC bei 20A. Also
habe ich die Liste nach 20A gefiltert. Danach bleiben nur noch 18
Einträge. In der Spalte „FW file" blieben aber immer noch zu viele
mögliche hex-Dateien. Also musste ich die Liste solange filtern, bis mir
nur eine einzige Möglichkeit bleiben würde.

Mikrocontroller auf dem Board ist ein ATmega 8, also Spalte „MCU" nach
ATmega filtern. In der Spalte „Pads" ist die Anordnung der Pads zum
Programmieren gemeint. Wie man auf dem Foto weiter oben sehen kann, sind
meine in Reihe angeordnet. Bei Pads also nach Row filtern.

Bei der nächsten Spalte „Ext.Osc" geht es darum, ob auf der Platine ein
externer Oszillator/Quarz vorhanden ist. In meinem Fall konnte ich keins
finden, also nach „No" filtern. Danach bleibt in der Spalte „FW file"
nur noch eine Möglichkeit: tgy.hex

Man könnte jetzt eigentlich meinen, dass man alles nötige weiß und mit
gutem Gewissen die tgy.hex auf den ESC flashen kann.

Leider musste ich in Vergangenheit unangenehme Erfahrungen sammeln,
insbesondere wenn es um Platinen aus Fernosten geht. Mal wird die
Firmware angepasst, mal das Layout, mal die Bauteile -- eben alles, was
den Preis nach unten drückt. Um aber doch noch die Akzeptanz zu
behalten, werden dann Aufdrucke von bekannten Produkten/Platinen
verwendet usw. Aber das ist noch mal ein anderes Thema.

Ich habe den Filter mit dem externen Oszillator nochmal raus genommen.
Es kann ja sein, dass der Hersteller lieber auf den internen Oszillator
gesetzt hat, um somit die Materialkosten bei der Herstellung zu sparen.
Was in der Tabelle noch bleibt, sind drei Einträge, mit drei
unterschiedlichen hex-Dateien und eine ungefilterte Spalte „FETs". Zwei
Einträge für ESCs mit N-Chanel FETs und ein Eintrag für ESCs mit einem
Gemisch aus N-Kanal und P-Kanal MOS-FETs. Wenn man in der Firmware nicht
berücksichtigt, ob man nur mit N-Kanal oder mit einem Gemisch aus N- und
P-Kanal FETs arbeitet, kann das böse Folgen haben. Im Besten Fall riecht
man nur, dass sein ESC ab jetzt nicht mehr funktioniert

Als Nächstes habe ich nach Bezeichnungen der FETs gesucht. Auf der
Platine sind 6 [MT6680 (N-Chanel
MOS-FETs)](http://www.mtsemi.com/uploadfile/MT6680.pdf) und 6 [AO4407
(P-Chanel MOS-FETs)](http://aosmd.com/pdfs/datasheet/ao4407.pdf).

Ok, also kann das wirklich nur noch die Firmware tgy.hex sein.

Um meine Skepsis dann noch ein bisschen zu beruhigen, habe ich die ISP
Pins des Controllers, zu den sechs Pads für den Programmer, mit einem
Multimeter durchgeklingelt.

Im letzten Schritt konnte ich die tgy.hex Firmware auf den ESC flashen,
der dann auch ohne Rauchwolken einen Brushless Motor ansteuern konnte
