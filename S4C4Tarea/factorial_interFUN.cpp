#include<iostream>
#include <cmath>
using namespace std;
//  Tome su programa que calcula el factorial de un numero n (y que recibe n interactivamente). Reescribalo usando funciones. La seccion de codigo que calcula el factorial debe ser una funcion independiente que es llamada desde la funcion main. llamelo factorial_interFUN.cpp
void funcion ( int a) 
{
    int  valor =1;
    for ( int i = 1;i<=a; i ++)
        valor*=i;
    cout<<"El facotorial de  "<< a <<" es "<<valor<<endl;
        
}

int main()
{
    int a ; 
    int valor;
    cout << "Introduzca un numero: ";
    cin >> a;
    funcion (a); // se llama desde la funcion main 
    return  0; 
    
    
}


