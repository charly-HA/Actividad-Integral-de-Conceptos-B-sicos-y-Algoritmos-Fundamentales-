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
#include "funcionesExtra.h"
#include <string.h>
#include "selectionSort.h"
#include <stdlib.h>
#include "header.h"

using namespace std;

int main(int argc, char* argv[]){

    
	ifstream inputFile; 
	ofstream outputFile;

	vector <char*> Fecha; //Vector donde almaceno la fecha
	vector <char*> Hora; //Vector donde almaceno la hora
	vector<char*> Mar; //Vector donde almaceno el mar
	vector<char*> Identificador; //Vector donde almaceno el identificador del barco
	vector<char*> UBI; //Vector donde almaceno el prefijo
	vector<float> Tiempo; 

	//Restricción de Ejecución
	if (argc != 3){
		string formatoRequerido;
		formatoRequerido = "Se requiere el siguiente formato de ejecución: .\app inputFile.txt outputFile.txt";

		cout<<"Error en el formato de ejecución"<<endl;
		cout<< formatoRequerido<<endl;

		return -1;
	}

    inputFile.open(argv[1]); //Abrimos el archivo de entrada

	//Restricción de apertura de archivo
	if(!inputFile.is_open()){
		cout<<argv[1]<<"El archivo no existe"<<endl;

		return -1;
	}
	outputFile.open(argv[2]);

	int barcos; //Número de barcos a almacenar
	char* UBI_buscada = new char[3]; //Variable para el prefijo

	inputFile>>barcos>>UBI_buscada;

	Fecha.resize(barcos); //Inicializo el vector Fecha
	Hora.resize(barcos); //Inicializco el vector Hora
	Mar.resize(barcos); //Inicializo el vector Mar
	Identificador.resize(barcos); //Inicializo el vector identificador

	for(int i = 0; i < barcos; i++){
		Fecha[i] = new char[8]; //Que me tome la cadena de 8 caracteres
		Hora[i] = new char[5]; //Que me tome la cadena de 5 caracteres
		Mar[i] = new char [1]; //Que me tome la cadena de un caracter
		Identificador[i] = new char[5]; //Que me tome la cadena de 5 caracteres
		UBI.resize(i + 1); 
		UBI[i] = new char[3]; //UBI es mi vector de prefijos. Que me tome los prefijos

		inputFile >> Fecha[i] >> Hora[i] >> Mar[i] >> Identificador[i]; //Extraigo la cadena

		subcadena(Identificador[i], 0, 3, UBI[i]);
	}

	//Creamos vectores para filtrar los barcos con el prefijo indicado
	vector<char*> _Fecha;
	vector<char*> _Hora;
	vector<char*> _Mar;
	vector<char*> _Identificador;

	for(int i = 0; i < barcos; i++){

		//Compara si las cadenas son iguales
		if(strcmp(UBI[i], UBI_buscada) == 0){
			_Fecha.push_back(Fecha[i]); //La manda al final del vector Fecha
			_Hora.push_back(Hora[i]); //La manda al final del vector Hora
			_Mar.push_back(Mar[i]); //La manda al final del vector Mar
			_Identificador.push_back(Identificador[i]); //La manda al final del vector Identificador
		}
	}

	float _tiempo;
	Tiempo.resize(_Fecha.size());

	for(int i = 0; i < Tiempo.size(); i++){
		_tiempo = fecha_a_flotante(_Fecha, i) + hora_a_flotante(_Hora, i); //_tiempo almacena los días y con la formula obtenemos el total de días
		Tiempo[i] = _tiempo; //Almaceno en mi vector Tiempo
	}

	selectionSort(Tiempo, _Fecha, _Hora, _Mar, _Identificador);


	//Imprimimos todos los vectores con el formato deseado y lo mandamos al archivo de salida
	for(int i = 0; i < Tiempo.size(); i++){
		outputFile << _Fecha[i] << " "<< _Hora[i] << " "<< _Mar[i]<<" "<< _Identificador[i]<<endl;
	}

	//Cerramos Archivos
	outputFile.close();
	inputFile.close();

	system("pause");
	return 0; //Finalizamos ejecución del programa
}