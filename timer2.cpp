#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <sstream>
#include <cctype>
#include <chrono>
#include "date/date.h"

using namespace std;
using namespace date;
using namespace std::chrono;

void LimpiarPantalla(){
	if(system("cls") == -1){
		cout<<"Error al borrar la pantalla  :(";
	}
}

int obtenerNumeroEntero(string mensaje, int minVal, int maxVal) {
    int numero;
    string input;

    while (true) {
        cout << mensaje;
        cin >> input;

        stringstream ss(input);
        if (ss >> numero && ss.eof() && numero >= minVal && numero <= maxVal) {
            break;
        }

        cout << "Por favor, ingrese un numero valido en el rango (" << minVal << " - " << maxVal << ")." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return numero;
}

int getCurrentDate(){
    // Obtiene el tiempo actual en formato de tiempo de UNIX
    time_t tiempo_actual = time(nullptr);

    // Convierte el tiempo a una estructura tm
    tm* tiempo_descompuesto = localtime(&tiempo_actual);

    // Muestra la fecha actual
    cout << "                             "
              << tiempo_descompuesto->tm_mday << '/'
              << tiempo_descompuesto->tm_mon + 1 << '/'
              << tiempo_descompuesto->tm_year + 1900 << endl;

    return 0;

}

int daysDiff0() {
    //tm date1 = { 0 }; // Inicializa la estructura de fecha

    int yearEntry1 = obtenerNumeroEntero("\nIntroduzca anno del suceso: ", INT_MIN, INT_MAX);
    int monthEntry1 = obtenerNumeroEntero("Introduzca mes del suceso (1-12): ", 1, 12);
    int dayEntry1 = obtenerNumeroEntero("Introduzca dia del suceso: ", 1, 31);

    year_month_day fecha = year{yearEntry1}/month{monthEntry1}/day{dayEntry1};
    auto today = floor<days>(system_clock::now());
    year_month_day fecha2 = year_month_day{today};

    time_t tiempo_actual = time(nullptr);

    sys_days time_point1 = fecha;
    sys_days time_point2 = fecha2;

    auto duracion_en_dias = time_point2 - time_point1;

    int dias = duracion_en_dias.count();
    int weeks = dias / 7;
    int resto_dias = static_cast<int>(dias) % 7;

    cout << "\nLa diferencia en dias es de: " << dias << " dias." << endl;
    cout << weeks << " semanas" << " y " << resto_dias << " dias." << endl;
    return 0;
}

int daysDiff(){
    //tm date1 = {0}; // Inicializa las estructuras de fechas
    //tm date2 = {0};

    int yearEntry1 = obtenerNumeroEntero("\nIntroduzca anno del primer suceso: ", INT_MIN, INT_MAX);
    int monthEntry1 = obtenerNumeroEntero("Introduzca mes del primer suceso (1-12): ", 1, 12);
    int dayEntry1 = obtenerNumeroEntero("Introduzca dia del primer suceso: ", 1, 31);

    int yearEntry2 = obtenerNumeroEntero("\nIntroduzca anno del segundo suceso: ", INT_MIN, INT_MAX);
    int monthEntry2 = obtenerNumeroEntero("Introduzca mes del segundo suceso (1-12): ", 1, 12);
    int dayEntry2 = obtenerNumeroEntero("Introduzca dia del segundo suceso: ", 1, 31);

    year_month_day fecha1 = year{yearEntry1}/month{monthEntry1}/day{dayEntry1};
    year_month_day fecha2 = year{yearEntry2}/month{monthEntry2}/day{dayEntry2};

    sys_days time_point1 = fecha1;
    sys_days time_point2 = fecha2;

    auto duracion_en_dias = time_point2 - time_point1;

    int dias = duracion_en_dias.count();
    int weeks = dias / 7;
    int resto_dias = static_cast<int>(dias) % 7;


    cout << "\nDiferencia en dias: " << static_cast<int>(dias) << " dias" << endl;
    cout << weeks << " semanas" << " y " << resto_dias << " dias" << endl;

    return 0;

}

void dateFromNum(){
    int numeroDias;
    cout << "Introduce numero de dias: ";
    cin >> numeroDias;

    auto today = floor<days>(system_clock::now());
    auto future_date = today + days(numeroDias);

    year_month_day ymd{future_date};

    // Extraer dia mes y año
    int year = static_cast<int>(ymd.year());
    unsigned month = static_cast<unsigned>(ymd.month());
    unsigned day = static_cast<unsigned>(ymd.day());

    // Formateo de fecha d/m/y
    stringstream dateStream;
    dateStream << day << "/" << month << "/" << year;

    int weeks = numeroDias / 7;
    int resto_dias = static_cast<int>(numeroDias) % 7;

    if(numeroDias > 0){
        cout << "Fecha dentro de " << numeroDias << " dias " << "(" << weeks << " semanas y " << resto_dias << " dias): "
        << dateStream.str() << endl;
    }
    else if(numeroDias < 0){
        cout << "Fecha hace " << abs(numeroDias) << " dias " << "(" << abs(weeks) << " semanas y " << abs(resto_dias) << " dias): "
        << dateStream.str() << endl;
    }
    else{
        auto current_date = year_month_day{today};
        int currentYear = static_cast<int>(current_date.year());
        unsigned currentMonth = static_cast<unsigned>(current_date.month());
        unsigned currentDay = static_cast<unsigned>(current_date.day());
        stringstream currentDateStream;
        currentDateStream << currentDay << "/" << currentMonth << "/" << currentYear;
        cout << "Hoy es: " << currentDateStream.str() << endl;
    }
}

string options(){
    string optionsOne;
    LimpiarPantalla();
    //string frase = "";
    //int longitud = int(frase.length());
    //cout << "Longitud frase: " << longitud << endl;

    cout << "            __________________________________________               " << endl;
    cout << "           /__   ____________________________________/               " << endl;
    cout << "             /  / __   _________   ______   ________                 " << endl;
    cout << "            /  / |  | |  _   _  | | =====| |  ----_/                 " << endl;
    cout << "           /__/  |__| |_| |_| |_| |______| |_|  \\_\\                " << endl;
    cout << "*******************************************************************\n" << endl;
    getCurrentDate();

    cout << "-------------------------ESCOJA UNA OPCION-------------------------" << endl;
    cout << "A) Calcular numero de dias entre una fecha y la actual." <<endl;
    cout << "B) Calcular numero de dias entre dos fechas." <<endl;
    cout << "C) Conocer fecha a partir del numero de dias." <<endl;
    cout << "D) Salir del programa." << endl;
    cout << "-------------------------------------------------------------------\n" << endl;

    cout << "Introduzca aqui su opcion: "; cin >> optionsOne;

    //optionsOne = toupper(optionsOne[0]); //conversion a mayuscula
    if (!optionsOne.empty()) {
        optionsOne[0] = toupper(optionsOne[0]);
    }

    return optionsOne;
};

int main()
{
    locale::global(std::locale(""));
    string option;
    string cont;
    while(option != "D"){

        do{
            option = options();
            if(option == "A"){
                daysDiff0();
            }
            if(option == "B"){
                daysDiff();
            }
            if(option == "C"){
                dateFromNum();
            }
            if(option != "D"){
                cout << "INGRESE CUALQUIER TECLA PARA CONTINUAR: "; cin >> cont;
        }
        }while(option != "A" && option != "B" && option != "C" && option != "D");

    }
    LimpiarPantalla();
    return 0;
}

