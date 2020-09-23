#include <iostream>
using namespace std;

void burbuja(double a[],int n)
{
    int i,j;
    double aux;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
        }
    }
}
