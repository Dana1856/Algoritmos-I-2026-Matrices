#include "OperacionesMatrices.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// Lee una matriz desde el teclado posición por posición (Recorrido completo)
void leerMatriz(tMatriz& m, const string& nombre) {
    cout << "\n--> Ingrese los elementos para la matriz " << nombre << " (" << N << "x" << N << "):" << endl;
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < N; c++) {
            cout << "Elemento [" << f << "][" << c << "]: ";
            cin >> m.datos[f][c];
        }
    }
}

// Muestra la matriz de manera tabulada en pantalla (Recorrido completo)
void mostrarMatriz(const tMatriz& m) {
    for (int f = 0; f < N; f++) {
        cout << "  [ ";
        for (int c = 0; c < N; c++) {
            cout << setw(6) << m.datos[f][c] << " ";
        }
        cout << "]" << endl;
    }
}

// a) Suma: resultado[f][c] = a[f][c] + b[f][c]
void sumarMatrices(const tMatriz& a, const tMatriz& b, tMatriz& resultado) {
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < N; c++) {
            resultado.datos[f][c] = a.datos[f][c] + b.datos[f][c];
        }
    }
}

// b) Resta: resultado[f][c] = a[f][c] - b[f][c]
void restarMatrices(const tMatriz& a, const tMatriz& b, tMatriz& resultado) {
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < N; c++) {
            resultado.datos[f][c] = a.datos[f][c] - b.datos[f][c];
        }
    }
}

// c) Multiplicación: Fórmulá clásica del producto interno de matrices (3 bucles anidados)
void multiplicarMatrices(const tMatriz& a, const tMatriz& b, tMatriz& resultado) {
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < N; c++) {
            resultado.datos[f][c] = 0; // Inicializador del acumulador
            for (int k = 0; k < N; k++) {
                resultado.datos[f][c] += a.datos[f][k] * b.datos[k][c];
            }
        }
    }
}

// d) Traspuesta: Se intercambian filas por columnas (resultado[c][f] = original[f][c])
void trasponerMatriz(const tMatriz& original, tMatriz& resultado) {
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < N; c++) {
            resultado.datos[c][f] = original.datos[f][c];
        }
    }
}

// e) Puntos de Silla: Busca elementos que sean MÍNIMOS de su fila y MÁXIMOS de su columna
void mostrarPuntosSilla(const tMatriz& m) {
    cout << "\n=== ANÁLISIS DE PUNTOS DE SILLA ===" << endl;
    bool halladoSilla = false;

    // Recorremos cada celda de la matriz para verificar la propiedad
    for (int f = 0; f < N; f++) {
        for (int c = 0; c < N; c++) {
            int valorObjetivo = m.datos[f][c];
            bool esMinFila = true;
            bool esMaxCol = true;

            // 1. Validar si realmente es el menor de su fila 'f'
            for (int k = 0; k < N; k++) {
                if (m.datos[f][k] < valorObjetivo) {
                    esMinFila = false; // Se descarta
                    break;
                }
            }

            // 2. Validar si realmente es el mayor de su columna 'c'
            for (int k = 0; k < N; k++) {
                if (m.datos[k][c] > valorObjetivo) {
                    esMaxCol = false; // Se descarta
                    break;
                }
            }

            // Si supera ambos filtros lógicos, es un punto de silla legítimo
            if (esMinFila && esMaxCol) {
                cout << "-> Encontrado en posicion [" << f << "][" << c << "] con valor: " << valorObjetivo << endl;
                halladoSilla = true;
            }
        }
    }

    if (!halladoSilla) {
        cout << "No existen puntos de silla en la matriz analizada." << endl;
    }
    cout << "===================================" << endl;
}