#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

float promedio(Alumno a) {
    return (a.calif[0] + a.calif[1] + a.calif[2]) / 3;
}

int main() {
    Alumno alumnos[50];
    string nombreArchivo;

    cout << "=== Reporte de alumnos ===" << endl;
    cout << "Archivo con los alumnos: ";
    getline(cin, nombreArchivo);

    int n = leerAlumnos(nombreArchivo, alumnos, 50);
    if (n == -1) {
        cout << "ERROR: no se pudo abrir " << nombreArchivo << endl;
        return 1;
    }
    if (n == 0) {
        cout << "El archivo no tiene alumnos, no hay nada que reportar." << endl;
        return 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (promedio(alumnos[j]) < promedio(alumnos[j + 1])) {
                Alumno aux = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = aux;
            }
        }
    }

    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma = suma + promedio(alumnos[i]);
    }

    ofstream rep("reporte.txt");
    if (!rep) {
        cout << "ERROR: no se pudo crear reporte.txt" << endl;
        return 1;
    }
    rep << fixed << setprecision(2);
    rep << "REPORTE DE ALUMNOS" << endl;
    rep << "Ordenado por promedio, de mayor a menor" << endl;
    rep << "Archivo de origen: " << nombreArchivo << endl;
    rep << "-----------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        rep << (i + 1) << ". " << alumnos[i].nombre << " (" << alumnos[i].matricula
            << ") - Promedio: " << promedio(alumnos[i]) << endl;
    }
    rep << "-----------------------------------------------" << endl;
    rep << "Total de alumnos: " << n << endl;
    rep << "Promedio general: " << suma / n << endl;
    rep << "Mejor promedio: " << alumnos[0].nombre << endl;
    rep.close();

    cout << "\nSe genero reporte.txt con " << n << " alumnos." << endl;
    cout << "\n--- Contenido de reporte.txt ---" << endl;
    ifstream lec("reporte.txt");
    string linea;
    while (getline(lec, linea)) {
        cout << linea << endl;
    }
    lec.close();
    return 0;
}
