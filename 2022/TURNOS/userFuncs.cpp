#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include "macros.cpp"
#include "prototypes.cpp"
#include "utils.cpp"
class user {
    public:
        int dni;
        string name;
        string surname;
        int age;
        int type;
        int lic;
        string psw;
        user(int d, string n, string s, int a, int t, int l, string p);
        void save(void);
};

user::user(int d, string n, string s, int a, int t, int l, string p) {
    dni = d;
    name = n;
    surname = s;
    age = a;
    type = t;
    lic = l;
    psw = p;
};

void user::save(void) {
    ofstream DB;
    DB.open("users_db.txt", ios::app);
    DB << dni << endl;
    DB << name << endl;
    DB << surname << endl;
    DB << age << endl;
    DB << type << endl;
    DB << lic << endl;
    DB << psw << endl;
    DB.close();
};

int checkUser(int dni, string name, string surname) {
    ifstream DB;
    DB.open("users_db.txt");
    int j = 0;
    while(!DB.eof()) {
        string line;
        getline(DB, line);
        if(line == to_string(dni) || ( line == name && line == surname) ) j++;
    }
    return j;
}

void logIn(void) {
    cout << "hola";
};

int signUp(void) {
    int state = NAME, option = 0;
    string tmpName, tmpSur, tmpPsw;
    int tmpAge, tmpLic, tmpType, tmpDni;
    while(state != OUT) {
        switch (state) {
            case NAME:
                cout << "Ingrese su nombre: ";
                cin >> tmpName;
                cout << endl << "Ingrese su apellido: ";
                cin >> tmpSur;
                cout << endl << "Ingrese su DNI: ";
                cin >> tmpDni;
                if (checkUser(tmpDni, tmpName, tmpSur) > 0)
                {
                    system("CLS");
                    cout << endl << "El nombre y apellido o dni se encuentra repetido" << endl;
                    state = NAME;
                 }
                else state = AGE;

                break;

            case AGE:
                cout << endl << "Igrese su edad: ";
                cin >> tmpAge;
                if (tmpAge < 17) {
                    cout << endl << "Es menor de edad, no puede registrarse. Se cerrara la sesion en 3 segundos." << endl;
                    delay(3);
                    option = 3;
                    state = OUT;
                } else if (tmpAge >= 17 && tmpAge <= 100) {
                    state = TYPE;
                } else {
                    cout << endl << "Estas medio viejo para volar, se cerrara la sesion en 3 segundos.";
                    delay(3);
                    option = 3;
                    state = OUT;
                }
                break;

            case TYPE:
                cout << endl << "Seleccione: " << endl << "1. Alumno" << endl << "2. Instructor" << endl << "3. Piloto" << endl;
                cin >> tmpType;
                if (tmpType == ALUMNO) {
                    state = PSW;
                } else if (tmpType == INSTRUCTOR || tmpType == PILOTO) {
                    state = LIC;
                }
                break;

            case LIC:
                cout << endl << "Ingrese el numero de su licencia: ";
                cin >> tmpLic;
                state = PSW;
                break;

            case PSW: 
                cout << endl << "Ingrese su contraseña: ";
                cin >> tmpPsw;
                state = SAVE;
                break;

            case SAVE:
                {
                    user tmpUser(tmpDni, tmpName, tmpSur, tmpAge, tmpType, tmpLic, tmpPsw);
                    system("CLS");
                    tmpUser.save();
                    cout << endl << "Usuario " << tmpUser.name << " registrado! \n" << endl;
                }
                state = OUT;
                break;

            default:
                break;
        }
    }
    return option;
};
