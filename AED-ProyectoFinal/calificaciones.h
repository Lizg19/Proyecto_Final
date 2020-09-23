#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "burbuja.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "insercion.h"
#include "seleccion.h"
#include "colores.h"

using namespace std;

namespace califica
{
  const int Notas = 20;
  const int MAX = 40;

  typedef struct
  {
    string nombre;
    string apellido;
    string correo;
    double nota[Notas];
    double Total;
  }tEstudiante;

  typedef struct
  {
    tEstudiante alumno[MAX];
    int contador = 0;
  }tLista;

  typedef struct {
  string prof_orden;
  string ci_orden;
  }tDocente_ordenamiento;


    void imprimir_ordenar(double a[], int n,tLista &listado,string Ordena);
     void cargarDocente_ordenamiento(tDocente_ordenamiento &doc, bool &ok);

    int menu()
  {
    int op;
    do
    {
      cout << "\n* * * MENU DE OPCIONES * * *" << endl;
      cout << "1. Ingresar docente" << endl;
      cout << "2. Ingresar materia" << endl;
      cout << "3. Ingresar cantidad de estudiantes y calificaciones" << endl;
      cout << "4. Registrar notas" << endl;
      cout << "5. Mostrar resumen" << endl;
      cout << "0. Salir" << endl;
      cout << "Eliga una opcion: ";
      cin >> op;
      if ((op < 0) || (op > 5))
      {
        cout << "\nEliga una opcion correcta del MENU" << endl;
      }
    }while((op < 0) || (op > 5));
    system("cls");
    return op;
  }

  tEstudiante nuevo(int t_1)
  {
    tEstudiante alumno;

    cin.ignore();
    cout << "\nNombre: ";
    cin >> alumno.nombre;
    cout << "Apellido: ";
    cin >> alumno.apellido;
    cout << "Correo: ";
    cin >> alumno.correo;
    for(int i = 0; i < t_1; i++)
    {
      cout << "Calificación[" << i+1 << "]: ";
      cin >> alumno.nota[i];
    }
    return alumno;
  }

  void insertar_estudiante(tLista &listado, tEstudiante estudiante, int t_2)
  {
    listado.alumno[listado.contador] = estudiante;
    listado.contador++;
  }

  double total(tLista &listado, int a, int t_1)
  {
    double promedio = 0;
    for(int i = 0; i < t_1; i++)
    {
      promedio += listado.alumno[a].nota[i];
    }
    return promedio/t_1;
  }


  void mostrar_estudiante(tLista &listado, string docente, string materia, int t_1, long long int Cedula)
  {
    int i, j, conta_A = 0, conta_S = 0, conta_R = 0;
    double promedio_curso = 0, T;
    TextColor(10);
    Rectangle(2,2,90,3,"."); // derecha,hacia abajo,ancho,alto, simbolo
    Say(2,3,"\t\t\tCOLEGIO MEJIA\n" );
    Say(3,4,"\t\tREPORTE DE CALIFICACIONES\n" );
    Rectangle(2,5,90,2,".");
    Say(3,6,"AÑO LECTIVO: 2019-2020\n" );
    Rectangle(2,7,90,2,".");
    Say(3,8,"MATERIA: " );
    cout << materia;
    Rectangle(2,9,90,21,".");
    Say(3,10,"\n");
    cout << "\tN°-: Nombre          Apellido         Correo                 ";
    for(i = 0; i < t_1; i++)
    {
      cout << "\tNota " << i+1 << " ";
    }
    cout << "Total" << endl;
    for(i = 0; i < listado.contador; i++)
    {
      cout <<"\t";
      cout << i+1  << setw(15)<<right<< listado.alumno[i].nombre << setw(15)<<  listado.alumno[i].apellido <<"\t"<< setw(15)<<  listado.alumno[i].correo << " \t\t";
      for(j = 0; j < t_1; j++)
      {
        cout << right << setw(6) <<listado.alumno[i].nota[j];
      }
      T = total(listado, i, t_1);
      listado.alumno[i].Total = T;
      cout << " " <<right <<setw(6) <<fixed <<setprecision(2)<< T << endl;
     if((T <= 20)&&(T >= 14))
      {
        conta_A++;
      }
      else if((T < 14)&&(T >= 9))
      {
        conta_S++;
      }
      else if((T < 9)&&(T > 1))
      {
        conta_R++;
      }
      promedio_curso += T;
    }
    Rectangle(2,30,90,10,".");
    Say(3,32, "RESUMEN\n");
    Say(3,33,"Promedio del curso:\t\t\t");
    cout << right<<setw(26) << promedio_curso / listado.contador;
    Say(3,34,"Total:         Aprobados (14 - 20)");
    cout <<right << setw(29) <<conta_A ;
    Say(3,35,"               Suspenso (09 - 13)");
    cout <<right << setw(30) << conta_S;
    Say(3,36,"               Reprobados (01 - 08)");
    cout << right << setw(28) << conta_R;
    Say(3,37,"         _______________________________\n" );
    Say(3,38,"               ");
        cout  << docente;
    Say(3,39,"               " );
        cout << Cedula;
    Say(3,41,"");system("pause");
                 system("cls");
  }

