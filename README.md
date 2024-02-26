# EEPROM_PROGRAMER

## Description:
This is an EEPROM programmer made to program the AT28C64 and AT28C256 EEPROMS with arduino. The programmer was made with the purpose to program the AT28C64 EEPROM for the [display register](https://github.com/Tonikiller10000/8BitProcessor/tree/main/DisplayRegister) of the 8 bit processor and the AT28C256 EEPROM for the [W65C02](https://github.com/Tonikiller10000/W65C02Computer) 8 bit computer.



<table>
  <tr>
    <td>Version 1.0
The EEPROM Programmer V1.0 has only 2 smd shift registers used with and arduino on the breadboard to set the eeprom address at programming. With this programmer, the shift register connections ware already made so you don`t have to place 2 shift registers on breadboard, but because of the pins placement, it needed to be connected with jumper wires.
    </td>
    <td><img src="https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V1.0/EEPROM_PROGRAMER_V1.0_Pictures/20230729_093718.jpg" width=200 height = 400 ></td>
  </tr>

</table>



Version 2.0
The EEPROM Programmer V2.0 has 2 dip shift registers for an easy to build design. Also for an easier and faster way to program the EEPROMS, the ZIF socket was added witch also adds an cool design. This design needs dirrect connection of the 16 pins including 2 power pins, dirrectly to the arduino. 

<table>
  <tr>
    <td>
### Pinout
- EEPROM Data pins
    - D0-D7     : Data EEPROM IO pins
- Shift Register control pins
    - CLK       : Shift Register CLK pin
    - LATCH     : Shift Register Latch pin
    - OE        : Shift Register OE pin
    - DataIn    : Shift Register Serial Data In pin
- EEPROM control pins
    - WE        : EEPROM Write Enable pin
    - OE        : EEPROM Output Enable pin
    - GND       : arduino GND
    - VCC       : arduino 5V
    </td>
    <td><img src="https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V2.0/EEPROM_PROGRAMER_V2.0_Pictures/EE2.jpg" width=400 height=300 ></td>
  </tr>
</table>






Version 3.0
<table>
  <tr>
    This design is an plug and play version. It is an arduino shield, with some extra power, pins and 4 smd dip switches with one power switch and 8 modes to program the eeprom on the go, without the need of an computer:
    - *program make programs for every switch in the arduino(max 8);
    - connect a battery;
    - turn the power of the shield down;
    - insert the EEPROM;
    - set the switches for the data you want to program on it;
    - press the reset button while turning the shield power on;   
    - release the reset button and let the EEPROM be programed (may take a while).
  </tr>
  <tr>
    <td><img src="https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V3.0/EEPROM_PROGRAMER_V3.0_Pictures/ee32.png"></td>
    <td><img src="https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V3.0/EEPROM_PROGRAMER_V3.0_Pictures/ee31.png"></td>
    <td><img src="https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V3.0/EEPROM_PROGRAMER_V3.0_Pictures/ee33.png"></td>
  </tr>
</table>


<table>
  <tr>
    <td>Version 1.0</td>
    <td>Version 2.0</td>
  </tr>
  <tr>
    <td><img src=""  height = 400 width= 400 ></td>
    <td><img src="https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V2.0/EEPROM_PROGRAMER_V2.0_Pictures/EE2.jpg"  height = 400 width= 400 ></td>
  </tr>
</table>




### Programming:
[This](https://github.com/Tonikiller10000/EEPROM_PROGRAMER/blob/main/EEPROM_PROGRAMER_V2.0/EEPROM_PROGRAMER_V2.0.ino) code is made for the EEPROM V1.0 and V2.0. The version 3.0 has permanent pins seted. ...


### Links:
74HC595 datasheet (shift register): https://datasheetspdf.com/pdf-file/446162/ONSemiconductor/74HC595/1
AT28C256 datasheet (32K EEPROM): https://ww1.microchip.com/downloads/en/DeviceDoc/doc0006.pdf
AT28C64 datasheet (8K EEPROM): https://ww1.microchip.com/downloads/en/devicedoc/doc0001h.pdf

