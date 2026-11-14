#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
};

int leerAlumnos(string archivo, Alumno alumnos[], int maximo) {
    ifstream arch(archivo.c_str());
    if (!arch) {
        return -1;
    }
    int n = 0;
    while (n < maximo && getline(arch, alumnos[n].nombre, ',')) {
        getline(arch, alumnos[n].matricula, ',');
        arch >> alumnos[n].calif[0] >> alumnos[n].calif[1] >> alumnos[n].calif[2];
        if (arch) {
            arch.ignore(1000, '\n');
            n++;
        }
    }
    arch.close();
    return n;
}

int main() {
    Alumno alumnos[50];
    string nombreArchivo;

    cout << "=== Leer y reconstruir alumnos ===" << endl;
    cout << "Nombre del archivo a leer: ";
    getline(cin, nombreArchivo);

    int n = leerAlumnos(nombreArchivo, alumnos, 50);
    if (n == -1) {
        cout << "ERROR: no se pudo abrir " << nombreArchivo << endl;
        return 1;
    }

    cout << "\n--- Contenido del archivo ---" << endl;
    ifstream arch(nombreArchivo.c_str());
    string linea;
    while (getline(arch, linea)) {
        cout << linea << endl;
    }
    arch.close();

    cout << "\n--- Alumnos reconstruidos en memoria (" << n << ") ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " << alumnos[i].nombre << " | " << alumnos[i].matricula
             << " | " << alumnos[i].calif[0] << " " << alumnos[i].calif[1]
             << " " << alumnos[i].calif[2] << endl;
    }
    return 0;
}
