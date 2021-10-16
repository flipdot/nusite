+++
title = "Shut down your Raspberry Pi on button press and add reset function"
date = 2013-06-03T12:08:55Z
author = "typ_o"
path = "/blog/2013/06/03/shut-down-your-raspberry-pi-on-button-press-and-add-reset-function"
+++
Connect a shutdown-pushbutton to
[header 5](http://elinux.org/RPi_Low-level_peripherals#P5_header) (pin 6
and 8) and a reset button to
[header 6](http://elinux.org/RPi_Low-level_peripherals#P6_header) (pin 1
and 2). Copy
[shutdown.py](https://flipdot.org/blog/uploads/shutdown.py.txt) to your
/home/pi folder, and add line in crontab with crontab -e: "@reboot sudo
python /home/pi/shutdown.py" (without the quotes). Done.

![](https://flipdot.org/blog/uploads/raspi_shutdown.jpg)

![](https://flipdot.org/blog/uploads/raspi_reset.jpg)

Das Script legt eine Interruptroutine an, die bei einer fallenden Flanke
am GPIO pin 31 angesprungen wird.
