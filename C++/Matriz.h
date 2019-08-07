#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std; 
	int tam_x,tam_y;
class Matriz {


	public: 
		float x[3][3],y[3][3],z[3][3]; 
	
	void mostrar_x();
	void llenar_x();
	void mostrar_y();
	void llenar_y();
	void mostrar_z();
	

};

void Matriz :: llenar_x(){
	
	int s,t;
	
	
	cout<<"Que tamaño sera tu matriz?\n 1. 2x2 \n 2. 3x3\n"; 
	cin>>t; 
	switch(t){
		case 1: 
		tam_x= 2;
	
		for(s=1;s<=2;s++){
			for(t=1;t<=2;t++){
				cout<<"introduce A "<<s<<t<<" : ";
				cin>>x[s][t];
			}
		}
		break;
		
		case 2:
			tam_x= 3;
		
			for(s=1;s<=3;s++){
			for(t=1;t<=3;t++){
				cout<<"introduce A "<<s<<t<<" : ";
				cin>>x[s][t];
			}
		}
		
		break; 
	}
	
}

void Matriz :: mostrar_x(){
	int s,t;
	cout<<"\tMatris X:\n";

		for(s=1;s<=tam_x;s++){
			for(t=1;t<=tam_x;t++){ 
				cout<<x[s][t]<<"  ";
			
			}
			cout<<endl;
		}
	system("pause");
}

void Matriz :: llenar_y(){
	
	int s=0,t=0;
	
	
	cout<<"Que tamaño sera tu matriz?\n 1. 2x2 \n 2. 3x3\n"; 
	cin>>t; 
	switch(t){
		case 1: 
		tam_y= 2;
	
		for(s=1;s<=2;s++){
			for(t=1;t<=2;t++){
				cout<<"introduce B "<<s<<t<<" : ";
				cin>>y[s][t];
			}
		}
		break;
		
		case 2:
			tam_y= 3;
		
			for(s=1;s<=3;s++){
			for(t=1;t<=3;t++){
				cout<<"introduce B "<<s<<t<<" : ";
				cin>>y[s][t];
			}
		}
		
		break; 
	}
	
}

void Matriz :: mostrar_y(){
	int s,t;
	cout<<"\tMatrix y:\n";

		for(s=1;s<=tam_y;s++){
			for(t=1;t<=tam_y;t++){ 
				cout<<y[s][t]<<"  ";
			
			}
			cout<<endl;
		}
	system("pause");
}

void Matriz :: mostrar_z(){
	int s,t,r;
	r= tam_x;
		for(s=1;s<=r;s++){
			for(t=1;t<=r;t++){ 
				cout<<z[s][t]<<"  ";
			
			}
			cout<<endl;
		}
	system("pause");
}

class OpMatriz: public Matriz {
	
	
	public:
		void restarM(); 
		void sumarM();
		void multiplicarM();
	//	void ppM();
	
};

class TrMatriz: public Matriz{
	
	public: 
	
		void matrizI();
		void matrizT();
	
};

class EqMatriz: public Matriz{
	
	public: 
	
		void gaussM();
};

