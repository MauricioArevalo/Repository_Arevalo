
#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>

//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;


      	
		



class menu_p
{
private:
	float subprecio;
	float total;
    string nombre;
    string marca;
    string precio;
    string provedor;
    string codigoProducto;

public:
    void altaProducto();
    void bajaProducto();
    void modificarProducto();
    void listarProductos();
    void menuPrincipal_p();
    void detallesProducto();
    void compraProducto();
    void listarCarrito();
    void comprar();
    void borrarCarrito();
    void mostarRegistro_p(string codigo);
};



void pausa();
void error();

void menu_p::menuPrincipal_p()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Ferreteria(Productos)***\t\t\t\t\n\n";
        cout<<"1. Agregar producto\n\n";
        cout<<"2. Mostrar detalles de un producto\n\n";
        cout<<"3. Listar producto\n\n";
        cout<<"4. Dar de baja un producto\n\n";
        cout<<"5. Modificar un producto\n\n";
        
        cout<<"6. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            altaProducto();
            break;

        case 2:
            detallesProducto();
            break;

        case 3:
            listarProductos();
            break;

        case 4:
            bajaProducto();
            break;

        case 5:
            modificarProducto();
            break;

        case 6:
            break;
        
        case 7: 
        	compraProducto();
        	break;
        case 8:
        	listarCarrito();
        	break;
    	}
    }
    while(opcion!=6);
}

void menu_p::altaProducto()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("productos.txt",ios::in);
    escritura.open("productos.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Dar de alta un Producto***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Producto: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"c\242digo de Producto no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigoProducto);
            while(!verificador.eof())
            {
                getline(verificador,nombre);
                getline(verificador,marca);
                getline(verificador,precio);
                getline(verificador,provedor);

                if(codigoProducto==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un producto con ese c\242digo!\n\n";
                    cout<<"El producto con ese c\242digo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nc\242digo de producto no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigoProducto);
            }

            if(verificador.eof()&&auxCodigo!=codigoProducto)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigoProducto=auxCodigo;
        cout<<"\t\t\t\t***Dar de alta un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del producto: ";
        cout<<codigoProducto;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del Producto: ";
        getline(cin,nombre);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la marca del producto: ";
        getline(cin,marca);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el precio del producto: ";
        getline(cin,precio);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el provedor: ";
        getline(cin,provedor);
        cout<<"\n\n";
//imp sht
        escritura<<codigoProducto<<"\n"<<nombre<<"\n"<<marca<<"\n"<<precio
                 <<"\n"<<provedor<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu_p::bajaProducto()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("productos.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Dar de baja un producto***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del producto que deseas dar de baja: ";
        getline(cin,auxCodigo);
        getline(lectura,codigoProducto);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,marca);
            getline(lectura,precio);
            getline(lectura,provedor);

            if(auxCodigo==codigoProducto)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoProducto<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Marca: "<<marca<<endl;
                cout<<"Precio: "<<precio <<endl;
                cout<<"Provedor: "<<provedor<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas dar de baja : "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl producto se ha dado de baja correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nProductp conservado\n\n";
                    auxiliar<<codigoProducto<<"\n"<<nombre<<"\n"<<marca<<"\n"<<precio
                            <<"\n"<<provedor<<"\n";

                }

            }
            else
            {
                auxiliar<<codigoProducto<<"\n"<<nombre<<"\n"<<marca<<"\n"<<precio
                        <<"\n"<<provedor<<"\n";
            }
            getline(lectura,codigoProducto);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("productos.txt");
    rename("auxiliar.txt","productos.txt");
    pausa();
}

void menu_p::detallesProducto()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("productos.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar detalles de un Producto***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del Producto que deseas consultar detalles: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigoProducto);
        while(!mostrar.eof())
        {
            getline(mostrar,nombre);
            getline(mostrar,marca);
            getline(mostrar,precio);
            getline(mostrar,provedor);

            if(auxCodigo==codigoProducto)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoProducto<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Marca: "<<marca<<endl;
                cout<<"Precio: "<<precio <<endl;
                cout<<"Provedor: "<<provedor<<endl;
                cout<<"\n\n";
            }
			
            getline(mostrar,codigoProducto);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}


