#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std; 

int n,t,i,j,x;
bool b;

int Burbuja();//ya	
int BurbujaMej();//ya
int Insercion();//ya
int Seleccion();//ya
int QuickSort();//ya
int Secuencial();//ya
int Binario();//ya
int BucketSort();//ya

void quicksort( int *array, int inicio, int fin);
int binary_search(int *array, int searched, int arraySize);
void bucketSort(int *arr, int size);



main(){
	int sel;
	do{
		cout<<"METODOS DE ORDENAMIENTO \n";
		cout<<"1-------------Burbuja\n2----------------Burbuja mejorado\n3-----------------Insercion\n4--------------------Seleccion\n5-----------------QuickSort\n6---------------Secuencial\n7----------------Binario\n8----------------Bucket\n0---------------Salir\n";
		cin>>sel;
		system("cls");
		
		
		switch(sel){
			case 1:
				Burbuja();
				break;
			case 2:
				BurbujaMej();
				break;
			case 3:
				Insercion();
				break;
			case 4:
				Seleccion();
				getch();
				system("cls");
				break;
			case 5:
				QuickSort();
				getch();
				system("cls");
				break;
			case 6:
				Secuencial();
				getch();
				system("cls");
				break;
			case 7:
				Binario();
				getch();
				system("cls");
				break;
				
			case 8:
				BucketSort();
				getch();
				system("cls");
				break;

			case 0:
				printf("Bye");
				getch();
				break;
			default:
				cout<<"Opcion no valida";
				getch();
				system("pause");
		}
	}while(sel!=8);
}

Burbuja(){ //DONE
	printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	system("cls");
	
	printf("Metodo de burbuja:\n");
				for(i=1;i<n;i++){
					for(j=0;j<n-i;j++){
						if(arre[j]>arre[j+1]){
							t=arre[j+1];
							arre[j+1]=arre[j];
							arre[j]=t;
						
						}
				
					}

					for(x=0;x<n;x++){
					printf(" %d ",arre[x]);
					}
					cout<<endl;
				}
				for(i=0;i<n;i++){
					printf("Valor #%d: %d\n",i+1,arre[i]);
					}
				getch();
				system("cls");
				return 0;
}


BurbujaMej(){//DONE
	printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];

	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	system("cls");
	
	printf("Metodo de burbuja mejorado:\n");
				
				for(i=1;i<n;i++){
					b=false;
					for(j=0;j<n-i;j++){
						if(arre[j]>arre[j+1]){
							t=arre[j+1];
							arre[j+1]=arre[j];
							arre[j]=t;
							b=true;
						}
					}
					if(b==false){
						break;
					}
					for(x=0;x<n;x++){
					printf(" %d ",arre[x]);
					}
					cout<<endl;
				}
				for(i=0;i<n;i++){
					printf("Valor #%d: %d\n",i+1,arre[i]);
					}
				getch();
				system("cls");
				return 0;
}


Insercion(){//DONE
	int Act;
	printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	system("cls");
	
	for(i=0;i<n;i++){
		Act=i;
		t=arre[i];
		while(Act>0&&t<arre[Act-1]){
			arre[Act]=arre[Act-1];
			Act--;
		}
		arre[Act]=t;
			for(x=0;x<n;x++){
					printf(" %d ",arre[x]);
					}
					cout<<endl;
	}
	
	for(i=0;i<n;i++){
			printf("Valor #%d: %d\n",i+1,arre[i]);
		}
	getch();
	system("cls");
	return 0;
}


Seleccion(){//DONE
	int menor=0;
	printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	system("cls");
	
	printf("Metodo de seleccion:\n");
	for(i=0;i<n-1;i++){
		menor=i;
		for(j=i+1;j<n;j++){
			if(arre[menor]>arre[j]){
				menor=j;
			}
		}
		t=arre[menor];
		arre[menor]=arre[i];
		arre[i]=t;
			for(x=0;x<n;x++){
					printf(" %d ",arre[x]);
					}
					cout<<endl;
	}
	
	for(i=0;i<n;i++){
			printf("Valor #%d: %d\n",i+1,arre[i]);
		}
	getch();
	system("cls");
	return 0;	
}


QuickSort(){//NOPE
	printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	system("cls");

quicksort (arre,0,n-1);
		for(x=0;x<n;x++){
			printf("Valor #%d: %d\n",x+1,arre[x]);
		}
	
	getch();
	system("cls");
	return 0;	
	
};

