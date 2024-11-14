#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <sstream>
#include <cctype>
#include <chrono>
//#include "date/date.h"

using namespace std;

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

int main()
{
    char exit_program = 'n';
    while(exit_program == 'n'){
        int year = numeroEntero("Introduce anno de nacimiento: ");
        int month = numeroEntero("Introduce mes de nacimiento: ");
        int day = numeroEntero("Introduce dia de nacimiento: ");
        cout << "NACISTE EL " << day << " DE " << month << " DE " << year << endl;
        exit_program = question();
    }
    return 0;
}
