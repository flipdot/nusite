+++
title = "Apple iPad1-3G Akkutausch (Reparatur mit vorhandenem Material)"
date = 2017-02-12T07:09:48Z
author = "typ_o"
path = "/blog/2017/02/12/apple-ipad1-3g-akkutausch-reparatur-mit-vorhandenem-material"
+++
Problem war folgendes: Freund von mir hat sein iPad1-3G vor einigen
Wochen beim Aufräumen wiedergefunden, Akku komplett leer (lag halt
einige Jahre unbenutzt umher). Hat nicht mehr gebootet (boot-loop, also
kurz an, dann wieder aus, dann wieder an, dann wieder aus usw). Ursache:
Beide LiPo Zellen waren bloaty...und hatten 0V Zellspannung.

Reparaturziel: iPad soll (zumindest bei Netzbetrieb) wieder benutzbar
sein \[mal davon ab, dass heute eigentlich jedes Billo Android-Tablet
bessere Hardwarespecs hat als der alte Apfel da\].

Weitere Vorgehensweise (teilweise nicht zur Nachahmung empfohlen\!):  
iPad aufhebeln (ja, das hier war noch nicht geklebt\!), dabei trotz
ifixit-Bilderbuch gefühlt die Hälfte der Halteclips abbrechen und das
Gehäuse zerkratzen. Stellt sich raus, dass 'nen großer Metallspachtel
doch nicht so gut zum iPad-Öffnen gedacht ist.

Fehler war schnell gefunden: Akku bloaty...

[![](/media/ipad-bloaty1.serendipityThumb.jpg)](/media/ipad-bloaty1.jpg)

Als nächstes dann alles weiter auseinandergenommen und die schwarzen
Aufkleber von den Akkuzellen abgefummelt, Akkus entsprechend markiert
und dann vom Akku-Board getrennt.

Nur wo ist jetzt "Plus" und "Minus" bei den Akkuzellen? Da hat dann
'nen Schaltplan (Quelle: Internet) mit bei geholfen das auch sicher
rauszufinden.
Da sich ganz ohne Akkuzellen am Fehlerbild nichts weiter verändert
hatte, gab es die erste Idee, ein altes nicht mehr so ganz brauchbares
Nikon Akkupack als Zellenspender zu verwenden. Also das auch mal
zerlegt:

[![](/media/DSC_0026.serendipityThumb.JPG)](/media/DSC_0026.JPG)

...und die zwei Akkuzellen voneinander getrennt und dann einzeln mit
einer Ladeelektronik aus einer kaputten Powerbank (wo glücklicherweise
nur der Akku kaputt war) geladen:

[![](/media/DSC_0052.serendipityThumb.JPG)](/media/DSC_0052.JPG)

Erste Erkenntnis: Diese flachen Panasonic Lithium-Zellen haben ihren
"Plus"-Pol am Gehäuse anliegen! Muss man also aufpassen und die
Umgebung gut isolieren, damit es keinen ungewollten Kurzschluss geben
kann (Kapton Tape to the rescue!).
Also mal gucken ob das iPad am Labornetzteil angeht und wieviel Strom
das so zieht:

[![](/media/ipad-alive.serendipityThumb.jpg)](/media/ipad-alive.jpg)

It's alive!

[![](/media/DSC_0105.serendipityThumb.JPG)](/media/DSC_0105.JPG)

Aber hm, doch n bisschen viel Stromverbrauch. Mal im Datenblatt von den
Panasonic Akkuzellen nachschauen was die so können\...da stand erstmal
nix zu Lade-&Entladeströmen. Also weiter gesucht und irgendwo eine
Tabelle gefunden, aus der ich entnommen habe, dass man diese Akkuzellen
nur mit 0,2C entladen darf, was bei zwei Zellen (je ca 1100mAh) parallel
immernoch um einiges vom benötigten Wert (plus Sicherheitsbuffer)
entfernt lag.
Also die Panasonic-Akkuzellen wieder weggepackt (in mehrere
Plastiktütchen eingewickelt, damit es bei der Lagerung hoffentlich
keinen ungewollten Kurzschluss gibt).

Plan B: Ich hatte da doch noch 'nen altes Samsung Galaxy S2 mit
kaputtem Display vor dem Schrott gerettet und da war doch der Akku noch
gut!

Akku gefunden (der hat sogar hoffentlich auch noch seine eigene
Schutzschaltung mit drin), jetzt also nur noch schnell Kabel anlöten und
ab damit in's iPad:

[![](/media/DSC_0107.serendipityThumb.JPG)](/media/DSC_0107.JPG)

[![](/media/DSC_0112.serendipityThumb.JPG)](/media/DSC_0112.JPG)

Und dann noch alles schön mit Kapton Tape isoliert und festgeklebert und
wieder zusammengebaut:

[![](/media/DSC_0124.serendipityThumb.JPG)](/media/DSC_0124.JPG)

[![](/media/DSC_0132.serendipityThumb.JPG)](/media/DSC_0132.JPG)

[![](/media/itsalive1.serendipityThumb.jpg)](/media/itsalive1.jpg)

Yay, Funktioniert!

Akkulaufzeit ist so ca 'ne Stunde - aber immerhin besser als garnix.
Und außer Kapton Tape musste ich für diese Reparatur auch nix extra
kaufen, da alles andere noch vorhanden war. Nur gut, dass ich (fast) nie
was wegwerfe!
