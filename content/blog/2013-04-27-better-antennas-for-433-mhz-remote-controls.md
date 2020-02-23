+++
title = "Better antennas for 433 MHz remote controls"
date = 2013-04-27T09:07:00Z
author = "typ_o"
+++
You can control those cheapo hardware store remote controllable power
plugs via your Raspberry Pi:
[rcswitch-pi](http://github.com/r10r/rcswitch-pi). Maybe you like to
switch off some unneccessary lights in your neighborhood. In this case
you only need to iterate all the "house codes" of that simple protocol.
But for a better operating range you want a better antenna.  
  
Hier die Ergebnisse meiner Versuche, einem [einfachen Sender für die 433
MHz](http://www.watterott.com/de/RF-Link-Sender-434MHz) ISM Frequenz am
Raspberry Pi zu einer etwas besseren Reichweite zu verhelfen. Ich habe
die [rcswitch-pi](http://github.com/r10r/rcswitch-pi) - Bibliothek
benutzt, mit der man die gängigen Baumarkt-Steckdosen steuern kann.
Neben einem Viertelwellenstrahler (164mm Draht am Antennenanschluss),
einem Dipol (Zwei solcher Viertelwellenstrahler an Antenne und Masse)
hatte dich die besten Ergebnisse mit einer
[Groundplane](http://de.wikipedia.org/wiki/Groundplane_\(Antenne\)) -
Antenne und einer Sperrtopfantenne.  
  
Die Reichweite habe ich mit einem Scanner-Empfänger und einer
batterieversorgten Funksteckdose ausprobiert.  
  
Für die Groundplane - Antenne braucht man 4 Drahtstücke mit je 164 mm
Länge. Eines kommt an den Antennenanschluss des Sendemoduls senkrecht
nach oben, die anderen drei an den Masseanschluss im Winkel von 45 °
nach unten.  
  
![](https://flipdot.org/blog/uploads/gp.jpg)  
  
Die Sperrtopfantenne braucht weniger Platz und ist ähnlich einfach
herzustellen: An den Innenleiter eines Koaxialkabels lötet man den 164
mm langen Strahler, an den Schirm den 114 mm langen "Sperrtopf" -
einfach ein Stück Messingrohr, durch das das Kabel durchpasst. (Der
Sperrtopf ist kürzer als der Strahler, weil wegen der größeren Kapazität
ein anderer
[Verkürzungsfaktor](http://de.wikipedia.org/wiki/Verk%C3%BCrzungsfaktor)
gilt, 0,66)  
  
![](https://flipdot.org/blog/uploads/sperrtopf3.jpg)  
  
Der Schirm vom anderen Ende des Kabels kommt an GND vom Sender, der
Innenleiter an den Antennenanschluss.  
  
![](https://flipdot.org/blog/uploads/sperrtopf4.jpg)