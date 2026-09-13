#include <stdio.h>
#include <stdbool.h>
void Calculadora(unsigned char ip[]);
void imprimeTipo(unsigned char ip[], unsigned char MR[]);
void datosRed(unsigned char ip[] ,unsigned char MR[]);
int main()
{
    unsigned char ip[]={192,34,7,255}; // 000 0000
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
                imprimeTipo(ip,MR);
                datosRed(ip,MR);
            }
        }
        else                                                                                                                                                                                                                      
        {
            MR[1]=255;                                                                                                                                                                                      
            printf("Es de clase B\n");
            imprimeTipo(ip,MR);
            datosRed(ip,MR);                                                                                                                                                                             
        }
    }
    else
    {
        printf("Es de clase A\n");
        imprimeTipo(ip,MR);
        datosRed(ip,MR);
    }                                                                                                                                                                                                                                                                              
       

  }
  void imprimeTipo(unsigned char ip[], unsigned char MR[])
  {
    printf("%d.%d.%d.%d\n", ip[0],ip[1],ip[2],ip[3]); 
    //Supongamos que es broadcast con flag=true;
    //la msacara de red ya viene SEGUN la clase, por lo que solo verificamos el primer bit para comprobar la clase
    //ejemplo MR={255,255,255,0} 1111 1111 0000 0000 1111 1111 
    bool flag=true;
    if(ip[3]&1)
    {
        //Buscar por difusion
        for(char i=0;i<8;i++)
        {
            if(!(ip[3]>>i&1))
            {
                flag=false; // es de host
                break;
            }
            if(!(MR[2]&1))
            {
                if(!(ip[2]>>i&1))
                {
                    flag=false;
                    break;
                }
                if(!(MR[1]&1))
                {
                    if(!ip[1]>>i&1)
                    {
                        flag=false;
                        break;
                    }
                    
                }
                
            }
            
        }
        if(flag)
            printf("Es de Difusion\n");
        else
            printf("Es de Host\n");
        
    }
    else 
    {
        // buscar por red
        for(char i=0;i<8;i++)
        {
            if((ip[3]>>i&1)) //0000 0000 0000 0000 0000 0000 0000 0000
            {
                flag=false;
                break;
            }
            if(!(MR[2]&1))
            {
                if((ip[2]>>i&1))
                {
                    flag=false;
                    break;
                }
                if(!(MR[1]&1))
                {
                    if(ip[1]>>i&1)
                    {
                        flag=false;
                        break;
                    }
                    
                }
                
            }
            
        }
        if(flag)
            printf("Es de Red\n");
        else
            printf("Es de Host\n");
    }
  }
  void datosRed(unsigned char ip[] ,unsigned char MR[]){
			unsigned char red[4], i;
			for(i=0;i<4;i++){
				red[i]=ip[i]&MR[i];
			}
			printf("La direccion de red es: %d.%d.%d.%d\n",red[0],red[1],red[2],red[3]);
			for(i=0;i<4;i++){
				ip[i]=ip[i]|(~MR[i]);
			}
			printf("La direccion de Difusion es: %d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
			
			printf("Rango inicial: %d.%d.%d.%d\n",red[0],red[1],red[2],red[3]+1);
			printf("Rango inicial: %d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]-1);
	}
