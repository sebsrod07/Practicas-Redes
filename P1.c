#include <stdio.h>
void Calculadora(unsigned char ip[]);
int main()
{
    unsigned char ip[]={219,17,9,1};
        Calculadora(ip);

        }
void Calculadora(unsigned char ip[])
{
    unsigned char MR[]={255,0,0,0};
        if(ip[0]&128)
            {
                if(ip[0]&64)
                {
                    if(ip[0]&32)
                    {
                        if(ip[0]&16)
                            printf("Es de clase E\n");
                        else
                            printf("Es de clase D\n");
                    }
                    else
                    {
                        MR[1]=MR[2]=255;
                        printf("Es de clase C\n");
                    }
                }
                else                                                                                                                                                                                                                      
                {
                    MR[1]=255;                                                                                                                                                                                      
                    printf("Es de clase B");                                                                                                                                                                               
                }
            }
            else                                                                                                                                                                                                                                                                               
                printf("Es de clase A\n");
  }