void menu_p::compraProducto()
{
   /* string auxCodigo;
    ifstream mostrar;
    
    mostrar.open("clientes.txt",ios::in);
    if(mostrar.is_open())
   {
     */
     string auxCodigo;
     ofstream escritura;
    ifstream mostrar;
    char respuesta[5];
    bool encontrado=false;
    mostrar.open("productos.txt",ios::in);
    escritura.open("carrito.txt",ios::app);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Comprar un Producto***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del Producto que deseas comprar: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigoProducto);
        while(!mostrar.eof())
        {
            getline(mostrar,nombre);
            getline(mostrar,marca);
            getline(mostrar,precio);
            getline(mostrar,provedor);
				
				
				
			
				
            if(auxCodigo==codigoProducto)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoProducto<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Marca: "<<marca<<endl;
                cout<<"Precio: "<<precio<<endl;
                cout<<"Provedor: "<<provedor<<endl;
                cout<<"\n\n";
                
                
                cout<<"Realmente deseas comprar: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl producto se ha añadido al carrito\n\n";
                                 escritura<<codigoProducto<<"\n"<<nombre<<"\n"<<marca<<"\n"<<precio
                 <<"\n"<<provedor<<"\n";
                }

                else
                {

                    cout<<"\n\nProductp conservado\n\n";


                }
   
            }

            getline(mostrar,codigoProducto);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();

    escritura.close();
    pausa();
}


void menu_p::modificarProducto()
{
 ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxNombre;
    string auxMarca;
    string auxPrecio;
    string auxProvedor;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("productos.txt",ios::in);
    verificador.open("productos.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un producto***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del producto que deseas modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<"c\242digo de producto no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,codigoProducto);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,marca);
            getline(lectura,precio);
            getline(lectura,provedor);

            if(auxCodigo==codigoProducto)
            {
                encontrado=true;
                mostarRegistro_p(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el producto\n\n";
                fflush(stdin);
                cout<<"Ingresa el c\242digo del producto: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigoProducto);
                        while(!verificador.eof())
                        {
                            getline(verificador,nombre);
                            getline(verificador,marca);
                            getline(verificador,precio);
                            getline(verificador,provedor);

                            if(auxCodigo==codigoProducto)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un producto con ese c\242digo!\n\n";
                                cout<<"El producto con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de producto no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,codigoProducto);
                        }

                        if(verificador.eof()&&auxCodigo!=codigoProducto)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un producto***\n\n";
                cout<<"Ingresa el c\242digo del producto que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro_p(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el producto\n\n";
                cout<<"Ingresa el c\242digo del producto: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del producto: ";
                getline(cin,auxNombre);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa la marca del producto: ";
                getline(cin,auxMarca);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el precio del producto: ";
                getline(cin,auxPrecio);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el provedor de el producto: ";
                getline(cin,auxProvedor);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxNombre<<"\n"<<auxMarca<<"\n"<<auxPrecio
                        <<"\n"<<auxProvedor<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigoProducto<<"\n"<<nombre<<"\n"<<marca<<"\n"<<precio
                        <<"\n"<<provedor<<"\n";
            }


            getline(lectura,codigoProducto);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("productos.txt");
    rename("auxiliar.txt","productos.txt");
    pausa();
}

void menu_p::listarProductos()
{
    int i=0;
    ifstream lectura;
    lectura.open("productos.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los Productos***\t\t\t\t\n\n";
        getline(lectura,codigoProducto);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,nombre);
            getline(lectura,marca);
            getline(lectura,precio);
            getline(lectura,provedor);
            cout<<"C\242digo: "<<codigoProducto<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Marca: "<<marca<<endl;
            cout<<"Precio: "<<precio<<endl;
            cout<<"Provedor: "<<provedor<<endl;
            cout<<"\n\n";
            getline(lectura,codigoProducto);
        }

        if(i==1)
            cout<<"Hay un solo producto no manchen pongan mas huebones\n\n";

        else

            cout<<"Hay un total de "<<i<<" producots registrados en esta ferreteria vergota\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}


void menu_p::listarCarrito()
{
    int i=0;
    ifstream lectura;
    lectura.open("carrito.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los Productos***\t\t\t\t\n\n";
        getline(lectura,codigoProducto);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,nombre);
            getline(lectura,marca);
            getline(lectura,precio);
            getline(lectura,provedor);
            cout<<"C\242digo: "<<codigoProducto<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Marca: "<<marca<<endl;
            cout<<"Precio: "<<precio<<endl;
            cout<<"Provedor: "<<provedor<<endl;
            cout<<"\n\n";
            getline(lectura,codigoProducto);
        }

        if(i==1)
            cout<<"Hay un solo producto no manchen no sean codos\n\n";

        else

            cout<<"Hay un total de "<<i<<" producots registrados pa comprar\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}
