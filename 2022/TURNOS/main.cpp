#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

#define NAME 0
#define AGE 1
#define TYPE 2
#define LIC 3
#define PSW 4
#define SAVE 5
#define OUT 6

#define ALUMNO 1
#define INSTRUCTOR 2
#define PILOTO 3

class user {
    public:
        int id;
        string name;
        string surname;
        int age;
        int type;
        int lic;
        string psw;
        user(string name, string surname, int age, int type, int lic, string psw);

};

user::user(string n, string s, int a, int t, int l, string p) {
    id = 1;
    name = n;
    surname = s;
    age = a;
    type = t;
    lic = l;
    psw = p;
};

void saveToUsersDb(user newUser) {
    ofstream DB;
    DB.open("users_db.txt", ios::app);
    DB << newUser.id << endl;
    DB << newUser.name << endl;
    DB << newUser.surname << endl;
    DB << newUser.age << endl;
    DB << newUser.type << endl;
    DB << newUser.lic << endl;
    DB << newUser.psw << endl;
    DB.close();
}

void login(void);
void regis(void);

void logIn(void) {
    cout << "hola";
};

void signIn(void) {
    int state = NAME;
    string tmpName, tmpSur, tmpPsw;
    int tmpAge, tmpLic, tmpType;
    while(state != OUT) {
        switch (state) {
            case NAME:
                cout << "Ingrese su nombre: ";
                cin >> tmpName;
                cout << endl << "Ingrese su apellido: ";
                cin >> tmpSur;
                state = AGE;
                break;

            case AGE:
                cout << endl << "Igrese su edad: ";
                cin >> tmpAge;
                if (tmpAge < 17) {
                    cout << endl << "Es menor de edad, no puede registrarse." << endl;
                    state = OUT;
                } else if (tmpAge >= 17 && tmpAge <= 100) {
                    state = TYPE;
                } else {
                    cout << endl << "Estas medio viejo para volar";
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
                    user tmpUser(tmpName, tmpSur, tmpAge, tmpType, tmpLic, tmpPsw);
                    system("CLS");
                    saveToUsersDb(tmpUser);
                    cout << endl << "Usuario " << tmpUser.name << " registrado! \n" << endl;
                }
                state = OUT;
                break;

            default:
                break;
        }
    }
    return;
};

void menu(void) {
    int option;
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
            signIn();
            break;

        default:
            break;
        }
    } while (option != 3);

};

int main() {
    menu();
}