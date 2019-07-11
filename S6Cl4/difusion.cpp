#include <iostream>
#include <fstream>
#include <math.h>
#define PI 3.1416
using namespace std;

//DATOS INICIALES

double L = 1;  
double L2 = 1; // 1m^2
double v = 0.0004 ; //coeficiente de difusion 
double TL= 50; // temperatura de toda la placa
double dx = 0.01; // paso en x
double dy= 0.01 // paso en y


//double l2 = ;
double Tl=100; // temperatura en esa seccion de l placa
double ti=0;
double tm = 100;
double tf= 2500;
double tmean;
// cuadrado pequeño    

double l= 0.2; //lado de 20cm

int main (){
// DEFINO ARREGLO... foward
    int Nx= 100;
    int Ny= 100;

  double Tpre[Nx][Ny];
  double Tpast[Nx][Ny];
 
// condiciones iniciales 
    for ( int i =0; i<= Nx; i++){ // defino x
        for (int k =0; k <=Ny; k++){ // defino y 
            if (i <=0.2 || i>= 0.40 || k<=40 || k<=60){
                Tpre[Nx][Ny] = 100;
             else {
                  Tpre[Nx][Ny]=50;
              cout<< Tpre[Nx][Ny] <<endl
                    }
            
            }
        }
    }
   
    
 return 0 ;
}
