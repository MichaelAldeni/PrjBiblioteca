#include "Biblioteca.h"

using namespace std;

class Clienti {
	int ID;
	string nome, cognome, email;
	long int numero;
	

public:
	Clienti( string n, string c, string num, string mail);
	void setNome(string n) {nome = n; };
	void setCognome(string c) {cognome = c;};
	void setNumero(long int num) {numero = num;};
	void setEmail(string mail) { email = mail; };
};