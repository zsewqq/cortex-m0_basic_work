#include <stdio.h>
#include <stdlib.h>
#include "armv6m.h"

int memory_init(FILE *fp)
{
    word cnt = 0;
    word memcnt = 0;

    for(cnt = 0 ; cnt < MEMSIZE ; cnt++)
    {
        mem[cnt] = 0;
    }

    while(1)
    {
        if(fread((void *)&mem[memcnt+ 1], 1, 1, fp) == 0) break;
        if(fread((void *)&mem[memcnt+ 0], 1, 1, fp) == 0) break;

        memcnt += 2;
    }

    CODESIZE = memcnt;
    return EXIT_SUCCESS;
}

/*
// Reserved for Project #2
void memory_dump(FILE *fm)
{
    word address = 0;

    for(address = 0 ; address < DUMPMEMSIZE ; address += 4)
    {
        fprintf(fm, "%02x", dmem[address+3]);
        fprintf(fm, "%02x", dmem[address+2]);
        fprintf(fm, "%02x", dmem[address+1]);
        fprintf(fm, "%02x\n", dmem[address]);
    }
}
*/

void print_instr(FILE *fm, .....)
{
}

/*
// Reserved for Project #2
int reg_init(void)
{
    int regcnt = 0;

    for(regcnt = 0 ; regcnt < 30 ; regcnt++) gpr[regcnt] = 0;

    r15 = BASEADDR;

    return EXIT_SUCCESS;
}
*/

int armv6m_init(FILE *fp)
{
    if(memory_init(fp) == EXIT_FAILURE) return EXIT_FAILURE;
//    if(reg_init() == EXIT_FAILURE) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void fetch(void)
{
    if(PC < MEMSIZE) instr = readmem16(PC);
    else fprintf(stderr, "> error: address exceeds memory boundary.\n");
    printf("  [Current instruction: 0x%08X]\n", instr);
}


void decode(void)
{
}

void execute(void)
{
//    PC = PC+ ?
}

void print_information(void)
{
    printf("  PC    = 0x%08x \n", PC);
//    printf("  PSR   = %c %c %c %c \n",
//        N ? 'N' : 'n',
//        Z ? 'Z' : 'z',
//        C ? 'C' : 'c',
//        V ? 'V' : 'v'); 
}

void armv6m_core(void)
{
    fetch();
    decode();
    execute();
    print_information();
}

void armv6m(void)
{
    while(PC < CODESIZE ......)
    {
        printf("\n  Select the program execution mode [step: s / run: r] => ");
    }
}


int main(int argc, char **argv)
{
    FILE *fp, *fm;

    printf("\n   -------------------------------------------------------------\n");
    printf("   Instruction Decoder\n");
    printf("   (ARM architecture version: ARMv6-M)\n");
    printf("   -------------------------------------------------------------\n");
    printf("   AUTHOR     :   Wooseok Byun (byunwooseok@gmail.com)\n");
    printf("   SUPERVISOR :   Ji-Hoon Kim  (jihoonkim@seoultech.ac.kr)\n");
	printf("   SUMBIT FROM :   Kyumin Kang  (zsewqq@seoultech.ac.kr)\n");
    printf("   VERSION    :   1.0\n");
    printf("   Copyright (c) 2016 Computer System Architecture Lab., SeoulTech\n");
    printf("   -------------------------------------------------------------\n\n");

    if(argc != 3)
    {
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "rb");
    if(fp == NULL)
    {
        fprintf(stderr, "> error: can not open file '%s'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    fm = fopen(argv[2], "wb");
    if(fm == NULL)
    {
        fprintf(stderr, "> error: empty dump file! can not create file '%s'.\n", argv[2]);
        return EXIT_FAILURE;
    }

    armv6m();

//    memory_dump(fm);
    fclose(fp);
    fclose(fm);
    printf("> info: End of the program. Check dumpfile. :D\n");

    return EXIT_SUCCESS;
}
