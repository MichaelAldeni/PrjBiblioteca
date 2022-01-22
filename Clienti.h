#include "Biblioteca.h"

using namespace std;


class Clienti {
	int ID;
	string nome, cognome, user, password, codice_fiscale;
	long int numero_telefono;
	int n_prestito;

public:
	Clienti(string n, string c, string us_name, string pass, long int num=0);

	void setNome(string n) {nome = n; };
	void setCognome(string c) {cognome = c;};
	void setUser(string us) { user = us; };
	void setPassword(string pass) { password = pass };
	void setCod_fiscale(string cod) { codice_fiscale = cod };
	void setNumero(long int num) { numero = num; };
//	void setEmail(string mail) { email = mail; };

	int getID()const { return ID; };
	string getNome()const { return nome; };
	string getCognome()const { return cognome; };
	string getUser()const { return user; };
	string getPassword()const { return password; };
	string getCod_fiscale()const { return codice_fiscale; };
	long int getNumero()const { return numero_telefono; };


};