#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};

int contarLineas(string archivo) {
    ifstream arch(archivo.c_str());
    if (!arch) {
        return 0;
    }
    string linea;
    int c = 0;
    while (getline(arch, linea)) {
        if (linea != "") {
            c++;
        }
    }
    return c;
}

int main() {
    Alumno nuevo;

    cout << "=== Agregar un alumno sin borrar los anteriores ===" << endl;
    cout << "Alumnos guardados antes: " << contarLineas("alumnos.txt") << endl;

    cout << "\n--- Alumno nuevo ---" << endl;
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Matricula: ";
    getline(cin, nuevo.matricula);
    for (int j = 0; j < 3; j++) {
        cout << "Calificacion " << (j + 1) << ": ";
        cin >> nuevo.calif[j];
    }

    ofstream arch("alumnos.txt", ios::app);
    if (!arch) {
        cout << "ERROR: no se pudo abrir alumnos.txt para agregar" << endl;
        return 1;
    }
    arch << nuevo.nombre << "," << nuevo.matricula << ","
         << nuevo.calif[0] << " " << nuevo.calif[1] << " " << nuevo.calif[2] << endl;
    arch.close();

    cout << "\nAlumnos guardados ahora: " << contarLineas("alumnos.txt") << endl;

    cout << "\n--- Contenido de alumnos.txt ---" << endl;
    ifstream lectura("alumnos.txt");
    string linea;
    while (getline(lectura, linea)) {
        cout << linea << endl;
    }
    lectura.close();
    return 0;
}
