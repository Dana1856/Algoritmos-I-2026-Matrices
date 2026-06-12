#include <iostream>
#include "OperacionesMatrices.hpp"

using namespace std;

int main() {
    tMatriz A, B, Resultado;
    char opcion;

    // Carga inicial obligatoria de datos antes de operar
    cout << "=== CONFIGURACIÓN INICIAL DE MATRICES ===" << endl;
    leerMatriz(A, "A");
    leerMatriz(B, "B");

    do {
        cout << "\n=========================================" << endl;
        cout << "      MENÚ DE OPERACIONES MATRICIALES    " << endl;
        cout << "=========================================" << endl;
        cout << "a) Sumar matrices (A + B)" << endl;
        cout << "b) Restar matrices (A - B)" << endl;
        cout << "c) Multiplicar matrices (A * B)" << endl;
        cout << "d) Trasponer matriz A" << endl;
        cout << "e) Analizar puntos de silla de la matriz A" << endl;
        cout << "s) Salir del programa" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 'a': case 'A':
                sumarMatrices(A, B, Resultado);
                cout << "\nMatriz Resultado (A + B):" << endl;
                mostrarMatriz(Resultado);
                break;
            case 'b': case 'B':
                restarMatrices(A, B, Resultado);
                cout << "\nMatriz Resultado (A - B):" << endl;
                mostrarMatriz(Resultado);
                break;
            case 'c': case 'C':
                multiplicarMatrices(A, B, Resultado);
                cout << "\nMatriz Resultado (A * B):" << endl;
                mostrarMatriz(Resultado);
                break;
            case 'd': case 'D':
                trasponerMatriz(A, Resultado);
                cout << "\nMatriz A Traspuesta:" << endl;
                mostrarMatriz(Resultado);
                break;
            case 'e': case 'E':
                cout << "\nMatriz A analizada:" << endl;
                mostrarMatriz(A);
                mostrarPuntosSilla(A);
                break;
            case 's': case 'S':
                cout << "\nFinalizando ejecución del sistema." << endl;
                break;
            default:
                cout << "\n[!] Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 's' && opcion != 'S');

    return 0;
}