  void guardar_reporte(tLista &listado, string docente, string materia, int t_1, long long int Cedula)
  {
    ofstream estudiante;
    int i, j, conta_A = 0, conta_S = 0, conta_R = 0;
    double T, promedio = 0;
    estudiante.open("calificaciones.txt");
    if(estudiante.is_open())
    {
      estudiante << docente << endl;
      estudiante << Cedula << endl;
      estudiante << materia << endl;
      for(i = 0; i < listado.contador; i++)
      {
        estudiante << listado.alumno[i].nombre << " " << listado.alumno[i].apellido << " " << listado.alumno[i].correo << " ";
        for(j = 0; j < t_1; j++)
        {
          estudiante << listado.alumno[i].nota[j] << " ";
        }
        T = total(listado, i, t_1);
        estudiante << listado.alumno[i].Total << endl;
       if((T <= 20)&&(T >= 14))
      {
        conta_A++;
      }
      else if((T < 14)&&(T >= 9))
      {
        conta_S++;
      }
      else if((T < 9)&&(T > 1))
      {
        conta_R++;
      }
        promedio += T;
      }
      promedio /= listado.contador;
      estudiante << "Promedio del curso: " << promedio << endl;
      estudiante << "Aprobados (14 - 20): " << conta_A << endl;
      estudiante << "Suspenso (09 - 13): " << conta_S << endl;
      estudiante << "Reprobados (01 - 08): " << conta_R << endl;
    }
    else
    {
      cout << "\nEl archivo no abrió exitosamente" << endl;
    }
  }


  int menu_ordenamiento()
  {
    int op;
    do
    {
      cout << "\n* * * MENU PARA ORDENAR * * *" << endl;
      cout << "1. Burbuja" << endl;
      cout << "2. HeapSort" << endl;
      cout << "3. MergeSort" << endl;
      cout << "4. QuickSort" << endl;
      cout << "5. Insercion" << endl;
      cout << "6. Seleccion" << endl;
      cout << "7. Salir" << endl;
      cout << "Eliga una opcion: ";
      cin >> op;
      if ((op < 0) || (op > 7))
      {
        cout << "\nEliga una opcion correcta del MENU" << endl;
      }
    }while((op < 0) || (op > 7));
    system ("cls");
    return op;
  }


  void seleccion_ordenar(tLista &listado){
  string ORDENA;
  int op_ordenamiento;
  double A[MAX];
  for(int i = 0; i< listado.contador; i++){
     A[i] = listado.alumno[i].Total;
  }

   do{
    op_ordenamiento = menu_ordenamiento();
    int n; n = listado.contador;
    if (op_ordenamiento == 1){
    ORDENA = "Burbuja";
    burbuja(A,n);
    imprimir_ordenar(A,n,listado,ORDENA);
    }

    else if(op_ordenamiento == 2){
      ORDENA = "HeapSort";
      HeapSort(A,n);
      imprimir_ordenar(A,n,listado,ORDENA);
    }

    else if(op_ordenamiento == 3){
      ORDENA = "MergeSort";
      dividir(A, 0, n-1);
       imprimir_ordenar(A,n,listado,ORDENA);

    }

    else if(op_ordenamiento == 4){
      ORDENA = "QuickSort";
      //ordenar(A,0,n-1);
      imprimir_ordenar(A,n-1,listado,ORDENA);

    }

    else if(op_ordenamiento == 5){
       insercion(A, n);
      imprimir_ordenar(A,n,listado,ORDENA);
      ORDENA = "Insercion";
    }

    else if(op_ordenamiento == 6){
      algoritmoSeleccion(A,n);
      imprimir_ordenar(A,n,listado,ORDENA);
      ORDENA = "Seleccion";
    }
  }while(op_ordenamiento != 7);
  }

  void imprimir_ordenar(double a[], int n,tLista &listado,string Ordena)
  {
    tDocente_ordenamiento doc;
    bool ok;
    cargarDocente_ordenamiento(doc,ok);
    ofstream salida_ordenar;
    int i;
    salida_ordenar.open("ordenamiento.txt");
    if(!salida_ordenar.fail())
    {
      TextColor(11);
      Rectangle(2,2,60,3,".");
      Say(3,3,"\t\tCOLEGIO MEJIA\n");
      Say(3,4, "\t\tREPORTE DE CALIFICACIONES\n");
      TextColor(14);
      Rectangle(2,7,60,10,".");
      Say(3,6,"Calificaciones Ordenadas\n");
      Say(3,8,"ALGORITMO: " );
      cout << Ordena ;
      Say(3,9,"N° - ");

      for(i=0; i <listado.contador ; i++)
      {
        cout << " |" <<a[i] << "| ";
        salida_ordenar << listado.alumno[i].nombre <<" "<< listado.alumno[i].apellido<< " " << a[i] << " " << endl;
      }
      Say(3,12,"          ___________________________\n");
      Say(3,13,"      \t ");
      cout <<  doc.prof_orden;
      Say(3,14,"      \t ");
      cout << doc.ci_orden ;
    }
    else
    {
      Say(3,15,"El archivo no abrió exitosamente\n" );
    }
    Say(3,16,"");system("pause");
                system("cls");
    salida_ordenar<< -1 << endl;
    salida_ordenar.close();
  }

  void cargarDocente_ordenamiento(tDocente_ordenamiento &doc, bool &ok){
    ok = true;
   ifstream profesor_orden;
   profesor_orden.open("calificaciones.txt",ios::app);

   if (!profesor_orden.is_open()) {
      ok = false;
   }
   else {
     cin.ignore ();
      getline(profesor_orden,doc.prof_orden);
      profesor_orden >> doc.ci_orden;

   }
  profesor_orden.close();
}

}

