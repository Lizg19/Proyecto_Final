#include <iostream>
//using namespace std;

void Fusionar(double a[],int pinicial, int pfinal, int medio);

void dividir(double a[], int inicial, int final)
{
    int mitad;
    if (inicial < final)
	{
		mitad=(inicial+final)/2;

		dividir(a,inicial,mitad);
		dividir(a,mitad+1,final);
		Fusionar(a,inicial,final,mitad);
	}
}

void Fusionar(double a[],int pinicial, int pfinal, int medio)
{

	int i, j, k; double temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;

	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}

}

