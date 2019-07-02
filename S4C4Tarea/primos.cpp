
#include<iostream>
#include <cmath>
using namespace std;

void funcion( int a, int b) ; // valores que le entran a la funcion 
int main ()  // se corre en el main
{
  funcion(1,10);
  return 0;
}
void funcion (int EnteroI, int EnteroF) // le entran dos enteros 
{ 
   for ( int i = EnteroI+1 ; i< EnteroF; i ++ ) // El recorrido empieza en el valor delante del primer entero intervalo
   {
  int cont = 0;

    for(int j = 2; j<i ; j++) //va desde 2 hasta i cuando es mayor que 2 
    {
     int  valor = i % j ;
      if(  valor ==0) // si no hay residuo de la division  
      {
        cont += 1;
      }
    }
    if(cont==0){  // si no encuentra ningujn primo 
      cout<<i <<endl;
    }
  }
}







