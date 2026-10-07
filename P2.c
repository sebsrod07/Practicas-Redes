#include <stdio.h>
void checksumValidacion(unsigned char *t)
{
    int resultado=0x00;
    printf("SIZEOF: %d\n", sizeof(t));
    for(int i=0 ;i< sizeof(t);i+=2)
    {
        printf("0x %.2x", t[i]);
        printf(" %.2x - - - i:%d\n", t[i+1],i);
        resultado+=(t[i]<<8 | t[i+1]);
    }
    printf("Resultado: %.6x\n", resultado);
    printf("Resultado corrido: %.6x\n",  ((resultado & 0xF0000)));
    resultado=~(resultado + ((resultado & 0xF0000)>>16)) & 0xFFFF;
    printf("Resultado: %.6x\n", resultado);
    printf(" - - - - COMPROBACION - - - - \n");

}
int main()
{
    unsigned char t[]= {
        0x00,0x1f, 
        0x45, 0x9d, 
        0x1e, 0xa2, 
        0x00, 0x23, 
        0x8b, 0x46, 
        0xe9, 0xad, 
        0x08, 0x00, 
        0x45, 0x10,  
        0x00, 0x3c, 
        0x04, 0x57, 
        0x00, 0x00, 
        0x64, 0x01, 
        0x98, 0x25, 
        0x94, 0xcc
    };
    printf("SIZEOF: %d\n", sizeof(t));
    checksumValidacion(&t[0]);

}
