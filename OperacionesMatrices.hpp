#ifndef OPERACIONES_MATRICES_HPP
#define OPERACIONES_MATRICES_HPP

#include <string>

// Definición de la dimensión de las matrices (NxN)
const int N = 3;

// Estructura que envuelve el array multidimensional
struct tMatriz {
    int datos[N][N];
};

// Subprogramas obligatorios de entrada/salida (E/S)
void leerMatriz(tMatriz& m, const std::string& nombre);
void mostrarMatriz(const tMatriz& m);

// Subprogramas de operaciones algebraicas
void sumarMatrices(const tMatriz& a, const tMatriz& b, tMatriz& resultado);
void restarMatrices(const tMatriz& a, const tMatriz& b, tMatriz& resultado);
void multiplicarMatrices(const tMatriz& a, const tMatriz& b, tMatriz& resultado);
void trasponerMatriz(const tMatriz& original, tMatriz& resultado);

// Subprograma avanzado: Detección de puntos de silla
void mostrarPuntosSilla(const tMatriz& m);

#endif // OPERACIONES_MATRICES_HPP