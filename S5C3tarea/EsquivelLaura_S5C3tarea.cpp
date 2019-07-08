#include<iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Calcule la posici ́on de la masa en funci ́on del tiempo hasta un tiempo final de t = 5s e imprima en consola el tiempo t, la velocidad y la posici ́on de la masa..

// constantes iniciales 
int m= 2 ; // masa
int k = 300; // constante de elasticidad

double t_ini = 0 ;
double vel_ini =0;
double x_ini = 0.1;// posicion en 0 y tiempo 0
double x_eq =0; // posicion de equilibrio


double vel_fin; // restorna
double x_fin; // retorna
double t_fin= 5 ; // tiempo final

double dx = 0.01 ; // h 
int N = int ((x_ini-x_eq)/dx);// numero de puntos 
double dt = int (t_fin/N);
double x_pri; // x prima.. vel dx/dt 
double v_pri;// y prima... aceleracion dv/dt

//double func1 (int dx, int dt ){
//int v_pri = dx/ dt ;
//    return v_pri;
//}

//double func2 (int dvx, int dt, int k, int m , int x){
//    int v_pri = (-k/m)*x; //  aceleracion

//}

int main (){
    
    // arreglos
    double tiem[N]; // 5 segundos 
    
    
    double xpast[N];
    //double xpres[N];
    double yfutu[N];
    
    
    double vpast[N];
    //double vpres[N];
    double vfutu[N];
    
    double apast[N];
    //double vpres[N];
    double afutu[N];
    
    for ( int i =0 ; i <N; i++){
    
        
    }
    
    
   
    // inicializa el archivo donde se guardan los datos
    ofstream outfile ("resorte.dat");
    
    
    
    // pasado 
    for (int i = 1; i< N;i++){
        xpast[i] = xpast[i-1]+dx;
        xfutu[i]= xfutu [i-1]+2*dx*xfutu[i];
        }
    
     // posciones 
    for (int i = 1; i< N;i++){
        vpast[i]= vpast[i-1]+dx;
        vfutu[i] = vfutu[i-1]+2*dx*-(k/m)*vfutu[i-1];//funcion* 
    }
  
    
  for (int i = 0; i<N ; i++){
  outfile<<tiem<<","<< xfutu<< "," << vfutu<< endl ;
  }
    
  cout <<endl << " la posicion y velocidad en 5 segundos es: ";
  outfile.close();
  return 0; 
}



