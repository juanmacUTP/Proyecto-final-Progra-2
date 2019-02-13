#include <iostream>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


struct Usuario {
	char usuario[20];
	char contrasena[10];
};


struct Registro {
	char nombre[40];
	char cedula[15];
	struct Usuario usuarios;
};

struct habitacion {
	int id_hab;
	char clasificacion[30];
	bool libre;
};

struct  ciudad_hot{
	char ciudad[20];
	char direccion[25];
};


struct Hoteles{
	char nit[15];
	char nombre[40];
	int valoracion;
	int n_habt;
	struct ciudad_hot ciudad_h;
	struct habitacion habitac;
	
};

FILE *archi1;
FILE *archi2;


void registrar(Registro registros);
void inic_sesion(Registro registros);
void menu_admin();
void menu_clien();
bool validarregistro(char cedula[],Registro registros);



int main() {
	int opc;
	Registro registros;
	Usuario usuarios;
	Hoteles hotel;
	
	do{
		system("cls");
		cout<<"1. Registrar"<<endl;
		cout<<"2. Iniciar Sesion"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: "; cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				registrar(registros);
				break;
			case 2:
				inic_sesion(registros);
				break;	
		}
	}while(opc<3);
	
	return 0;
}


void registrar(Registro registros){
	system("cls");
	
	archi1 = fopen("e:/U/Progra 2/Proyecto final/registro usuarios.txt","at+");
	
	char cedula[15];
	cout<<"Digite la cedula: "; cin.getline(cedula,15,'\n'); fflush(stdin);
	
	if(validarregistro(cedula,registros) == 0){
	 
	cout<<"Digite su nombre: "; cin.getline(registros.nombre,40,'\n'); fflush(stdin);
	cout<<"Digite el usuario que va a utilizar: "; cin.getline(registros.usuarios.usuario,20,'\n'); fflush(stdin);
	cout<<"Digite la contrasena que va a utilizar (no mas de 10 caracteres): "; cin.getline(registros.usuarios.contrasena,10,'\n');
	strcpy(registros.cedula,cedula);
	fwrite(&registros,sizeof(Registro),1,archi1);
	cout<<"\t== Usuario Registrado! =="<<endl;
	system("pause");
	}
	else{
		cout<<"==Usuario ya registrado=="<<endl;
	}
	
	
	
	fclose(archi1);
}

void inic_sesion(Registro registros){
	system("cls");
	
	archi1  = fopen("e:/U/Progra 2/Proyecto final/registro usuarios.txt","at+");
	char cade[]="admin";
	char usua[20],clave[20];
	bool band = true;
	cout<<"Usuario: "; cin.getline(usua,20,'\n'); fflush(stdin);
	cout<<"Contrasena: "; cin.getline(clave,20,'\n'); fflush(stdin);
	system("cls");
	
	while(fread(&registros,sizeof(Registro),1,archi1)==1){
		if(strcmp(usua,registros.usuarios.usuario)== 0 && strcmp(clave,registros.usuarios.contrasena)== 0){
			cout<<"==Ha ingresado correctamente=="<<endl;
			system("pause");
			system("cls");
			band = true;
			break;
		}else{
			band = false;
		}
		
	}
	if(band == false){
		cout<<"Contrasena o usuario incorrectos. O usuario no registrado "<<endl;
	}
		if(band = true){
			if(strcmp(usua,cade)==0){
					menu_admin();
				}else{
					menu_clien();
				}
			}
		
	fclose(archi1);
	system("pause");
}


void menu_admin(){
	int opc;
	Hoteles hotel;
	system("cls");
		do{
		cout<<"1. Registrar Hotel"<<endl;
		cout<<"2. Generar Factura"<<endl;
		cout<<"3"<<endl;
		cout<<"opcion: "; cin>>opc; fflush(stdin);
		//switch(opc){
		//	case 1
		
	}while(opc < 3);
}

void menu_clien(){
	system("cls");
	cout<<"en proceso";
	system("pause");
}

bool validarregistro(char cedula[], Registro registros){
	
	archi1 = fopen("e:/U/Progra 2/Proyecto final/registro usuarios.txt","at+");
		
	while(fread(&registros,sizeof(Registro),1,archi1)==1){
		if(strcmp(registros.cedula,cedula)==0){
			return 1;
			//break;
		}else{
			return 0;
		}
	}
	fclose(archi1);
}
