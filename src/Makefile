all: libLcd.a lcddemo.elf

CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include -L../lib
#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c
AR              = msp430-elf-ar

libLcd.a: font-5x7.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h

lcdutils.o: lcdutils.c lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

#additional rules for files
load.elf: main.o switches.o buzzer.o stateMachine.o interrupt.o led.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer -lLcd -lp2sw

load: load.elf
	msp430loader.sh $^

clean:
	rm -f libLcd.a *.o *.elf

buzzer.o: buzzer.c buzzer.h

led.o: led.c led.h switches.h

switches.o: switches.c led.h switches.h buzzer.h lcddraw.h lcdutils.h

stateMachine.o: stateMachine.s stateMachine.h led.h switches.h

main.o: main.c buzzer.h led.h switches.h

interrupt.o: interrupt.c 
