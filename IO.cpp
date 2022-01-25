/// <seealso cref="IO.h"/>
#include "IO.h"


vector<Libri> carica_libri() {
	vector<Libri> v;

	ifstream ifs;
	string filename = "Biblioteca.txt";

	ifs.open(filename);
	if (!ifs.is_open()) {
		cout << "Errore!: file non aperto correttamente.";
		exit;
	}

	int i = 0;
	while (!ifs.eof()) {
		Libri book;
		book.aggiungi(ifs);
		v[i++] = book;
	}

	return v;
}