void menu_p::comprar()
{
	char respuesta[5];
    int i=0;
    total = 0;
    ifstream lectura;
    lectura.open("carrito.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Comprar el carrito***\t\t\t\t\n\n";
        getline(lectura,codigoProducto);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,nombre);
            getline(lectura,marca);
            getline(lectura,precio);
            getline(lectura,provedor);
            getline(lectura,codigoProducto);
            subprecio=strtof((precio).c_str(),0);
            total=total+subprecio;
            
        }

        if(i==1)
           {
			cout<<"Hay un solo producto no manchen no sean codos\n\n";
			}
            

        else
			{
            cout<<"Hay un total de "<<i<<" producots registrados pa comprar\n\n";
			}
			
			
			cout<<"Tu precio total es de : "<< total<<"$ con efectivo y "<<total*1.01<<"$ con tarjeta\n\n";
			
				 
	 cout<<"Quieres realizar la compra (s/n)?: ";
                cin>>respuesta;
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                	
                	
                 	  remove("carrito.txt");
	  cout<<"Compra realizada con exito"<<endl;
                }

                else
                {

                    cout<<"\n\nCarrito conservado\n\n";


                }
			
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

void menu_p::borrarCarrito()
{
	 char respuesta[5];
	 cout<<"Realmente deseas borrar todo en tu carrito (s/n)?: ";
               cin>>respuesta;
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                 	  remove("carrito.txt");
	  cout<<"Carrito limpiado con exito"<<endl;
                }

                else
                {

                    cout<<"\n\nCarrito conservado\n\n";


                }
   
	 
	 

		pausa();	  
	
}
void pausa()
{
    cout<<"Presiona Enter para continuar...";
    getch();
    system(CLEAR);
}


class menu_o
{
private:
    string nombre;
    string correo;
    string telefono;
    string direccion;
    string codigoProvedor;

public:
    void altaProvedor();
    void bajaProvedor();
    void modificarProvedor();
    void listarProvedors();
    void menuPrincipal_o();
    void detallesProvedor();
    void mostarRegistro_o(string codigo);
};



void pausa();
void error();

void menu_o::menuPrincipal_o()
{
    int opcion;
    do
    {
        cout<<"\t\t\t\t***Ferreteria(Provedors)***\t\t\t\t\n\n";
        cout<<"1. Agregar Provedor\n\n";
        cout<<"2. Mostrar detalles de un Provedor\n\n";
        cout<<"3. Listar Provedor\n\n";
        cout<<"4. Dar de baja un Provedor\n\n";
        cout<<"5. Modificar un Provedor\n\n";
        
        cout<<"6. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            altaProvedor();
            break;

        case 2:
            detallesProvedor();
            break;

        case 3:
            listarProvedors();
            break;

        case 4:
            bajaProvedor();
            break;

        case 5:
            modificarProvedor();
            break;

        case 6:
            break;
        
     
    	}
    }
    while(opcion!=6);
}

void menu_o::altaProvedor()
{
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("provedores.txt",ios::in);
    escritura.open("provedores.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\t\t\t\t***Dar de alta un Provedor***\t\t\t\t\n\n";
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Provedor: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<"c\242digo de Provedor no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigoProvedor);
            while(!verificador.eof())
            {
                getline(verificador,nombre);
                getline(verificador,correo);
                getline(verificador,telefono);
                getline(verificador,direccion);

                if(codigoProvedor==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\n\nYa existe un Provedor con ese c\242digo!\n\n";
                    cout<<"El Provedor con ese c\242digo es: "<<nombre<<"\n\n";
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"\nc\242digo de Provedor no v\240lido!, intentalo nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigoProvedor);
            }

            if(verificador.eof()&&auxCodigo!=codigoProvedor)
                coincidencia=false;

        }
        while(coincidencia==true);
        system(CLEAR);
        codigoProvedor=auxCodigo;
        cout<<"\t\t\t\t***Dar de alta un cliente***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del Provedor: ";
        cout<<codigoProvedor;
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el nombre del Provedor: ";
        getline(cin,nombre);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa la correo del Provedor: ";
        getline(cin,correo);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el telefono del Provedor: ";
        getline(cin,telefono);
        cout<<"\n\n";
        fflush(stdin);
        cout<<"Ingresa el direccion: ";
        getline(cin,direccion);
        cout<<"\n\n";
//imp sht
        escritura<<codigoProvedor<<"\n"<<nombre<<"\n"<<correo<<"\n"<<telefono
                 <<"\n"<<direccion<<"\n";

        cout<<"El registro se ha completado correctamente.\n\n";
    }

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}

