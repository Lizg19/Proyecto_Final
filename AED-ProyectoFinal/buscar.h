#include <iostream>
#include <fstream>
#include "colores.h"

using namespace std;
const int M = 40;
typedef struct{
    string nombre, apellido;
    double nota;
}tEstud;

typedef struct{
    tEstud estudiantes [M];
    int contador;
}tList;

typedef struct {
  string prof;
  string ident;
}tDocente;

void cargarEstudiante(tList &lista, bool &ok) {
   ok = true;
   ifstream ordenamiento;
   lista.contador = 0;
   ordenamiento.open("ordenamiento.txt",ios::app);

   tEstud estudiante;
   if (!ordenamiento.is_open()) {
      ok = false;
   }
   else {
      tEstud reg;
      ordenamiento>> reg.nombre;
      while ((lista.contador < M) && (reg.nombre != "-1")){
            ordenamiento >> reg.apellido>> reg.nota;
            lista.estudiantes[lista.contador] = reg;
            lista.contador++;
            ordenamiento >> reg.nombre;
      }
      ordenamiento.close();
   }
}

int busquedaLineal(tList &lista, int tam, double valor ){   // la funcionretorna un valor

    for (int i=0; i<tam; i++){
        if(lista.estudiantes[i].nota == valor){   // elemento del arreglo es igual al dato ingresado
            return i;  // en caso de que el elemento exista
        }
    }
    return -1;  // si el elemento no se encuentra
}

int busquedaBinaria(tList &lista, int tam, double valor)
{
  int numf = tam-1;
  int numi = 0;
  int mitad;
  while (numi<= numf){
      mitad = (numf + numi)/2;
      if (lista.estudiantes[mitad].nota == valor){
         return mitad;
         }else{
             if (valor < lista.estudiantes[mitad].nota){
                 numf=mitad-1;
            }else{
            numi=mitad+1;
        }
    }
    }
  return -1;
}

void busquedaInterpolacion(tList &lista,int tam, double valor){
    int primero=0;
    int ultimo= tam-1;
    int medio, contador=0;

    while (lista.estudiantes[primero].nota!= valor && contador<tam){
        medio= primero+ ((valor-lista.estudiantes[primero].nota)*(ultimo -primero))/ (lista.estudiantes[ultimo].nota-lista.estudiantes[primero].nota); // para calcular el elemento medio
        if(lista.estudiantes[medio].nota<valor)
            ultimo = medio+1;
            else if (lista.estudiantes[medio].nota>valor)
            ultimo= medio-1;

        else
            primero= medio;


        contador++;

    }
    ofstream busqueda;
    busqueda.open("busqueda.txt",ios::app);

    // verificar la comprobacion
    if( lista.estudiantes[medio].nota== valor)
    {
        Say(3,11,"CORRESPONDE AL ESTUDIANTE: " );
        cout << lista.estudiantes[medio].nombre << " "<<lista.estudiantes[medio].apellido << endl;
        busqueda << "CORRESPONDE AL ESTUDIANTE: " << lista.estudiantes[medio].nombre << " "<<lista.estudiantes[medio].apellido << "\n";
    } else{
        Say(3,11, "CALIFICACION NO ENCONTRADA\n");
        busqueda << "CALIFICACION NO ENCONTRADA\n" ;
    }

    busqueda.close();
}

void cargarDocente(tDocente &doc, bool &ok){
  ok = true;
   ifstream profesor;
   profesor.open("calificaciones.txt",ios::app);

   if (!profesor.is_open()) {
      ok = false;
   }
   else {
     cin.ignore ();
      getline(profesor,doc.prof);
      profesor>> doc.ident;

   }
  profesor.close();
}
