#include <iostream>
#include <string>
#include <fstream>
#include "calificaciones.h"

using namespace std;
using namespace califica;

void inicio();
void buscar();
void parte1(tLista &listado, tEstudiante estudiante);
int menuProgramaPrincipal();

int main(){
  TextColor(9);
  inicio();
  tEstudiante estudiante;
  tLista libreta;
  int op1;
  setlocale(LC_ALL,"spanish");

  do{
  op1=menuProgramaPrincipal();

  switch (op1){
    case 1:
    parte1(libreta, estudiante);
    break;

    case 2:
    seleccion_ordenar(libreta);
    break;

    case 3:
    buscar();
    break;
  }
  }while (op1!=0);

  return 0;

}

void parte1(tLista &listado, tEstudiante estudiante) {
  setlocale(LC_ALL,"spanish");
  int opcion, aula, calif, i = 0;
  long long int CI;
  string docente, materia;
  do
  {
    opcion = menu();
    switch (opcion)
    {
      case 1:
      {
        cin.ignore();
        cout << "\nIngrese el nombre del docente: ";
        getline(cin, docente);
        cout << "Cedula del docente: ";
        cin >> CI;
      break;
      }
      case 2:
      {
        cin.ignore();
        cout << "\nIngrese el nombre de la materia: ";
        getline(cin, materia);
      break;
      }
      case 3:
      {
        do
        {
          cout << "\nIngrese la cantidad de estudiantes a registrar: ";
          cin >> aula;
          if(aula > MAX)
          {
            cout << "\n¡Máximo 40 estudiantes! Intentelo de nuevo " << endl;
          }
        }while(aula > MAX);
        do
        {
          cout << "\nIngrese la cantidad de calificaciones a registrar: ";
          cin >> calif;
          if(calif > Notas)
          {
            cout << "\n¡Máximo 20 calificaciones! Intentelo de nuevo " << endl;
          }
        }while(calif > Notas);
      break;
      }
      case 4:
      {
        cout << "\n* * * Complete los espacios para ingresar un estudiante y calificaciones * * *" << endl;
        while(i < aula)
        {
          cout << "\nEstudiante[" << i+1 << "]" << endl;
          estudiante = nuevo(calif);
          insertar_estudiante(listado, estudiante, aula);
          i++;
        }
      break;
      }
      case 5:
      {
        mostrar_estudiante(listado, docente, materia, calif, CI);
      break;
      }

    }
  }while (opcion != 0);
  guardar_reporte(listado, docente, materia, calif, CI);
  //cout << "\nGRACIAS POR USAR NUESTRO SERVICIO" << endl;
}

int menuProgramaPrincipal(){
  int o;
  cout << "\t\tCOLEGIO MEJIA"<< endl;
  cout << "\t\tCALIFICACIONES" << endl;
  cout << endl;
  cout << "1. Ingresar informacion PROFESOR-ESTUDIANTE" << endl;
  cout << "2. Algoritmos de ordenamiento para las CALIFICACIONES" << endl;
  cout << "3. Algoritmos de busqueda para las CALIFICACIONES " << endl;
  cout << "0. Salir" << endl;
  cout << "Eliga una opción: ";
  cin >> o;
  system ("cls");
  return o;
}
