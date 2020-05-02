/*Manejar codigo emp, nombre y salarios
utilice funciones
grabe datos al un archivo
sumatoria salarios
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct empleado{
	string nombre;
	string apellido;
	int codemp;
	float salario;
};
void mp();
void leer_archivo();
void grabar_archivo();
int main(){
	mp();
}

void mp(){ // menu principal
	
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Empleado "<<"\n";
		cout<<" 2 - Mostrar Empleados "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}

void grabar_archivo(){
	//variables basadas en la estructura
	string nombre_emp;
	string apellido_emp;
	int cod_emp;
	float salario_emp;
	fflush(stdin);
	cout<<"Ingrese Nombre de empleado: "<<endl;
	getline(cin,nombre_emp);
	fflush(stdin);
	cout<<"Ingrese Apellido de empleado: "<<endl;
	getline(cin,apellido_emp);
	cout<<"Ingrese Codigo de empleado: "<<endl;
	cin>>cod_emp;
	cout<<"Ingrese Salario de empleado: "<<endl;
	cin>>salario_emp;
	
	ofstream archivo; //leer archivo 
	archivo.open("empleado.txt",ios::app);
	
	//archivo.open(na.c_str(),ios::app);
	archivo<<nombre_emp<<"\t"<<apellido_emp<<"\t"<<cod_emp<<"\t"<<salario_emp<<endl;
	archivo.close();
}
void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("empleado.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	float sumatoriasalarial=0.00;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	empleado recordset[lineas];
	
	archivo.open("empleado.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        //cout<<"i: "<<i;
        archivo>>recordset[i].nombre>>recordset[i].apellido>>recordset[i].codemp>>recordset[i].salario;
    }
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].codemp<<" "<<recordset[i].nombre<<" "<<recordset[i].apellido<<" "<<recordset[i].salario<<endl;
    	sumatoriasalarial+=recordset[i].salario;
	}
	cout<<"Sumatorial total: "<<sumatoriasalarial;
	system("PAUSE");
}
