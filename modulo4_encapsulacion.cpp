// ============================================================
//  MÓDULO 4 – Encapsulación
//  Tema: private/public, getters, setters, protección de datos
//  Problema: Temperatura con validación (no < -273.15 °C)
// ============================================================

#include <iostream>

// ============================================================
//  VERSIÓN ESTRUCTURADA
// ============================================================
//
//  Sin encapsulación, nada impide asignar un valor inválido
//  directamente al campo.  La validación depende de que el
//  programador RECUERDE llamar la función correcta.
// ============================================================

struct TemperaturaStruct {
    double celsius;   // accesible desde cualquier parte — peligroso
};

void setTempStruct(TemperaturaStruct &t, double c) {
    if (c >= -273.15) t.celsius = c;
    else std::cout << "  [Error] Temperatura bajo el cero absoluto.\n";
}

double getTempStruct(TemperaturaStruct t) {
    return t.celsius;
}

// ============================================================
//  VERSIÓN OOP
// ============================================================
//
//  Con 'private', el atributo NO puede ser tocado desde afuera.
//  Solo los métodos de la propia clase pueden modificarlo.
//  Así la validación es OBLIGATORIA — no hay forma de saltársela.
//
//  Diagrama:
//
//  +---------------------------+
//  |       Temperatura         |
//  +---------------------------+
//  | - celsius  (private)      |  <- nadie de fuera puede tocarlo
//  +---------------------------+
//  | + setCelsius(double)      |  <- setter con validación
//  | + getCelsius() : double   |  <- getter (solo lectura)
//  | + getKelvin()  : double   |  <- método de conversión
//  | + getFahrenheit(): double |
//  +---------------------------+
// ============================================================

class Temperatura {
private:
    // *** El atributo es PRIVADO ***
    // Intentar hacer  obj.celsius = -999  desde fuera da ERROR de compilación
    double celsius;

public:
    // Constructor
    Temperatura(double c = 20.0) {
        setCelsius(c);   // usamos el setter para validar desde el inicio
    }

    // --- Setter (escritura con validación) ---
    void setCelsius(double c) {
        if (c >= -273.15) {
            celsius = c;
        } else {
            std::cout << "  [Error] Temperatura bajo el cero absoluto. Valor rechazado.\n";
        }
    }

    // --- Getter (lectura) ---
    double getCelsius() {
        return celsius;
    }

    // --- Métodos de conversión ---
    double getKelvin() {
        return celsius + 273.15;
    }

    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32.0;
    }

    void mostrar() {
        std::cout << "  " << celsius << " °C  |  "
             << getKelvin() << " K  |  "
             << getFahrenheit() << " °F\n";
    }
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 4: Encapsulación\n";
    std::cout << "==============================\n";

    // --- Estructurada: sin protección ---
    std::cout << "\n[Estructurada] – sin protección\n";
    TemperaturaStruct ts;
    ts.celsius = -500;  // ← DATO INVÁLIDO aceptado sin problema
    std::cout << "  Temperatura (inválida aceptada): " << ts.celsius << " °C\n";
    setTempStruct(ts, 25.0);
    std::cout << "  Temperatura válida: " << getTempStruct(ts) << " °C\n";

    // --- OOP: con encapsulación ---
    std::cout << "\n[OOP] – con encapsulación\n";
    Temperatura t(25.0);
    t.mostrar();

    std::cout << "\n  Intentando asignar -500 °C:\n";
    t.setCelsius(-500);    // la validación rechaza el valor
    t.mostrar();           // el valor anterior se conserva

    std::cout << "\n  Cambiando a -10 °C (válido):\n";
    t.setCelsius(-10);
    t.mostrar();

    // La siguiente línea daría ERROR de compilación (probarlo en clase):
    // t.celsius = -500;   // ERROR: 'celsius' is private

    std::cout << "\nConceptos clave:\n";
    std::cout << "  private : solo los métodos de la clase pueden acceder al dato\n";
    std::cout << "  public  : accesible desde cualquier parte del programa\n";
    std::cout << "  getter  : método que DEVUELVE el valor de un atributo privado\n";
    std::cout << "  setter  : método que MODIFICA el atributo (con validación)\n";

    return 0;
}
