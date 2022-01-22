#include "Biblioteca.h"

using namespace std;

class Libri {
	int ID;
	string nome;
	float prezzo_prestito;
	bool prestato;

	Autori autore;

public:
	Libro(int ID, string n, float prz, bool pre);

	//	void setID();
	void setNome(string n) { nome = n; };
	void setPrezzo(float p) { prezzo_prestito = p; };
	void prestato() { prestato = true; };

	int getID() { return ID; };
	string getNome() { return nome; };
	float getPrezzo() { return prezzo_prestito; }
	bool getPrestato() { return prestato; }

//	void ordina_Autore();
	void ordina_Nome();
};

class Autori : public Libri {
	string nome, cognome;

public:
	Autori();
	void setAutore(string nome, string cognome);

	//		void stampaAutore(string nome, string cognome);
	//		void delAutore(string nome, string cognome);
};
