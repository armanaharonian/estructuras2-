#include <iostream>
#include <string>
#include "./table.cpp"
using namespace std;

struct Nodo {
    string clave;
    int valor;
    Nodo* sig;

    Nodo(string c, int v) {
        clave = c;
        valor = v;
        sig = nullptr;
    }
};

class TablaHash {
private:
    Nodo** tabla;
    int tam;

    int hashFunc(string clave) {
        int suma = 0;
        for (int i = 0; i < clave.length(); i++) {
            suma += clave[i] * (i + 1);
        }
        return suma % tam;
    }

public:
    TablaHash(int capacidad) {
        tam = capacidad;
        tabla = new Nodo*[tam];
        for (int i = 0; i < tam; i++)
            tabla[i] = nullptr;
    }

    void insertar(string clave, int valor) {
        int pos = hashFunc(clave);
        Nodo* actual = tabla[pos];
        Nodo* nuevo = new Nodo(clave, valor);
        nuevo->sig=actual;
        tabla[pos] = nuevo; 
    }

    bool buscar(string clave) {
        int pos = hashFunc(clave);
        Nodo* actual = tabla[pos];

        while (actual != nullptr) {
            if (actual->clave == clave) {
                return true;
            }
            actual = actual->sig;
        }
        return false;
    }
    int get(string clave){
        int pos = hashFunc(clave);
        Nodo* actual= tabla[pos];
        while(actual!= nullptr){
            if(actual->clave == clave) return actual->valor;
            else actual=actual->sig;
        }
        return -1;
    }
    void eliminar(string clave) {
        int pos = hashFunc(clave);
        Nodo* actual = tabla[pos];
        Nodo* anterior = nullptr;

        while (actual != nullptr) {
            if (actual->clave == clave) {
                if (anterior == nullptr)
                    tabla[pos] = actual->sig;
                else
                    anterior->sig = actual->sig;
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->sig;
        }
    }

    void imprimir() {
        for (int i = 0; i < tam; i++) {
            cout << "[" << i << "]";
            Nodo* actual = tabla[i];
            while (actual != nullptr) {
                cout << " -> " << actual->clave << ":" << actual->valor;
                actual = actual->sig;
            }
            cout << endl;
        }
    }

    ~TablaHash() {
        for (int i = 0; i < tam; i++) {
            Nodo* actual = tabla[i];
            while (actual != nullptr) {
                Nodo* tmp = actual;
                actual = actual->sig;
                delete tmp;
            }
        }
        delete[] tabla;
    }
};

/*int main() {
    TablaHash t(17);

    t.insertar("hola", 1);
    t.insertar("mundo", 2);
    t.insertar("foo", 3);
    t.insertar("bar", 4);
    t.insertar("hola", 99);

    t.imprimir();

    int v;
    if (t.buscar("hola", v))
        cout << "hola -> " << v << endl;

    t.eliminar("mundo");
    t.imprimir();

    return 0;
}*/