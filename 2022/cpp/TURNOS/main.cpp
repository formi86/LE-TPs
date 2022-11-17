#include <iostream>
#include <fstream>
#include <windows.h>
#include "./utils/macros.cpp"
#include "./utils/prototypes.cpp"
#include "userFuncs.cpp"

int option;
user actualUser;

void menu(void) {
    do
    {
        cout << "1: Iniciar Sesion " << endl << "2: Registrarse" << endl << "3: Eliminar Usuario Actual" << endl << "4: Salir" << endl; 
        cout << "Elija la opcion que desea:";
        cin >> option;
        system("CLS");
        switch (option) {
            case 1:
                actualUser = logIn();
                cout << endl << actualUser.dni << endl;
                break;

            case 2:
                option = signUp();
                break;

            case 3:
                actualUser.del();
                break;

            default:
                break;
        }
    } while (option != OUT_OPTION);

};

int main() {
    menu();
}