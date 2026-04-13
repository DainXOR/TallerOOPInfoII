// ============================================================
//  MÓDULO 6 – Manejo de objetos en memoria
//  Tema: stack vs heap, new/delete, punteros a objetos
//  Problema: Objeto Punto 2D
// ============================================================

#include <iostream>
#include <math.h>

// ============================================================
//  VERSIÓN ESTRUCTURADA
// ============================================================

struct PuntoStruct {
    double x, y;
};

double distanciaStruct(PuntoStruct a, PuntoStruct b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

// ============================================================
//  VERSIÓN OOP – clase Punto
// ============================================================

class Punto {
public:
    double x, y;

    // Constructor
    Punto(double x = 0.0, double y = 0.0) : x(x), y(y) {
        std::cout << "  [Constructor] Punto(" << x << ", " << y << ") creado\n";
    }

    // Destructor
    ~Punto() {
        std::cout << "  [Destructor]  Punto(" << x << ", " << y << ") destruido\n";
    }

    double distanciaA(Punto otro) {
        double dx = x - otro.x;
        double dy = y - otro.y;
        return sqrt(dx*dx + dy*dy);
    }

    void mostrar() {
        std::cout << "  Punto(" << x << ", " << y << ")\n";
    }
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 6: Objetos en memoria\n";
    std::cout << "==============================\n";

    // ----------------------------------------------------------
    //  1. OBJETOS EN EL STACK (memoria automática)
    // ----------------------------------------------------------
    //  • Se declaran como variables locales normales.
    //  • El compilador los crea y destruye automáticamente.
    //  • Viven mientras exista el bloque {} donde se declararon.
    //  • Rápido, pero tamaño limitado.
    // ----------------------------------------------------------
    std::cout << "\n--- Objetos en STACK ---\n";
    {
        Punto p1(1.0, 2.0);   // creado en el stack
        Punto p2(4.0, 6.0);
        std::cout << "  Distancia p1-p2 = " << p1.distanciaA(p2) << "\n";
    }   // <-- p1 y p2 se destruyen aquí automáticamente

    // ----------------------------------------------------------
    //  2. OBJETOS EN EL HEAP (memoria dinámica)
    // ----------------------------------------------------------
    //  • Se crean con 'new' — el programador controla cuándo existen.
    //  • Se accede a ellos a través de un PUNTERO.
    //  • Deben liberarse con 'delete' para evitar fugas de memoria.
    //  • El operador -> accede a miembros a través de un puntero.
    // ----------------------------------------------------------
    std::cout << "\n--- Objetos en HEAP (new / delete) ---\n";

    Punto* pPtr = new Punto(3.0, 4.0);  // 'new' devuelve un puntero

    // Dos formas de acceder a miembros con puntero:
    std::cout << "  x via ->  : " << pPtr->x << "\n";       // forma corta (usual)
    std::cout << "  x via *   : " << (*pPtr).x << "\n";     // forma larga (equivalente)

    pPtr->mostrar();

    delete pPtr;   // OBLIGATORIO: liberar la memoria
    pPtr = nullptr;  // buena práctica: evitar puntero colgante

    // ----------------------------------------------------------
    //  3. ARREGLO DINÁMICO DE OBJETOS
    // ----------------------------------------------------------
    std::cout << "\n--- Arreglo dinámico de objetos ---\n";
    int n = 3;
    Punto* puntos = new Punto[n];   // arreglo de n Puntos en el heap

    // Asignar valores
    puntos[0].x = 1; puntos[0].y = 1;
    puntos[1].x = 5; puntos[1].y = 1;
    puntos[2].x = 5; puntos[2].y = 4;

    std::cout << "  Puntos del triángulo:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "    [" << i << "] ";
        puntos[i].mostrar();
    }

    delete[] puntos;   // para arreglos dinámicos se usa delete[]

    // ----------------------------------------------------------
    //  Comparación rápida
    // ----------------------------------------------------------
    std::cout << "\nResumen:\n";
    std::cout << "  Stack  : Punto p(1,2);          <- automático, destrucción automática\n";
    std::cout << "  Heap   : Punto* p = new Punto;  <- manual, requiere delete\n";
    std::cout << "  Acceso : p.x  (stack)  |  ptr->x  (heap via puntero)\n";

    return 0;
}
