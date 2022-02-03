/// <seealso cref="Clienti.h"/>
#include "Clienti.h"

#pragma warning(disable : 4996)


Clienti::Clienti(string n, string c, string cod_fisc, string us_name, string pass, int num)
{
	nome = n;
	cognome = c;
	codice_fiscale = cod_fisc;
	user = us_name;
	password = pass;
	numero_telefono = num;

}

bool is_on(string str, vector<Clienti>& vect)
{
	vector<Clienti>::iterator it;
	for (it = vect.begin(); it != vect.end(); it++) {
		if ((*it).codice_fiscale == str)
			return true;
	}
	return false;
}

bool ceck_pass(string str)
{
	char pass[40];
	strcpy(pass, str.c_str());
	if (sizeof(pass) / sizeof(char) < 6)
		return false;
	return true;
}

void elimina_Cliente(Clienti x, vector <Clienti>& vect)
{
	vector<Clienti>::iterator it;
	for (it = vect.begin(); it != vect.end(); it++) {
		if ((*it).codice_fiscale == x.codice_fiscale)
			vect.erase(it);
		else
			it++;
	}
	return;
}

void registrazione(vector <Clienti>& vect)
{
	bool ceck = true;
	string n, c, us_name, pass, cod_fisc, num;
	int n_telefono = 0;

	//inserimento delle generalità del cliente
	do {
		cout << "Nome: ";
		getline(cin, n);
		if (n.empty())
			cout << "ERRORE!\nRiempire il campo Nome " << endl;
	} while (n.empty());
	do {
		cout << "Cognome: ";
		getline(cin, c);
		if (c.empty())
			cout << "ERRORE!\nRiempire il campo Cognome " << endl;
	} while (c.empty());
	do {
		cout << "Codice Fiscale: ";
		getline(cin, cod_fisc);
		if (is_on(cod_fisc, vect)) {
			cout << "ERRORE!" << endl << "L'utente " << n << " " << c << " ha già effettuato la registrazione" << endl;
			exit(1);
		}
		else if (cod_fisc.empty())
			cout << "Errore!\nInserire codice fiscale" << endl;
	} while (is_on(cod_fisc, vect) || cod_fisc.empty());

	do {
		cout << "Numero di cellulare: ";
		getline(cin, num);
		n_telefono = atoi(num.c_str());
		if (n_telefono == 0)
			cout << "ERRORE!\nInserire recapito telefonico" << endl;
	} while (n_telefono == 0);

	//creazione del profilo cliente
	do {
		cout << "Username: " << endl;
		getline(cin, us_name);
		if (us_name.empty())
			cout << "ERRORE!\nInserire Username" << endl;
		else if (is_on(us_name, vect))
			//non è possibile utilizzare username uguali 
			cout << "Username già utilizzato\nInserire Username" << endl;
	} while (us_name.empty() || is_on(us_name, vect));
	do {
		cout << "Password: " << endl;
		getline(cin, pass);
		if (!ceck_pass(pass))
			//la password deve contenere minimo 6 caratteri
			cout << "ERRORE!\nInserire minimo 6 caratteri" << endl;
	} while (!ceck_pass(pass));

	Clienti x(n, c, cod_fisc, us_name, pass, n_telefono);
	//chiamata del costruttore e inserimento nel vettore
	vect.push_back(x);

	return;
}

ostream& operator<<(ostream& os, Clienti x)
{
	os << "Nome Cognome: " << x.getNome() << " " << x.getCognome() << endl
		<< "Codice fiscale: " << x.getCod_fiscale() << endl
		<< "Numero cellulare: " << x.getNumero() << endl
		<< "Username: " << x.getUser() << endl;
	return os;
}

void stampa_vettore(vector <Clienti>& vect)
{
	vector<Clienti>::iterator it;

	for (it = vect.begin(); it != vect.end(); it++) {
		cout << *it << endl;
	}
	return;
}

void stampa_Cliente(string user, vector <Clienti>& vect)
{
	vector<Clienti>::iterator it;

	for (it = vect.begin(); it != vect.end(); it++) {
		if ((*it).getUser() == user)
			cout << *it;
	}
	return;
}
