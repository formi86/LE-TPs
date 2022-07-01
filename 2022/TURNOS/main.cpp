#include <iostream>
#include <fstream>
#include <windows.h>
#include "macros.cpp"
#include "prototypes.cpp"
#include "userFuncs.cpp"

int option;

void menu(void) {
    do
    {
        cout << "1: Iniciar Sesion " << endl << "2: Registrarse" << endl << "3: Salir" << endl; 
        cout << "Elija la opcion que desea:";
        cin >> option;
        system("CLS");
        switch (option)
        {
        case 1:
            logIn();
            break;
        
        case 2:
            option = signUp();
            break;

        default:
            break;
        }
    } while (option != 3);

};

int main() {
    menu();
}