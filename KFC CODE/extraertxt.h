#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
string auxcodigo;
int cantidad;
 bool encontrado = false;

struct NuevoProducto {
	string codigo;
	string nombre;
	float precio;
    string ingredientes[3];
};
NuevoProducto productos[12];

struct Inventario{
    string codigo;
    string nombre;
    int cantidad;
};
Inventario elinventario[36];


void mostrarmenu(){

	ifstream arch_menu;


	arch_menu.open("menuaux.txt", ios :: in);

	if (arch_menu.fail ()){
		cout << "No se pudo abrir el menu";
		exit (1);
	}
    cout<<endl<<"========================================================================="<<endl;
    cout<<"   ******************************  MENU  ****************************    "<<endl;
    cout<<"========================================================================="<<endl;
    cout<<setw(7)<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(35)<<"PRECIO"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

	for (int i = 0; i < 12; i++){
        arch_menu >> productos[i].codigo
        >> productos[i].nombre
        >> productos[i].precio;
	}
	for (int i = 0; i < 12; i++){
        cout <<endl<< left << "  " << productos[i].codigo << "\t\t "
        << setw(15)<< productos[i].nombre<< "\t"
        <<setw(23)<<right<< productos[i].precio;
	}
		arch_menu.close() ;
}

void venta() {
  cout<<endl<<"========================================================================="<<endl;
  cout << endl << "Ingrese el codigo del producto: ";
  cin >> auxcodigo;

  bool encontrado = false;

  for (int i = 0; i < 12; i++) {
    if (productos[i].codigo == auxcodigo) {
      encontrado = true;

      cout << "Cantidad: ";
      cin >> cantidad;

      float subtotal = productos[i].precio * cantidad;
      cout<<endl<<"========================================================================="<<endl;
      cout << "\n\nProducto: " << productos[i].nombre << endl;
      cout << "Cantidad: " << cantidad << endl;
      cout << "Subtotal: $" << subtotal << endl;
      cout<<endl<<"========================================================================="<<endl;
      char respuesta;
        cout << endl<<"¿Desea anadir otro producto? (S/N): ";
        cin >> respuesta;

        if (respuesta == 'S' || respuesta == 's') {
          venta();
        }else if (respuesta == 'N' || respuesta == 'n') {
          float total = subtotal;
          cout << "\n=========================================================================";
          cout << "\n\nTotal de la venta: $" << total << endl;
        }

      break;
    }
  }

  if (!encontrado) {
    cout << "\nNo se encontro un producto con el codigo \"" << auxcodigo << "\"" << endl;
  }
}

void mostrarinventario(){
    ifstream arch_inventario;

	arch_inventario.open("inventario.txt", ios :: in);

	if (arch_inventario.fail ()){
		cout << "No se pudo abrir el inventario";
		exit (1);
	}
    cout<<endl<<"========================================================================="<<endl;
    cout<<"   ************************  DETALLE INVENTARIO  **********************    "<<endl;
    cout<<"========================================================================="<<endl;
    cout<<"CODIGO"<<setw(20)<<"NOMBRE"<<setw(35)<<"CANTIDAD"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < 36; i++){
        arch_inventario >> elinventario[i].codigo
        >> elinventario[i].nombre
        >> elinventario[i].cantidad;
	}
	for (int i = 0; i < 36; i++){
        cout <<endl<< left << "   "<< elinventario[i].codigo << "\t\t "
        << setw(15)<< elinventario[i].nombre<< "\t\t"
        <<setw(23)<<right<< elinventario[i].cantidad;
	}
		arch_inventario.close() ;

}

/*
void agregarProducto () {

  fstream arch_menu("menuaux.txt", ios::app);

  if (arch_menu.fail()) {
    cout << "Error al abrir el archivo menu.txt" << endl;
    return;
  }

  // Leer datos del nuevo producto
  fflush(stdin);
  cout << endl << "\nIngrese codigo del producto: ";
  getline (cin, productos.codigo);

  cout << "\nIngrese Nombre del producto: ";
  getline(cin, productos.nombre);

  cout << "\nPrecio: ";
  cin >> productos.precio;

  // Escribir el nuevo producto al final del archivo
  arch_menu << "\n"<< productos.codigo <<","<< productos.nombre <<","<< productos.precio;

  // Cerrar el archivo
  arch_menu.close();

  cout << "Producto anadido exitosamente" << endl;
}*/

