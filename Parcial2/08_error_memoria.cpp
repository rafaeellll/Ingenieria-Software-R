#include <iostream>
using namespace std;

// ============================================
// FUNCION CON ERROR DE MEMORIA (version con bug)
// Accede a una posicion fuera del rango del arreglo (indice 10
// en un arreglo de tamano 5). Esto es un acceso fuera de limites:
// el compilador NO lo detecta, y en ejecucion el resultado es
// comportamiento indefinido (puede mostrar basura, un valor de
// otra parte de la memoria, o cerrar el programa).
//
// Para probarla: descomenta la llamada "funcionConError();" en
// main() y vuelve a compilar.
// ============================================
void funcionConError() {
    int numeros[5] = {10, 20, 30, 40, 50};

    cout << "Intentando leer la posicion 10 de un arreglo de tamano 5..." << endl;
    cout << "Valor leido: " << numeros[10] << endl; // fuera de rango
}

// ============================================
// FUNCION CORREGIDA
// Valida que el indice este dentro del rango valido (0 a 4)
// antes de acceder al arreglo.
// ============================================
void funcionCorregida() {
    int numeros[5] = {10, 20, 30, 40, 50};
    int indice = 10;

    cout << "Intentando leer la posicion " << indice << " de un arreglo de tamano 5..." << endl;

    if (indice >= 0 && indice < 5) {
        cout << "Valor leido: " << numeros[indice] << endl;
    } else {
        cout << "Error controlado: la posicion " << indice
             << " esta fuera del rango valido (0 a 4)." << endl;
    }
}

int main() {
    cout << "=== Error de Memoria: Version Corregida ===" << endl;
    funcionCorregida();

    // Para ver el error de memoria original (puede comportarse de forma
    // impredecible o cerrar el programa), descomenta la siguiente linea:
    // funcionConError();

    return 0;
}