int dividir(int *array, int inicio, int fin){


  int izq;
  int der;
  int pibote;
  int temp;

  pibote = array[inicio];
  izq = inicio;
  der = fin;

  //Mientras no se cruzen los índices
  while (izq < der){
    while (array[der] > pibote){
	  der--;
    }

	while ((izq < der) && (array[izq] <= pibote)){
      izq++;
    }

    // Si todavia no se cruzan los indices seguimos intercambiando
	if(izq < der){
      temp= array[izq];
      array[izq] = array[der];
      array[der] = temp;
    }
  }

  //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
  temp = array[der];
  array[der] = array[inicio];
  array[inicio] = temp;

  //La nueva posición del pivote
  return der;
}

void quicksort(int *array, int inicio, int fin){

  int pivote;
  if(inicio < fin)
  {
    pivote = dividir(array, inicio, fin );
    quicksort( array, inicio, pivote - 1 );//ordeno la lista de los menores
    quicksort( array, pivote + 1, fin );//ordeno la lista de los mayores
  }
}


Secuencial(){ //DONE
	printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	int bus;
	int pos;
	int f =0;
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	
		printf("Que valor deseas buscar?\n");
	scanf("%d",&bus);
	system("cls");
	
	printf("Busqueda secuencial:\n");
		for(x=0;x<n;x++){
			if(arre[x]==bus){
			printf("Valor #%d: %d !ENCONTRADO! \n",x+1,arre[x]);
			
				pos = x+1;
				
				f = 1; 
				break;
				
			}
			else{				
				printf("Valor #%d: %d\n ",x+1,arre[x]);				
			}
			}	
				if( f == 1){
						printf("El valor %d existe y se encuentra en la pos # %d ",bus,pos);			
				}	
				else{	
					printf("El valor no existe");
				}
				getch();
				system("cls");
				return 0;
}


Binario(){ //done
		printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	int bus;
	int pos;
	int f =0;
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
		system("cls");
		quicksort(arre,0,n-1);
		cout<<"se reacomodo el arreglo : "<<endl; 
			for(x=0;x<n;x++){
			printf("Valor #%d: %d\n",x+1,arre[x]);
		}
		
	
		printf("Que valor deseas buscar?\n");
	scanf("%d",&bus);
	system("cls");
	

	binary_search(arre,bus,n);
	
	
	
	
	
}

int binary_search(int *array, int searched, int arraySize){
    int first = 0;
    int middle;
    int last = arraySize - 1;
 
    while (first <= last) {
        middle = (first + last) / 2;
 
        if (searched == array[middle]) {
            cout << "Se encuentra en la posicion " << middle + 1 << endl;
            return array[middle];
        } else {
            if (array[middle] > searched) {
                last = middle - 1;
            } else {
                first = middle + 1;
            }
        }
    }
    cout<< "no se encontro"<<endl;
    return -1;
}


BucketSort(){//DONE
		printf("Cuantos numeros quieres ingresar?\n");
	scanf("%d",&n);
	int arre[n];
	for(i=0;i<n;i++){
		printf("Ingresa el valor #%d: ",i+1);
		scanf("%d",&arre[i]);
	}
	system("cls");

bucketSort(arre,n);
		for(x=0;x<n;x++){
			printf("Valor #%d: %d\n",x+1,arre[x]);
		}
	
	getch();
	system("cls");
	return 0;
	
	
}

void bucketSort(int *arr, int size) {
  //variables
  int max=0, bucket = 10, divider, i, j, k,z;
  
  //10 buckets
 vector<float> B[bucket];

  //find max and min
  for(z=0; z< size ; z++){
	if(arr[z]>max){
		max=arr[z];
	}
}
  divider = ceil(float(max + 1) / bucket);
  
  //insert element into bucket
  for(i = 0; i < size; i++) {
    j = floor( arr[i] / divider );
    B[j].push_back(arr[i]);
  }
  
  //sort elements in the buckets
  for(i = 0; i < bucket; i++) {
    sort(B[i].begin(), B[i].end());
  }

  //append back the elements from the buckets
  k = 0;
  for(i = 0; i < bucket; i++) {
    for(j = 0; j < B[i].size(); j++) {
      arr[k++] = B[i][j];
    }
  }
}




