#include <iostream>
using namespace std;

// Clase base
class Handler {
protected:
    Handler* siguiente;

public:
    Handler() : siguiente(nullptr) {}

    void setSiguiente(Handler* sig) {
        siguiente = sig;
    }

    virtual void manejar(string solicitud) {
        if (siguiente != nullptr) {
            siguiente->manejar(solicitud);
        }
    }
};

// Validar que no esté vacía
class ValidarVacio : public Handler {
public:
    void manejar(string solicitud) override {
        if (solicitud.empty()) {
            cout << "❌ Error: cadena vacía\n";
        } else {
            cout << "✅ No está vacía\n";
            Handler::manejar(solicitud);
        }
    }
};

// Validar longitud
class ValidarLongitud : public Handler {
public:
    void manejar(string solicitud) override {
        if (solicitud.length() < 5) {
            cout << "❌ Error: muy corta\n";
        } else {
            cout << "✅ Longitud válida\n";
            Handler::manejar(solicitud);
        }
    }
};

// Validar número
class ValidarNumero : public Handler {
public:
    void manejar(string solicitud) override {
        bool tieneNumero = false;

        for (char c : solicitud) {
            if (isdigit(c)) {
                tieneNumero = true;
                break;
            }
        }

        if (!tieneNumero) {
            cout << "❌ Error: no tiene números\n";
        } else {
            cout << "✅ Contiene número\n";
            cout << "🎉 Cadena válida completamente\n";
        }
    }
};

int main() {
    ValidarVacio h1;
    ValidarLongitud h2;
    ValidarNumero h3;

    // Construir cadena
    h1.setSiguiente(&h2);
    h2.setSiguiente(&h3);

    string entrada;
    cout << "Ingrese una cadena: ";
    cin >> entrada;

    h1.manejar(entrada);

    return 0;
}
