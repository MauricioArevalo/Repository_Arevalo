#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  
	typedef struct nodo{
		int dato;
		struct nodo* siguiente;       
	}nodo;
	
	nodo*primero = NULL;
	
	void insertarNodo();
	void desplegarPila();
	void eliminar();
	
	
	int main() {
		
		int op,salir,i;
		
		do{
	     system ("cls");	
		printf ("\n-------Menu-------\n 1. Insertar\n 2. Eliminar\n 3. Ver tope\n 4. Salir\n\n");	
		scanf ("%i",&op);		
		
		switch (op) {			
		case 1:		
		system ("cls");
		insertarNodo();
		insertarNodo();
		insertarNodo();
		insertarNodo();	
	     desplegarPila();
	     system("pause");	
	     break;
		
		case 2:
	     system ("cls");
		desplegarPila();
		printf("\n\n");	
		eliminar ();
		desplegarPila();
	     system("pause");	
	     break;
	     
	     case 3:
		system ("cls");
		desplegarPila();
		for(i=3;i>0;i--){
		printf("\nDel valor %i, su tope es: %i\n",i,i-1);	
		}

	     system("pause");
		break;
		
		case 4:	
		printf("Bye");
	}
	}while(op != 4);
		return 0;
	}
	
	void insertarNodo(){
		nodo* nuevo = (nodo*) malloc(sizeof(nodo));
		printf("\nIngresa un valor \n ");
		
		scanf("%i",&nuevo->dato);
		
		nuevo->siguiente = primero;
		primero = nuevo;
	     
		
	}
	
	void desplegarPila(){
		nodo* actual = (nodo*) malloc(sizeof(nodo));
		actual = primero;
		
		if(primero!=NULL){
			printf("\nTu pila tiene estos valores: \n");
			
			while(actual!=NULL){
				
				printf("\n %i",actual->dato);
				
				actual = actual->siguiente;
				
			}
		}else{
			printf("\n La pila esta vacia");
			
		}
		
	}
	
	void eliminar (){
		nodo* actual=(nodo*) malloc(sizeof(nodo));
		actual=primero;
		nodo* anterior=(nodo*) malloc(sizeof(nodo));
		anterior=NULL;
		int nodobuscado =0, encontrado =0;
		printf("\n Ingresa el valor a eliminar\n");
		scanf("%i",&nodobuscado);
		if(primero!=NULL){
			while(actual!=NULL&&encontrado!=1){
				if(actual->dato==nodobuscado){
				
				if(actual==primero){
					primero=primero->siguiente;
					}else{
						anterior->siguiente=actual->siguiente;
						}
			printf("\n El valor se ha eliminado\n");
			encontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
			}
			if(encontrado==0){
			printf("\n Valor no encontrado\n");	
			}else{
				free(anterior);
		}
			}else{
			printf("\n La pila se encuentra vacia\n");	
			}
		}
