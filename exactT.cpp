#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <sstream>
#include <cctype>
#include <chrono>
//#include "date/date.h"

using namespace std;

void LimpiarPantalla(){
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux / MacOS
    #endif
}

char question() {
    char exit_program;
    do {
        cout << "Desea salir del programa? (y/n): ";
        cin >> exit_program;
        if (exit_program != 'y' && exit_program != 'n') {
            cout << "Introduzca 'n' o 'y'"<< endl;
        }
    } while(exit_program != 'y' && exit_program != 'n');

    return exit_program;
}

int numeroEntero(string mensaje) {
    int numero;
    string input;

    while (true) {
        cout << mensaje;
        cin >> input;

        stringstream ss(input);
        if (ss >> numero && ss.eof()) {
            break;
        }

        cout << "Por favor, ingrese un numero valido." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return numero;
}

// Función que obtiene la fecha actual y la devuelve por referencia
void currentDate(int &year, int &month, int &day) {
    // Obtener el tiempo actual en formato de tiempo del sistema
    auto now = std::chrono::system_clock::now();

    // Convertir el tiempo a un objeto de tipo time_t
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

    // Convertir el time_t a una estructura tm (tiempo local)
    std::tm* now_tm = std::localtime(&now_time);

    // Asignar el año, mes y día por separado
    year = now_tm->tm_year + 1900;   // tm_year es el número de años desde 1900
    month = now_tm->tm_mon + 1;      // tm_mon es el número de meses desde enero (0-11)
    day = now_tm->tm_mday;           // tm_mday es el día del mes (1-31)

    // Imprimir los valores obtenidos (opcional)
    cout << "Fecha actual -> Año: " << year << " Mes: " << month << " Día: " << day << endl;
}


int validateNum(string text, int minNum, int maxNum){
    int numero;
    string entrada;

    while (true){
        cout << text;
        cin >> entrada;

        stringstream ss(entrada);
        if (ss >> numero && ss.eof() && numero >= minNum && numero <= maxNum){
            break;
        }
        cout << "Por favor, ingrese un numero valido en el rango (" << minNum << " - " << maxNum << ")." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    return numero;

}

bool bisiesto(int num){

    if((num % 4 == 0 && num % 100 != 0) || (num % 100 == 0 && num % 400 == 0)){
        return true;
    }else{
        return false;
    }
}

int main()
{
    char exit_program = 'n';
    int currentYear, currentMonth, currentDay;
    bool esBisiesto;

    // Obtener la fecha actual
    currentDate(currentYear, currentMonth, currentDay);

    while(exit_program == 'n'){
        int year = validateNum("Introduce anno de nacimiento: ",1,currentYear);
        esBisiesto = bisiesto(year);
        //if(esBisiesto){
            //cout << "Es bisiesto" << endl;
        //}else{
            //cout << "No es bisiesto" << endl;
        //}
        int month = validateNum("Introduce mes de nacimiento: ",1,12);
        int day = validateNum("Introduce dia de nacimiento: ",1,31);
        cout << "NACISTE EL " << day << " DEL " << month << " DE " << year << endl;
        exit_program = question();
        LimpiarPantalla();
    }
    return 0;
}
