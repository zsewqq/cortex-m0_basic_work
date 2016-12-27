#include <stdio.h>

#ifndef ARMv6M_DATATYPE_DEFINE
#define ARMv6M_DATATYPE_DEFINE

typedef unsigned char       byte;       // byte type - 8-bit
typedef unsigned short      halfword;   // half word type - 16-bit
typedef unsigned int        word;       // word type - 32-bit

typedef union{
    byte        byt[4];
    halfword    h[2];
    word        w;
} WORD;

typedef union{
    word w;
    struct {
        word n: 1;
        word z: 1;
        word c: 1;
        word v: 1;
        word  : 28;
    } b;
} APSR_TYPE;

#endif

#ifndef ARMv6M_GLOBAL_DECLARE
#define ARMv6M_GLOBAL_DECLARE

word gpr[16];

#define PC      gpr[15]

//APSR_TYPE    apsr;

//#define APSR        apsr
//#define N           apsr.b.n
//#define Z           apsr.b.z
//#define C           apsr.b.c
//#define V           apsr.b.v

// -------------------------------------------------------------------------- //
//      Function prototype
// -------------------------------------------------------------------------- //

void armv6m(void);

void decode(void);

extern word CODESIZE;

word instr;

#endif

#ifndef ARMv6M_MEM_DEFINE
#define ARMv6M_MEM_DEFINE

// -------------------------------------------------------------------------- //
//      Main memory
// -------------------------------------------------------------------------- //

#define MEMSIZE    0x20000
byte mem[MEMSIZE];

#define BASEADDR    0x0
#define DUMPMEMSIZE 0x2000

// -------------------------------------------------------------------------- //
//      Memory interface
// -------------------------------------------------------------------------- //

#define readmem32(addr)     ((mem[((addr)- ((addr)%4))- BASEADDR+ 3] << 24) | \
                             (mem[((addr)- ((addr)%4))- BASEADDR+ 2] << 16) | \
                             (mem[((addr)- ((addr)%4))- BASEADDR+ 1] <<  8) | \
                             (mem[((addr)- ((addr)%4))- BASEADDR]))
#endif

#ifndef ARMv6M_MACRO_DEFINE
#define ARMv6M_MACRO_DEFINE

#define OPCODE1             (((instr)>>10)&0x3f)    // 6-bit opcode for 16-bit Thumb instruction encoding
#define OPCODE2             (((instr)>>9)&0x1f)     // 5-bit opcode for Shift(immediate, add, subtract, move, and compare


#endif


