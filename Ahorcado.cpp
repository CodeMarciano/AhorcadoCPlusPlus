#include <iostream>
#include <string.h>

using namespace std;

string obtenerCadenaDeLinea(int tamanioPalabra){
    int i = 0;
    string linea;

    while(i < tamanioPalabra){
        linea += "_";
        i++;
    }

    return linea;
}

bool verificarLetra(string &palabra, char letra){

    int tamanioPalabra = (int)palabra.length();
    bool existe = false;
    int i = 0;

    while (i < tamanioPalabra){
        if(palabra[i] == letra){
            existe = true;
        }
        i++;
    }

    return existe;
}

void cambiarLineaPorLetra(string &linea, char letra, string &palabra){

    int i = 0;
    int tamanioLinea = (int)linea.length();

    while (i < tamanioLinea) {

        if (palabra[i] == letra) {
            linea[i] = letra;
        }

        i++;
    }
}

string obtenerLineaParaComparar(string &linea){

    int i = 0;
    int tamanioLinea = (int)linea.length();
    string lineaComparar;

    while (i < tamanioLinea) {
        if (linea[i] != ' ') {
            lineaComparar += linea[i];
        }
        i++;
    }

    return lineaComparar;
}

string obtenerCadenaDeLineaParaMostrar (string &linea){

    string lineaParaMostrar;
    int tamanioLinea = (int)linea.length();
    int i = 0;

    while (i < tamanioLinea) {

        lineaParaMostrar += linea[i];
        lineaParaMostrar += ' ';
        i++;
    }

    return lineaParaMostrar;
}


int main() {

    string palabra = "codemarciano";
    string linea;
    char letra = '\0'; // esta en null
    bool existeLetraEnPalabra, noSeTerminoElJuego = true;
    int vidas = 5;
    linea = obtenerCadenaDeLinea((int)palabra.length());

    cout << "Tienes " << vidas << " vida(s)\n";

    while (noSeTerminoElJuego) {

        if (vidas != 0) {
            string lineaMostrar = obtenerCadenaDeLineaParaMostrar(linea); //
            cout << lineaMostrar << "\n";
            string lineaAComparar = obtenerLineaParaComparar(linea);

            if (lineaAComparar == palabra) {
                cout << "Ganaste :)\n";
                noSeTerminoElJuego = false;
            } else {
                cout << "\nDigite una letra: ";
                cin.get(letra);
                cin.ignore();

            }
        } else {
            noSeTerminoElJuego = false;
        }

        if (noSeTerminoElJuego) {
            existeLetraEnPalabra = verificarLetra(palabra, letra);
            if (existeLetraEnPalabra) {

                cambiarLineaPorLetra(linea, letra, palabra);

            } else {
                vidas--;

                if (vidas == 0) {
                    cout << "Perdiste :(\n";
                } else {
                    cout << "\nIncorrecto\n";
                    cout << "Te queda " << vidas << " vida(s)\n";
                }

            }
        }

    }

    return 0;
}

