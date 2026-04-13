// ============================================================
//  MÓDULO 7 – Diagramas de clase (básico)
//  Tema: representación UML, atributos/métodos, relación simple
//  Problema: Estudiante y Materia (sin herencia)
// ============================================================
//
//  DIAGRAMA UML (texto):
//
//  +---------------------+          +---------------------+
//  |      Materia        |          |     Estudiante      |
//  +---------------------+          +---------------------+
//  | - nombre : std::string   |          | - nombre : std::string   |
//  | - creditos : int    |          | - matricula : std::string|
//  | - aprobada : bool   |          | - promedio : double |
//  +---------------------+          +---------------------+
//  | + getNombre()       |<>--------| + inscribir()       |
//  | + getCreditos()     |  (tiene) | + calcularPromedio()|
//  | + aprobar()         |          | + mostrar()         |
//  | + mostrar()         |          +---------------------+
//  +---------------------+
//
//  Relación: Estudiante TIENE (composición simple) una Materia
//            (sin herencia — solo asociación directa)
//
//  Notación UML básica:
//    -  atributo  →  privado
//    +  atributo  →  público
//    <>-----------  asociación / composición
// ============================================================

#include <iostream>
#include <string>

// ============================================================
//  VERSIÓN ESTRUCTURADA
// ============================================================

struct MateriaStruct {
    std::string nombre;
    int    creditos;
    bool   aprobada;
};

struct EstudianteStruct {
    std::string nombre;
    std::string matricula;
    double promedio;
    MateriaStruct materia;   // el struct contiene otro struct
};

void mostrarEstudianteStruct(EstudianteStruct e) {
    std::cout << "  " << e.nombre << " [" << e.matricula << "]"
         << "  Promedio: " << e.promedio << "\n";
    std::cout << "  Materia: " << e.materia.nombre
         << " (" << e.materia.creditos << " créditos)"
         << (e.materia.aprobada ? " ✓" : " ✗") << "\n";
}

// ============================================================
//  VERSIÓN OOP – con dos clases relacionadas
// ============================================================

// --- Clase Materia ---
class Materia {
private:
    std::string nombre;
    int    creditos;
    bool   aprobada;

public:
    // Constructor
    Materia(std::string n = "Sin nombre", int c = 0)
        : nombre(n), creditos(c), aprobada(false) {}

    // Getters
    std::string getNombre()   { return nombre;   }
    int    getCreditos() { return creditos; }
    bool   getAprobada() { return aprobada; }

    // Setter / acción
    void aprobar() { aprobada = true; }

    void mostrar() {
        std::cout << "    Materia  : " << nombre
             << " | Créditos: " << creditos
             << " | Estado: " << (aprobada ? "Aprobada ✓" : "Pendiente ✗") << "\n";
    }
};

// --- Clase Estudiante (TIENE una Materia) ---
class Estudiante {
private:
    std::string  nombre;
    std::string  matricula;
    double  promedio;
    Materia materia;   // ← atributo de tipo Materia (composición)

public:
    // Constructor
    Estudiante(std::string n, std::string m, double prom, Materia mat)
        : nombre(n), matricula(m), promedio(prom), materia(mat) {}

    // Getters
    std::string getNombre()    { return nombre;    }
    std::string getMatricula() { return matricula; }
    double getPromedio()  { return promedio;  }

    // Acciones
    void inscribir(Materia nuevaMateria) {
        materia = nuevaMateria;
        std::cout << "  " << nombre << " inscrito en: " << nuevaMateria.getNombre() << "\n";
    }

    void aprobarMateria() {
        materia.aprobar();   // delega la acción al objeto Materia
    }

    void mostrar() {
        std::cout << "  Estudiante: " << nombre
             << " | Matrícula: " << matricula
             << " | Promedio: " << promedio << "\n";
        materia.mostrar();
    }
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 7: Diagramas de clase\n";
    std::cout << "==============================\n";

    // --- Estructurada ---
    std::cout << "\n[Estructurada]\n";
    MateriaStruct ms;
    ms.nombre   = "Programación I";
    ms.creditos = 4;
    ms.aprobada = false;

    EstudianteStruct es;
    es.nombre    = "Luis";
    es.matricula = "2024-001";
    es.promedio  = 85.5;
    es.materia   = ms;

    mostrarEstudianteStruct(es);
    es.materia.aprobada = true;   // sin protección — se accede directo
    mostrarEstudianteStruct(es);

    // --- OOP ---
    std::cout << "\n[OOP]\n";
    Materia prog("Programación I", 4);
    Estudiante est("Luis", "2024-001", 85.5, prog);
    est.mostrar();

    std::cout << "\n  Aprobando materia...\n";
    est.aprobarMateria();
    est.mostrar();

    std::cout << "\n  Inscribiendo en nueva materia...\n";
    Materia mate("Cálculo I", 5);
    est.inscribir(mate);
    est.mostrar();

    std::cout << "\nConceptos UML básicos:\n";
    std::cout << "  + método/atributo  → público  (public)\n";
    std::cout << "  - método/atributo  → privado  (private)\n";
    std::cout << "  Relación <>------  → composición (TIENE un objeto de otra clase)\n";

    return 0;
}
