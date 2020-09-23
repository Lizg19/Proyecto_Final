#include <iostream>
using namespace std;
  void algoritmoSeleccion(double a[], int n)
  {

      int i,j;
      double aux;int min;
      for (i=0 ; i<n; i++)
      {
        min=i;

          for (j=i+1;j<n;j++)
          {
              if(a[j]<a[min])
              {
                  min =j;
              }

          }
          aux=a[i];
          a[i]=a[min];
          a[min]=aux;
      }

  }



