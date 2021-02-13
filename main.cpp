#include <iostream>
#include <fstream>
using namespace std;

int menu();
void intercambiar();
void ordenar();
void pichincha();
void error(string cadena);

bool salir;

int main() {
  salir = false;
  while (!salir) 
  {
    switch(menu()) 
    {
      case 1:
        intercambiar();
      break;
      case 2:
        ordenar();
      break;
      case 3:
        pichincha();
      break;
      case 4:
        cout << "Saliendo...\n";
        salir = true;
      break;
      default:
        error("Opcion invalida");
      break;
    }
  }
  return 0;
}

int menu() {
  int opc;
  cout << "\n\t\t\tTRABAJO EN GRUPO\n\n";
  cout << "\tALGORITMOS Y ESTRUCTURAS DE DATOS\n\n";
  cout << "\t SELECCIONE UNA OPCION DEL MENU\n\n";
  cout << "1.- INTERCAMBIAR POSICIONES DE UN VECTOR DE SEIS ELEMENTOS\n";
  cout << "2.- ORDENAMIENTO DE UN VECTOR\n";
  cout << "3.- CUENTA DE AHORROS VIRTUAL DEL BANCO PICHINCHA\n";
  cout << "4.- SALIR\n";
  cout << "OPCION: ";
  cin >> opc;
  if (cin.fail() || cin.get() != '\n')
  {
    cin.clear();
    while (cin.get() != '\n')
    opc = -1;
  }
  return opc;
}

void intercambiar() {
  ofstream archivoIntercambiar;
  ifstream archivoLectura;
  string texto;
  archivoIntercambiar.open("intercambiar.txt",ios::app);
  int tam = 6;
  string vector[tam], intercambiado[tam];
  archivoIntercambiar << "\n\nINTERCAMBIAR POSICIONES DE UN VECTOR\n";
  archivoIntercambiar << "------------------------------------\n";
  for (int i=0; i<tam; i++) 
  {
    cout << "Ingrese el valor de la posición #" << i+1 << ": ";
    cin >> vector[i];
    archivoIntercambiar << "Elemento de la posición #" << i+1 << ": "<<vector[i]<<endl;
  }
  archivoIntercambiar << "\nVector original: ";
  for (int i=0; i<tam; i++) 
  {
    archivoIntercambiar << "[" << vector[i] << "]";
  }
  archivoIntercambiar << "\n";
  for (int i=0; i<tam; i++) 
  {
    intercambiado[tam-i-1]=vector[i];
  }
  archivoIntercambiar << "Vector intercambiado: ";
  for (int i=0; i<tam; i++) 
  {
    archivoIntercambiar << "[" << intercambiado[i] << "]";
  }
  archivoIntercambiar << "\n";
  archivoIntercambiar << "------------------------------------\n";
  archivoIntercambiar.close();
  archivoLectura.open("intercambiar.txt",ios::in);
  if (archivoLectura.fail())
  {
    cout<<"EL ARCHIVO NO SE PUDO ABRIR";
  }
  else
  {
    while (!archivoLectura.eof())
    {
      getline(archivoLectura,texto);
      cout<<texto<<endl;
    }
  }
  archivoLectura.close();
}

void ordenar() {
  ofstream archivoOrdenar;
  ifstream archivoLectura;
  string texto;
  int tam, aux;
  archivoOrdenar.open("ordenamiento.txt",ios::app);
  archivoOrdenar << "\n\nORDENAMIENTO DE UN VECTOR\n";
  archivoOrdenar << "-------------------------\n";
  cout << "Ingrese el tamaño del vector: ";
  cin >> tam;
  archivoOrdenar <<"Tamaño del vector: "<<tam<<endl;
  int vector[tam];
  for (int i=0; i<tam; i++) 
  {
    cout << "Ingrese el valor de la posición #" << i+1 << ": ";
    cin >> vector[i];
    archivoOrdenar << "Valor de la posición #" << i+1 << ": "<<vector[i]<<endl;
  }
  archivoOrdenar << "\nVector original: ";
  for (int i=0; i<tam; i++) 
  {
    archivoOrdenar << "[" << vector[i] << "]";
  }
  archivoOrdenar << "\n";
  for (int i=0; i<tam; i++) 
  {
    for (int j=i+1; j<tam; j++) 
    {
      if (vector[j] < vector[i]) 
      {
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }
  archivoOrdenar << "Vector ordenado: ";
  for (int i=0; i<tam; i++) 
  {
    archivoOrdenar << "[" << vector[i] << "]";
  }
  archivoOrdenar << "\n";
  archivoOrdenar << "-------------------------\n";
  archivoOrdenar.close();
  archivoLectura.open("ordenamiento.txt",ios::in);
  if (archivoLectura.fail())
  {
    cout<<"EL ARCHIVO NO SE PUDO ABRIR";
  }
  else
  {
    while (!archivoLectura.eof())
    {
      getline(archivoLectura,texto);
      cout<<texto<<endl;
    }
  }
  archivoLectura.close();
}

void pichincha() {
  ofstream archivoPichincha;
  ifstream archivoLectura;
  int n=2; 
  string mes1; 
  float buscar,valor; 
  int cont=0; 
  string mes,texto;
  archivoPichincha.open("cuenta.txt",ios::app);
  string meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"}; 
  float ahorros[12];
  archivoPichincha << "\n\nCUENTA DE AHORROS BANCO PICHINCHA\n";
  archivoPichincha << "---------------------------------\n";
  for(int i=0; i<12; i++) 
  { 
    cout << "Ingrese los ahorros de " << *(meses+cont) << ": " << endl; 
    cin >> ahorros[i]; 
    archivoPichincha << "Ahorros de " << *(meses+cont) << ": " << ahorros[i]<< endl; 
    cont++;
  }
  cout << "\nIngrese la cantidad de dinero a buscar: \n"; 
  cin >> buscar;
  archivoPichincha << "\nCantidad de dinero a buscar: "<<buscar<<endl;
  cont = 0; 
  for (int i=0; i<12; i++) 
  { 
    if (buscar == ahorros[i]) 
    { 
      valor = ahorros[i]; 
      mes1 = *(meses+cont); 
      n = 1; 
    } 
    cont++; 
  } 
  if (n==1) 
  { 
    archivoPichincha<<"\nLa cantidad de ahorro $"<<valor<<" se ha encontrado en el mes de "<<mes1<<"."<<endl; 
  } 
  else 
  { 
    archivoPichincha<<"\nEl ahorro ingresado no se encuentra registrado en ningun mes. \n"; 
  }
  archivoPichincha << "---------------------------------\n";
  archivoPichincha.close();
  archivoLectura.open("cuenta.txt",ios::in);
  if (archivoLectura.fail())
  {
    cout<<"EL ARCHIVO NO SE PUDO ABRIR";
  }
  else
  {
    while (!archivoLectura.eof())
    {
      getline(archivoLectura,texto);
      cout<<texto<<endl;
    }
  }
  archivoLectura.close();
} 

void error(string cadena) {
  cadena = "  *** " + cadena + " ***  ";
  cout << "\n╔";
  for (int i=0; i<cadena.length(); i++) 
  {
    cout << "═";
  }
  cout << "╗\n║" << cadena << "║\n╚";
  for (int i=0; i<cadena.length(); i++) 
  {
    cout << "═";
  }
  cout << "╝\n";
}