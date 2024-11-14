<h1 align="center">
  <br>
  <a href="https://www.tmvtech.com/">
    <img width=100px height=100px src="https://www.tmvtech.com/wp-content/uploads/2024/05/net.svg">
  </a>
  <br>
    <b>TMVTech</b>
  <br>
  <sub><sup><b>Baremetal Arduino</b></sup></sub>
  <br>
</h1>


This repo contains all of our tutorial's code related to Baremetal programming with Arduino Nano, Uno and Mega.

## Requirements

You will need an Arduino Nano or Uno for most of the tutorials but some will be made for the Arduino Mega's MCU. Besides the hardware, your PC will need to have the following packages installed:

```sh
# On Ubuntu
sudo apt install avr-libc avrdude binutils-avr gcc-avr build-essential
``` 

## How to use

This repo is setup in a way that running a project should be as easy as 'cd-ing' into it and running 'make upload'.

For example:

```sh
cd 01-onboard_LED_blink
make upload
```

## Other Repos

You can visit our [Blog](https://www.tmvtech.com/tutorials/) for more tutorials on other microcontrollers, docker and linuxor you can also visit our other repos:

- [Esp32 tutorials](https://www.tmvtech.com/tutorials/)
- [Ubuntu tutorials](https://www.tmvtech.com/tutorials/)
- [Raspberry Pi tutorials](https://www.tmvtech.com/tutorials/)