#include <iostream>
//using namespace std;
  void insercion(double a[], int n)
  {
    double aux;

    for (int i=0; i<n; i++)
    {

        aux=a[i];

        int p=i;

       while (p>0)
        {
            if(a[p-1]>aux)
            {
                a[p]=a[p-1];
                a[p-1]=aux;
            }
            p--;
        }
    }
  }

