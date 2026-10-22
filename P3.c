#include <stdio.h>

int main() {
    printf("HOLA");
    return 0;

}
void tramaLLC(unsigned char *t, char** UR, char** UC)
{
    switch(t[16]&3)
    {
        case 1:
            printf("Trama de Supervision; N(s): %d, N(r): %d\n", t[16] >> 1, t[17] >> 1);
            break;
        case 3:
            if(t[16]&1)
                if(t[15&1])
                    printf("Trama Unsigned; %s -f", UR[   ((t[16]>>2)&3 )| ((t[16]>>3)&28)    ]   );
                else
                    printf("Trama Unsigned; %s -f", UC[   ((t[16]>>2)&3 )| ((t[16]>>3)&28)    ]   );
                
            break;
        case 0x42:
            printf("Trama LLC: STP\n");
            break;
        default:
            printf("Trama LLC: Desconocida\n");
    }
}