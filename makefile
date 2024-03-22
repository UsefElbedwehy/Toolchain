CC = arm-none-eabi-gcc

MACK = cortex-m4

CFLAGS = -c -mcpu=$(MACK) -mthumb -std=gnu11

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@
	
GPIO_prog.o: GPIO_prog.c 
	$(CC) $(CFLAGS) $^ -o $@