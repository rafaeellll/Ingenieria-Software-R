#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};

int main() {
    Alumno alumnos[10];
    int n = 0;

    cout << "=== Guardar alumnos en archivo de texto ===" << endl;
    cout << "Cuantos alumnos vas a capturar (1 a 10)? ";
    cin >> n;
    cin.ignore();

    if (n < 1 || n > 10) {
        cout << "Cantidad no valida." << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        cout << "\n--- Alumno " << (i + 1) << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, alumnos[i].nombre);
        cout << "Matricula: ";
        getline(cin, alumnos[i].matricula);
        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << (j + 1) << ": ";
            cin >> alumnos[i].calif[j];
        }
        cin.ignore();
    }

    ofstream arch("alumnos.txt");
    if (!arch) {
        cout << "ERROR: no se pudo crear alumnos.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arch << alumnos[i].nombre << "," << alumnos[i].matricula << ","
             << alumnos[i].calif[0] << " " << alumnos[i].calif[1] << " "
             << alumnos[i].calif[2] << endl;
    }
    arch.close();

    cout << "\nSe guardaron " << n << " alumnos en alumnos.txt" << endl;
    return 0;
}
