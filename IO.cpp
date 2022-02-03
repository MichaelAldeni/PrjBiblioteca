#include"IO.h"



vector<Libri> carica_libri() {
	vector<Libri> v;

	ifstream ifs;
	string filename = "Biblioteca.txt";

	ifs.open(filename);
	if (!ifs.is_open()) {
		cout << "Errore!: file non aperto correttamente.";
		exit(1);
	}

	while (!ifs.eof()) {
		string n, a, p_s;
		float p;

		getline(ifs, n, ';');
		getline(ifs, a, ';');
		getline(ifs, p_s);
		p = atof(p_s.c_str());

		Libri book(n, a, p);

		v.push_back(book);
	}

	return v;
}


void salva_libri(vector<Libri> v) {
	ofstream ofs;
	string filename = "Biblioteca.txt";

	ofs.open(filename);
	if (!ofs.is_open()) {
		cout << "Errore!: file non aperto correttamente.";
		exit(1);
	}

	vector<Libri>::iterator it = v.begin();
	for (it = v.begin(); it != v.end(); it++) {
		ofs << *it << endl;
	}
}

vector<Clienti> carica_clienti() 
{
	vector<Clienti> v;

	ifstream ifs;
	string filename = "Clienti.txt";

	ifs.open(filename);
	if (!ifs.is_open()) {
		cout << "Errore!: file non aperto correttamente.";
		exit(1);
	}

	while (!ifs.eof()) {
		string n, c, cod_fisc, us_name, pass, num, n_prestito;
		int  num_prestito;

		getline(ifs, n, ';');
		getline(ifs, c, ';');
		getline(ifs, cod_fisc, ';');
		getline(ifs, num, ';');
		getline(ifs, us_name, ';');
		getline(ifs, pass, ';');
		getline(ifs, n_prestito);
		num_prestito = atoi(n_prestito.c_str());
		
		Clienti x(n, c, cod_fisc, us_name, pass, num, num_prestito);
		v.push_back(x);

	}
	return v;
}

void salva_clienti(vector<Clienti>& v)
{
	ofstream ofs;
	string filename = "Clienti.txt";

	ofs.open(filename);
	if (!ofs.is_open()) {
		cout << "Errore!: file non aperto correttamente.";
		exit(1);
	}

	vector<Clienti>::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		ofs << (*it).getNome() << ";" << (*it).getCognome() << ";" << (*it).getCod_fiscale() <<
			";" << (*it).getNumero() << ";" << (*it).getUser() << ";" << (*it).getPassword() << ";"
			<< (*it).getPrestito();
		if (it != v.end())
			ofs << endl;
	}
}

bool login(vector<Clienti> vect, string& u, string& p, string& cf)
{
	bool ceck = false;
	int i = 6;

	cout << "*********LOGIN*********" << endl;
	do {
		cout << "Username: ";
		getline(cin, u);

		if (u.empty())
			cout << "ERRORE!\nInserire Username" << endl;
		if (!is_on(u, vect))
			cout << "ERRORE!\nUsername non valido" << endl;

	} while (u.empty() || !is_on(u, vect));

	do {
		cout << "Password: ";
		getline(cin, p);

		if (p.empty())
			cout << "ERRORE!\nInserire password" << endl;
		else if (!is_on(p, vect)) {
			i--;
			cout << "ERRORE!\nPassword non valida " << i << "tentativi rimasti" << endl;
		}
		else if (i <= 0) {
			ceck = false;
			cout << "Login annullato" << endl;
			exit(1);
		}
		else
			ceck = true;

	} while (p.empty() || !is_on(p, vect));

	return ceck;
}