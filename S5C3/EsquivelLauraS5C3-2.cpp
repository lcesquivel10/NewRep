#include <fstream>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

// defincion de variables iniciales 
float m = 2; // masa del resrte
float k = 300;// constante del resorte

// condiciones en tiempo 0
float t_ini = 0 ;
float vel_ini =0;
float x_ini = 0.1; 
float vel_final;
float x_final; 


double funcionVel(float x, float t){ // m (d2x(t)/dt2)+kx(t) =0
    
    
    return    
}1

double funcionAce(float v, float t){
    
    return
}


float rungeK(float x0, float y0, float x, float h)
{
    // Cuenta el numero de iteraciones haciendo tamaño del paso o altura del paso
    int n = (int)((x - x0)/h);
    float k1; 
    float k2; 
    float k3;
    float k4;
    
for (int i=1; i<=n; i++) // para las vel
    {
        k1 = h*(funcion(x0, y));
        k2 = h*(funcion(x0 + 0.5*h, y + 0.5*k1));
        k3 = h*(funcion(x0 + 0.5*h, y + 0.5*k2));
        k4 = h*(funcion(x0 + h, y + k3));        
    }

 for (int j=1; j<=n; j++) // para las acelera
    {
        k1 = h*(funcion(x0, y));
        k2 = h*(funcion(x0 + 0.5*h, y + 0.5*k1));
        k3 = h*(funcion(x0 + 0.5*h, y + 0.5*k2));
        k4 = h*(funcion(x0 + h, y + k3));        
    }
    return y;
}

// debo hacer un recorrido para el tiempo
// como resultado dan dos valores a partir de las pendientes 
// empezar por euler 
// seguir con leapfrog 


  

