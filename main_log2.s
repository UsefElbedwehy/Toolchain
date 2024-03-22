
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	b580      	push	{r7, lr}
   2:	b082      	sub	sp, #8
   4:	af00      	add	r7, sp, #0
   6:	2000      	movs	r0, #0
   8:	f7ff fffe 	bl	0 <RCC_AHB1EnableClock>
   c:	4a09      	ldr	r2, [pc, #36]	@ (34 <main+0x34>)
   e:	463b      	mov	r3, r7
  10:	e892 0003 	ldmia.w	r2, {r0, r1}
  14:	6018      	str	r0, [r3, #0]
  16:	3304      	adds	r3, #4
  18:	8019      	strh	r1, [r3, #0]
  1a:	3302      	adds	r3, #2
  1c:	0c0a      	lsrs	r2, r1, #16
  1e:	701a      	strb	r2, [r3, #0]
  20:	463b      	mov	r3, r7
  22:	4618      	mov	r0, r3
  24:	f7ff fffe 	bl	0 <GPIO_u8PinInit>
  28:	2201      	movs	r2, #1
  2a:	2105      	movs	r1, #5
  2c:	2000      	movs	r0, #0
  2e:	f7ff fffe 	bl	0 <GPIO_u8SetPinValue>
  32:	e7fe      	b.n	32 <main+0x32>
  34:	00000004 	.word	0x00000004

00000038 <MemManage_Handler>:
  38:	b480      	push	{r7}
  3a:	af00      	add	r7, sp, #0
  3c:	bf00      	nop
  3e:	46bd      	mov	sp, r7
  40:	bc80      	pop	{r7}
  42:	4770      	bx	lr
