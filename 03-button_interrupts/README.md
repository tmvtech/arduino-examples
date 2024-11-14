<h1 align="center">
  <br>
  <a href="https://www.tmvtech.com/">
    <img width=100px height=100px src="https://www.tmvtech.com/wp-content/uploads/2024/05/net.svg">
  </a>
  <br>
    <b>TMVTech</b>
  <br>
  <sub><sup><b>Button w/interrupts</b></sup></sub>
  <br>
</h1>

[This project](https://www.tmvtech.com/baremetal-arduino-button-with-interrupts/) toggles the onboard LED state when a button on pin INT0 (D2 on Nano) is pressed.

## Makefile commands

```sh
# create output directory
make dir

# compile everything
make all

# compiles test.c file and runs it on your local pc
make test

# send the program to your arduino
make flash

# the same as doing 'make all & make flash'
make upload

# delete out folder and it's contents
make clean

# used while making this make file, shows sources and test args
make print
```