#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nombre;

    cout << "=== Manejo de errores al abrir archivos ===" << endl;
    cout << "Nombre del archivo a abrir: ";
    getline(cin, nombre);

    ifstream arch(nombre.c_str());
    if (!arch) {
        cout << "\nERROR: no se pudo abrir el archivo \"" << nombre << "\"." << endl;
        cout << "Verifica que el archivo exista y que el nombre este bien escrito." << endl;
        cout << "El programa termina normalmente, sin cerrarse de golpe." << endl;
        return 0;
    }

    string linea;
    int c = 0;
    while (getline(arch, linea)) {
        if (linea != "") {
            c++;
        }
    }
    arch.close();

    if (c == 0) {
        cout << "\nEl archivo se abrio bien, pero esta vacio." << endl;
    } else {
        cout << "\nEl archivo se abrio correctamente. Tiene " << c << " alumnos." << endl;
    }
    return 0;
}
