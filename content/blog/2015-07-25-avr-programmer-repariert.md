+++
title = "AVR Programmer repariert"
date = 2015-07-25T20:27:55Z
author = "al"
path = "/blog/2015/07/25/avr-programmer-repariert"
+++
![](/media/AVR_ISP_MKII_Programmer_Reparieren_8.serendipityThumb.jpg)  
Die AVR ISP MKII Programmer von Atmel sind schon ziemlich robuste
Dinger, doch bei falscher Handhabung, können auch diese Programmer sich
relativ schnell verabschieden. Wenn man nicht ganz so viel Pech hatte,
verabschiedet sich nur ein Teil des Programmers und man kann es noch
reparieren.In vielen Fällen verabschiedet sich der [MAX4712
(Fault-Protected, Low-Voltage, Quad SPST Analog
Switches](https://datasheets.maximintegrated.com/en/ds/MAX4711-MAX4713.pdf)).
Manchmal brennt es richtig durch, sodass man ein Brandloch sehen kann
und manchmal sieht es optisch völlig in Ordnung aus, ist im Inneren
dennoch defekt.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_2.serendipityThumb.jpg)

Ich habe schon ein Paar von diesen Programmern repariert, nur ständig
vergessen, es zu dokumentieren. Vor einigen Tagen habe ich wieder einen
in die Hände bekommen und der Defekt war auch offensichtlich.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_3.serendipityThumb.jpg)

Ich habe zwar einen Zugang zu einer Heißluft-Rework-Station, mit der
sich so ein IC problemlos ein-/auslöten lässt, wollte es aber mit
relativ einfachen Mitteln reparieren, damit mehr Bastler (auch ohne
Rework-Station) nach dieser Doku gehen können.

1\. Im ersten Schritt werden dem IC die Beinchen abgeschnitten. Man
sollte sich dabei genug Zeit lassen und sehr vorsichtig schneiden, sonst
trennt man die Leiterbahn unter dem IC durch.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_4.serendipityThumb.png)

2\. Im nächsten Schritt die übrig gebliebenen Beinchen mit der Lötspitze
von den Pads runter löten. Auf dem unteren Bild sind die Beinchen der
linken Reihe bereits entfernt worden.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_5.serendipityThumb.png)

3\. Nun sollte man die Rest des Lötzinns mit der Entlötlitze entfernen.
An dieser Stelle sollte man auch aufpassen, dass man keine Pads
abreisst.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_6.serendipityThumb.jpg)

4\. Im nächsten Schritt wird ein Pad, an irgendeiner Ecke verzinnt, wo
man das IC anlöten kann. So sitzt es dann fest auf der Platine und man
kann mit der anderen Hand wieder das Lötzinn halten.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_7.serendipityThumb.jpg)

5\. Nun das IC anlöten. Am Besten wechselt man nach jedem Pin die Seite.
D.h. ein Pin links anlöten, dann ein Pin rechts, dann wieder eins links
und eins rechts usw.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_8.serendipityThumb.jpg)

6\. Wenn man aus Versehen eine Lötbrücke gemacht hat oder es nicht anders
geht, kann man mit der Lötlitze diese wider entfernen. Meistens bleibt
dann genug Lötzinn unter dem Pin, sodass dieser noch einen guten Kontakt
zum Pad hat.

![](/media/AVR_ISP_MKII_Programmer_Reparieren_9.serendipityThumb.jpg)

Nachdem man mit den Lötarbeiten fertig ist, kann man es wieder mal
testen. In meinem Fall habe ich dann einfach versucht, die Signatur
eines Controllers, mit Hilfe von AVR Studio auszulesen ;-)

![](/media/AVR_ISP_MKII_Programmer_Reparieren_10.serendipityThumb.png)
