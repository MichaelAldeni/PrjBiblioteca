//============================================================================
// Nome        : main.cpp
// Autore      : Antonio D'Urso, Alessandro Villa, Michael Aldeni
// Versione    : 1
// Descrizione : Gestione di una biblioteca pubblica
//============================================================================

/// <seealso cref="Clienti.h"/>
#include "Clienti.h"
/// <seealso cref="IO.h"/>
#include "IO.h"

int main() {
    vector<Libri> biblioteca;
    cout << biblioteca.capacity() << endl;
    biblioteca = carica_libri();
    cout << biblioteca.capacity();

	return 0;
}