//============================================================================
// Nome        : main.cpp
// Autore      : Antonio D'Urso, Alessandro Villa, Michael Aldeni
// Versione    : 1
// Descrizione : Gestione di una biblioteca
//============================================================================

/// <seealso cref="Clienti.h"/>
//#include "Clienti.h"
/// <seealso cref="IO.h"/>
#include "IO.h"
using namespace std;

int main() {
	vector<Libri> biblioteca;

	biblioteca = carica_libri();

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
	case 1:  // pagina di accesso dipendente 
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

		// pagina di lavoro dipendenti
		int scelta_dip;
		system("CLS");
		do {
			do {
				cout << "**********************************************" << endl;
				cout << "*****MENU GESTIONE BIBLIOTECA/DIPENDENTI******" << endl;
				cout << "***Digita l'operazione da voler effettuare:***" << endl << endl;
				cout << "(1) Visualizza la lista completa dei libri" << endl;
				cout << "(2) Aggiungi un nuovo libro" << endl;
				cout << "(3) Elimina un libro che la biblioteca non ha più" << endl;
				cout << "(4) Menu di gestione dei clienti" << endl;
				cout << "(5) Esci" << endl << endl;
				cout << "Digita il numero corrispondente: ";
				cin >> scelta_dip;
			} while (scelta_dip != 1 && scelta_dip != 2 && scelta_dip != 3 && scelta_dip != 4 && scelta_dip != 5);
			switch (scelta_dip) {
			case 1:
				system("CLS");
				stampa_libri(biblioteca);
				break;
			case 2:
				cin.ignore();
				system("CLS");
				aggiungi(biblioteca);
				break;
			case 3:
				cin.ignore();
				system("CLS");
				elimina_libro(biblioteca);
				break;
			case 4: //menu gestione clienti
				system("CLS");
				int scelta_dip_cl;
				do {
					cout << "**********************************************" << endl;
					cout << "************MENU GESTIONE DEI CLIETI**********" << endl;
					cout << "***Digita l'operazione da voler effettuare:***" << endl << endl;
					cout << "(1) Mostra i dati dei clienti registrati" << endl;
					cout << "(2) Elimina l'account di un cliente" << endl;
					cout << "(3) Indietro" << endl;
					cout << "(4) Esci" << endl << endl;
					cout << "Digita il numero corrispondente: ";
					cin >> scelta_dip_cl;
				} while (scelta_dip_cl != 1 && scelta_dip_cl != 2 && scelta_dip_cl != 3 && scelta_dip_cl != 4);
				switch (scelta_dip_cl) {
				case 1:
					break;
				case2:
					break;
				case 3: 
					system("CLS");
					break;
				case 4:
					return 0;
				}
				break;
			case 5:
				return 0;
			}
		} while (scelta_dip);
		break;
	case 2: // registrazione/accesso cliente 
		return 0;
	}

	return 0;
}

//aggiugnere i caricamenti su file ogni volta che si chiude il programma !!!