void menu_o::bajaProvedor()
{
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("provedores.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Dar de baja un Provedor***\t\t\t\t\n\n";
    if(lectura.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Provedor que deseas dar de baja: ";
        getline(cin,auxCodigo);
        getline(lectura,codigoProvedor);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,correo);
            getline(lectura,telefono);
            getline(lectura,direccion);

            if(auxCodigo==codigoProvedor)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoProvedor<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Correo: "<<correo<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Provedor: "<<direccion<<endl;
                cout<<"\n\n";
                cout<<"Realmente deseas dar de baja : "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                {
                    cout<<"\n\nEl Provedor se ha dado de baja correctamente\n\n";
                }

                else
                {

                    cout<<"\n\nProductp conservado\n\n";
                    auxiliar<<codigoProvedor<<"\n"<<nombre<<"\n"<<correo<<"\n"<<telefono
                            <<"\n"<<direccion<<"\n";

                }

            }
            else
            {
                auxiliar<<codigoProvedor<<"\n"<<nombre<<"\n"<<correo<<"\n"<<telefono
                        <<"\n"<<direccion<<"\n";
            }
            getline(lectura,codigoProvedor);
        }
        if(encontrado==false)
        {
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }

    }
    else
    {
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("provedores.txt");
    rename("auxiliar.txt","provedores.txt");
    pausa();
}

