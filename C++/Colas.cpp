
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include "iostream" 

using namespace std;

struct Cliente{
	public: string nombre;
	public: string apellido;
	public: string rfc;
	public: string domicilio;
};

class Cuenta{
	public: int numero;
	public: float saldo;
	public: string banco;
	public: Cliente user;
	public: Cuenta *sig;
	
	//Constructor
	public: Cuenta(){
		
	}
	
	public: void setNom(string nom){
		this->user.nombre=nom;
	}
	
	public: string getNom(){
		return this->user.nombre;
	}
	
	public: void setApe(string ape){
		this->user.apellido=ape;
	}
	
	public: string getApe(){
		return this->user.apellido;
	}
	
	public: void setRFC(string r){
		this->user.rfc=r;
	}
	
	public: string getRFC(){
		return this->user.rfc;
	}
	
	public: void setDom(string dom){
		this->user.domicilio=dom;
	}
	
	public: string getDom(){
		return this->user.domicilio;
	}
	
	public: void setNum(int n){
		this->numero=n;
	}
	
	public: int getNum(){
		return this->numero;
	}
	
	public: void setSal(float s){
		this->saldo=s;
	}
	
	public: float getSal(){
		return this->saldo;
	}
	
	public: void setBan(string b){
		this->banco=b;
	}
	
	public: string getBan(){
		return this->banco;
	}
	//set y get para obtencion de datos
	
	public: void capturar(){
		string auxi;
		int numaux;
		float salaux;
		
		cout << "Nombre: ";
		getline(cin,auxi);
		this->setNom(auxi);
		fflush(stdin);
		
		cout << "Apellido: ";
		getline(cin,auxi);
		this->setApe(auxi);
		fflush(stdin);
		
		cout << "RFC: ";
		getline(cin,auxi);
		this->setRFC(auxi);
		fflush(stdin);
		
		cout << "Domicilio: ";
		getline(cin,auxi);
		this->setDom(auxi);
		fflush(stdin);
		
		cout << "Numero de cuenta: ";
		cin>>numaux;
		this->setNum(numaux);
		fflush(stdin);
		
		cout << "Salario: ";
		cin>>salaux;
		this->setSal(salaux);
		fflush(stdin);
		
		cout << "Banco: ";
		getline(cin,auxi);
		this->setBan(auxi);
		fflush(stdin);
	}
	
	
	public: void imprimir(){
		cout << "Nombre: "<<this->getNom()<<endl;
		fflush(stdin);
			
		cout << "Apellido: "<<this->getApe()<<endl;
		fflush(stdin);
			
		cout << "RFC: "<<this->getRFC()<<endl;
		fflush(stdin);
		
		cout << "Domicilio: "<<this->getDom()<<endl;
		fflush(stdin);
			
		cout << "Numero: "<<this->getNum()<<endl;
		fflush(stdin);
			
		cout << "Saldo: "<<this->getSal()<<endl;
		fflush(stdin);
		
		cout << "Banco: "<<this->getBan()<<endl;
		fflush(stdin);
	}
	
