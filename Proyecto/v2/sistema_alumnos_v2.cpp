#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
using namespace std;

// ============================================
// Sistema de Alumnos y Calificaciones - VERSION 2
// Usa arreglos y structs en lugar de variables sueltas.
// Para pasar de 3 a 30 alumnos solo cambia el numero que
// escribe el usuario (el limite esta en MAX_ALUMNOS).
// ============================================

const int MAX_ALUMNOS = 100;
const int MAX_GRUPOS = 20;
const int MAX_MAESTROS = 20;

// Struct Alumno reutilizado del ejercicio 6 del Parcial2
// (nombre, matricula, calif[3]); aqui solo se le agrega el campo grupo.
struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
    int grupo;          // numero del grupo (1, 2, 3...) segun la lista de grupos
};

struct Maestro {
    string nombre;
    string materia;
};

struct Grupo {
    string nombre;
    string carrera;
};

// ---------- Funciones de ayuda para leer datos ----------

int leerEntero(string mensaje, int minimo, int maximo) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= minimo && valor <= maximo) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor no valido. Escribe un numero entre "
            << minimo << " y " << maximo << "." << endl;
    }
}

float leerCalificacion(string mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor && valor >= 0 && valor <= 10) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Calificacion no valida. Escribe un numero de 0 a 10." << endl;
    }
}

string leerTexto(string mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    if (cin.eof()) exit(0);
    return texto;
}

string aMinusculas(string texto) {
    for (size_t i = 0; i < texto.length(); i++) {
        texto[i] = tolower(texto[i]);
    }
    return texto;
}

// ---------- Funcion de promedio ----------
// Reutilizada de mi proyecto v1 (PSeInt): el SubProceso CalcularPromedio(p1, p2, p3),
// traducido a C++. Hace exactamente lo mismo: suma las 3 y divide entre 3.

float calcularPromedio(float p1, float p2, float p3) {
    return (p1 + p2 + p3) / 3;
}

// ---------- Opcion 1: capturar alumnos ----------

void capturarAlumnos(Alumno alumnos[], int& totalAlumnos, Grupo grupos[], int totalGrupos) {
    if (totalGrupos == 0) {
        cout << "Primero captura los grupos (opcion 2)." << endl;
        return;
    }
    if (totalAlumnos >= MAX_ALUMNOS) {
        cout << "Ya no hay espacio para mas alumnos." << endl;
        return;
    }

    int espacioLibre = MAX_ALUMNOS - totalAlumnos;
    int n = leerEntero("Cuantos alumnos vas a capturar? ", 1, espacioLibre);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Alumno " << (totalAlumnos + 1) << " ---" << endl;
        alumnos[totalAlumnos].nombre = leerTexto("Nombre: ");
        alumnos[totalAlumnos].matricula = leerTexto("Matricula: ");

        for (int j = 0; j < 3; j++) {
            alumnos[totalAlumnos].calif[j] =
                leerCalificacion("Calificacion " + to_string(j + 1) + " (0 a 10): ");
        }

        cout << "Grupos disponibles:" << endl;
        for (int g = 0; g < totalGrupos; g++) {
            cout << "  " << (g + 1) << ". " << grupos[g].nombre
                << " (" << grupos[g].carrera << ")" << endl;
        }
        alumnos[totalAlumnos].grupo = leerEntero("Numero de grupo: ", 1, totalGrupos);

        totalAlumnos++;
    }
    cout << "\nAlumnos capturados. Total en el sistema: " << totalAlumnos << endl;
}

// ---------- Opcion 2: capturar grupos y carreras ----------

void capturarGrupos(Grupo grupos[], int& totalGrupos) {
    if (totalGrupos >= MAX_GRUPOS) {
        cout << "Ya no hay espacio para mas grupos." << endl;
        return;
    }

    int espacioLibre = MAX_GRUPOS - totalGrupos;
    int n = leerEntero("Cuantos grupos vas a capturar? ", 1, espacioLibre);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Grupo " << (totalGrupos + 1) << " ---" << endl;
        grupos[totalGrupos].nombre = leerTexto("Nombre del grupo: ");
        grupos[totalGrupos].carrera = leerTexto("Carrera del grupo: ");
        totalGrupos++;
    }
    cout << "\nGrupos capturados. Total: " << totalGrupos << endl;
}

// ---------- Opcion 3: capturar maestros ----------

