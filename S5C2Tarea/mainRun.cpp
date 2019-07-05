//Runge Kutta method to solve ODEs de 4to orden
#include<stdio.h>
#include <iostream>
#include <math.h>
#include <fstream>
#define PI 3.14159265

using namespace std;
float h = 0.001 ; 
float a=0 ;
float b=2 ; 



float funcion(float x, float y ){

    return(-y);
}

int main()
{
    int N= int((b-a)/h);
    //int xN[N];
    //int yN[N];
    int *xN;
    xN = new int[N];
    int *yN;
    yN = new int[N];
    float k1, k2;
  
    for (int i=1; i<=N; i++)
    {
        xN[0]= a; // empiece en 1 y en 0 
        yN[0]=1.0;
        k1 = h*(funcion(xN[i-1], yN[i-1]));
        k2 = h*(funcion(xN[i-1]+ 0.5*h, yN[i-1]+ 0.5*k1));
        xN[i] = xN[i-1] +h;
        yN[i] =yN[i-1]+k2;
        cout<< *xN<<","<< *yN<< endl;
             /* save data in dat.txt */
  
    }
     char data[100];
         ofstream outfile ("dataR.dat");
        cout<<*xN<<","<<*yN<<endl;
        outfile.close ();
  
   return 0;

}