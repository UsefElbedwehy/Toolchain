CC = arm-none-eabi-gcc

MACK = cortex-m4

CFLAGS = -c -mcpu=$(MACK) -mthumb -std=gnu11 -Wall

LDFLAGS =  -T Stm32F446_LS.ld -nostdlib -Wl,-Map=final.map

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@
	
GPIO_prog.o: GPIO_prog.c 
	$(CC) $(CFLAGS) $^ -o $@
	
RCC_Program.o: RCC_Program.c
	$(CC) $(CFLAGS) $^ -o $@
	
STM32_F446reStartup.o: STM32_F446reStartup.c
	$(CC) $(CFLAGS) $^ -o $@
	
final.elf: main.o  GPIO_prog.o STM32_F446reStartup.o RCC_Program.o
	$(CC) $(LDFLAGS) $^ -o $@
	
all: main.o  GPIO_prog.o STM32_F446reStartup.o RCC_Program.o final.elf
	
clean:
	rm -rf *.o *.elf
	
load:
	openocd -f board/st_nucleo_f4.cfg
