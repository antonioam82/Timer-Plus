#include <iostream>
#include <ctime>

using namespace std;

void LimpiarPantalla(){
	if(system("cls") == -1){
		cout<<"Error al borrar la pantalla  :(";
	}
}

string options(){
    string optionsOne;
    time_t tiempo_actual = std::time(nullptr);
    tm* tiempo_descompuesto = std::localtime(&tiempo_actual);

    cout << "            __________________________________________               " << endl;
    cout << "           /__   ____________________________________/               " << endl;
    cout << "             /  / __   _________   ______   ________                 " << endl;
    cout << "            /  / |  | |  _   _  | | =====| |  ----_/                 " << endl;
    cout << "           /__/  |__| |_| |_| |_| |______| |_|  \\_\\                " << endl;
    cout << "*******************************************************************\n" << endl;
    cout << "                             "
              << tiempo_descompuesto->tm_mday << '/'
              << tiempo_descompuesto->tm_mon + 1 << '/'
              << tiempo_descompuesto->tm_year + 1900 << endl;

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
    while(option != "D"){
        option = options();
        //cout << "Ha escojido la opcion " << option << endl;
        LimpiarPantalla();
    }

    return 0;
}
