+++
title = "Einschaltstrombegrenzung"
+++

## Projekt

Im Space haben wir einen großen alten Schalter der diverse Lampen, das
Flipdot-Display und ein paar Blinkenlights schaltet, dabei fliegt
manchmal die Sicherung raus. Eine Einschaltstrombegrenzung wäre da die
ideale Lösung...

## Allgemeine Erklärung

Eine Einschaltstrombegrenzung (auch Sanftanlauf genannt) verhindert
Überströme beim Einschalten elektrischer Lasten. Das ist beispielsweise
bei Staubsaugern und großen Netzteilen oftmals wichtig, da der
Staubsauger beim Beschleunigen aus dem Stillstand quasi einen
Kurzschluss darstellt, so auch beim Netzteil, dessen Netzgleichrichter
beim Einschalten große Kondensatoren auflädt.

Diese Problematik wird mit einer Schutzschaltung verhindert, die diesen
Strom begrenzt. Im einfachsten Falle ist dies ein Widerstand in
Verbindung mit einem Netzspannungsrelais. Dabei steigt die Lastspannung
zunächst nur langsam bis die Lastspannung den Schwellwert des
Netzspannungsrelais übersteigt, da der Innenwiderstand des Verbrauchers
steigt, sodass das Relais den Widerstand kurzschließt und die Last
schließlich bei voller Netzspannung betrieben wird

<!--
\|\|
`{{https://upload.wikimedia.org/wikipedia/commons/7/7d/Einschaltverzögerung.png|Schaltplan einer Einschaltstrombegrenzung|width="100%"}}`{=mediawiki}
\|\| \|\|\~-Der im Bild gezeigte Trafo ist nur als Beispiel für eine
Last zu verstehen und ist nicht zwingend erforderlich.-\~ \|\|
-->

## Hacker

- Jesus

## Fragen/Antworten

- Im Space haben wir viele kleine Netzteile z.B. für Raspberry-Pis,
  welche beim Hochfahren häufig abstürzen. Könnte so ein Sanftanlauf
  dieses Problem beheben? (Was stürzt da ab, NT ? Hm, NT für
  Prozessoren *langsam* einzuschalten, dh. eine langsame
  Spannungserhöhung am Ausgang zu erwirken, könnte gerade dann
  Probleme bereiten - es gibt Boards, die ein mindest dU/dt brauchen,
  um sauber anzugehen \[typ_o\])

## Alternative Lösungen

- Billig Funksteckdosen (3 Stück 10 €) + 433 MHz Sender vom Chinamann
  (2 €) + vorhandener Pi. Der Pi erkennt wenn Space geschlossen -\>
  offen, sendet im Sekundenabstand Einschaltcodes an die Dosen - done.

*siehe weitere [Projekte](Projekte)*
