#include "Biblioteca.h"

using namespace std;

class Libri {
	int id;
	string nome;
	float prezzo_prestito;
	bool prestato;

public:
	//costruttore parametrizzato
	Libri(string n, float prz);

	//funzioni set
	void setNome(string n) { nome = n; };
	void setPrezzo(float p) { prezzo_prestito = p; };

	//funzioni get
	int getID() const { return id; };
	string getNome() const { return nome; };
	float getPrezzo() const { return prezzo_prestito; }
	bool getPrestato() const { return prestato; }

	//funzioni principali
	void modifica_prestito();
	void aggiungi();

};
