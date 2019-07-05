#include<iostream>
#include <cmath>
#include <fstream>
#include <math.h>
using namespace std;


//euler 

double funcion (int x,int y){
cout<< -y<<endl;
}



int main () {
    
float h = 0.001 ; 
float a=0 ;
float b=2 ; 
int  N = int((b-a)/h);


int *xN;
xN = new int[N];
int *yN;
yN = new int[N];
    xN[0]= a;
 yN[0]=1;
    for (int i=1;i < N; i ++){
        xN[i]= xN[i-1] +h;
        yN[i] = yN [i-1]+h* funcion(xN[i-1],yN[i-1]) ;
        //cout<< yN [i-1]+h* funcion(xN[i-1],yN[i-1])<<"," << xN[i-1] +h<<endl;     
        
        
        char data[100];
         ofstream outfile ("dataE.dat");
        cout<<*xN<<","<<*yN<<endl;
        outfile.close ();
   // FILE *output;      /* save data in dat.txt */
  	//output = fopen("dat.txt","w");
       // fclose(output);
    }
    return 0;
}
   

