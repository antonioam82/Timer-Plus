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
            if(option == "A"){

            }
        }
    }
    LimpiarPantalla();
    return 0;
}
