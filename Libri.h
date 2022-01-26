#include "Biblioteca.h"

using namespace std;

static int current_id = 0;


class Libri {
	int id;
	string nome, autore;
	float prezzo_prestito;
	bool prestato;

public:
	//costruttore base
	Libri();
	//costruttore parametrizzato
	Libri(string n, string a, float prz);
	//distruttore
	~Libri();
	//costruttore di copia
	Libri(const Libri& l);

	//funzioni set
	void setNome(string n) { nome = n; };
	void setAutore(string a) { nome = a; };
	void setPrezzo(float p) { prezzo_prestito = p; };

	//funzioni get
	int getID() const { return id; };
	string getNome() const { return nome; };
	string getAutore() const { return autore; };
	float getPrezzo() const { return prezzo_prestito; }
	bool getPrestato() const { return prestato; }

	//overloading
	Libri& operator=(const Libri& l);
	friend ostream& operator<<(ostream &os, Libri l);

	//funzioni principali
	void modifica_prestito();
	Libri aggiungi(ifstream &ifs);

};
