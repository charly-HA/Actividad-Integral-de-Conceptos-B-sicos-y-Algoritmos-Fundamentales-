// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream input;
	ofstream output;
	if (argc != 3){
		cout << "Error";
		return -1;
	}
	input.open(argv[1]);
	if(!input.is_open()){
		cout << "El archivo no existe";
		return -1;
	}
	output.open(argv[2]);
    int nb;
	input>>nb;
	string ID;
	input>>ID;
	
	return 0;
}
