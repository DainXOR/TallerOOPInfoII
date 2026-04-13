// ============================================================
//  MÓDULO 3 – Constructores y Destructores
//  Tema: Constructor por defecto, con parámetros, destructor
//  Problema: Gestión de un Producto con precio
// ============================================================

#include <iostream>
#include <string>

// ============================================================
//  VERSIÓN ESTRUCTURADA
// ============================================================
//
//  No existe el concepto de constructor.  El programador debe
//  inicializar manualmente cada campo — es fácil olvidar alguno.
// ============================================================

struct ProductoStruct {
    std::string nombre;
    double precio;
    int    cantidad;
};

// Función de "inicialización" manual — equivalente artesanal al constructor
void inicializarProducto(ProductoStruct &p, std::string n, double pr, int c) {
    p.nombre    = n;
    p.precio    = pr;
    p.cantidad  = c;
}

void mostrarProductoStruct(ProductoStruct p) {
    std::cout << "  " << p.nombre << " | $" << p.precio
         << " x " << p.cantidad << " unidades\n";
}

// ============================================================
//  VERSIÓN OOP
// ============================================================
//
//  El constructor es un método especial que:
//    • Tiene el MISMO nombre que la clase.
//    • Se ejecuta AUTOMÁTICAMENTE al crear el objeto.
//    • NO tiene tipo de retorno (ni siquiera void).
//
//  El destructor:
//    • Comienza con ~ (tilde) seguido del nombre de la clase.
//    • Se ejecuta AUTOMÁTICAMENTE cuando el objeto se destruye.
//    • Útil para liberar recursos (memoria, archivos, etc.).
// ============================================================

class Producto {
public:
    std::string nombre;
    double precio;
    int    cantidad;

    // --- Constructor por defecto ---
    // Se llama cuando creamos: Producto p;
    Producto() {
        nombre   = "Sin nombre";
        precio   = 0.0;
        cantidad = 0;
        std::cout << "  [Constructor por defecto] Producto creado: " << nombre << "\n";
    }

    // --- Constructor con parámetros ---
    // Se llama cuando creamos: Producto p("Libro", 15.99, 10);
    Producto(std::string n, double pr, int c) {
        nombre   = n;
        precio   = pr;
        cantidad = c;
        std::cout << "  [Constructor con params] Producto creado: " << nombre << "\n";
    }

    // --- Destructor ---
    // Se llama automáticamente cuando el objeto sale de su ámbito (scope)
    ~Producto() {
        std::cout << "  [Destructor] Producto destruido: " << nombre << "\n";
    }

    void mostrar() {
        std::cout << "  " << nombre << " | $" << precio
             << " x " << cantidad << " unidades\n";
    }
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 3: Constructores y Destructores\n";
    std::cout << "==============================\n";

    // --- Estructurada ---
    std::cout << "\n[Estructurada] – inicialización manual\n";
    ProductoStruct ps;
    inicializarProducto(ps, "Cuaderno", 3.50, 50);
    mostrarProductoStruct(ps);
    // Si olvidamos llamar a inicializarProducto, los datos quedan "basura"

    // --- OOP: constructor por defecto ---
    std::cout << "\n[OOP] – constructor por defecto\n";
    {   // bloque para controlar el ciclo de vida
        Producto p1;             // llama al constructor por defecto automáticamente
        p1.mostrar();
    }   // <-- aquí se llama al destructor de p1 automáticamente

    // --- OOP: constructor con parámetros ---
    std::cout << "\n[OOP] – constructor con parámetros\n";
    {
        Producto p2("Lápiz", 1.25, 100);   // constructor con params
        Producto p3("Borrador", 0.75, 200);
        p2.mostrar();
        p3.mostrar();
    }   // <-- destructores de p2 y p3 al salir del bloque

    std::cout << "\nConceptos clave:\n";
    std::cout << "  Constructor : inicializa el objeto AUTOMÁTICAMENTE al crearlo\n";
    std::cout << "  Destructor  : limpia recursos AUTOMÁTICAMENTE al destruirlo\n";
    std::cout << "  Sobrecarga  : una clase puede tener VARIOS constructores\n";

    return 0;
}
