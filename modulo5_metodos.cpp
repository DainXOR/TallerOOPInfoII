// ============================================================
//  MÓDULO 5 – Métodos de clase
//  Tema: métodos normales, paso de parámetros, métodos inline
//  Problema: Calculadora de área de figuras geométricas
// ============================================================

#include <iostream>
#include <math.h>     // para M_PI y pow

// ============================================================
//  VERSIÓN ESTRUCTURADA
// ============================================================
//
//  Las funciones están sueltas en el espacio global.
//  Todos los datos necesarios deben pasarse como parámetros.
//  Si hay muchas figuras, el número de funciones crece rápido
//  y los nombres deben ser muy descriptivos para no confundirse.
// ============================================================

double areaRectanguloFunc(double base, double altura) {
    return base * altura;
}

double areaCirculoFunc(double radio) {
    return M_PI * radio * radio;
}

double areaTrianguloFunc(double base, double altura) {
    return (base * altura) / 2.0;
}

double perimetroRectanguloFunc(double base, double altura) {
    return 2 * (base + altura);
}

// ============================================================
//  VERSIÓN OOP
// ============================================================
//
//  Cada figura es una clase con sus propios atributos y métodos.
//  Los métodos "saben" qué atributos usar — no necesitan parámetros
//  redundantes porque ya tienen acceso a los datos del objeto.
//
//  Método inline: definido directamente dentro de la clase.
//  El compilador puede sustituir la llamada por el cuerpo del método
//  (optimización), aunque esto es transparente al programador.
// ============================================================

class Rectangulo {
public:
    double base;
    double altura;

    Rectangulo(double b, double h) : base(b), altura(h) {}

    // Método inline (definido dentro de la clase)
    double area() { return base * altura; }

    double perimetro() { return 2 * (base + altura); }

    void mostrar() {
        std::cout << "  Rectángulo " << base << " x " << altura << "\n";
        std::cout << "    Área      = " << area() << "\n";
        std::cout << "    Perímetro = " << perimetro() << "\n";
    }
};

class Circulo {
public:
    double radio;

    Circulo(double r) : radio(r) {}

    // Método inline
    double area()       { return M_PI * radio * radio; }
    double perimetro()  { return 2 * M_PI * radio; }   // circunferencia

    void mostrar() {
        std::cout << "  Círculo radio=" << radio << "\n";
        std::cout << "    Área          = " << area() << "\n";
        std::cout << "    Circunferencia= " << perimetro() << "\n";
    }
};

class Triangulo {
public:
    double base;
    double altura;
    double ladoA, ladoB, ladoC;   // para el perímetro

    Triangulo(double b, double h, double a, double lb, double c)
        : base(b), altura(h), ladoA(a), ladoB(lb), ladoC(c) {}

    double area()       { return (base * altura) / 2.0; }
    double perimetro()  { return ladoA + ladoB + ladoC; }

    void mostrar() {
        std::cout << "  Triángulo base=" << base << " alt=" << altura << "\n";
        std::cout << "    Área      = " << area() << "\n";
        std::cout << "    Perímetro = " << perimetro() << "\n";
    }
};

// ============================================================
//  DEMOSTRACIÓN: paso de objeto como parámetro a una función
// ============================================================
//
//  Los objetos se pueden pasar a funciones igual que cualquier
//  variable — por valor (copia) o por referencia.
// ============================================================

// Función que recibe un Rectangulo por referencia
void escalarRectangulo(Rectangulo &r, double factor) {
    r.base    *= factor;
    r.altura  *= factor;
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 5: Métodos de clase\n";
    std::cout << "==============================\n";

    // --- Estructurada ---
    std::cout << "\n[Estructurada]\n";
    std::cout << "  Área rectángulo 4x3   = " << areaRectanguloFunc(4, 3) << "\n";
    std::cout << "  Área círculo r=5      = " << areaCirculoFunc(5) << "\n";
    std::cout << "  Área triángulo 6x4    = " << areaTrianguloFunc(6, 4) << "\n";
    std::cout << "  Perim. rectángulo 4x3 = " << perimetroRectanguloFunc(4, 3) << "\n";

    // --- OOP ---
    std::cout << "\n[OOP]\n";
    Rectangulo rect(4, 3);
    rect.mostrar();

    Circulo circ(5);
    circ.mostrar();

    Triangulo tri(6, 4, 6, 5, 5);
    tri.mostrar();

    // Paso de objeto como parámetro
    std::cout << "\n[OOP] – pasar objeto como parámetro (escalar x2)\n";
    escalarRectangulo(rect, 2.0);
    rect.mostrar();

    std::cout << "\nConceptos clave:\n";
    std::cout << "  Método inline : definido DENTRO de la clase (el compilador puede optimizarlo)\n";
    std::cout << "  this          : puntero implícito al objeto actual (avanzado)\n";
    std::cout << "  Los métodos acceden a los atributos SIN recibirlos como parámetro\n";

    return 0;
}
