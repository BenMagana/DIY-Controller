# DIY-Controller
Homegrown USB/Bluetooth controller

## Programming the ATMEGA4809

### Bootloading

[Source](https://github.com/SpenceKonde/megaTinyCore/blob/master/MakeUPDIProgrammer.md)

The 4809 only allows UPDI software loading, so a spare Arduino ( I used an Uno) will be used to burn the bootloader. The bootloader software (jtag2updi) is loaded on the spare arduino. All files from the “source” folder of the git are copied to a jtag2updi folder. Select the proper board (Uno) and port and upload the program to the Arduino. The .ino program will be blank, this is fine.

Once uploaded, the Arduino can be connected to the 4809 as shown below.

*Ignore chip name, use ATMEGA 4809*

![alt text](https://github.com/BenMagana/DIY-Controller/blob/main/img/UPDI_Wiring_Diagram.png?raw=true)
![alt text](https://github.com/BenMagana/DIY-Controller/blob/main/img/UPDI_Fritzing_Diagram.png?raw=true)

Pin numbers correspond to correct numbers of 4809


Go to the link below to have the option for the 4809 to be selected.
https://github.com/MCUdude/MegaCoreX#how-to-install

Once the above is done, choose these options and select “burn bootloader”

![alt text](https://github.com/BenMagana/DIY-Controller/blob/main/img/Bootloader_Settings.png?raw=true)

Once bootloaded, the 4809 can be used in one of the configurations below to test that the “blink” Arduino program works on the bootloader.

![alt text](https://github.com/BenMagana/DIY-Controller/blob/main/img/USB_Diagrams.png?raw=true)


## Programming

![alt text](https://github.com/BenMagana/DIY-Controller/blob/main/img/Atmega4809_DIP.png?raw=true)
![alt text](https://github.com/BenMagana/DIY-Controller/blob/main/img/Atmega4809.png?raw=true)

## To Do List
* Implement Bluetooth
* Implement Accelerometer
