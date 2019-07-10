#include <iostream>
#include <fstream>
#include <math.h>
#define PI 3.1416


using namespace std;

// datos iniciales

double  A  = 0.01;
double L = 1 ; // longitud de la cuerda .. 1 metro
double dx = 0.005 ; 
int N = L / dx ; // numero de puntos es equivalente a la longitud de la cuerda sobre el paso
double tfin = 0.1 ; 
double c = 300; //velocidad
double ci = 0; // velocidad inicial
double pmax = 50; // punto maximo en en que se mueve la onda en la cuerda
int inicio = 0 ;  // inicio de la cuerda
int fin = 99; // final de la cuerda..... para las condiciones de frontera ( cuando esta uno fijo )

int main () {
    

    // como son 3 condiciones se hacen arreglos para que se vayan actualizando 
    // CASO 1 :  extremos de la cuerda fijos 
double past[N];
double pre[N];
double fut[N];
   // CASO 2 :  extremo  fijo y extremo libre
double past2[N];
double pre2[N];
double fut2[N];
    // CASO 3 : amplitud cambia de acuerdo a una funcion A = cos...
double past3[N];
double pre3[N];
double fut3[N];
    // donde se guardaran los datos 
ofstream outfile ("ondacuerda.dat");
  
    // inicializar cada casao en el pasado.. no se tiene 
 
for (int i=0; i<pmax; i++){
    past [i] = A * (double(i) / double(N-1));
    past2[i] = A * ( i/pmax );
    past3[i] = 0;
}
   
for (int i=pmax; i<N; i++){
    past [i] = A * ( 1 - double(i) / double(N-1));
    past2[i] = A * (( A/pmax )*(i- pmax) );
    past3[i] = A * (( A/pmax )*(i- pmax) );
}
    
    // pra presente .... depende de cada casooo
    
double dt = tfin/ N; 
    
for (int i=0; i<N; i++){
   if  ( i == inicio ){ // si la posicion en 0 tosdos los casos se inicializan
       pre [i]= 0;
       pre2 [i]= 0;
       pre3 [i]= 0;
   }
  
  else if ( i ==fin ){
       pre [i]= 0;
       pre2 [i]= pre2[i-1];
       pre3 [i]= A* cos((3*c*dt*PI)/L);
  }
  else {
      pre[i]= past[i]+0.5*(past[i+1]+past[i-1]-2*past[i]);
      pre2[i]= past2[i]+0.5*(past2[i+1]+past2[i-1]-2*past2[i]);
      pre3[i]= past3[i]+0.5*(past3[i+1]+past3[i-1]-2*past3[i]);
  }
}
    
// para el futuro 
    
for (int i=0; i<1000;i++){
    for (int i=0; i<N; i++){
        if ( i == inicio){
            fut[i] = 0;
             fut2[i] = 0;
             fut3[i] = 0;
        }
        else if ( i == fin){
            fut[i] =0;
             fut2[i] =fut2[fin-1];
            fut3[i]= A*cos((3*c*dt*PI)/L);
        }
        else {
          fut[i]=pre[i]+0.5* (pre[i+1]+ pre[i-1]-2* pre[i]);
         fut2[i]=pre2[i]+0.5*(pre2[i+1]+pre2[i-1]-2*pre2[i]);
         fut3[i]=pre3[i]+0.5*(pre3[i+1]+pre3[i-1]-2*pre3[i]);
            }
        }
 // 
    for (int i=0; i<N; i++){
        past[i]= pre[i];
        pre[i]=fut[i];
        
        past2[i]= pre2[i];
        pre2[i]=fut2[i];
        
        past3[i]= pre3[i];
        pre3[i]=fut3[i];
        }
     
    // para imprimir los paso ( posdiciones ) 
for ( int i=0; i<N; i++){
    outfile<< i *dx << ","<< pre[i]<< ","<< pre2[i]<< ","<< pre3[i]<<endl;
        }
outfile.close ();
return 0; 
    }

}