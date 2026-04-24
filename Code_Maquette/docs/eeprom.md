# EEPROM Programming
## Install AVRDUDE
[AVRDUDE](https://github.com/avrdudes/avrdude) - AVR Downloader Uploader - is a program for downloading and uploading the on-chip memories of Microchip’s AVR microcontrollers. It can program the Flash and EEPROM, and where supported by the programming protocol, it can program fuse and lock bits

## Usage
```sh
avrdude -c <programmer> -p <mcu> -U eeprom:w:<file>.eep[:format]
```


### 🧩 Explanation of Flags
| Option              | Description                                                                 | Example(s)                                    |
|---------------------|-----------------------------------------------------------------------------|-----------------------------------------------|
| `-c <programmer>`   | Specifies the programmer type                                               | `usbasp`, `usbtiny`, `arduino` , `wiring`     |
| `-p <mcu>`          | Specifies the target AVR microcontroller                                    | `m2560` (for ATmega2560)                 |
| `-P`                | Port COM to use                                                             | `COM3`                                        |
| `-b`                | Baudrate                                                                    | `115200`                                      |
| `-U`                | Memory operation in the format: `<memtype>:<op>:<filename>[:format]`        | See details below                             |

### `-U` Option Breakdown

| Component     | Meaning                    | Example(s)                           |
|---------------|----------------------------|--------------------------------------|
| `<memtype>`   | Memory type                | `eeprom`                             |
| `<op>`        | Operation type             | `w` (write), `r` (read)              |
| `<filename>`  | File to operate on         | `file.eep`, `file.bin`               |
| `[:format]`   | (Optional) File format     | `:i` (Intel Hex), `:r` (raw binary)  |


## Dump EEPROM
```sh
.\avrdude -c wiring -p m2560 -P COM3 -b 115200 -U eeprom:r:backup.eep:i
```

## Flash EEPROM
```sh
.\avrdude -c wiring -p m2560 -P COM3 -b 115200 -U eeprom:w:backup.eep:i
```
