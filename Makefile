
PROJECT = datalogger
CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m7 -mthumb -O2

all: $(PROJECT).elf

$(PROJECT).elf: main.o onewire.o ds18b20.o sdcard.o
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f *.o $(PROJECT).elf
