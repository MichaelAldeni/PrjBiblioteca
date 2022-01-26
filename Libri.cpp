#include "Libri.h"


Libri::Libri() {
	id = current_id++;
	nome = "";
	autore = "";
	prezzo_prestito = 0;
	prestato = false;
}

Libri::Libri(string n,  string a, float prz) {
	id = current_id++;
	nome = n;
	autore = a;
	prezzo_prestito = prz;
	prestato = false;
}

Libri::~Libri() {
	id = 0;
	nome = "";
	autore = "";
	prezzo_prestito = 0;
	prestato = false;
}

Libri::Libri(const Libri& l) {
	id = l.id;
	nome = l.nome;
	autore = l.autore;
	prezzo_prestito = l.prezzo_prestito;
	prestato = l.prestato;
}

Libri& Libri::operator=(const Libri& l) {
	id = l.id;
	nome = l.nome;
	autore = l.autore;
	prezzo_prestito = l.prezzo_prestito;
	prestato = l.prestato;

	return *this;
}

ostream& operator<<(ostream& os, Libri l) {
	os << l.nome << ";" << l.autore << ";" << l.prezzo_prestito;
	return os;
}

void Libri::modifica_prestito() {
	if (prestato == false)
		prestato = true;
	else prestato = false;
	return;
}

Libri Libri::aggiungi(ifstream &ifs) {
	Libri book;

	string n, a, p_s;
	float p;

	getline(ifs, n, ';');
	getline(ifs, a, ';');
	getline(ifs, p_s);
	p = atof(p_s.c_str());

	book.setNome(n);
	book.setAutore(a);
	book.setPrezzo(p);

	return book;
}