#include "Biblioteca.h"

using namespace std;


class Cliente {
	/// <summary>Classe clienti</summary> 
	/// <remarks>
	/// <list type="bullet">
	/// <item>Questa classe conterrà tutti i clienti della libreria</item> 
	/// </remarks>

	/// <summary>Queste sono le variabili utilizzate per l'implementazione della lista</summary>
	/// <param name="nome">Stringa per gestire il nome dell'utente</param>
	string nome;

	/// <param name="cognome">Stringa per gestire il cognome dell'utente</param>
	string cognome;

	/// <param name="user">Variabile che gestisce la credenziale di accesso per il login nel programma dell'utente</param>
	string user;

	/// <param name="password">Password utilizzata per il login nel programma da parte dell'utente</param>
	string password;

	/// <param name="codice_fiscale">Codice fiscale, utilizzato per identificare il cliente </param>
	string codice_fiscale;

	/// <param name="numero_telefono">Variabile che gestisce i numeri di telefono dei vari clienti, 1 per ogni cliente</param>
	int numero_telefono;

	/// <param name="n_prestito">Variabile riguardante la gestione dei libri in prestito per ogni cliente</param>
	int n_prestito;

public:
	///<summary>Funzioni pubbliche della classe dei Clienti</summary>

	///<param name="Clienti">Costruttore per la classe Clienti, la inizializza</param> 
	Cliente(string n, string c, string cod_fisc, string us_name, string pass, int num);

	///<param name="setNome">Funzione di assegnazione del nome</param>
	void setNome(string n) { nome = n; }

	///<param name="setCognome">Funzione di assegnazione per il cognome</param>
	void setCognome(string c) { cognome = c; }

	///<param name="setUser">Funzione di assegnazione per il nome utente scelto dal cliente</param>
	void setUser(string us) { user = us; }

	///<param name="setPassword">Funzione di assegnazione della password scelta dal cliente</param>
	void setPassword(string pass) { password = pass; }

	///<param name="setCod_fiscale">Funzione di assegnazione codice fiscale del cliente</param>
	void setCod_fiscale(string cod) { codice_fiscale = cod; }

	///<param name="setNumero">Funzione di assegnazione del numero di telefono del cliente</param>
	void setNumero(int num) { numero_telefono = num; }

	///<param name="getNome">Funzione di restituzione del nome del cliente</param>
	string getNome()const { return nome; }
	///<returns>Restituisce il nome del cliente</returns>

	///<param name="getCognome">Funzione di restituzuione del cognome del cliente</param>
	string getCognome()const { return cognome; }
	///<returns>Restituisce il cognome del cliente</returns>

	///<param name="getUser">Funzione di restituzuione del nome utetnte del cliente</param>
	string getUser()const { return user; }

	///<param name="getPassword">Funzione di restituzuione della password del cliente, costante in modo da non essre modificata</param>
	string getPassword()const { return password; }
	///<returns>Restituisce la password del cliente</returns>

	///<param name="getCod_fiscale">Funzione di restituzuione della codice fiscale del cliente</param>
	string getCod_fiscale()const { return codice_fiscale; }
	///<returns>Restituisce il codice fiscale del cliente</returns>

	///<param name="getNumero">Funzione di restituzuione della numero del cliente</param>
	long int getNumero()const { return numero_telefono; }
	///<returns>Restituisce il numero di telefono del cliente</returns>


	friend void registrazione(vector <Cliente>& vect);
	//funzione che permette di effettuare la registrazione di un nuovo cliente, i dati dei clienti sono memorizzati in un vettore
	friend void elimina_Cliente(Cliente x, vector <Cliente>& vect);
	//funzione che permette di eliminare un cliente dal vettore
	friend void stampa_vettore(vector <Cliente>& vect);
	//stampa delle informazione di tutti i clienti registrati 
	friend void stampa_Cliente(string user, vector <Cliente>& vect);
	//stampa delle informazioni di un determinato cliente

	friend bool is_on(string str, vector <Cliente>& vect);
	//funzione ausiliaria, controlla se la stringa str è presente nel vettore vect
	friend bool ceck_pass(string str);
	//funzione ausiliaria, controlla la validità della password



	// OVERLOAD DEGLI OPERATORI 
	friend ostream &operator<<(ostream &os, Cliente x);



};