void menu_o::detallesProvedor()
{
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("provedores.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\t\t\t\t***Consultar detalles de un Provedor***\t\t\t\t\n\n";
        cout<<"Ingresa el c\242digo del Provedor que deseas consultar detalles: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigoProvedor);
        while(!mostrar.eof())
        {
            getline(mostrar,nombre);
            getline(mostrar,correo);
            getline(mostrar,telefono);
            getline(mostrar,direccion);

            if(auxCodigo==codigoProvedor)
            {
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<"C\242digo: "<<codigoProvedor<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Correo: "<<correo<<endl;
                cout<<"Telefono: "<<telefono<<endl;
                cout<<"Provedor: "<<direccion<<endl;
                cout<<"\n\n";
            }

            getline(mostrar,codigoProvedor);
        }

        if(encontrado==false)
        {
            cout<<"\n\nNo se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else
    {
        error();
    }

    mostrar.close();
    pausa();
}



void menu_o::modificarProvedor()
{
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxNombre;
    string auxCorreo;
    string auxTelefono;
    string auxDireccion;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("provedores.txt",ios::in);
    verificador.open("provedores.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\t\t\t\t***Modificar los datos de un Provedor***\t\t\t\t\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<"Ingresa el c\242digo del Provedor que deseas modificar: ";
        getline(cin,auxCodigo);

        if(auxCodigo=="")
        {
            do
            {
                cout<<"c\242digo de Provedor no v\240lido!, intentalo nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }

        codigoModif=auxCodigo;

        getline(lectura,codigoProvedor);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,correo);
            getline(lectura,telefono);
            getline(lectura,direccion);

            if(auxCodigo==codigoProvedor)
            {
                encontrado=true;
                mostarRegistro_o(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el Provedor\n\n";
                fflush(stdin);
                cout<<"Ingresa el c\242digo del Provedor: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(auxCodigo==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigoProvedor);
                        while(!verificador.eof())
                        {
                            getline(verificador,nombre);
                            getline(verificador,correo);
                            getline(verificador,telefono);
                            getline(verificador,direccion);

                            if(auxCodigo==codigoProvedor)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un Provedor con ese c\242digo!\n\n";
                                cout<<"El Provedor con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin,auxCodigo);

                                if(auxCodigo=="")
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de Provedor no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }

                            getline(verificador,codigoProvedor);
                        }

                        if(verificador.eof()&&auxCodigo!=codigoProvedor)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un Provedor***\n\n";
                cout<<"Ingresa el c\242digo del Provedor que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro_o(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el Provedor\n\n";
                cout<<"Ingresa el c\242digo del Provedor: ";
                cout<<auxCodigo;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del Provedor: ";
                getline(cin,auxNombre);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa la correo del Provedor: ";
                getline(cin,auxCorreo);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el telefono del Provedor: ";
                getline(cin,auxTelefono);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el direccion de el Provedor: ";
                getline(cin,auxDireccion);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxNombre<<"\n"<<auxCorreo<<"\n"<<auxTelefono
                        <<"\n"<<auxDireccion<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<codigoProvedor<<"\n"<<nombre<<"\n"<<correo<<"\n"<<telefono
                        <<"\n"<<direccion<<"\n";
            }


            getline(lectura,codigoProvedor);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("provedores.txt");
    rename("auxiliar.txt","provedores.txt");
    pausa();
}

void menu_o::listarProvedors()
{
    int i=0;
    ifstream lectura;
    lectura.open("provedores.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\t\t***Listado de todos los Provedors***\t\t\t\t\n\n";
        getline(lectura,codigoProvedor);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,nombre);
            getline(lectura,correo);
            getline(lectura,telefono);
            getline(lectura,direccion);
            cout<<"C\242digo: "<<codigoProvedor<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Correo: "<<correo<<endl;
            cout<<"Telefono: "<<telefono<<endl;
            cout<<"Provedor: "<<direccion<<endl;
            cout<<"\n\n";
            getline(lectura,codigoProvedor);
        }

        if(i==1)
            cout<<"Hay un solo Provedor no manchen pongan mas huebones\n\n";

        else

            cout<<"Hay un total de "<<i<<" provedores registrados en esta ferreteria vergota\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}




void error()
{
    cout<<"No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en\n";
    cout<<"la misma ubicaci\242n que el programa o que el archivo de texto se llame: \n";
    cout<<"provedores.txt, si el archivo tiene otro nombre ren\242mbrelo al ya mencionado\n\n";
}

void menu_o::mostarRegistro_o(string codigo)
{

    ifstream mostrar;
    mostrar.open("provedores.txt",ios::in);
    getline(mostrar,codigoProvedor);
    while(!mostrar.eof())
    {
        getline(mostrar,nombre);
        getline(mostrar,correo);
        getline(mostrar,telefono);
        getline(mostrar,direccion);

        if(codigo==codigoProvedor)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"C\242digo: "<<codigoProvedor<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Correo: "<<correo<<endl;
            cout<<"Telefono: "<<telefono<<endl;
            cout<<"Provedor: "<<direccion<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,codigoProvedor);
    }

    mostrar.close();
}




void menu_p::mostarRegistro_p(string codigo)
{

    ifstream mostrar;
    mostrar.open("clientes.txt",ios::in);
    getline(mostrar,codigoProducto);
    while(!mostrar.eof())
    {
        getline(mostrar,nombre);
        getline(mostrar,marca);
        getline(mostrar,precio);
        getline(mostrar,provedor);

        if(codigo==codigoProducto)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"C\242digo: "<<codigoProducto<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Marca: "<<marca<<endl;
            cout<<"Precio: "<<precio<<endl;
            cout<<"Provedor: "<<provedor<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,codigoProducto);
    }

    mostrar.close();
}
class menu_vergas: public menu_p, public menu_o
{
	public:
		void menuPrincipal();
};


void menu_vergas::menuPrincipal()
{
	int opcion;
    do
    {	
		system(CLEAR);
        cout<<"\t\t\t\t***Ferreteria***\t\t\t\t\n\n";
        cout<<"1. Menu producto\n\n";
        cout<<"2. Menu provedores\n\n";
        cout<<"4. Comprar\n\n";
        cout<<"5. Proximamente dildo maker\n\n";
        
        cout<<"6. Salir\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            menuPrincipal_p();
            break;

        case 2:
            menuPrincipal_o();
            break;

        case 4:
        system(CLEAR);
        do
		{
		
        cout<<"\t\t\t\t***Comprar***\t\t\t\t\n\n";
        cout<<"1. Agregar producto\n\n";
        cout<<"2. Comprar \n\n";
        cout<<"3. Limpiar carrito\n\n";
        cout<<"4. Mostrar carrito\n\n";
        cout<<"0. Regresar\n\n";
        cout<<"Opci\242n: ";
        cin>>opcion;
        switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
        	 system(CLEAR);
            compraProducto();
            break;

        case 2:
        	 system(CLEAR);
            comprar();
            break;

        case 3:
        	 system(CLEAR);
        	borrarCarrito();
        	break;
        case 4:
        	 system(CLEAR);
        	listarCarrito();
        	break;
        case 0:
        	break;
        }
        
    	}while(opcion!=0);
            break;

        case 5:
            cout<<"enfermo"<<endl;
            break;

        case 6:
            break;
    	}
    }
    while(opcion!=6);
}  



int main()
{
    system ("color f0");
    menu_vergas inicio;
    inicio.menuPrincipal();
    return 0;
}
