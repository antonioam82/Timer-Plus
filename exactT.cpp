#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <sstream>
#include <cctype>
#include <chrono>

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
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);
    year = now_tm->tm_year + 1900;
    month = now_tm->tm_mon + 1;
    day = now_tm->tm_mday;
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
    return (num % 4 == 0 && num % 100 != 0) || (num % 100 == 0 && num % 400 == 0);
}

int maxiDay(int month,bool bisiesto){
    if(month == 2){
        return bisiesto ? 29 : 28;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }
    return 31;
}

int max_Month(int year,int currentYear,int currentMonth){
    return (year == currentYear) ? currentMonth : 12;
}

int calcularDiferenciaFechas(tm fechaNacimiento, tm fechaActual) {
    auto time_nacimiento = std::mktime(&fechaNacimiento);
    auto time_actual = std::mktime(&fechaActual);
    auto diferencia = std::difftime(time_actual, time_nacimiento);

    return static_cast<int>(diferencia / (60 * 60 * 24)); // Diferencia en días
}

void calcularEdad(int dias) {
    int years = dias / 365;
    dias %= 365;
    int months = dias / 30; // Aproximación
    int remaining_days = dias % 30;

    cout << "Diferencia: " << years << " annos, " << months << " meses y " << remaining_days << " dias." << endl;
    //cout << "Total de dias: " << years * 365 + months * 30 + remaining_days << " días." << endl; // Nueva línea
}

int main() {
    char exit_program = 'n';
    int currentYear, currentMonth, currentDay;
    bool esBisiesto;
    int maxDay;
    int maxMonth;

    currentDate(currentYear, currentMonth, currentDay);

    while(exit_program == 'n'){
        int year = validateNum("Introduce anno de nacimiento: ",1,currentYear);
        esBisiesto = bisiesto(year);
        maxMonth = max_Month(year, currentYear, currentMonth);
        int month = validateNum("Introduce mes de nacimiento: ",1,maxMonth);
        maxDay = maxiDay(month,esBisiesto);
        int day = validateNum("Introduce dia de nacimiento: ",1,maxDay);

        tm fechaNacimiento = { 0 }; // Inicializa la estructura de fecha
        fechaNacimiento.tm_year = year - 1900;
        fechaNacimiento.tm_mon = month - 1;
        fechaNacimiento.tm_mday = day;

        tm fechaActual = { 0 };
        fechaActual.tm_year = currentYear - 1900;
        fechaActual.tm_mon = currentMonth - 1;
        fechaActual.tm_mday = currentDay;

        int diferenciaDias = calcularDiferenciaFechas(fechaNacimiento, fechaActual);
        cout << "Han pasado " << diferenciaDias << " dias desde tu fecha de nacimiento." << endl; // Nueva línea
        calcularEdad(diferenciaDias);

        exit_program = question();
        LimpiarPantalla();
    }
    return 0;
}


