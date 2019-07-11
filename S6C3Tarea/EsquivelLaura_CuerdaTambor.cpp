#include <iostream>
#include <fstream>
#include <math.h>
#define PI 3.1416
using namespace std;

//DATOS INICIALES


double A  =  0.01 ;
double L  =  1 ;

double dx  =  0.005 ;// numero de puntos es equivalente a la longitud de la cuerda sobre el paso
int N =  L/ dx; 

int pmax = N/2 ;// punto de maxima amplitud de lCa cuerda
double c =  300 ;
double ci = 0;

double tfinal= 0.1; 
double dt = tfinal/N;
double sigma = 0.1;

int main(){
//se realizan arreglos :pasados presentes y futuros  para cada condicion
    
//CASO1...fijos
    
    double past[N];
    double pre[N];
    double fut[N];
//CASO2...uno libre
    
    double past2[N];
    double pre2[N];
    double fut2[N];
    
// CASO3... uno libre con funcion
    double past3[N];
    double pre3[N];
    double fut3[N];
// CASO4... tambor
    double past4[N];
    double pre4[N];
    double fut4[N];


ofstream outfile ("cuerdaonda.dat"); // aqui se van a  imprimir los datos 

    
 // PASADO

    
// se definen las condiciones inciales 
    for (int i=0 ;  i <=pmax  ;  i ++){
        past[i]= A* (double(i)/double(N-1));
        past2[i]= A* (i/pmax);
        past3[i]= 0;
        past4[i]=0;
    }

    for (int i =pmax; i<N; i ++){
        past[i]=  A* (1-double(i)/double(N-1));
        past2[i]= A* ((A/pmax)*(i-pmax));
        past3[i]= A* ((A/pmax)*(i-pmax));
        past4[i]= A* ((A/pmax)* (i-pmax));
    }
    
// PRESENTE // extremos de la cuerda
    
    for (int i = 0; i < N; i++){
        if(i==0){ // al inicio de la cuerda
        
            pre[i] = 0 ;
            pre2[i] = 0;
            pre3[i] = 0;
            pre4[i] = 0;
        }

        else if (i==N-1){// final de la cuerda con extremo libre
            pre[i]= 0 ;
            pre2[i] = pre2[i-1];
            pre3[i]= A *sin((3.0*c*dt*PI)/L);
            //pre4[i] = ;
        }

        else{
            pre[i]= past[i] + (1)/2.0 * ( past[i+1] + past[i-1] - 2.0*past[i] );
            pre2[i]= past2[i] + (1)/2.0 * ( past2[i+1] + past2[i-1] - 2.0*past2[i] );
            pre3[i]= past3[i] + (1)/2.0 * ( past3[i+1] + past3[i-1] - 2.0*past3[i] );
           }
    }

// FUTURO
    for (int i=0 ; i<1000 ; i ++){
    for (int i=0 ; i<N ; i ++){
        if(i==0){
            fut[i]= 0 ;
            fut2[i]= 0 ;
            fut3[i]= 0 ;
        }
        else if( i== (N-1) ){
            fut[i]= 0;
            fut2[i]= fut2[99-1];  // condicion libre
            fut3[i]= A * sin((3.0*c*dt*PI)/L); // extremo libre con funcion
        }
        else{
            fut[i]= pre [i] + (1)/2.0 * ( pre[i+1] + pre[i-1] - 2.0*pre[i] );
            fut2[i]= pre2[i] + (1)/2.0 * ( pre2[i+1] + pre2[i-1] - 2.0*pre2[i] );
            fut3[i]= pre3[i] + (1)/2.0 * ( pre3[i+1] + pre3[i-1] - 2.0*pre3[i] );
        }
    }
        
// ACTUALIZA TIEMPPOS
        
    for (int i = 0; i <= N; i++)
    {
        past[i] = pre[i];  // pasado y futuro se guardan en presente
        pre[i] = fut[i];

        past2[i] = pre2[i];
        pre2[i] = fut2[i];
        
        past3[i] = pre3[i];
        pre3[i] = fut3[i];
    }
}

for (int i = 0; i < N; i++) // array de N puntos para la posicion
{
    outfile << i*dx << "," << pre[i] << "," << pre2[i] << "," << pre3[i] <<","<<pre4[i] <<endl;
}

outfile.close ();

return 0;
}








