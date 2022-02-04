/// <seealso cref="Libri.h"/>
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

void Libri::stampaPrestato() {
	if (getPrestato() == true)
		cout << "SI" << endl;
	else cout << "NO";
}

void aggiungi(vector<Libri> &v) {
	string nome, autore;
	float prezzo;
	
	do {
		cout << endl << "Inserisci il nome: ";
		getline(cin, nome);

	} while (nome.empty());
	
	do {
		cout << "Inserisci l'autore: ";
		getline(cin, autore);

	} while (autore.empty());

	do {
		cout << "Inserisci il prezzo: ";
		cin >> prezzo;

	} while (prezzo == 0);

	Libri book(nome, autore, prezzo);
	v.push_back(book);
}

void stampa_libri(vector<Libri> v) {
	vector<Libri>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		cout << *it << endl;
	cout << endl;
}

void modifica_prestito_vettore(vector<Libri>& v) {
	string n;
	bool check = false;

	cout << "Inserisci il nome del libro da prestare: ";
	getline(cin, n);

	vector<Libri>::iterator it;
	for (it = v.begin(); it != v.end(); it++)
		if ((*it).getNome() == n) {
			(*it).modifica_prestito();
			check = true;
		}
	if (check == false)
		cout << "Libro non presente in biblioteca";
}

void elimina_libro(vector<Libri>& v) {
	string n;

	cout << "Inserisci il nome del libro da eliminare: ";
	getline(cin, n);
	

	int i;
	for (i = 0; i != v.capacity(); i++)
		if (v[i].getNome() == n) {
			v[i].~Libri();
			break;
		}

	for (int j = i; j != v.capacity()-1; j++)
		v[j] = v[j+1];

	v.resize(v.capacity() - 1);
}

vector<Libri> cerca_autore(vector<Libri> v, string str)
{
	vector<Libri> vect;
	vector<Libri>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if ((*it).getAutore() == str) {
			vect.push_back(*it);
		}

	}
	if (vect.empty())
		cout << "Mi dispiace, la biblioteca non possiede alcun libro di " << str << endl;
	return vect;

}

Libri cerca_libro(vector<Libri> v, string str)
{
	Libri l;

	vector<Libri>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		if ((*it).getNome() == str) {
			l = *it;
		}

	}
	if (l.getNome().empty()) {
		cout << "Mi dispiace, il libro " << str << "non e' presente nella biblioteca" << endl;
		exit(EXIT_FAILURE);
	}
	return l;

}
