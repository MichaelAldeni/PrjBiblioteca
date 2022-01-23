#include "Biblioteca.h"

using namespace std;


class Clienti {
	//<summary>Classe clienti</summary> 
	///<remarks>
	///<list type="bullet">
	///<item>Questa classe conterrà tutti i clienti della libreria</item> 
	///</remarks>/

	///<summary>Queste sono le variabili utilizzate per l'implementazione della lista</summary>
	///<param name="nome">Stringa per gestire il nome dell'utente</param>
	///<param name="cognome">Stringa per gestire il cognome dell'utente</param>
	///<param name="user">Variabile che gestisce la credenziale di accesso per il login nel programma dell'utente</param>
	///<param name="password">Password utilizzata per il login nel programma da parte dell'utente</param>
	///<param name="codice_fiscale">Codice fiscale, utilizzato per identificare il cliente </param>
	string nome, cognome, user, password, codice_fiscale;
	long int numero_telefono;
	///<param name="numero_telefono">Variabile che gestisce i numeri di telefono dei vari clienti, 1 per ogni cliente</param>
	int n_prestito;
	///<param name="n_prestito">Variabile riguardante la gestione dei libri in prestito per ogni cliente</param>

public:
	///<summary>Funzioni pubbliche della classe dei Clienti</summary>
	
	
	///<param name="Clienti">Costruttore per la classe Clienti, la inizializza</param> 
	Clienti(string n, string c, string us_name, string pass, long int num=0);

	///<param name="setNome">Funzione di assegnazione del nome</param>
	void setNome(string n) {nome = n; };

	///<param name="setCognome">Funzione di assegnazione per il cognome</param>
	void setCognome(string c) {cognome = c;};

	///<param name="setUser">Funzione di assegnazione per il nome utente scelto dal cliente</param>
	void setUser(string us) { user = us; };

	///<param name="setPassword">Funzione di assegnazione della password scelta dal cliente</param>
	void setPassword(string pass) { password = pass; };

	///<param name="setCod_fiscale">Funzione di assegnazione codice fiscale del cliente</param>
	void setCod_fiscale(string cod) { codice_fiscale = cod; };
	
	///<param name="setNumero">Funzione di assegnazione del numero di telefono del cliente</param>
	void setNumero(long int num) { numero_telefono = num; };

	///<param name="getNome">Funzione di restituzione del nome del cliente</param>
	string getNome()const { return nome; };
	///<returns>Restituisce il nome del cliente</returns>

	///<param name="getCognome">Funzione di restituzuione del cognome del cliente</param>
	string getCognome()const { return cognome; };
	///<returns>Restituisce il cognome del cliente</returns>

	///<param name="getUser">Funzione di restituzuione del nome utetnte del cliente</param>
	string getUser()const { return user; };
	
	///<param name="getPassword">Funzione di restituzuione della password del cliente, costante in modo da non essre modificata</param>
	string getPassword()const { return password; };
	///<returns>Restituisce la password del cliente</returns>

	///<param name="getCod_fiscale">Funzione di restituzuione della codice fiscale del cliente</param>
	string getCod_fiscale()const { return codice_fiscale; };
	///<returns>Restituisce il codice fiscale del cliente</returns>

	///<param name="getNumero">Funzione di restituzuione della numero del cliente</param>
	long int getNumero()const { return numero_telefono; };
	///<returns>Restituisce il numero di telefono del cliente</returns>

};