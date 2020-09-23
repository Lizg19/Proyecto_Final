#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 10;

typedef struct
{

    string nombre;
    string cedula;
    int codigo;

} tProfesor;

typedef struct
{

    tProfesor profesores[MAX];
    int contador = 0;

} tListaProfesores;

int solicitar_codigo(tListaProfesores &lista, int N);
void almacenar_maestros(tListaProfesores &maestros);
tProfesor agregar_maestro();
void guardar_maestro(tListaProfesores &maestros);

void inicio()
{

    srand(time(NULL));
    tListaProfesores lista_maestros;
    almacenar_maestros(lista_maestros);
    int permiso;
    do
    {
        permiso = solicitar_codigo(lista_maestros, 10);
        //cout << "Para acceder ingrese el codigo asignado" << endl;
    } while (!permiso);
    guardar_maestro(lista_maestros);

}

int solicitar_codigo(tListaProfesores &lista, int N)
{

    int opcion, codigo_asignado, i, codigo_ingresado, valor;
    tProfesor maestro;
    string nombre, cedula;

    cout << "Esta usted registrado en el sistema?" << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    cout << "Seleccione una opcion(1-2)" << endl;
    cin >> opcion;
    system("pause>null");
    system ("cls");

    if (opcion == 1)
    {

        cout << "Ingrese su codigo de acceso: ";
        cin >> codigo_ingresado;
        for (i = 0; i < N; i++)
        { //algoritmo de busqueda

            if (lista.profesores[i].codigo == codigo_ingresado)
            {

                cout << "Bienvenido " << lista.profesores[i].nombre << endl;
                system("pause>null");
                system("cls");

                return 1;
            }
        }

        cout << "No existe registro" << endl;
    }
    else
    {
      maestro = agregar_maestro();
      lista.profesores[lista.contador] = maestro;
      lista.contador++;
      valor = 0;
    }
    return valor;
}

tProfesor agregar_maestro()
{
  tProfesor docente;
  docente.codigo = 10000 + rand() % (10000 - 1);
  cout << "Su codigo de acceso asignado es: " << docente.codigo << endl;
  cin.ignore();
  cout << "Ingrese su nombre: ";
  getline (cin, docente.nombre);
  cout << "Ingrese su cedula: ";
  cin >> docente.cedula;
  return docente;
}
void guardar_maestro(tListaProfesores &maestros)
{
    ofstream archivo;
    int i;
    archivo.open("registro.txt", ios::out);
    if (!archivo.fail())
    {
      for(i = 0; i < maestros.contador; i++)
      {
        archivo << maestros.profesores[i].codigo << " " << maestros.profesores[i].cedula << " " << maestros.profesores[i].nombre << "\n";
      }
      archivo << -1;

    }
    else
    {
        cout << "No se pudo abrir el archivo";
    }
    archivo.close();
}

void almacenar_maestros(tListaProfesores &maestros)
{
    ifstream archivo;
    int i = 0;
    archivo.open("registro.txt", ios::in);
    if (!archivo.fail())
    {
      archivo >> maestros.profesores[i].codigo;
      while(maestros.profesores[i].codigo != -1)
      {
        getline(archivo, maestros.profesores[i].cedula, ' ');
        getline(archivo, maestros.profesores[i].nombre, '\n');
        maestros.contador++;
        i++;
        archivo >> maestros.profesores[i].codigo;
      }
    }
    else
    {
        cout << "No se pudo abrir el archivo";
    }
    archivo.close();
}
