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

	while (!ifs.eof()) {
		Libri book;
		book.aggiungi(ifs);
		v.push_back(book);
	}

	return v;
}

void salva_libri(vector<Libri> v) {
	ofstream ofs;
	string filename = "Biblioteca.txt";

	ofs.open(filename);
	if (!ofs.is_open()) {
		cout << "Errore!: file non aperto correttamente.";
		exit;
	}

	vector<Libri>::iterator it = v.begin();
	for (it = v.begin(); it != v.end(); it++) {
		ofs << *it << endl;
	}
}