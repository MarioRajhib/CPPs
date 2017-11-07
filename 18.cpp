#include <iostream>
using namespace std;
int menu();
void mostrar (char m[][20]);
void acciontotal(char m[][20], int avanzar, int pintar, int girar, int &controlcolumnas, int &controlrenglones);

int main()
{
    int op, vendedor, producto;
    int girar=0, avanzar=0, pintar, controlg=0, controlcolumnas=0, controlrenglones=0;
    char m[20][20]={{'.'}};
    
    for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
            m[i][j]='_';
    do
    {
        op=menu();
        switch(op)
        {
        case 1:
            pintar=1;
        break;
        case 2:
            pintar=2;
        break;
        case 3:
            girar++;
            if(girar==4)
                girar=0;
        break;
        case 4:
            girar--;
            if(girar==-1)
                girar=3;
        break;
        case 5:
            cout<<"cuanto desea avanzar->";
            cin>>avanzar;
            acciontotal(m, avanzar, pintar, girar, controlcolumnas, controlrenglones);
        break;
        case 6:
            mostrar(m);
        break;


        }
    }while(op!=0);
    cout<<"adios...";

}

int menu()
{
	int op;
	do
	{
 	  	cout<<"MENU\n";
  	  	cout<<"1-Pluma hacia arriba\n";
  	  	cout<<"2-pluma hacia abajo\n";
  	  	cout<<"3-Gira hacia la derecha\n";
  	  	cout<<"4-Gira hacia la izquierda\n";
  	  	cout<<"5-Avanzar\n";
  	  	cout<<"6-Mostrar\n";
   		cout<<"7-Centinela\n";
   		cin>>op;
	}while(op>=1 && op>8);
 	return op;
}


void mostrar (char m[][20])
{
   for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            cout<<m[i][j];
        }
        cout<<endl;
    }
}

void acciontotal(char m[][20], int avanzar, int pintar, int girar, int &controlcolumnas, int &controlrenglones)
{
    if(pintar==2)
    {
        switch(girar)
        {
            case 0:
                for(int i=controlrenglones;i<=controlrenglones+avanzar-1;i++)
                {
                    m[i][controlcolumnas]='*';
                }
                controlrenglones=controlrenglones+avanzar-1;
            break;
            case 1:
                 for(int i=controlcolumnas;i<=controlcolumnas+avanzar-1;i++)
                {
                    m[controlrenglones][i]='*';
                }
                controlcolumnas=controlcolumnas+avanzar-1;               
            break;
            case 2:
                for(int i=controlrenglones;i>=controlrenglones-avanzar+1;i--)
                {
                    m[i][controlcolumnas]='*';
                }
                controlrenglones=controlrenglones-avanzar+1;
            break;
            case 3:
               
                for(int i=controlcolumnas;i>=controlcolumnas-avanzar+1;i--)
                {
                    m[controlrenglones][i]='*';
                }
                controlcolumnas=controlcolumnas-avanzar+1;   
            break;

        }       

    }
    else
    {
       switch(girar)
        {
            case 0:
                controlrenglones=controlrenglones+avanzar-1;
            break;
            case 1:
                controlcolumnas=controlcolumnas+avanzar-1;                  
            break;
            case 2:
                controlrenglones=controlrenglones-avanzar+1;
            break;
            case 3:
               controlcolumnas=controlcolumnas-avanzar+1; 
            break;

        }
    }
}










