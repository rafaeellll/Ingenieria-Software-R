#include <iostream>
using namespace std;

int main() {
    float matriz[10][3];

    cout << "=== Matriz de Alumnos (Grupo A y B) ===" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "\nAlumno " << (i + 1) << ":" << endl;
        cout << "  Promedio grupo A: ";
        cin >> matriz[i][0];
        cout << "  Promedio grupo B: ";
        cin >> matriz[i][1];
        matriz[i][2] = (matriz[i][0] > matriz[i][1]) ? matriz[i][0] : matriz[i][1];
    }

    cout << "\n=== Resultados ===" << endl;
    cout << "Fila\tGrupo A\tGrupo B\tMayor" << endl;
    for (int i = 0; i < 10; i++) {
        cout << (i + 1) << "\t" << matriz[i][0] << "\t" << matriz[i][1] << "\t" << matriz[i][2] << endl;
    }

    return 0;
}
