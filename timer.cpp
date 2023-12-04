#include <iostream>

using namespace std;

string options(){
    string optionsOne;
    cout << "            __________________________________________               " << endl;
    cout << "           /__   ____________________________________/               " << endl;
    cout << "             /  / __   _________   ______   ________                 " << endl;
    cout << "            /  / |  | |  _   _  | | =====| |  ----_/                 " << endl;
    cout << "           /__/  |__| |_| |_| |_| |______| |_|  \\_\\                " << endl;
    cout << "*******************************************************************\n" << endl;

    cout << "-------------------------ESCOJA UNA OPCIÓN-------------------------" << endl;
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
        cout << "Ha escojido la opcion " << option << endl;
    }

    return 0;
}

