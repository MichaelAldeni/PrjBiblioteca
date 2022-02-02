#include "Clienti.h"

#pragma warning(disable : 4996)

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
	vector<Clienti>::iterator it;
	string cod;
	cout << "Inserire il codice fiscale del cliente del quale si vuole annullare la registrazione: ";
	getline(cin, cod);
	for (it = vect.begin(); it != vect.end(); it++) {
		if ((*it).getCod_fiscale() == cod)
			vect.erase(it);
	}
	return;
}

void registrazione(vector <Clienti>& vect)
{
	bool ceck = true;
	string n, c, us_name, pass, cod_fisc, num;
	int num_prestito = 0;

	//inserimento delle generalit� del cliente
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
				cout << "ERRORE!" << endl << "L'utente " << n << " " << c << " ha gi� effettuato la registrazione" << endl;
				exit(1);
			}
			else if (cod_fisc.empty())
				cout << "Errore!\nInserire codice fiscale" << endl;
		} while (is_on(cod_fisc, vect) || cod_fisc.empty());

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

void modifica(vector<Clienti> vect, int i)
{
	string cod_fisc, pass, user_name;
	vector<Clienti>::iterator it;

	switch (i)
	{
	case 0:
		cout << "Modifica Username" << endl;

		do {
			cout << "Codice fiscale: ";
			getline(cin, cod_fisc);
			cout << "Password: ";
			getline(cin, pass);
			if (!is_on(cod_fisc, vect) || !is_on(pass, vect))
				cout << "ERRORE!\nInserire codice fiscale e password corretti" << endl;
		} while (!is_on(cod_fisc, vect) || !is_on(pass, vect));

		cout << "Inserire il nuovo username: ";
		getline(cin, user_name);

		for (it = vect.begin(); it != vect.end(); it++) {
			cout << "entro nel ciclo" << endl;
			if ((*it).getCod_fiscale() == cod_fisc) {
				cout << "entro nell'if" << endl;
				(*it).user = user_name;
				cout << "username modificato" << endl;
			}
		}
		break;
	case 1:
		cout << "Modifica Password" << endl;

		do {
			cout << "Username: ";
			getline(cin, user_name);
			cout << "Codice fiscale: ";
			getline(cin, cod_fisc);
			if (!is_on(cod_fisc, vect) || !is_on(user_name, vect))
				cout << "ERRORE!\nInserire username e codice fiscale corretti" << endl;
		} while (!is_on(cod_fisc, vect) || !is_on(user_name, vect));

		cout << "Inserire la nuova password: ";
		getline(cin, pass);

		for (it = vect.begin(); it != vect.end(); it++) {
			if ((*it).getCod_fiscale() == cod_fisc) {
				(*it).setPassword(pass);
				cout << "password modificata" << endl;
			}
		}
		break;
	}
}