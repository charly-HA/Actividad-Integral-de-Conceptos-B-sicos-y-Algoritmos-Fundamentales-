#include <iostream>
#include <vector>

using namespace std;

void subcadena(char*, int, int, char*&);
float fecha_a_flotante(vector<char*>, int);
float hora_a_flotante(vector <char*>, int);


//Extrae de una cadena original la cantidad o tamaño indicado y la manda a la cadena destino
void subcadena(char* original, int inicio, int tamanio, char*& destino){
    for(int i = 0; i < tamanio; i++){
        destino[i] = original[inicio + i];
    }
    destino[tamanio] = '\0';
}

float fecha_a_flotante(vector<char*> fechas, int posicion){
    char* fecha = new char[8];
    fecha = fechas[posicion]; //Cadena de 8 caracteres

    char* dia = new char[2];
    char* mes = new char[2];
    float days, acum_dias;
    int meses;

    //Para el día solo quiero la cadena 0 y 1
    for(int i = 0; i < 2; i++){
        dia[i] = fecha[i];
    }
    dia[2] = '\0';

    for(int i = 0; i < 2; i++){
        mes[i] = fecha[i+3]; //Posicion 3
    }
    mes[2] = '\0';

    days = atof(dia); //Agarra la cadena de caracteres y la convierte a flotante
    meses = atoi(mes); //Agarra la cadena de caracteres y la convierte a enteros

    int n1 = 31, n2 = 28, n3 = 30;


    //Contando los días respecto al 1 de enero
    switch (meses)
    {
    case 1:
        acum_dias = 0; //En caso de que la fecha sea 1 de enero
        break;
    case 2:
        acum_dias = n1; //Días de enero
        break;
    case 3:
        acum_dias = n1 + n2; //Días de enero + febrero
        break;
    case 4:
        acum_dias = n1 + n2 + n1; //Días de enero + febraro + marzo
        break;
    case 5:
        acum_dias = n1 + n2 + n1 + n3;
        break;
    case 6:
        acum_dias = n1 + n2 + n1 + n3 + n1;
        break;
    case 7:
        acum_dias = n1 + n2 + n1 + n3 + n1 + n3;
        break;
    case 8:
        acum_dias = n1 + n2 + n1 + n3 + n1 + n3 + n1;
        break;
    case 9:
        acum_dias =  n1 + n2 + n1 + n3 + n1 + n3 + n1 + n1;
        break;
    case 10:
        acum_dias = n1 + n2 + n1 + n3 + n1 + n3 + n1 + n1 + n3;
        break;
    case 11:
        acum_dias = n1 + n2 + n1 + n3 + n1 + n3 + n1 + n1 + n2 + n1;
        break;
    case 12:
        acum_dias = n1 + n2 + n1 + n3 + n1 + n3 + n1 + n1 + n2 + n1 + n2;
        break;
    }
    days+= acum_dias; //Sumo los acumulados de días
    return days;

}


float hora_a_flotante(vector <char*> horas, int posicion){
    char* hora = new char[5];
    hora = horas[posicion];

    char* hour = new char[2];
    char* minutes = new char[2];

    float _hora, minutos;

    for(int i = 0; i < 2; i++){
        hour[i] = hora[i];
    }

    hour[2] = '\0';

    for(int i = 0; i < 2; i++){
        minutes[i] = hora[i + 3];
    }

    minutes[2] = '\0';

    _hora = atof(hour);
    minutos = atof(minutes);

    float dias = 0;

    dias+= _hora/24;
    dias+= (minutos/60)/24;

    return dias; 
}