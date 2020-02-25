+++
title = "Mechanisches \"Hello World\" am T-Shirt-Drucker"
date = 2010-12-22T05:54:06Z
author = "typ_o"
path = "/blog/2010/12/22/mechanisches-hello-world-am-t-shirt-drucker"
+++
Erste mechanische Baustufe des T-Shirt-Druckers.

  
  
Jetzt brauche ich nur noch eine funktionierende Lösung, wie ich die eher
dickflüssige Farbe auf den Stoff bringe. Irgendwas mit einem Stempel?
Leerer Edding mit Stoffarbe gefüllt? Ein Röhrchen, das durch
Kapillareffekt Farbe nach vorn saugt und auf den Stoff tupft? Eine
Schlauch-Rollenpumpe? Ein Perfusor? Ein
[Piezo-Tintenstrahl-Druckkopf](http://reprap.org/wiki/Scratchbuilt_Piezo_Printhead)?

Für die beiden Pumpenvarianten habe ich schon mal was da: Eine alte
Maschine, mit der Patienten im Krankenhaus z.B. Schmerzmittel über
längere Zeit bekommen:

![](https://flipdot.org/blog/uploads/IMG_8693.jpg)

Die Mechanik drückt den Spritzenkolben langsam rein... Aber wie die
Spitze gestalten? Na, und die Schlauchpumpe sieht so aus:

![](https://flipdot.org/blog/uploads/IMG_8694.jpg)

Großer Nachteil für diesen Zweck: Die Förderrate ist nicht konstant,
sondern schwankt regelmäßig, wenn die Rollen den Schlauch erfassen bzw.
freigeben. Das Teil dürfte dann eher im Bar-Bot zur Förderung von Gin
Verwendung finden.

Farbe zum Testen ist auch schon da (Braun und schwarz, \*seufz\*), aber
für umsonst:

![](https://flipdot.org/blog/uploads/IMG_8695.jpg)

Ach, und dann natürlich noch eine Kleinigkeit für Softwerker, für mich
gleich nochmal 1-2 Monate: Ein PC-Programm, das ein Bitmap-Bild, das ich
mir zb. mit Photoshop anlege, zeilenweise ausliest und wenn schwarz bzw.
weisses Pixel, über die serielle Schnittstelle (bzw. derzeit Bluetooth
SPP) einen Steuerstring an den Chefcontroller sendet. (Am besten:
Pixelzahl bis zum nächsten schwarzen Pixel in der Zeile)
