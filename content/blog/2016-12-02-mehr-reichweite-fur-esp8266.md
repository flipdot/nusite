+++
title = "Mehr Reichweite für ESP8266"
date = 2016-12-02T10:15:40
author = "typ_o"
+++
Auf dem verwendeten ESP8266-12F sitzt eine
[Inverted-F](http://www.antenna-theory.com/antennas/aperture/ifa.php)
Leiterplattenantenne. Für mehr Reichweite habe ich eine [Antenne aus
einem alten Router](https://flipdot.org/blog/uploads/antenne.JPG)
angeschlossen.  
  
[![](https://flipdot.org/blog/uploads/modification.serendipityThumb.jpg)](https://flipdot.org/blog/uploads/modification.jpg)  
  
Dazu an den beiden mit dem roten X gekennzeichneten Stellen die
Leiterbahnen auf der Oberseite auftrennen (nicht nur ein Schnitt, sonst
bleibt eine zu große Koppelkapazität, ein Millimeter darf das Kupfer
schon entfernt werden).  
  
[![](https://flipdot.org/blog/uploads/anloet.serendipityThumb.JPG)](https://flipdot.org/blog/uploads/anloet.JPG)  
  
Der Innenleiter der neuen Antenne wird an die Speiseleitung angelötet,
die zwischen den beiden Masseflächen mit den vielen Durchkontaktierungen
herauskommt. Der Schirm kommt an die Masse.  
  
Danach ist die Reichweite besser. Wie groß der Gewinn ist, kann ich
mangels Messmitteln nur raten - auf jeden Fall geht's jetzt auch bis in
den Keller. In der Literatur wird Inverted-F und
[Sperrtopf](http://www.dl2bcm.de/down/Koaxant.pdf) (das ist der
Antennentyp in der neuen Antenne aus dem Router) mit ähnlichen Werten
angegeben, vermutlich funktioniert die PCB Antenne in der
Platinenumgebung nicht optimal.
