#include <iostream>
#include "buscar.h"
#include <fstream>
#include "colores.h"
using namespace std;

//void buscar();
int menu();
int busquedaLineal(tList &lista, int tam, double valor );
void busquedaInterpolacion(tList &lista,int tam, double valor);
int busquedaBinaria(tList &lista, int tam, double valor);
void cargarEstudiante(tList &lista, bool &ok);
void cargarDocente(tDocente &doc, bool &ok);
void formato();
void formato2();

void buscar(){
    ofstream busqueda;
    busqueda.open("busqueda.txt",ios::app);
    tEstud estudiante;
    tList lista;
    bool ok;
    double calf1,calf2,calf3;
    long long int CI;
    string docente;

    int opcion;
    do{
        cargarEstudiante(lista,ok);
        opcion = menu();
        switch(opcion){
            case 1:
                cout << "¿Que calificacion desea buscar?: ";
                cin >> calf1;
                Rectangle(2,2,60,3,"."); // derecha,hacia abajo,ancho,alto, simbolo
                formato();
                Rectangle(2,7,60,10,".");
                Say(3,8,"ALGORITMO: Busqueda Lineal\n");
                Say(3,9,"La calificacion a buscar fue: ") ;
                cout << calf1 ;
                busqueda << "La calificacion a buscar fue: " <<calf1 << "\n";
                 if(busquedaLineal(lista, lista.contador,calf1)==-1){
                    Say(3,11,"CALIFICACION NO ENCONTRADA \n");
                    busqueda <<"CALIFICACION NO ENCONTRADA \n";
                 }else {
                    Say(3,11,"CORRESPONDA AL ESTUDIANTE: " );
                    cout << lista.estudiantes[busquedaLineal(lista, lista.contador,calf1)].nombre <<" "
                    << lista.estudiantes[busquedaLineal(lista, lista.contador,calf1)].apellido<< "\n";
                    busqueda << "CORRESPONDA AL ESTUDIANTE: " <<  lista.estudiantes[busquedaLineal(lista, lista.contador,calf1)].nombre <<" "
                    << lista.estudiantes[busquedaLineal(lista, lista.contador,calf1)].apellido<< "\n";
                    formato2();
                 }
                 Say(3,16,"");system("pause");
                 system("cls");
                break;
            case 2:
                cout << "¿Que calificacion desea buscar?: ";
                cin >> calf2;
                Rectangle(2,2,60,3,".");
                formato();
                Rectangle(2,7,60,10,".");
                Say(3,8,"ALGORITMO: Busqueda Binaria\n");
                Say(3,9,"La calificacion a buscar fue: ");
                cout << calf2;
                busqueda << "La calificacion a buscar fue: " << calf2 <<"\n";
                if(busquedaBinaria(lista, lista.contador,calf2)==-1){
                    Say(3,11, "CALIFICACION NO ENCONTRADA \n");
                 }else {
                    Say(3,11,"CORRESPONDA AL ESTUDIANTE: " );
                    cout << lista.estudiantes[busquedaBinaria(lista, lista.contador,calf2)].nombre  << " "
                    << lista.estudiantes[busquedaBinaria(lista, lista.contador,calf2)].apellido ;
                    busqueda <<"CORRESPONDA AL ESTUDIANTE: " << lista.estudiantes[busquedaBinaria(lista, lista.contador,calf2)].nombre  << " "
                    << lista.estudiantes[busquedaBinaria(lista, lista.contador,calf2)].apellido << "\n";
                    formato2();

                 }
                 Say(3,16,"");system("pause");
                 system("cls");
                break;
            case 3:
                cout << "¿Que calificacion desea buscar?: ";
                cin >> calf3;
                Rectangle(2,2,60,3,".");
                formato();
                Rectangle(2,7,60,10,".");
                Say(3,8, "ALGORITMO: Busqueda por Interpolacion\n");
                Say(3,9,"La calificacion a buscar fue: ");
                cout << calf3 ;
                busqueda << "La calificacion a buscar fue: " << calf3 <<"\n";
                busquedaInterpolacion(lista,lista.contador,calf3);
                formato2();
                Say(3,16,"");system("pause");
                system("cls");
                break;
    }
    }while (opcion!=4);
    busqueda.close();
}

int menu(){
    int op;
cout << endl;
cout << "BUSCAR CALIFICACIONES" << endl;
cout << "1. BUSQUEDA LINEAL/SECUENCIAL" << endl;
cout << "2. BUSQUEDA BINARIA" <<endl;
cout << "3. BUSQUEDA POR INTERPOLACION" <<endl;
cout << "4. SALIR"<< endl;
cout << "¿Que algoritmo desea usar?: ";
cin >>op;
system("cls");

return op;
}

void formato(){
  TextColor(11);
  Say(3,3,"\t\tCOLEGIO MEJIA\n");
  Say(3,4, "\t\tREPORTE DE CALIFICACIONES\n");
  TextColor(14);
  Say(3,6,"Busqueda de calificaciones\n");
}

void formato2(){
  tDocente doc;
  bool ok;
  cargarDocente(doc,ok);
  Say(3,12,"        ____________________\n");
  Say(3,13,"      \t ");
      cout <<doc.prof ;
  Say(3,14,"      \t ");
      cout << doc.ident;
}
