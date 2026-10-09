#include <iostream>
using namespace std;

int main() {
    float grupo1[5], grupo2[5], mayores[5];

    cout << "=== Promedio de Grupo ===" << endl;

    cout << "\n--- Grupo 1 ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Promedio del alumno " << (i + 1) << ": ";
        cin >> grupo1[i];
    }

    cout << "\n--- Grupo 2 ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Promedio del alumno " << (i + 1) << ": ";
        cin >> grupo2[i];
    }

    for (int i = 0; i < 5; i++) {
        mayores[i] = (grupo1[i] > grupo2[i]) ? grupo1[i] : grupo2[i];
    }

    cout << "\nPromedio mas alto por posicion:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Posicion " << (i + 1) << ": " << mayores[i] << endl;
    }

    return 0;
}