	public: void editar(){
		int opc;
		string auxi;
		int numaux;
		float salaux;
		do{	
			system("CLS");
			cout<<"Opcion de editar"<<endl<<"Cliente: "<<this->getNom()<<endl;
			cout<<"1.-Nombre\n";
			cout<<"2.-Apellido\n";
			cout<<"3.-RFC\n";
			cout<<"4.-Domicilio\n";
			cout<<"5.-Numero de cuenta\n";
			cout<<"6.-Saldo\n";
			cout<<"7.-Banco\n";
			cout<<"8.-Regresar\n";
			cin>>opc;
			fflush(stdin);
			system("CLS");
			switch(opc){
				case '1':
					cout << "Nombre: "<<this->getNom()<<endl;		
					cout << "Nombre nuevo: ";
					getline(cin,auxi);
					this->setNom(auxi);
					cout<<endl;
					fflush(stdin);
					break;
				
				case '2':
					cout << "Apellido: "<<this->getApe()<<endl;		
					cout << "Apellido nuevo: ";
					getline(cin,auxi);
					this->setApe(auxi);
					cout<<endl;
					fflush(stdin);
					break;
				
				case '3':
					cout << "RFC: "<<this->getRFC()<<endl;		
					cout << "RFC nuevo: ";
					getline(cin,auxi);
					this->setRFC(auxi);
					cout<<endl;
					fflush(stdin);
					break;
					
				case '4':
					cout << "Domicilio: "<<this->getDom()<<endl;		
					cout << "Domicilio nuevo: ";
					getline(cin,auxi);
					this->setDom(auxi);
					cout<<endl;
					fflush(stdin);
					break;
				
				case '5':
					cout << "Numero: "<<this->getNum()<<endl;		
					cout << "Numero nuevo: ";
					cin >> numaux;
					this->setNum(numaux);
					cout<<endl;
					fflush(stdin);
					break;
				
				case '6':
					cout << "Saldo: "<<this->getSal()<<endl;		
					cout << "Saldo nuevo: ";
					cin >> salaux;
					this->setSal(numaux);
					cout<<endl;
					fflush(stdin);
					break;
				
				case '7':
					cout << "Banco: "<<this->getBan()<<endl;		
					cout << "Banco nuevo: ";
					getline(cin,auxi);
					this->setBan(auxi);
					cout<<endl;
					fflush(stdin);
					break;
				
				case '8':
					cout<<"Volviendo\n"<<endl;
					break;
					
				default:
					cout<<"Opcion invalida\n"<<endl;
					break;
			}
		}while(opc != '8');
	}
};

class Cola{
	private: Cuenta *cola;
	
	public: Cola(){
		cola = NULL;
	}
	
	public: void Encolar(){
		Cuenta *nuevo = new Cuenta();
		
		nuevo->capturar();
		nuevo->sig = NULL;
		
		if(cola == NULL){
			cola = nuevo;
		}
		else{
			Cuenta *aux = cola;
			while(aux->sig != NULL){
				aux = aux->sig;
			}
			aux->sig = nuevo;
		}
	}
	
	public: void Desencolar(){
		Cuenta *aux = cola, *ant=NULL;
		if(aux->sig != NULL){
			ant = aux->sig;
		}
		free(aux);
		cola = ant;
		cout<<"Eliminado\n"<<endl;
	}
	
	public: void Recorrer(){
		Cuenta *aux = cola;
		if(aux != NULL){
			while(aux != NULL){
				aux->imprimir();
				cout<<endl<<endl;
				aux=aux->sig;
			}
		}
		else{
			cout<<"Vacia...\n"<<endl;
		}
	}
	
	public: void Buscar(){
		bool b=false;
		string auxi;
		cout<<"Ingrese el nombre: ";
		getline(cin,auxi);
		fflush(stdin);
		Cuenta *aux = cola;
		while(aux != NULL){
			if(aux->getNom() == auxi){
				aux->editar();
				b = true;
			}
			aux=aux->sig;
		}
		if(!b){
			cout<<"No se encontro\n"<<endl;
		}
	}
};

int main(void){
	Cola *c = new Cola(); 
	int opc;
	do{
		system("CLS");
		cout<<"********** COLAS ************\n";
		cout<<"1.-Encolar\n";
		cout<<"2.-Desencolar\n";
		cout<<"3.-Recorrer cola de espera\n";
		cout<<"4.-Buscar\n";
		cout<<"5.-Salir\n"; 
		cin>>opc;
		fflush(stdin);
		system("CLS");
		switch(opc){
			case 1:
				c->Encolar();
				break;
			
			case 2:
				c->Desencolar();
				break;
			
			case 3:
				c->Recorrer();
				break;			
			
			case 4:
				c->Buscar();
				break;
			
			case 5:
				cout<<"Fin del Programa\n"<<endl;
				break;
				
		}
		system("PAUSE");
	}while(opc!='5');
	return 0;
}
