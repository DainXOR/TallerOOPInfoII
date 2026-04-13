// ============================================================
//  MÓDULO 8 – Sobrecarga
//  Tema: sobrecarga de funciones y operadores (+, ==, =)
//  Problema: Vector 2D matemático
// ============================================================

#include <iostream>
#include <cmath>
#include <string>

// ============================================================
//  PARTE A – Sobrecarga de FUNCIONES
// ============================================================
//
//  C++ permite definir múltiples funciones con el MISMO nombre
//  siempre que difieran en el número o tipo de sus parámetros.
//  El compilador elige la versión correcta según los argumentos.
// ============================================================

// Misma función "imprimir" para distintos tipos
void imprimir(int    x) { std::cout << "  [int]    " << x << "\n"; }
void imprimir(double x) { std::cout << "  [double] " << x << "\n"; }
void imprimir(std::string s) { std::cout << "  [string] " << s << "\n"; }

// Misma función "sumar" con distinta cantidad de parámetros
int sumar(int a, int b)           { return a + b; }
int sumar(int a, int b, int c)    { return a + b + c; }

// ============================================================
//  PARTE B – Sobrecarga de OPERADORES en una clase
// ============================================================
//
//  Los operadores (+, -, ==, etc.) no son más que funciones
//  con una sintaxis especial.  Podemos redefinirlos para que
//  funcionen con nuestras propias clases.
//
//  Sintaxis:
//    TipoRetorno operator SIMBOLO (parámetros) { ... }
//
//  Operadores que sobrecargaremos:
//    +   sumar dos vectores
//    ==  comparar si dos vectores son iguales
//    =   asignación (el compilador genera uno por defecto, lo hacemos explícito)
// ============================================================

// ============================================================
//  VERSIÓN ESTRUCTURADA – sin sobrecarga de operadores
// ============================================================

struct Vec2Struct {
    double x, y;
};

Vec2Struct sumarVecStruct(Vec2Struct a, Vec2Struct b) {
    Vec2Struct r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

bool igualesStruct(Vec2Struct a, Vec2Struct b) {
    return a.x == b.x && a.y == b.y;
}

void mostrarVecStruct(Vec2Struct v) {
    std::cout << "  (" << v.x << ", " << v.y << ")\n";
}

// ============================================================
//  VERSIÓN OOP – con sobrecarga de operadores
// ============================================================

class Vec2 {
public:
    double x, y;

    // Constructor
    Vec2(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // --- Sobrecarga de + ---
    //  Permite escribir: Vec2 c = a + b;
    //  En lugar de     : Vec2 c = sumarVec(a, b);
    Vec2 operator+(const Vec2& otro) const {
        return Vec2(x + otro.x, y + otro.y);
    }

    // --- Sobrecarga de - ---
    Vec2 operator-(const Vec2& otro) const {
        return Vec2(x - otro.x, y - otro.y);
    }

    // --- Sobrecarga de == ---
    //  Permite escribir: if (a == b)
    //  En lugar de     : if (iguales(a, b))
    bool operator==(const Vec2& otro) const {
        return x == otro.x && y == otro.y;
    }

    // --- Sobrecarga de != ---
    bool operator!=(const Vec2& otro) const {
        return !(*this == otro);   // reutilizamos == que ya definimos
    }

    // --- Sobrecarga de = (asignación) ---
    //  El compilador genera una versión por defecto, pero es útil
    //  saber cómo se escribe explícitamente.
    Vec2& operator=(const Vec2& otro) {
        if (this != &otro) {   // protección de auto-asignación: a = a
            x = otro.x;
            y = otro.y;
        }
        return *this;   // devolvemos el propio objeto para encadenar (a = b = c)
    }

    // --- Método auxiliar ---
    double magnitud() const {
        return sqrt(x*x + y*y);
    }

    void mostrar(std::string etiqueta = "") const {
        if (!etiqueta.empty()) std::cout << "  " << etiqueta << " = ";
        else std::cout << "  ";
        std::cout << "(" << x << ", " << y << ")"
             << "  |magnitud| = " << magnitud() << "\n";
    }
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 8: Sobrecarga\n";
    std::cout << "==============================\n";

    // --- A: Sobrecarga de funciones ---
    std::cout << "\n[A] Sobrecarga de funciones\n";
    imprimir(42);
    imprimir(3.14);
    imprimir("Hola mundo");
    std::cout << "  sumar(2,3)   = " << sumar(2, 3)    << "\n";
    std::cout << "  sumar(2,3,4) = " << sumar(2, 3, 4) << "\n";

    // --- B: Estructurada — operadores son funciones ---
    std::cout << "\n[B] Estructurada – operaciones con funciones\n";
    Vec2Struct va = {3.0, 4.0};
    Vec2Struct vb = {1.0, 2.0};
    Vec2Struct vc = sumarVecStruct(va, vb);   // notación incómoda
    mostrarVecStruct(vc);
    std::cout << "  ¿Iguales? " << (igualesStruct(va, vb) ? "Sí" : "No") << "\n";

    // --- B: OOP — operadores sobrecargados ---
    std::cout << "\n[B] OOP – con sobrecarga de operadores\n";
    Vec2 a(3.0, 4.0);
    Vec2 b(1.0, 2.0);

    Vec2 c = a + b;          // usa operator+  (legible, natural)
    Vec2 d = a - b;          // usa operator-
    a.mostrar("a");
    b.mostrar("b");
    c.mostrar("a + b");
    d.mostrar("a - b");

    std::cout << "  a == b ? " << (a == b ? "Sí" : "No") << "\n";
    std::cout << "  a == a ? " << (a == a ? "Sí" : "No") << "\n";

    // Asignación
    std::cout << "\n  Asignación: b = a\n";
    b = a;                   // usa operator=
    b.mostrar("b (ahora igual a a)");

    // Encadenamiento (posible porque operator= devuelve *this)
    std::cout << "\n  Encadenamiento: d = c = a\n";
    Vec2 e, f;
    f = e = a;
    e.mostrar("e");
    f.mostrar("f");

    std::cout << "\nConceptos clave:\n";
    std::cout << "  Sobrecarga funciones : mismo nombre, distintos parámetros\n";
    std::cout << "  Sobrecarga operadores: operator+ , operator== , operator=\n";
    std::cout << "  *this  : puntero al objeto actual (necesario en operator=)\n";
    std::cout << "  const  : indica que el método NO modifica el objeto\n";

    return 0;
}
