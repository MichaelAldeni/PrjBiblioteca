//============================================================================
// Nome        : main.cpp
// Autore      : Antonio D'Urso, Alessandro Villa, Michael Aldeni
// Versione    : 1
// Descrizione : Gestione di una biblioteca pubblica
//============================================================================

/// <seealso cref="Clienti.h"/>
//#include "Clienti.h"
/// <seealso cref="IO.h"/>
#include "IO.h"
using namespace std;

int main() {
	vector<Libri> biblioteca;
	
	int scelta;

	cout << "**********************************************" << endl;
	cout << "***Sei un dipendente (1) o un cliente (2) ?***" << endl;
	do {
		cout << "Digita il numero corrispondente: ";
		cin >> scelta;
	} while (scelta != 1 && scelta != 2);

	string d_user;
	string d_password;

	system("CLS");

	switch (scelta) {
	case 1:
		cout << "**********************************************" << endl;
		cout << "********************ACCEDI********************" << endl;
		cin.ignore();
		do {
			cout << "Username: ";
			getline(cin, d_user);
			cout << "password: ";
			getline(cin, d_password);
			if (d_user != DIPUSER || d_password != DIPPASS)
				cout << "Errore!: username o password errati" << endl;
		} while (d_user != DIPUSER || d_password != DIPPASS);
	case 2:

	}

	return 0;
}