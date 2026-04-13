// ============================================================
//  MÓDULO 2 – Clases y Objetos
//  Tema: Definición de clase, atributos, métodos, acceso public
//  Problema: Cuenta bancaria simple
// ============================================================

#include <iostream>
#include <string>

// ============================================================
//  VERSIÓN ESTRUCTURADA
// ============================================================
//
//  Con structs y funciones sueltas no hay "encapsulamiento":
//  cualquiera puede leer o escribir directamente los campos.
//  No existe un lugar natural para agrupar la lógica.
// ============================================================

struct CuentaStruct {
    std::string titular;
    double saldo;
};

void depositarStruct(CuentaStruct &c, double monto) {
    if (monto > 0) c.saldo += monto;
}

void retirarStruct(CuentaStruct &c, double monto) {
    if (monto > 0 && monto <= c.saldo) c.saldo -= monto;
    else std::cout << "  [Error] Fondos insuficientes o monto inválido.\n";
}

void mostrarCuentaStruct(CuentaStruct c) {
    std::cout << "  Titular: " << c.titular
         << " | Saldo: $" << c.saldo << "\n";
}

// ============================================================
//  VERSIÓN OOP
// ============================================================
//
//  La clase agrupa TODO lo relacionado con una cuenta.
//  Los métodos son parte del objeto; la lógica vive donde pertenece.
//
//  Diagrama básico de la clase:
//
//  +------------------+
//  |   CuentaBancaria |
//  +------------------+
//  | + titular        |  <- atributo (dato)
//  | + saldo          |  <- atributo (dato)
//  +------------------+
//  | + depositar()    |  <- método (comportamiento)
//  | + retirar()      |  <- método (comportamiento)
//  | + mostrar()      |  <- método (comportamiento)
//  +------------------+
// ============================================================

class CuentaBancaria {
public:
    // --- Atributos ---
    std::string titular;
    double saldo;

    // --- Métodos ---
    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            std::cout << "  Depósito de $" << monto << " realizado.\n";
        }
    }

    void retirar(double monto) {
        if (monto > 0 && monto <= saldo) {
            saldo -= monto;
            std::cout << "  Retiro de $" << monto << " realizado.\n";
        } else {
            std::cout << "  [Error] Fondos insuficientes o monto inválido.\n";
        }
    }

    void mostrar() {
        std::cout << "  Titular: " << titular
             << " | Saldo: $" << saldo << "\n";
    }
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    std::cout << "==============================\n";
    std::cout << " MÓDULO 2: Clases y Objetos\n";
    std::cout << "==============================\n";

    // --- Estructurada ---
    std::cout << "\n[Estructurada]\n";
    CuentaStruct cs;
    cs.titular = "Carlos";
    cs.saldo   = 0.0;
    depositarStruct(cs, 500.0);
    retirarStruct(cs, 200.0);
    retirarStruct(cs, 400.0);   // debe fallar
    mostrarCuentaStruct(cs);

    // --- OOP ---
    std::cout << "\n[OOP]\n";
    CuentaBancaria cuenta;      // OBJETO creado a partir de la clase
    cuenta.titular = "Carlos";
    cuenta.saldo   = 0.0;
    cuenta.depositar(500.0);    // el objeto hace la acción
    cuenta.retirar(200.0);
    cuenta.retirar(400.0);      // debe fallar
    cuenta.mostrar();

    // ¿Cómo se crea un segundo objeto?
    std::cout << "\n[OOP – segundo objeto independiente]\n";
    CuentaBancaria cuenta2;
    cuenta2.titular = "Laura";
    cuenta2.saldo   = 1000.0;
    cuenta2.mostrar();
    // 'cuenta' y 'cuenta2' son objetos distintos, cada uno con sus propios datos

    std::cout << "\nConceptos clave:\n";
    std::cout << "  Clase  : el MOLDE (CuentaBancaria)\n";
    std::cout << "  Objeto : la INSTANCIA concreta (cuenta, cuenta2)\n";
    std::cout << "  Método : función que PERTENECE a la clase\n";

    return 0;
}
