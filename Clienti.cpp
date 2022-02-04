#include "Clienti.h"

#pragma warning(disable : 4996)

Clienti::Clienti()
{
	nome = "";
	cognome = "";
	codice_fiscale = "";
	user = "";
	password = "";
	numero_telefono = "";
	n_prestito = 0;
}

Clienti::Clienti(string n, string c, string cod_fisc, string us_name, string pass, string num, int num_prestito)
{
	nome = n;
	cognome = c;
	codice_fiscale = cod_fisc;
	user = us_name;
	password = pass;
	numero_telefono = num;
	n_prestito = num_prestito;

}

bool is_on(string str, vector<Clienti>& vect)
{
	vector<Clienti>::iterator it;
	for (it = vect.begin(); it != vect.end(); it++) {
		if (((*it).getCod_fiscale() == str) || ((*it).getUser() == str) || ((*it).getPassword() == str))
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

void elimina_Cliente(vector <Clienti>& vect)
{
	string cod;
	int i, j;
	vector<Clienti>::iterator it;

	cout << "Inserire il codice fiscale del cliente del quale si vuole annullare la registrazione: ";
	getline(cin, cod);

	for (it = vect.begin(); it != vect.end(); it++)
		if ((*it).getCod_fiscale() == cod) {
			vect.erase(it);
			break;
		}

	return;
}

void registrazione(vector <Clienti>& vect)
{
	bool ceck = true;
	string n, c, us_name, pass, cod_fisc, num;
	int num_prestito = 0;

	//inserimento delle generalita del cliente
		do {
			cout << "Nome: ";
			getline(cin, n);
			if (n.empty()) 
				cout << "ERRORE!\nRiempire il campo Nome " << endl;
		} while (n.empty());
		do {
			cout << "Cognome: ";
			getline(cin, c);
			if(c.empty())
				cout << "ERRORE!\nRiempire il campo Cognome " << endl;
		} while (c.empty());
		do {
			cout << "Codice Fiscale: ";
			getline(cin, cod_fisc);
			if (is_on(cod_fisc, vect)) {
				cout << "ERRORE!" << endl << "L'utente " << n << " " << c << " ha giÃ  effettuato la registrazione" << endl;
				exit(1);
			}
			else if (cod_fisc.empty())
				cout << "Errore!\nInserire codice fiscale" << endl;
			else if (cod_fisc.size() != 21)
				cout << "Errore!\nInserire un codice fiscale valido" << endl;
		} while (is_on(cod_fisc, vect) || cod_fisc.empty() || cod_fisc.size() != 21);

		do {
			cout << "Numero di cellulare: ";
			getline(cin, num);
			if (num.empty())
				cout << "ERRORE!\nInserire recapito telefonico" << endl;
		}while (num.empty());

		//creazione del profilo cliente
		do {
			cout << "Username: " << endl;
			getline(cin, us_name);
			if(us_name.empty())
				cout << "ERRORE!\nInserire Username" << endl;
			else if(is_on(us_name, vect))
				//non � possibile utilizzare username uguali 
				cout << "Username gi� utilizzato\nInserire Username" << endl;
		} while (us_name.empty() || is_on(us_name, vect));
		do {
			cout << "Password: " << endl;
			getline(cin, pass);
			if(!ceck_pass(pass))
				//la password deve contenere minimo 6 caratteri
				cout << "ERRORE!\nInserire minimo 6 caratteri" << endl;
		} while (!ceck_pass(pass));

	Clienti x(n, c, cod_fisc, us_name, pass, num, num_prestito);
	//chiamata del costruttore e inserimento nel vettore
	vect.push_back(x);

	return;
}

ostream& operator<<(ostream &os, Clienti x)
{
	os << "Nome Cognome: " << x.getNome() << " " << x.getCognome() << endl
		<< "Codice fiscale: " << x.getCod_fiscale() << endl
		<< "Numero cellulare: " << x.getNumero() << endl
		<< "Username: " << x.getUser()<< endl;
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

void modifica(vector<Clienti>& vect, int i, string& u, string& p, string& cf)
{
	vector<Clienti>::iterator it;

	switch (i)
	{
	case 0:
		cout << "*****Modifica Username*****" << endl;

		do {
			cout << "Codice fiscale: ";
			getline(cin, cf);
			cout << "Password: ";
			getline(cin, p);
			if (!is_on(cf, vect) || !is_on(p, vect))
				cout << "ERRORE!\nInserire codice fiscale e password corretti" << endl;
		} while (!is_on(cf, vect) || !is_on(p, vect));

		cout << "Inserire il nuovo username: ";
		getline(cin, u);

		for (it = vect.begin(); it != vect.end(); it++) {
			cout << "entro nel ciclo" << endl;
			if ((*it).getCod_fiscale() == cf) {
				cout << "entro nell'if" << endl;
				(*it).setUser(u);
				cout << "username modificato" << endl;
			}
		}
		break;
	case 1:
		cout << "*****Modifica Password*****" << endl;

		do {
			cout << "Username: ";
			getline(cin, u);
			cout << "Codice fiscale: ";
			getline(cin, cf);
			if (!is_on(cf, vect) || !is_on(u, vect))
				cout << "ERRORE!\nInserire username e codice fiscale corretti" << endl;
		} while (!is_on(cf, vect) || !is_on(u, vect));

		cout << "Inserire la nuova password: ";
		getline(cin, p);

		for (it = vect.begin(); it != vect.end(); it++) {
			if ((*it).getCod_fiscale() == cf) {
				(*it).setPassword(p);
				cout << "password modificata" << endl;
			}
		}
		break;
	}
}

void modifica_prestito_piu(vector<Clienti>& v, string& cf) {
	string n;
	bool check = false;

	vector<Clienti>::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		if ((*it).getCod_fiscale() == cf){
			(*it).setPrestito(1);
		} if(!check) {
			cout << "Utente non registrato" << endl;
		}
	}
	return; 
}

void modifica_prestito_meno(vector<Clienti>& v, string& cf) {
	string n;
	bool check = false;

	vector<Clienti>::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		if ((*it).getCod_fiscale() == cf) {
			(*it).setPrestito(-1);
		}if (!check) {
			cout << "Utente non registrato" << endl;
		}
	}
	return; 
}