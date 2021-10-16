+++
title = "Jeder Space hat ein Schloss"
date = 2016-06-29T20:47:07Z
author = "typ_o"
path = "/blog/2016/06/29/jeder-space-hat-ein-schloss"
+++
Irgendein Schloss? Natürlich nicht\! Elektronisch, sicher, Schlüssel
leicht zurückzuziehen, Datensparsam usf.

Unsere
[Schlossmechanik](https://flipdot.org/blog/archives/345-Das-Auge-schliesst-mit!.html)
hat jetzt auch die nötige Soft- und Hardware bekommen.

Die Steuerung besteht aus einem PI und einem pihat mit einem PIC16LF1719
µC.

[![](/media/pic.serendipityThumb.jpg)](/media/pic.jpg)

Der PIC empfängt die Steuerbefehle seriell und steuert den
Zentralverriegelungsmotor an. Der µC liest die Stellung des Türriegels
über ein Schiebepotentiomieter aus und sendet diese Information
ebenfalls seriell an den PI zurück.

Auf dem PI existiert ein Benutzerkonto, welches alle öffentlichen
Schluessel von zugangsberechtigten Mitgliedern enthält. So kann der
Mechanismus von allen Mitgliedern mittels eines ssh clients (z.B. der
flipdot App) betätigt werden.

[![](/media/pihat.serendipityThumb.png)](/media/pihat.png)

Erweiterungsideen: Audiosignal vor dem Schließen, Kontrolle der
Riegel-Endpositionen auf korrektes schließen / öffnen, eigenes Wlan, um
nicht von der Space - Infrastruktur abhängig zu sein.

Im Playstore gibt es unsere flipdot App für Android, mit der die Tür
betätigt werden kann, der Spacestatus und die Besucheranzahl angezeigt
und unser IRC-Kanal betreten werden kann.

[![](/media/app.serendipityThumb.jpg)](/media/app.jpg)
