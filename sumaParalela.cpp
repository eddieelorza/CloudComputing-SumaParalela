#include "omp.h" // librería para paralelizar el programa
#include <iostream> // librería para imprimir en consola

#define N 1000 // tamaño del arreglo a sumar
#define chunk 100 // tamaño de los pedazos de los arreglos
#define mostrar 10 // cantidad de valores a mostrar de los arreglos

void imprimeArreglo(float *d); // función para imprimir los arreglos a, b y c

int main(){ // función principal del programa
    std::cout << "Sumando Arreglos en Paralelor!\n"; // mensaje principal del programa
    float a[N], b[N], c[N]; // declarando los arreglos a, b y c de tamaño N (1000), tipo float (decimales)
    int i; // variable para el ciclo for 

    for ( i = 0; i < N; i++) // ciclo for que llena los arreglos a y b con valores aleatorios y el arreglo c con ceros
    {
        a[i] = i * 10; // llenando el arreglo a con valores aleatorios
        b[i] = (i + 3) * 3.7; // llenando el arreglo b con valores aleatorios
    }
    int pedazos = chunk; // variable para el tamaño de los pedazos de los arreglos

    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos) // pragma para paralelizar el ciclo for

    for ( i = 0; i < N; i++) // ciclo for que suma los arreglos a y b y los guarda en el arreglo c
    {
        c[i] = a[i] + b[i]; // sumando los arreglos a y b y guardando el resultado en el arreglo c
    }

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl; // imprimiendo los primeros 10 valores del arreglo a
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl; // imprimiendo los primeros 10 valores del arreglo b
    imprimeArreglo(b); 
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl; // imprimiendo los primeros 10 valores del arreglo c
    imprimeArreglo(c);
}

void imprimeArreglo(float *d){ // función para imprimir los arreglos a, b y c
    for (int x = 0; x < mostrar; x++) // ciclo for que imprime los primeros 10 valores del arreglo d
    {
        std::cout << d[x] << " "; // imprimiendo el valor de la posición x del arreglo d
    }
    std::cout << std::endl; // imprimiendo un salto de línea
}