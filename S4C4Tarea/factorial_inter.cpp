// tercer punto
#include <iostream>
using namespace std;
int n= 5;// Entren el valor que quieren 
int main ()
{
    int num = n ; // cuando es 77 el factorial es 0, despues de 50 no da 
    int factor= 1;
     for(int i=1;i<=num;i++)
        factor = factor* i;
    cout<<"el factor es :"<< factor<< endl;
    return 0;
}
