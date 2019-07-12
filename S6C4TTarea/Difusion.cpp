#include <iostream>
#include <fstream>
#include <math.h>
#define PI 3.1416
using namespace std;

int main (){
    // Datos inciales

    int L=100; // 1m... 100cm
    double v = pow (10,-4);
    int Tplaca = 100;
    int Tplaquita=50;
    int dx =1;
    int dy =1;
    int tiempo_1=0;
    int tiempo_2=100;
    int tiempo_3= 2500;
    float dt = 0.0001
    double paso_2 = tiempo_2/dt;
    double paso_3 = tiempo_3/dt;
   int N = 101;
   int nx = 101;
   int ny = 101;
    double presente[nx][ny];
    double futuro[nx][ny];
    
    // para guardar los datos 
    ofstream outfile;
        outfile.open("data.dat");
 // i= x j=t k =y
    
    
 // condiciones iniciales 
    
    
    for (int i=0 ; i<101 ; i++) // x
    {
        for (int k=0; k<101 ; i++)//y
        {
         if (i>20 || i<40 || k>40 || k <60)
             {
             presente[i][k] = Tplaca;
             }
         else 
             {
             presente[i][k]=Tplaquita;
             }
         outfile<< i << ","<< k <<","<< presente[i][k] << endl;
        }
    }
    
   outfile.close(); 
    
// variar tiempo
// para tiempo 2
    
   outfile.open("data1.dat");
    
    for ( int j = 0; j< tiempo_2/dt ; j++) //timpo
    {
         for (int i= 0; i < 101 ; i++)// x
         {
              for (int k= 0; k< 101 ;k++) // y 
              {
                   presente[i][k]= dt*(v*(((presente[i+1][k]+presente[i-1][k]-2*presente[i][k])/pow(dx,2))+(v*((presente[i][k+1]+presente[i][k-1]-2*presente[i][k])/pow(dy,2)))))+ presente[i][k];
                  
                  // meter el futuro
                  // boundaries
               outfile<<i <<","<<k<<","<<presente[i][k]<<endl;
              }
         }
    }
    outfile.close()
    // para tiempo 3
    outfile.open("data2.dat");
    
    for ( int j = 0; j< tiempo_3/dt ; j++) //tiempo
    {
         for (int i= 0; i < 101 ; i++)// x
         {
              for (int k= 0; k< 101 ;k++) // y 
              {
                   presente[i][k]= dt*(v*(((presente[i+1][k]+presente[i-1][k]-2*presente[i][k])/pow(dx,2))+(v*((presente[i][k+1]+presente[i][k-1]-2*presente[i][k])/pow(dy,2))))+ presente[i][k];
               outfile<<i <<","<<k<<","<<presente[i][k]<<endl;
              }
         }
    }      
       
outfile.close();      
return 0; 
}