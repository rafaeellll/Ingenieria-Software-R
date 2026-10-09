#include <iostream>
using namespace std;

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;

    cout << "=== Intercambio por Referencia ===" << endl;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "\nAntes del intercambio: num1 = " << num1 << ", num2 = " << num2 << endl;

    intercambiar(num1, num2);

    cout << "Despues del intercambio: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
