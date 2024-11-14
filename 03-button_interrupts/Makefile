SPORT=/dev/ttyUSB0
BAUD=115200
F_CPU=16000000UL
MMCU=atmega328p
PROGRAMMER_ID=arduino

# ====================================================================================================
# directories
DIR_SRC=.
DIR_OUT=out
OUT_NAME=program

# ====================================================================================================
# files
ELF=$(DIR_OUT)/$(OUT_NAME).elf
HEX=$(DIR_OUT)/$(OUT_NAME).hex
EXE=$(DIR_OUT)/$(OUT_NAME)
# find all c files in src dir (ignore test.c file)
SOURCES := $(shell find $(DIR_SRC) -name '*.c' ! -name 'test.c') 
# comment line above and uncomment the one below to specify which c files to use
#SOURCES = $(DIR_SRC)/writeCfilesHere.c

# ====================================================================================================
# compilers
CC=avr-gcc
OCP=avr-objcopy
CCT=gcc
# upload to arduino cmd
UPLOADCMD = sudo avrdude -V -c $(PROGRAMMER_ID) -p $(MMCU) -P $(SPORT) -b $(BAUD) -D -U flash:w:$(HEX):i

# ====================================================================================================
# compiler flags
CC_FLAGS= -Os -DF_CPU=$(F_CPU)
# linker flags
LD_FLAGS= 

# ====================================================================================================
# compile files

$(ELF): $(SOURCES)
	$(CC) $(LD_FLAGS) $(CC_FLAGS) -mmcu=$(MMCU) -o $@ $(SOURCES)

$(HEX): $(ELF)
	$(OCP) $(ELF) -O ihex $(HEX)

$(EXE): $(DIR_SRC)/test.c
	$(CCT) $(LD_FLAGS) $(CC_FLAGS) -o $@ $(DIR_SRC)/test.c

# ====================================================================================================
# 'functions'

.PHONY: all, test, upload, flash, clean, print, dir

# make out dir
dir:
	mkdir -p $(DIR_OUT)

# compile
all: dir $(ELF) $(HEX) # compile hex file

# test
TestARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
test: $(EXE) # compile and run test exe on local machine
	$(EXE) $(TestARGS)

# uploads the hex file to the arduino
flash:
	$(UPLOADCMD)

# builds and uploads the hex file to the arduino 
upload: all
	$(UPLOADCMD)

# rm build files
clean: 
	rm -rf $(DIR_OUT)

# test makefile
print:
	$(info   SOURCES  := $(SOURCES))
	$(info   TESTARGS := $(TestARGS))

# fix to have test arguments without getting errors
%::
	@true
