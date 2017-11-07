#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int dado();
void llenarvector(int vec[]);
void tirar(int vec[], int &jugador1, int &jugador2);


int main()
{
    int jugador1=0;
    int jugador2=0;
    
    int vec[101]={0};
   
    srand(time(NULL));


    llenarvector(vec);
    do{
        tirar(vec, jugador1, jugador2);
        cout<<endl<<"jugador 1-"<<jugador1;
        cout<<endl<<"jugador 2-"<<jugador2<<endl;
        
    }while(jugador1<100 && jugador2<100);

   
    if (jugador1>jugador2)
        cout<<endl<<"El jugador 1 es el ganador con "<<jugador1;
    else if (jugador1<jugador2)
        cout<<endl<<"El jugador 2 es el ganador con "<<jugador2;
    else
        cout<<"Empate";

return 0;
}

int dado()
{
    int cara;
    cara=rand()%6+1;

return cara;
}

void llenarvector(int vec[])
{
    for(int i=1;i<=100; i++)
        vec[i]=i;
     
    vec[2]=19;
    vec[4]=18;
    vec[9]=45;
    vec[18]=25;
    vec[25]=50;
    vec[36]=48;
    vec[47]=54;
    vec[59]=64;
    vec[80]=85;
    vec[92]=98;
    vec[11]=5;
    vec[17]=10;
    vec[23]=15;
    vec[39]=36;
    vec[42]=38;
    vec[53]=48;
    vec[67]=62;
    vec[74]=72;
    vec[83]=79;
    vec[99]=90;    
    
       
    
}

void tirar(int vec[],int &jugador1, int &jugador2)
{
     jugador1=vec[jugador1+=dado()];
    jugador2=vec[jugador2+=dado()];
    
    if(jugador1<0)
        jugador1=0;
    if(jugador2<0)
        jugador2=0;
    if(jugador1>100)
        jugador1=100;
    if(jugador2>100)
        jugador2=100;
        
   
}
