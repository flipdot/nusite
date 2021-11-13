+++
title = "Pixelfun"
+++

Der Pixelfun ist ein Raspberry Pi, auf dem
[YMPD](https://github.com/notandy/ympd) läuft. Über die
Website [pixelfun.fd](http://pixelfun.fd) lässt sich im
Space-Netzwerk die Wiedergabe steuern.

## Streaming

Folgendes muss unter Arch Linux installiert und konfiguriert werden, um
auf den pixelfun-Pi streamen zu können:

- "paprefs" installieren und "Make discoverable [PulseAudio](PulseAudio)
  network sound devices available locally" aktivieren
- "pulseaudio-zeroconf" installieren und "avahi-daemon.service"
  starten / aktivieren (systemctl)
- "pavucontrol" installieren und unter "Playback" das Ausgabegerät
  wählen ("snd_rpi\_..." statt "Built-in Audio Analog Stereo"
  oder dergleichen)
