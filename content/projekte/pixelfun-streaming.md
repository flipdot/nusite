+++
title = "Pixelfun Streaming"
+++

*Eigenes Audio auf den pixelfun streamen*

Pulseaudio hat tolle Netzwerkfeatures, mit denen man zB auch seine
lokalen Audiostreams auf andere Rechner streamen kann. (Natürlich nur,
wenn die es auch explizit zulassen)

Um das ganze bei Euch lokal einzurichten müsst Ihr erst mal die GUI
Anwendung *paprefs* installieren. Die gibt\'s in den meisten
Paketrepositories unter gleichem Namen. Direkt im ersten Tab müsst Ihr
dann nur noch das Häkchen bei "Make discoverable pulseaudio network
sound devices available locally" setzen. ACHTUNG: Sollte es bei euch
ausgegraut sein, müsst Ihr noch das *pulseaudio-module-zeroconf* Paket
installieren. (Name kann je nach Paketmanager abweichen)

Danach startet Ihr am besten kurz Euren Rechner neu.

Zuletzt müsst ihr noch die GUI Anwendung *pavucontrol* installieren.
Dort solltet Ihr jetzt unter "Output devices" ganz unten devices mit
"pi@pixelfun.fd" im Namen haben.

An diese könnt Ihr jetzt einfach Euer Audio Routen. \\o/
