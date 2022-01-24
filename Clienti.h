#include "Biblioteca.h"

using namespace std;


class Clienti {
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
	long int numero_telefono;
	
	/// <param name="n_prestito">Variabile riguardante la gestione dei libri in prestito per ogni cliente</param>
	int n_prestito;
	

public:

	/// <summary>Funzioni pubbliche della classe dei Clienti</summary>
	
	
	/// <item>Costruttore per la classe Clienti, la inizializza</item> 
	Clienti(string n, string c, string us_name, string pass, long int num=0);

	/// <item>Funzione di assegnazione del nome</item>
	void setNome(string n) {nome = n; };

	/// <item>Funzione di assegnazione per il cognome</item>
	void setCognome(string c) {cognome = c;};

	/// <item>Funzione di assegnazione per il nome utente scelto dal cliente</item>
	void setUser(string us) { user = us; };

	/// <item>Funzione di assegnazione della password scelta dal cliente</item>
	void setPassword(string pass) { password = pass; };

	/// <item>Funzione di assegnazione codice fiscale del cliente</item>
	void setCod_fiscale(string cod) { codice_fiscale = cod; };
	
	/// <item>Funzione di assegnazione del numero di telefono del cliente</item>
	void setNumero(long int num) { numero_telefono = num; };

	/// <item>Funzione di restituzione del nome del cliente</item>
	/// <returns>Restituisce il nome del cliente</returns>
	/// <seealso cref="codice_fiscale"/>
	string getNome()const { return nome; };
	

	/// <item>Funzione di restituzuione del cognome del cliente</item>
	/// <returns>Restituisce il cognome del cliente</returns>
	/// <seealso cref="cognome"/>
	string getCognome()const { return cognome; };

	/// <item>Funzione di restituzuione del nome utetnte del cliente</item>
	/// <returns>Restituisce il nome utente del cliente</returns>
	/// <seealso cref="user"/>
	string getUser()const { return user; };
	
	/// <item>Funzione di restituzuione della password del cliente, costante in modo da non essre modificata</item>
	/// <returns>Restituisce la password del cliente</returns>
	/// <seealso cref="password"/>
	string getPassword()const { return password; };
	

	/// <item>Funzione di restituzuione della codice fiscale del cliente</item>
	/// <returns>Restituisce il codice fiscale del cliente</returns>
	/// <seealso cref="codice_fiscale"/>
	string getCod_fiscale()const { return codice_fiscale; };
	

	/// <item>Funzione di restituzuione della numero del cliente</item>
	/// <returns>Restituisce il numero di telefono del cliente</returns>
	/// /// <seealso cref="numero_telefono"/>
	long int getNumero()const { return numero_telefono; };
	

};