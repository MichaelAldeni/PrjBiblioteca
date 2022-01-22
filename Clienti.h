#include "Biblioteca.h"

using namespace std;

class Clienti {
	string nome, cognome, user, password;
	long int numero_telefono;
	int n_prestito;

	
public:
	Clienti( string n, string c, string num, string mail);
	void setNome(string n) {nome = n; };
	void setCognome(string c) {cognome = c;};
	void setNumero(long int num) {numero_telefono = num;};
};