/// <seealso cref="Biblioteca.h"/>
#include "Biblioteca.h"
using namespace std;

/// <param name="current_id">Variabile utilizzata per autoincrementare l'ID.</param>
static int current_id = 0;


class Libri {
	/// <summary>Classe dei libri</summary>
	/// <remarks>
	/// <list type="bullet">
	/// <item>Questa classe conterrà tutti i libri presenti nella biblioteca.</item> 
	/// </remarks>

	/// <summary>Queste sono le variabili utilizzate per l'implementazione della lista.</summary>
	/// <param name="id">ID univoco assegnato automaticamente dal sistema.</param>
	int id;

	/// <param name="nome">Stringa utilizzata per gestire i nomi dei libri.</param>
	string nome;

	/// <param name="autore">Stringa utilizzata per gestire l'autore di ogni libro.</param>
	string autore;

	/// <param name="prezzo_prestito">Variabile utilizzata per gestire il prezzo di prestito del libro.</param>
	float prezzo_prestito;

	/// <param name="prestato">Variabile booleana utilizzata per capire se un libro � stato prestato.</param>
	bool prestato;

public:
	/// <summary>Funzioni pubbliche della classe dei Clienti.</summary>

	/// <item>Costruttore base della classe libri.</item>
	Libri();

	/// <item>Costruttore parametrizzato della classe libri.</item>
	Libri(string n, string a, float prz);
	
	/// <item>Distruttore della classe.</item>
	~Libri();

	/// <item>Costruttore di copia della classe.</item>
	Libri(const Libri& l);

	/// <item>Funzione di assegnazione del nome del libro.</item>
	void setNome(string n) { nome = n; };

	/// <item>Funzione di assegnazione dell' autore del libro.</item>
	void setAutore(string a) { nome = a; };

	/// <item>Funzione di assegnazione del prezzo del libro.</item>
	void setPrezzo(float p) { prezzo_prestito = p; };

	/// <item>Funzione di restituzione dell'ID del libro.</item>
	/// <returns>Restituisce l'ID del libro.</returns>
	/// <seealso cref="id"/>
	int getID() const { return id; };

	/// <item>Funzione di restituzione del nome del libro.</item>
	/// <returns>Restituisce il nome del libro.</returns>
	/// <seealso cref="nome"/>
	string getNome() const { return nome; };

	/// <item>Funzione di restituzione dell'autore del libro.</item>
	/// <returns>Restituisce l'ID del libro.</returns>
	/// <seealso cref="autore"/>
	string getAutore() const { return autore; };

	/// <item>Funzione di restituzione del prezzo del libro.</item>
	/// <returns>Restituisce il prezzo del libro.</returns>
	/// <seealso cref="prezzo_prestito"/>
	float getPrezzo() const { return prezzo_prestito; }

	/// <item>Funzione di restituzione dell'autore del libro.</item>
	/// <returns>Restituisce l'ID del libro</returns>
	/// <seealso cref="prestato"/>
	bool getPrestato() const { return prestato; }

	void stampaPrestato();

	/// <item>Funzione di ridefinizione dell'operatore "=".</item>
	Libri& operator=(const Libri& l);

	/// <item>Funzione di ridefinizione dell'operatore "<<".</item>
	friend ostream& operator<<(ostream& os, Libri l);

	/// <item>Funzione di modifica della variabile prestato.</item>
	void modifica_prestito();

	/// <item>Funzione che permette di aggiungere un libro.</item>
	friend void aggiungi(vector<Libri> &v);

	/// <item>Funzione che permette di stampare a video la lista dei libri.</item>
	friend void stampa_libri(vector<Libri> v);

	/// <item>Funzione di ricerca del libro al quale modificare il presetito.</item>
	friend void modifica_prestito_vettore(vector<Libri>& v);

	/// <item>Funzione di eliminazione di un libro.</item>
	friend void elimina_libro(vector<Libri>& v);

	/// <item>Funzione di ricerca di un determinato libro.</item>
	friend Libri cerca_libro(vector<Libri> v, string str);

	/// <item>Funzione di ricerca dell'autore di un libro.</item>
	friend vector<Libri> cerca_autore(vector<Libri> v, string str);
};
