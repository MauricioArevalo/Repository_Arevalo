	
	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
	
	typedef struct nodo{
		int dato;
		struct nodo* siguente; 
	}nodo;
	
	nodo* primero=NULL;
	nodo* ultimo=NULL;
	
	void menu();
	void insertar();
	void desplegar();
	void buscarNodo();
	void eliminar();
	
	int main() {
		int eleccion, respuesta, salir;
	
		do{
		menu();
		scanf("%d",&eleccion);
		
			switch (eleccion) {
				
				case 1: 
					insertar();		
				break;	
				
				case 2:
					desplegar(); 
					buscarNodo();
				break;
				case 3:
					eliminar();
				break;
				case 4: 
					printf("Presione cualquier tecla para salir");
				break;
				
				default: 
					printf("\nSeleccione otra opcion\n");
				
				
				
			}
	}while(eleccion!=4);
	
		
		
		
		return 0;
	}
	
	
	void menu(){
		system("cls");
		printf("-------------Menu---------\n");
		printf("1. Insertar elemento a la lista\n");
		printf("2. Consultar elemento de la lista\n");
		printf("3. Suprimir elemento de la lista\n");
		printf("4. Salir\n");
	}
	
	
	void insertar() {
		nodo* nuevo= (nodo*) malloc(sizeof(nodo)); 
		printf("\nIngrese dato de la lista\n"); 
		scanf("%d",&nuevo->dato); 
		if(primero==NULL){ 
			primero=nuevo; 
			primero->siguente=NULL;
			ultimo=nuevo;
		} else { 
			ultimo->siguente=nuevo; 
			nuevo->siguente=NULL; 
			ultimo=nuevo; 
		}
		
		printf("\nEl dato ha sido ingresado\n\n");
		system("pause");
		
	}
	
	void desplegar() {
		nodo* actual= (nodo*) malloc(sizeof(nodo)); 
		actual=primero;
		if(primero!=NULL) { 
			while (actual !=NULL){
				printf("\n %d",actual->dato); 
				actual=actual->siguente;
			}	
		} else {
			printf("\nLa lista esta vacia\n");
		}
		system("pause");
	}
	
	void buscarNodo(){
		nodo* actual= (nodo*) malloc(sizeof(nodo));
		actual = primero;
		int nodoBuscado = 0, encontrado = 0; 
		printf("\nIngrese el elemento a buscar\n"); 
		scanf("%d",&nodoBuscado);
		if(primero!=NULL) { 
			while (actual != NULL && encontrado !=1) {
				if (actual->dato == nodoBuscado) {
					printf("\nEl el dato (%d) ha sido encontrado\n", nodoBuscado);
					encontrado=1;
				}
				actual=actual->siguente;
			}
		}
		if (encontrado == 0) { 
			printf("\nNodo no encontrado\n");
		}
		system("pause");
	}
	
	void eliminar(){
		nodo* actual= (nodo*) malloc(sizeof(nodo)); 
		actual = primero;
		nodo* anterior =(nodo*) malloc(sizeof(nodo));  
		anterior= NULL; 
		int nodoBuscado = 0, encontrado = 0; 
		printf("\nIngrese el elemento a eliminar\n"); 
		scanf("%d",&nodoBuscado);
		if(primero!=NULL) { 
			while (actual != NULL && encontrado !=1) {
				if (actual->dato == nodoBuscado) {
					if(actual== primero){
						primero=primero->siguente; 	
					} else if(actual==ultimo) {
						anterior->siguente =NULL; 
						ultimo=anterior; 		
					} else {
						anterior->siguente = actual->siguente; 
					}
					printf("\n El elemento ha sido eliminado\n");
					encontrado=1;
				}
				anterior=actual; 
				actual=actual->siguente; 
			}
		}
		if (encontrado == 0) { 
			printf("\nNodo no encontrado");
		} else {
			free(anterior);
		} 
		system("pause");
	}
