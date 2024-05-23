#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <sstream>
#include <cctype>

using namespace std;

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
    std::time_t tiempo_actual = std::time(nullptr);

    // Convierte el tiempo a una estructura tm
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_actual);

    // Muestra la fecha actual
    std::cout << "                             "
              << tiempo_descompuesto->tm_mday << '/'
              << tiempo_descompuesto->tm_mon + 1 << '/'
              << tiempo_descompuesto->tm_year + 1900 << std::endl;

    return 0;

}

int daysDiff0() {
    tm date1 = { 0 }; // Inicializa la estructura de fecha

    //cout << "\nIntroduzca anno del suceso: "; cin >> yearEntry1;
    int yearEntry1 = obtenerNumeroEntero("\nIntroduzca anno del suceso: ", INT_MIN, INT_MAX);
    int monthEntry1 = obtenerNumeroEntero("Introduzca mes del suceso (1-12): ", 1, 12);
    int dayEntry1 = obtenerNumeroEntero("Introduzca dia del suceso: ", 1, 31);

    date1.tm_year = yearEntry1 - 1900;
    date1.tm_mon = monthEntry1 - 1;
    date1.tm_mday = dayEntry1;

    time_t tiempo_actual = time(nullptr);
    tm* tiempo_descompuesto = localtime(&tiempo_actual);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(tiempo_descompuesto);

    double diferencia_segundos = difftime(time2, time1);
    double dias = diferencia_segundos / (60 * 60 * 24);
    cout << "\nDiferencia en dias: " << static_cast<int>(dias) << " dias" << endl;

    return 0;
}

int daysDiff(){
    tm date1 = {0}; // Inicializa las estructuras de fechas
    tm date2 = {0};

    int yearEntry1 = obtenerNumeroEntero("\nIntroduzca anno del primer suceso: ", INT_MIN, INT_MAX);
    int monthEntry1 = obtenerNumeroEntero("Introduzca mes del primer suceso (1-12): ", 1, 12);
    int dayEntry1 = obtenerNumeroEntero("Introduzca dia del primer suceso: ", 1, 31);

    int yearEntry2 = obtenerNumeroEntero("\nIntroduzca anno del segundo suceso: ", INT_MIN, INT_MAX);
    int monthEntry2 = obtenerNumeroEntero("Introduzca mes del segundo suceso (1-12): ", 1, 12);
    int dayEntry2 = obtenerNumeroEntero("Introduzca dia del segundo suceso: ", 1, 31);

    date1.tm_year = yearEntry1 - 1900;
    date1.tm_mon = monthEntry1 - 1;
    date1.tm_mday = dayEntry1;

    date2.tm_year = yearEntry2 - 1900;
    date2.tm_mon = monthEntry2 - 1;
    date2.tm_mday = dayEntry2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    double diferencia_segundos = difftime(time2, time1);
    double dias = diferencia_segundos / (60 * 60 * 24);
    cout << "\nDiferencia en dias: " << static_cast<int>(dias) << " dias" << endl;

    return 0;

}

void dateFromNum(){
    //int x;
    int numeroDias;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "Introduce numero de dias: "; cin >> numeroDias;
    time_t dateBeforeXDays = now + (numeroDias * 24 * 3600);
    tm *ltmBeforeXDays = localtime(&dateBeforeXDays);

    if(numeroDias > 0){
        cout << "Fecha dentro de " << numeroDias << " dias: " << ltmBeforeXDays->tm_mday << "/" << 1 + ltmBeforeXDays->tm_mon << "/" << 1900 + ltmBeforeXDays->tm_year << endl;
    }
    else if(numeroDias < 0){
        cout << "Fecha hace " << abs(numeroDias) << " dias: " << ltmBeforeXDays->tm_mday << "/" << 1 + ltmBeforeXDays->tm_mon << "/" << 1900 + ltmBeforeXDays->tm_year << endl;
    }
    else{
        cout << "Hoy es: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;
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

    optionsOne = toupper(optionsOne[0]); //conversion a mayuscula

    return optionsOne;
};

int main()
{
    locale::global(std::locale(""));
    string option;
    string cont;
    while(option != "D"){
        option = options();
        while(option != "A" && option != "B" && option != "C" && option != "D"){
            cout << "OPCION NO VALIDA." << endl;
            cout << "INGRESE CUALQUIER TECLA PARA CONTINUAR: "; cin >> cont;
            option = options();
        }
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

    }
    LimpiarPantalla();
    return 0;
}
