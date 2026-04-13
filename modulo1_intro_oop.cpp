// ============================================================
//  MÓDULO 1 – Introducción a OOP
//  Tema: Concepto de OOP, diferencia con programación estructurada
//  Problema: Modelar una "Persona" con nombre y edad
// ============================================================

#include <iostream>
#include <string>

// ============================================================
//  VERSIÓN ESTRUCTURADA (solo funciones y structs)
// ============================================================
//
//  En la programación estructurada los DATOS y las FUNCIONES
//  que los manipulan viven SEPARADOS.  El programador debe
//  recordar siempre qué función corresponde a qué dato.
// ============================================================

struct PersonaStruct {
    std::string nombre;
    int    edad;
};

// Las funciones "sueltas" deben recibir el struct como parámetro
void presentarPersonaStruct(PersonaStruct p) {
    std::cout << "Hola, me llamo " << p.nombre
         << " y tengo " << p.edad << " años.\n";
}

bool esMayorDeEdadStruct(PersonaStruct p) {
    return p.edad >= 18;
}

// ============================================================
//  VERSIÓN OOP (clase)
// ============================================================
//
//  En OOP los DATOS (atributos) y las FUNCIONES que los
//  manipulan (métodos) viven JUNTOS dentro de la clase.
//  El objeto "sabe" lo que puede hacer.
// ============================================================

class Persona {
public:
    // Atributos
    std::string nombre;
    int    edad;

    // Métodos — la lógica PERTENECE al objeto
    void presentar() {
        std::cout << "Hola, me llamo " << nombre
             << " y tengo " << edad << " años.\n";
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }
};

// ============================================================
//  MAIN – demostración comparativa
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 1: Intro a OOP\n";
    std::cout << "==============================\n";

    // --- Versión estructurada ---
    std::cout << "\n[Estructurada]\n";
    PersonaStruct ps;
    ps.nombre = "Ana";
    ps.edad   = 20;
    presentarPersonaStruct(ps);
    std::cout << "¿Mayor de edad? "
         << (esMayorDeEdadStruct(ps) ? "Sí" : "No") << "\n";

    // --- Versión OOP ---
    std::cout << "\n[OOP]\n";
    Persona obj;           // creamos un OBJETO de la clase Persona
    obj.nombre = "Ana";
    obj.edad   = 20;
    obj.presentar();       // el objeto llama a SU propio método
    std::cout << "¿Mayor de edad? "
         << (obj.esMayorDeEdad() ? "Sí" : "No") << "\n";

    std::cout << "\nDiferencia clave:\n";
    std::cout << "  Estructurada : presentarPersonaStruct(ps)  <- función externa\n";
    std::cout << "  OOP          : obj.presentar()             <- método del objeto\n";

    return 0;
}
