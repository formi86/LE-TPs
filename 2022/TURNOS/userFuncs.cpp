#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include "./utils/macros.cpp"
#include "./utils/prototypes.cpp"
#include "./utils/utils.cpp"
class user {
    public:
        int dni;
        string name;
        string surname;
        int age;
        int type;
        int lic;
        string psw;
        user();
        user(int d, string n, string s, int a, int t, int l, string p);
        void save(void);
        void del(void);
};

user::user() {
    dni = 0;
    name = "";
    surname = "";
    age = 0;
    type = 0;
    lic = 0;
    psw = "";
}

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

void user::del(void) {
    int firstLine = checkPsw(dni, psw);
    if (firstLine != -1) {
        string line;
        int i = 0;
        rename("users_db.txt", "old_users_db.txt");
        ifstream oldDB;
        oldDB.open("old_users_db.txt");
        ofstream DB;
        DB.open("users_db.txt");
        while(!oldDB.eof()) {
            getline(oldDB, line);
            if (i < firstLine || i > firstLine + 7) DB << line << endl;
            i++;
        }
        DB.close();
        oldDB.close();
        remove("old_users_db.txt");

        cout << endl << "Usuario eliminado" << endl << "======================" << endl << endl;
    } else {
        cout << endl << "Usuario no encontrado"<< endl << "======================" << endl << endl;
    }

}

int checkUser(int dni, string name, string surname) { //Check if user already exists, returns > 0 if so
    ifstream DB;
    DB.open("users_db.txt");
    int j = 0;
    if(DB) {
        while(!DB.eof()) {
            string line;
            getline(DB, line);
            if(line == to_string(dni)) j++;
            if(line == name) {
                getline(DB, line);
                if(line == surname) j++;
            };
        }
    }
    return j;
};

int checkPsw(int dni, string psw) { //Check user password for login, returns line of the dni in the file
    int out = -1, n = 0;
    ifstream DB;
    DB.open("users_db.txt");
    if(DB) {
        while(!DB.eof()) {
            string line;
            getline(DB, line);
            if(line == to_string(dni)) {
                for (int i = 0; i < 6; i++) {
                    getline(DB, line);
                    if(i == 5 && line == psw) out = n;
                    else if (i == 5 && line != psw) out = -1;
                }
            }
            n++;
        }
    }
    return out;
};

user searchUser(int firstLine) { //Search user data by first line, returns user object
    string line, properties[7];
    ifstream DB;
    DB.open("users_db.txt");
    for (int i = 0; i <= firstLine; i++)
    {
        getline(DB, line);
        if (i == firstLine) {
            properties[0] = line;
            for (int j = 0; j < 6; j++) {
                getline(DB, line);
                properties[j+1] = line;
            }
        }
    }
    user tmpUser(stoi(properties[0]), properties[1], properties[2], stoi(properties[3]), stoi(properties[4]), stoi(properties[5]), properties[6]);
    DB.close();
    return tmpUser;
};

user logIn(void) {
    int tmpDni, firstLine;
    string tmpPsw;
    user actualUser;

    cout << endl << "Ingrese su DNI: ";
    cin >> tmpDni;
    cout << endl << "Ingrese su contraseña: ";
    cin >> tmpPsw;
    firstLine = checkPsw(tmpDni, tmpPsw);
    if(firstLine != -1) {
        actualUser = searchUser(firstLine);
        system("CLS");
        cout << endl << "Has iniciado sesion como: " << actualUser.name << " " << actualUser.surname  << endl << "======================" << endl << endl;
    } else {
        system("CLS");
        cout << endl << "Las credenciales no coinciden"  << endl << "======================" << endl << endl;
    }
    return actualUser;
};

int signUp(void) {
    int state = NAME, option = 0;
    string tmpName, tmpSur, tmpPsw;
    int tmpAge, tmpLic = 0, tmpType, tmpDni;
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
                    cout << endl << "El nombre y apellido o dni se encuentra repetido"  << endl << "======================" << endl << endl;
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
                    option = OUT_OPTION;
                    state = OUT;
                } else if (tmpAge >= 17 && tmpAge <= 100) {
                    state = TYPE;
                } else {
                    cout << endl << "Estas medio viejo para volar, se cerrara la sesion en 3 segundos.";
                    delay(3);
                    option = OUT_OPTION;
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
                } else {
                    state = TYPE;
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
                    cout << endl << "Usuario " << tmpUser.name << " registrado! \n"  << endl << "======================" << endl << endl;
                }
                state = OUT;
                break;

            default:
                break;
        }
    }
    return option;
};
