// =================================================================
//
// File: main.cpp
// Author: Hossue E. Ceja Cartagena & Carlos Hernández Arciniega
// Date: 11/09/2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	int n; //Tamaño del VectorR
	string prefix; //Variable donde se va a almacenar el prefijo
    
	ifstream inputFile; 
	ofstream outputFile;

	//Restricción de Ejecución
	if (argc != 3){
		string formatoRequerido;
		formatoRequerido = "Se requiere el siguiente formato de ejecución: .\app inputFile.txt outputFile.txt";

		cout<<"Error en el formato de ejecución"<<endl;
		cout<< formatoRequerido<<endl;

		return -1;
	}

    inputFile.open(argv[1]); //Abrimos el archivo de entrada
	inputFile >> n; //Asignamos el número de barcos a la variable n

	//Restricción de apertura de archivo
	if(!inputFile.is_open()){
		cout<<argv[1]<<"El archivo no existe"<<endl;

		return -1;
	}

	//Creamos vector con n espacios
	vector <string> barcos;



	//Por cada vez que nuestro iterador sea menor al número de barcos vamos a ingresarlo al vector 
	/*for (int i = 0; i < n; i++){
		inputFile.barcos[i];
	
	}*/


	//Sección del prefijo
	/*inputFile.open(argv[2]); //Obtengo el prefix
	inputFile>>prefix; //Guardo el prefijo en una variable*/


	//Se requiere recorrer nuevamente el vector para hacer la comparación con lo que hay en prefix. En caso de que lo encuentre lo agrega a un nuevo vector
	/*for (int i = 0; i < n; i++){
		if (prefix == )

		cin>> barcosSelect[i];
	}*/

	system("pause");
	return 0; //Finalizamos ejecución del programa
}
