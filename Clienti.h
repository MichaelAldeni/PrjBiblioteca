#include "Biblioteca.h"

using namespace std;


class Clienti {
	/// <summary>Classe clienti</summary> 
	/// <remarks>
	/// <list type="bullet">
	/// <item>Questa classe conterra' tutti i clienti della libreria.</item> 
	/// </remarks>

	/// <summary>Queste sono le variabili utilizzate per l'implementazione della lista.</summary>
	/// <param name="nome">Stringa per gestire il nome dell'utente.</param>
	string nome;

	/// <param name="cognome">Stringa per gestire il cognome dell'utente.</param>
	string cognome;

	/// <param name="user">Variabile che gestisce la credenziale di accesso per il login nel programma dell'utente.</param>
	string user;

	/// <param name="password">Password utilizzata per il login nel programma da parte dell'utente.</param>
	string password;

	/// <param name="codice_fiscale">Codice fiscale, utilizzato per identificare il cliente.</param>
	string codice_fiscale;

	/// <param name="numero_telefono">Variabile che gestisce i numeri di telefono dei vari clienti, 1 per ogni cliente.</param>
	string numero_telefono;

	/// <param name="n_prestito">Variabile riguardante la gestione dei libri in prestito per ogni cliente.</param>
	int n_prestito;

public:
	
	/// <item>Costruttore per la classe Clienti.</item>
	Clienti();

	/// <item>Costruttore per la classe Clienti, la inizializza.</item> 
	Clienti(string n, string c, string cod_fisc, string us_name, string pass, string num, int num_prestito);

	/// <item>Funzione di assegnazione del nome.</item>
	void setNome(string n) { nome = n; }

	/// <item>Funzione di assegnazione per il cognome.</item>
	void setCognome(string c) { cognome = c; }

	/// <item>Funzione di assegnazione per il nome utente scelto dal cliente.</item>
	void setUser(string us) { user = us; }

	/// <item>Funzione di assegnazione della password scelta dal cliente.</item>
	void setPassword(string pass) { password = pass; }

	/// <item>Funzione di assegnazione codice fiscale del cliente.</item>
	void setCod_fiscale(string cod) { codice_fiscale = cod; }

	/// <item>Funzione di assegnazione del numero di telefono del cliente.</item>
	void setNumero(string num) { numero_telefono = num; }

	/// <item>Funzione di assegnazione del numero di libri presi in prestito al cliente.</item>
	void setPrestito(int p) { n_prestito += p; }

	/// <item>Funzione di restituzione del nome del cliente.</item>
	string getNome()const { return nome; }
	/// <returns>Restituisce il nome del cliente.</returns>

	/// <item>Funzione di restituzuione del cognome del cliente.</item>
	string getCognome()const { return cognome; }
	/// <returns>Restituisce il cognome del cliente.</returns>

	/// <item>Funzione di restituzuione del nome utetnte del cliente.</item>
	string getUser()const { return user; }

	/// <item>Funzione di restituzuione della password del cliente, costante in modo da non essre modificata.</item>
	string getPassword()const { return password; }
	/// <returns>Restituisce la password del cliente.</returns>

	/// <item>Funzione di restituzuione della codice fiscale del cliente.</item>
	string getCod_fiscale()const { return codice_fiscale; }
	/// <returns>Restituisce il codice fiscale del cliente.</returns>

	/// <item>Funzione di restituzuione della numero del cliente.</item>
	string getNumero()const { return numero_telefono; }
	/// <returns>Restituisce il numero di telefono del cliente.</returns>

	/// <item>Funzione di restituzuione della numero di libri prestati al cliente.</item>
	int getPrestito()const { return n_prestito; }
	/// <returns>Restituisce il numero di libri prestati al cliente.</returns>
	
	/// <item>Funzione che permette di effettuare la registrazione di un nuovo cliente, i dati dei clienti sono memorizzati in un vettore.</item>
	friend void registrazione(vector <Clienti>& vect);
	/// <item>Funzione che permette di eliminare un cliente dal vettore.</item>
	friend void elimina_Cliente(vector <Clienti>& vect);
	/// <item>Stampa delle informazione di tutti i clienti registrati.</item>
	friend void stampa_vettore(vector <Clienti>& vect);
	/// <item>Stampa delle informazioni di un determinato cliente.</item>
	friend void stampa_Cliente(string user, vector <Clienti>& vect);
	
	/// <item>Stampa delle informazioni di un determinato cliente.</item>
	friend void modifica_pass(vector<Clienti> vect, bool log);

	/// <item>Funzione ausiliaria, controlla se la stringa str e' presente nel vettore.</item>
	friend bool is_on(string str, vector <Clienti>& vect);

	/// <item>Funzione ausiliaria, controlla la validita della password.</item>
	friend bool ceck_pass(string str);
	

	/// <item>OVERLOAD DELL'OPERATORE "<<"</item>
	friend ostream &operator<<(ostream &os, Clienti x);

	/// <item>Funzione che permette di modificare username o password, la variabile i permette di scegliere cosa modificare.</item>
	friend void modifica(vector<Clienti>& vect, int i, string& u, string& p, string& cf);

	/// <item>Funzione che permette di incrementare il contatore dei libri prestati di un determinato cliente.</item>
	friend void modifica_prestito_piu(vector<Clienti>& v, string& cf);

	/// <item>Funzione che permette di diminuire, il contatore dei libri prestati di un determinato cliente.</item>
	friend void modifica_prestito_meno(vector<Clienti>& v, string& cf);

};
