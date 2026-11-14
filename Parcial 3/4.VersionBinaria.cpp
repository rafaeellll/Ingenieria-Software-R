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

long tamano(string archivo) {
    ifstream arch(archivo.c_str(), ios::binary);
    if (!arch) {
        return -1;
    }
    arch.seekg(0, ios::end);
    long t = arch.tellg();
    return t;
}

int main() {
    Alumno alumnos[50];
    Alumno otros[50];
    string nombreTxt;

    cout << "=== Version binaria ===" << endl;
    cout << "Archivo de texto a convertir: ";
    getline(cin, nombreTxt);

    int n = leerAlumnos(nombreTxt, alumnos, 50);
    if (n == -1) {
        cout << "ERROR: no se pudo abrir " << nombreTxt << endl;
        return 1;
    }
    if (n == 0) {
        cout << "El archivo no tiene alumnos." << endl;
        return 1;
    }
    cout << "Alumnos leidos del texto: " << n << endl;

    ofstream bin("alumnos.dat", ios::binary);
    if (!bin) {
        cout << "ERROR: no se pudo crear alumnos.dat" << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        int t = alumnos[i].nombre.length();
        bin.write((char*)&t, sizeof(t));
        bin.write(alumnos[i].nombre.c_str(), t);
        t = alumnos[i].matricula.length();
        bin.write((char*)&t, sizeof(t));
        bin.write(alumnos[i].matricula.c_str(), t);
        bin.write((char*)alumnos[i].calif, 3 * sizeof(float));
    }
    bin.close();
    cout << "Alumnos escritos en alumnos.dat: " << n << endl;

    ifstream lec("alumnos.dat", ios::binary);
    int m = 0;
    int t = 0;
    while (m < 50 && lec.read((char*)&t, sizeof(t))) {
        otros[m].nombre.resize(t);
        lec.read(&otros[m].nombre[0], t);
        lec.read((char*)&t, sizeof(t));
        otros[m].matricula.resize(t);
        lec.read(&otros[m].matricula[0], t);
        lec.read((char*)otros[m].calif, 3 * sizeof(float));
        m++;
    }
    lec.close();
    cout << "Alumnos recuperados del binario: " << m << endl;

    bool igual = (m == n);
    for (int i = 0; i < n && igual; i++) {
        if (alumnos[i].nombre != otros[i].nombre || alumnos[i].matricula != otros[i].matricula) {
            igual = false;
        }
        for (int j = 0; j < 3; j++) {
            if (alumnos[i].calif[j] != otros[i].calif[j]) {
                igual = false;
            }
        }
    }
    if (igual) {
        cout << "Verificacion: los datos del binario coinciden con los del texto." << endl;
    } else {
        cout << "Verificacion: HAY DIFERENCIAS entre el binario y el texto." << endl;
    }

    long tTxt = tamano(nombreTxt);
    long tBin = tamano("alumnos.dat");
    cout << "\nTamano del archivo de texto (" << nombreTxt << "): " << tTxt << " bytes" << endl;
    cout << "Tamano del archivo binario (alumnos.dat): " << tBin << " bytes" << endl;
    if (tBin > tTxt) {
        cout << "El binario pesa " << (tBin - tTxt) << " bytes mas que el texto." << endl;
    } else if (tBin < tTxt) {
        cout << "El binario pesa " << (tTxt - tBin) << " bytes menos que el texto." << endl;
    } else {
        cout << "Los dos archivos pesan lo mismo." << endl;
    }
    return 0;
}
