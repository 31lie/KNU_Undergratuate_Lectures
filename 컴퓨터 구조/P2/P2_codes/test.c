#include <stdio.h>
#include <stdlib.h>

#define INST_MEM_SIZE 32 * 1024
unsigned long inst_mem[INST_MEM_SIZE];

int main() {

    FILE *fp = fopen("add_test.hex", "r");
    int i;
    long inst;

    i = 0;
    while (fscanf(fp, "%lx", &inst) == 1)
    {  
        inst_mem[i] = inst;
        printf("%lx\n",inst_mem[i]);
        i++;
    }

    return 0;
}