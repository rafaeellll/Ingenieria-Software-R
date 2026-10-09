#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};

int main() {
    Alumno alumnos[5];

    cout << "=== Registro de Alumnos ===" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\n--- Alumno " << (i + 1) << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, alumnos[i].nombre);
        cout << "Matricula: ";
        getline(cin, alumnos[i].matricula);

        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << (j + 1) << ": ";
            cin >> alumnos[i].calif[j];
        }
        cin.ignore(); // limpia el salto de linea pendiente antes del siguiente getline
    }

    cout << "\n=== Promedios ===" << endl;
    for (int i = 0; i < 5; i++) {
        float promedio = (alumnos[i].calif[0] + alumnos[i].calif[1] + alumnos[i].calif[2]) / 3;
        cout << alumnos[i].nombre << " (" << alumnos[i].matricula << "): " << promedio << endl;
    }

    return 0;
}
