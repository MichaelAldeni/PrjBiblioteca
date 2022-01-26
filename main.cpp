#include "Clienti.h"
#include "IO.h"

int main() {
	vector<Libri> biblioteca;
	cout << biblioteca.capacity() << endl;
	biblioteca = carica_libri();
	cout << biblioteca.capacity();


	return 0;
}