void EqMatriz :: gaussM(){
	
	 int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
   // cout<<"\nIngrese el orden de la matriz : ";
   cout<<" resolver un problema de la forma : \n Cx + Cy + Cz = C\nCx + Cy + Cz = C\n Cx + Cy + Cz = C\n";
    n=3;
    cout<<"\nIntrodusca los elementods de la matriz aumentada : \n\n";
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
        	cout<<"A "<<i<<j<<" : ";
         	cin>>A[i][j];
           
        }
    }
    cout<<"sistema de ecuaciones : \n"
    <<"("<<A[1][1]<<")x + ("<<A[1][2]<<")y + ("<<A[1][3]<<")z"<<endl
    <<"("<<A[2][1]<<")x + ("<<A[2][2]<<")y + ("<<A[2][3]<<")z"<<endl
    <<"("<<A[3][1]<<")x + ("<<A[3][2]<<")y + ("<<A[3][3]<<")z"<<endl;
    
    
    for(j=1; j<=n; j++) /* Matriz Triangular*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    /*Sustitucion*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    cout<<"\nLa solucion es: \n";
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); 
    }
    system("pause");
		
}

void TrMatriz :: matrizT(){
	int f,c,r;
	cout<<"-----------------TRANSPUESTA DE UNA MATRIZ -------------\n";
	
	
	llenar_x();
	r = tam_x;
		mostrar_x();
		
		
		for(f=1;f<=r;f++){
			for(c=1;c<=r;c++){ 
				z[f][c]=x[c][f];
					
			}
	
		}
	
	
	cout<<"Transpuesta: \n";
mostrar_z();
}
void TrMatriz :: matrizI(){
	float det;
	int s,t,f,c;
		cout<<"-----------------INVERSA DE UNA MATRIZ----------------\n";
	
	llenar_x(); 
	
	if (tam_x == 2){
		
		det = ((x[1][1]*x[2][2])-(x[2][1]*x[1][2]));
		if (det != 0){
		cout<<"determinante : "<<det<<endl;
			
		z[1][1]=x[2][2];
		z[1][2]=(x[1][2])*-1;
		z[2][1]=(x[2][1])*-1;
		z[2][2]=x[1][1];
		for(t=1;t<=2;t++){
			for(s=1;s<=2;s++){
				z[t][s]=(z[t][s])/det; 
				
				
			}
		}
		
		cout<<"inversa :  "<<endl;
			mostrar_z();
		
		
			}else {
				
				cout<<"Determinante es 0 no tiene inversa\n";
			}
	
	}
	else{
		mostrar_x();
		det= ((x[1][1]*x[2][2]*x[3][3])+(x[1][2]*x[2][3]*x[3][1])+(x[2][1]*x[3][2]*x[1][3]))-((x[1][3]*x[2][2]*x[3][1])+(x[1][2]*x[2][1]*x[3][3])+(x[2][3]*x[3][2]*x[1][1]));
		cout<<"Determinante : "<<det<<endl;
		
		
		if(det!=0  ){
				for(f=1;f<=tam_x;f++){
			for(c=1;c<=tam_x;c++){ 
				z[f][c]=x[c][f];
					
			}
	
		}
			for(f=1;f<=tam_x;f++){
			for(c=1;c<=tam_x;c++){ 
				x[f][c]=z[f][c];
					
			}
	
		}
		
		cout<<"transpuesta :"<<endl; 
		mostrar_z();
		
		z[1][1]=(((x[2][2]*x[3][3])-(x[3][2]*x[2][3]))/det)*1;
		z[1][2]=(((x[2][1]*x[3][3])-(x[3][1]*x[2][3]))/det)*-1;
		z[1][3]=(((x[2][1]*x[3][2])-(x[3][1]*x[2][2]))/det)*1;
		
		z[2][1]=(((x[1][2]*x[3][3])-(x[3][2]*x[1][3]))/det)*-1;
		z[2][2]=(((x[1][1]*x[3][3])-(x[3][1]*x[1][3]))/det)*1;
		z[2][3]=(((x[1][1]*x[3][2])-(x[3][1]*x[1][2]))/det)*-1;
		
		z[3][1]=(((x[1][2]*x[2][3])-(x[2][2]*x[1][3]))/det)*1;
		z[3][2]=(((x[1][1]*x[2][3])-(x[2][1]*x[1][3]))/det)*-1;
		z[3][3]=(((x[1][1]*x[2][2])-(x[2][1]*x[1][2]))/det)*1;
		
		cout<<"inversa :  "<<endl; 
			mostrar_z();
			
		}else{
			cout<<"Determinante es 0 no tiene inversa\n";
			
			
		}
		
	}

	
	
}

void OpMatriz :: multiplicarM(){
	int s,t;
	
		cout<<"-----------------MULTIPLICACION DE MATRICES----------------\n";
	llenar_x();
	llenar_y();
	
	if(tam_y==2 && tam_x == 2){
		z[1][1]=(x[1][1]*y[1][1]+x[1][2]*y[2][1]);
		z[1][2]=(x[1][1]*y[1][2]+x[1][2]*y[2][2]);
		z[2][1]=(x[2][1]*y[1][1]+x[2][2]*y[2][1]);
		z[2][2]=(x[2][1]*y[1][2]+x[2][2]*y[2][2]);
		
	}
	else if(tam_y== tam_x){
	

	z[1][1]=(x[1][1]*y[1][1]+x[1][2]*y[2][1]+x[1][3]*y[3][1]);
	z[1][2]=(x[1][1]*y[1][2]+x[1][2]*y[2][2]+x[1][3]*y[3][2]);
	z[1][3]=(x[1][1]*y[1][3]+x[1][2]*y[2][3]+x[1][3]*y[3][3]);
	z[2][1]=(x[2][1]*y[1][1]+x[2][2]*y[2][1]+x[2][3]*y[3][1]);
	z[2][2]=(x[2][1]*y[1][2]+x[2][2]*y[2][2]+x[2][3]*y[3][2]);
	z[2][3]=(x[2][1]*y[1][3]+x[2][2]*y[2][3]+x[2][3]*y[3][3]);
	z[3][1]=(x[3][1]*y[1][1]+x[3][2]*y[2][1]+x[3][3]*y[3][1]);
	z[3][2]=(x[3][1]*y[1][2]+x[3][2]*y[2][2]+x[3][3]*y[3][2]);
	z[3][3]=(x[3][1]*y[1][3]+x[3][2]*y[2][3]+x[3][3]*y[3][3]);	
	}else{
		cout<<"Las matrices tienen que ser de el mismo tamaño\n";
		
	}
		cout<<"El resultado es : \n";
mostrar_z();
	
	}

void OpMatriz :: sumarM(){
	cout<<"-----------------SUMA DE MATRICES----------------\n";
	int s,t;
	llenar_x();
	llenar_y();
	if(tam_x == tam_y){
			
			for(s=1;s<=tam_y;s++){
			for(t=1;t<=tam_y;t++){ 
				z[s][t] = 0;
			}
		}
			for(s=1;s<=tam_y;s++){
			for(t=1;t<=tam_y;t++){ 
				z[s][t] = x[s][t]+y[s][t];
			}
		}
		system("cls");
		cout<<"-----------------SUMA DE MATRICES----------------\n";
		cout<<"El resultado es : \n";
		
		
mostrar_z();
		
	}else{
		cout<<"tienen que ser de el mismo tamanio\n"; 
		system("pause");
		
	}
	
}

void OpMatriz :: restarM(){
	cout<<"-----------------RESTA DE MATRICES----------------\n";
	int s,t;
	llenar_x();
	llenar_y();
	if(tam_x == tam_y){
			
			for(s=1;s<=tam_y;s++){
			for(t=1;t<=tam_y;t++){ 
				z[s][t] = 0;
			}
		}
			for(s=1;s<=tam_y;s++){
			for(t=1;t<=tam_y;t++){ 
				z[s][t] = x[s][t]-y[s][t];
			}
		}
		system("cls");
		cout<<"-----------------RESTA DE MATRICES----------------\n";
		cout<<"El resultado es : \n";
mostrar_z();
	
	}
		
	else{
		cout<<"tienen que ser de el mismo tamanio\n"; 
		system("pause");
		
	}
	
}
class Objeto: public OpMatriz, public TrMatriz , public EqMatriz{
	
	
	
};


