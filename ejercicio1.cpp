#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./tads/tablasHash/tablaHashAbierta/tablaHashAbierta.cpp"

using namespace std;

int ejercicio1(int n, string s) {
    TablaHash tabla(26);
    int cant = 0;

    for (int i = 0; i < 2*n-2; i++) {
        char c = s[i];

        if (i % 2 == 0) {
            // llave
            string key(1, c); // convertir char → string

            int val;
            if (tabla.buscar(key, val)) {
                tabla.insertar(key, val + 1);
            } else {
                tabla.insertar(key, 1);
            }

        } else {
            // puerta
            char lower = c - 'A' + 'a';
            string key(1, lower);

            int val;
            if (tabla.buscar(key, val) && val > 0) {
                tabla.insertar(key, val - 1); // uso llave
            } else {
                cant++; // necesito pedir
            }
        }
    }

    return cant;
}

/*int ejercicio1(int n, string s) {
    TablaHash inventario(53);
    int llavesSolicitadas = 0;

    for (int i = 0; i < n - 1; i++) {

        // --- Paso 1: Recoger la llave ---
        char llaveChar = s[2 * i];
        string llaveTipo(1, llaveChar);

        int cantActual = 0;

        if (inventario.buscar(llaveTipo, cantActual)) {
            inventario.insertar(llaveTipo, cantActual + 1);
        } else {
            inventario.insertar(llaveTipo, 1);
        }

        // --- Paso 2: Abrir la puerta ---
        char puertaChar = s[2 * i + 1];
        string llaveNecesaria(1, (char)(puertaChar - 'A' + 'a'));

        int cantDisponible = 0;

        if (inventario.buscar(llaveNecesaria, cantDisponible) && cantDisponible > 0) {

            if (cantDisponible == 1) {
                inventario.eliminar(llaveNecesaria);
            } else {
                inventario.insertar(llaveNecesaria, cantDisponible - 1);
            }

        } else {
            llavesSolicitadas++;
        }
    }

    return llavesSolicitadas;
}*/
int main()
{
   int n;
    cin >> n;

    string s;
    cin >> s;
    cout << ejercicio1(n,s) << endl; 
}

