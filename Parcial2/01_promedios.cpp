#include <iostream>
using namespace std;

int main() {
    float calificaciones[6];
    float suma = 0;

    cout << "=== Promedios ===" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Ingrese la calificacion parcial " << (i + 1) << ": ";
        cin >> calificaciones[i];
        suma += calificaciones[i];
    }

    calificaciones[5] = suma / 5;

    cout << "\nCalificaciones ingresadas: ";
    for (int i = 0; i < 5; i++) {
        cout << calificaciones[i] << " ";
    }
    cout << endl;

    cout << "Promedio: " << calificaciones[5] << endl;

    return 0;
}
