#include <iostream>
#include <ctime>

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
        }
    }
    LimpiarPantalla();
    return 0;
}
