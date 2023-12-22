#include <iostream>
#include <ctime>
#include <locale>

using namespace std;

void LimpiarPantalla(){
	if(system("cls") == -1){
		cout<<"Error al borrar la pantalla  :(";
	}
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

int daysDiff(){
    tm date1 = {0}; // Inicializa las estructuras de fechas
    tm date2 = {0};
    int yearEntry1;
    int monthEntry1;
    int dayEntry1;
    int yearEntry2;
    int monthEntry2;
    int dayEntry2;

    cout << "\nIntroduzca anno del primer suceso: "; cin >> yearEntry1;
    cout << "Introduzca mes del primer suceso: "; cin >> monthEntry1;
    cout << "Introduzca dia del primer suceso: "; cin >> dayEntry1;

    cout << "\nIntroduzca anno del segundo suceso: "; cin >> yearEntry2;
    cout << "Introduzca mes del segundo suceso: "; cin >> monthEntry2;
    cout << "Introduzca dia del segundo suceso: "; cin >> dayEntry2;

    date1.tm_year = yearEntry1 - 1900;
    date1.tm_mon = monthEntry1 - 1;
    date1.tm_mday = dayEntry1;

    date2.tm_year = yearEntry2 - 1900;
    date2.tm_mon = monthEntry2 - 1;
    date2.tm_mday = dayEntry2;

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    //double diferencia_segundos = difftime(time2, time1);
    //double dias = diferencia_segundos / (60 * 60 * 24);
    cout << "\nDiferencia en dias: " << dias << " dias" << endl;

    return 0;

}

string options(){
    string optionsOne;
    LimpiarPantalla();

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
        if(option == "B"){
            daysDiff();
            cout << "INGRESE CUALQUIER TECLA PARA CONTINUAR: "; cin >> cont;
        }
    }
    LimpiarPantalla();
    return 0;
}