void capturarMaestros(Maestro maestros[], int& totalMaestros) {
    if (totalMaestros >= MAX_MAESTROS) {
        cout << "Ya no hay espacio para mas maestros." << endl;
        return;
    }

    int espacioLibre = MAX_MAESTROS - totalMaestros;
    int n = leerEntero("Cuantos maestros vas a capturar? ", 1, espacioLibre);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Maestro " << (totalMaestros + 1) << " ---" << endl;
        maestros[totalMaestros].nombre = leerTexto("Nombre: ");
        maestros[totalMaestros].materia = leerTexto("Materia que imparte: ");
        totalMaestros++;
    }

    cout << "\nMaestros registrados:" << endl;
    for (int i = 0; i < totalMaestros; i++) {
        cout << "  " << (i + 1) << ". " << maestros[i].nombre
            << " - " << maestros[i].materia << endl;
    }
}

// ---------- Opcion 4: reportes ----------

void reportePromedios(Alumno alumnos[], int totalAlumnos, Grupo grupos[]) {
    cout << "\n=== Promedio de cada alumno ===" << endl;
    for (int i = 0; i < totalAlumnos; i++) {
        cout << (i + 1) << ". " << alumnos[i].nombre
            << " (" << alumnos[i].matricula << ")"
            << " - Grupo " << grupos[alumnos[i].grupo - 1].nombre
            << " - Promedio: " << calcularPromedio(alumnos[i].calif[0], alumnos[i].calif[1], alumnos[i].calif[2]) << endl;
    }
}

void reporteMejorPorGrupo(Alumno alumnos[], int totalAlumnos, Grupo grupos[], int totalGrupos) {
    cout << "\n=== Mejor promedio por grupo ===" << endl;
    for (int g = 0; g < totalGrupos; g++) {
        int mejor = -1;
        float mejorPromedio = -1;

        for (int i = 0; i < totalAlumnos; i++) {
            if (alumnos[i].grupo == g + 1) {
                float prom = calcularPromedio(alumnos[i].calif[0], alumnos[i].calif[1], alumnos[i].calif[2]);
                if (prom > mejorPromedio) {
                    mejorPromedio = prom;
                    mejor = i;
                }
            }
        }

        cout << "Grupo " << grupos[g].nombre << ": ";
        if (mejor == -1) {
            cout << "sin alumnos" << endl;
        }
        else {
            cout << alumnos[mejor].nombre << " con " << mejorPromedio << endl;
        }
    }
}

void reporteAlumnosPorCarrera(Alumno alumnos[], int totalAlumnos, Grupo grupos[], int totalGrupos) {
    cout << "\n=== Alumnos por carrera ===" << endl;
    for (int g = 0; g < totalGrupos; g++) {
        // Si esta carrera ya salio en un grupo anterior, no se repite
        bool yaContada = false;
        for (int k = 0; k < g; k++) {
            if (aMinusculas(grupos[k].carrera) == aMinusculas(grupos[g].carrera)) {
                yaContada = true;
            }
        }
        if (yaContada) continue;

        int cantidad = 0;
        for (int i = 0; i < totalAlumnos; i++) {
            Grupo grupoDelAlumno = grupos[alumnos[i].grupo - 1];
            if (aMinusculas(grupoDelAlumno.carrera) == aMinusculas(grupos[g].carrera)) {
                cantidad++;
            }
        }
        cout << grupos[g].carrera << ": " << cantidad << " alumno(s)" << endl;
    }
}

void mostrarReportes(Alumno alumnos[], int totalAlumnos, Grupo grupos[], int totalGrupos) {
    if (totalAlumnos == 0 || totalGrupos == 0) {
        cout << "Todavia no hay datos. Captura grupos y alumnos primero." << endl;
        return;
    }
    reportePromedios(alumnos, totalAlumnos, grupos);
    reporteMejorPorGrupo(alumnos, totalAlumnos, grupos, totalGrupos);
    reporteAlumnosPorCarrera(alumnos, totalAlumnos, grupos, totalGrupos);
}

// ---------- Programa principal ----------

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    Grupo grupos[MAX_GRUPOS];
    Maestro maestros[MAX_MAESTROS];

    int totalAlumnos = 0;
    int totalGrupos = 0;
    int totalMaestros = 0;

    int opcion;
    do {
        cout << "\n===== SISTEMA DE ALUMNOS V2 =====" << endl;
        cout << "1. Capturar alumnos" << endl;
        cout << "2. Capturar grupos y carreras" << endl;
        cout << "3. Capturar maestros" << endl;
        cout << "4. Mostrar reportes" << endl;
        cout << "5. Salir" << endl;
        opcion = leerEntero("Elige una opcion: ", 1, 5);

        switch (opcion) {
        case 1:
            capturarAlumnos(alumnos, totalAlumnos, grupos, totalGrupos);
            break;
        case 2:
            capturarGrupos(grupos, totalGrupos);
            break;
        case 3:
            capturarMaestros(maestros, totalMaestros);
            break;
        case 4:
            mostrarReportes(alumnos, totalAlumnos, grupos, totalGrupos);
            break;
        case 5:
            cout << "Hasta luego." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
