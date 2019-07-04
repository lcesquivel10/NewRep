#include<iostream>
#include <cmath>
using namespace std;

int arr1[]={1,2,3,4,5};
int arr2[]={10,20,30,40,50};
 
void producto (int A1[5], int A2[5] ){
   int resultado[5]; // arreglo vacio de 5 elementos donde guarda el resultado
    for (int i = 0; i< 5; i ++){
        resultado[i] =  A1[i]*A2[i];   
     
        
        cout<<"El producto es :"<< resultado[i]<<endl;
    }

}

void productopoint (int A1[5], int A2[5]){
    int contador=0; // contador  donde guarda el resultado de la sumatoria, apuntador ??
    for (int i = 0; i< 5; i ++){
        contador +=  A1[i]*A2[i]; // esto multiplica los dos arreglos .. y los suma a un solo arreglo que es contador 
    }
    cout<<"el producto punto es :"<< contador <<endl;
}    
    
int main(){
    producto (arr1, arr2);
    productopoint(arr1,arr2);
     return 0;
    
}