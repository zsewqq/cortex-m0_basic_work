void memory_dump(FILE *fm, word ADDR_L, word ADDR_H)
{       
    word address = 0;

    if((ADDR_L < DUMPMEMSIZE) && (ADDR_H < DUMPMEMSIZE))
    {
        for(address = (ADDR_L-(ADDR_L % 4)) ; address < ADDR_H ; address += 4) 
        { 
            fprintf(fm, "%02x : ", address+ BASEADDR);
            fprintf(fm, "%02x", mem[address]);
            fprintf(fm, "_%02x", mem[address+1]);
            fprintf(fm, "_%02x", mem[address+2]);
            fprintf(fm, "_%02x\n", mem[address+3]);
        }
        printf("> Memory dumping was completed!\n");
    }
    else printf("> error: Dump area exceeds the limit.\n");
}
