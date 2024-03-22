<h1 style="color:blue">  TOOLCHAIN   </h1>

<p>
what is the startup code?

The reset handler or startup code is the first piece of software to execute after a system reset.Typically, the reset handler is used for setting up configuration data for the C startup code (such as address range for stack and heap memories), which then branches into the C startup code.

actions done by startup code:
<ol>
<li> load <strong>.data</strong> section fromm FLASH to RAM.</li>
<li> Resrve <strong>.bss</strong> section in RAM.</li>
<li> Initialize <strong>.bss</strong> with zeroes.</li>
<li> Initialize the stack pointer (SP)</li>
<li> Call main(Entry function) function. (it is not a must to call the entry function main but main is the common used name)</li>
</ol>

<h3 style="color:orange"> A cross-compiler </h3>

is a compiler where the target is different from the host. 

<h3 style="color:orange"> A toolchain </h3>

 is the set of binaries: compiler + linker + librarian + any other tools you need to produce the executable (+ shared libraries, etc) for the target. 

<img src="toolchain_definintion.jpg" alt="toolchain and cross compilation toolchain" style="width:400px;height:230px;">

it also contains binaries to debug the application of the target

it also comes with other binaries which help you to analyze the executable:
<ol>
<li> Explain diff. sections of the executable file.</li>
<li> Disassembly.</li>
<li> Extract symbols and size.</li>
<li> convert executable into another formats.</li>
<li> provide c std libraries.</li>
</ol>

<h4> Download GCC toolchain for ARM from google:</h4>
<ol>
<li> </li>
<li> </li>
</ol>

<h4> Cross toolchain important binaries:</h4>

<ol>
<li> compiler, assembler, linker: </li>
    arm-none-eabi-gcc

<li> linker:</li>
    arm-none-eabi-ld

<li> assembler: </li>
    arm-none-eabi-as

<li> Elf file Analyser: </li>
    arm-none-eabi-objdump

<li> Format converter: </li>
    arm-none-eabi-objcopy

</ol>

<h3>Build Process:</h3>

<img src="BuildProcess.png" alt="BuildProcess" style="width:600px;height:255px;">

<strong>Note:</strong> object file is relocatable (it includes processor specific machine code with no absolute address).
the true address will be assigned by the linker & linker script.

<h4> Generate object file from source file (ex: main.c)</h4>

> <p style="color:green">arm-none-eabi-gcc -c main.c -o main.o </p>

Architecture must be selected.so we add -mcpu=cortex-m4

> <p style="color:green">arm-none-eabi-gcc -c -mcpu=cortex-m4 main.c -o main.o</p>

Identify if we work with mthARM instructions or Thumb instructions

> <p style="color:green">arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb main.c -o main.o</p>

-S to generate assembly file

> <p style="color:green">arm-none-eabi-gcc -S -mcpu=cortex-m4 -mthumb main.c -o main.s</p>

Add libraries too
,final:

> <p style="color:green">arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb -std=gnu11 main.c -o main.o </p>

Instead of writing all these commands in the cmd (command window), create a makefile.

makefile:

<code>

    CC = arm-none-eabi-gcc

    MACK = cortex-m4

    CFLAGS = -c -mcpu=$(MACK) -mthumb -std=gnu11

    main.o: main.c
	    $(CC) $(CFLAGS) $^ -o $@
</code>

----

<h3> Linker and Locator</h3>

<h3>use linker to:</h3>
<ol>
<li> resolve all undefined symbols of different object files </li>
<li> merge similar sections of different object files  </li>
</ol>

<h3> use locator to</h3>
Assign the addresses ,mentioned in linker script (written by you), of the different sections.

<h6>Note:</h6> make sure that the first address is the <strong>vector table</strong>.

Analysing file:

> <p style="color:green">arm-none-eabi-objdump

-h, --[section-]headers  Display the contents of the section headers

> <p style="color:green">arm-none-eabi-objdump main.o -h </p>

to save it in file instead of showing it on the cmd window.

> <p style="color:green">arm-none-eabi-objdump main.o -h >main_log1.s</p>

-d, --disassemble        Display assembler contents of executable sections

> <p style="color:green">arm-none-eabi-objdump main.o -d >main_log2.s</p>

-D, --disassemble-all    Display assembler contents of all sections

> <p style="color:green">arm-none-eabi-objdump main.o -D >main_log3.s</p>

makefile:

<code>

    CC = arm-none-eabi-gcc

    MACK = cortex-m4

    CFLAGS = -c -mcpu=$(MACK) -mthumb -std=gnu11

    main.o: main.c
	    $(CC) $(CFLAGS) $^ -o $@
	
    GPIO_prog.o: GPIO_prog.c 
	    $(CC) $(CFLAGS) $^ -o $@
</code>



<h4 style="color:orange">Loadtime:</h4>

when loading program into memory.

<h4 >LMA (load Memory Address):</h4>

Section memory address during loadtime. i.e. .data section in flash at loadtime.  

<h4 style="color:orange">Runtime:</h4>

when processor starts running the program.

<h4>VMA (Virtual Memory Address):</h4>

Section physical memory address during Runtime. i.e. .data section has a <strong>copy</strong> in RAM at Runtime.

<strong style="color:white">.data</strong> section located in Flash in loadtime but copied to RAM in runtime.


</p>

<p> <strong style="color:white">.bss</strong> doesnit have LMA. 

you must reserve RAM space for .bss section by knowing its size and initial address in RAM ,then initialize those memory spaces with zeroes.

This is typically done by <strong style="color:blue">"Startup code"</strong>.

Linker helps you to determine the final size of the bss section, so obtain the size information from the linkerscript symbols.

-------
</p>

<p>


</p>