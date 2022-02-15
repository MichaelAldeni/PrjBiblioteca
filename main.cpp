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
	vector<Clienti> clienti;

	biblioteca = carica_libri();
	clienti = carica_clienti();

	int scelta;
	string str;

	cout << "**********************************************" << endl;
	cout << "***Sei un dipendente (1) o un cliente (2) ?***" << endl;
	do {
		cout << "Digita il numero corrispondente: ";
		getline(cin, str);
		scelta = atoi(str.c_str());
	} while (scelta != 1 && scelta != 2);

	string d_user;
	string d_password;

	system("CLS");

	switch (scelta) {
	case 1:  // pagina di accesso dipendente 
		cout << "**********************************************" << endl;
		cout << "********************ACCEDI********************" << endl;
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
				getline(cin, str);
				scelta_dip = atoi(str.c_str());

			} while (scelta_dip != 1 && scelta_dip != 2 && scelta_dip != 3 && scelta_dip != 4 && scelta_dip != 5);
			switch (scelta_dip) {
			case 1:
				system("CLS");
				stampa_libri(biblioteca);
				break;
			case 2:
				system("CLS");
				aggiungi(biblioteca);
				break;
			case 3:
				system("CLS");
				elimina_libro(biblioteca);
				break;
			case 4: //menu gestione clienti
				system("CLS");
				int scelta_dip_cl;
				do {
					do {
						cout << "**********************************************" << endl;
						cout << "***********MENU GESTIONE DEI CLIENTI**********" << endl;
						cout << "***Digita l'operazione da voler effettuare:***" << endl << endl;
						cout << "(1) Mostra i dati dei clienti registrati" << endl;
						cout << "(2) Elimina l'account di un cliente" << endl;
						cout << "(3) Indietro" << endl;
						cout << "(4) Esci" << endl << endl;
						cout << "Digita il numero corrispondente: ";
						getline(cin, str);
						scelta_dip_cl = atoi(str.c_str());
					} while (scelta_dip_cl != 1 && scelta_dip_cl != 2 && scelta_dip_cl != 3 && scelta_dip_cl != 4);
					switch (scelta_dip_cl) {
					case 1:
						system("CLS");
						stampa_vettore(clienti);
						break;
					case 2:
						system("CLS");
						elimina_Cliente(clienti);
						break;
					case 3:
						system("CLS");
						break;
					case 4:
						salva_libri(biblioteca);
						salva_clienti(clienti);
						return 0;
					}
				} while (scelta_dip_cl != 3);
				break;
			case 5:
				salva_libri(biblioteca);
				salva_clienti(clienti);
				return 0;
			}
		} while (scelta_dip);
		break;
	case 2: // registrazione/accesso cliente 
		system("CLS");
		int scelta_log;
		do {
			cout << "**********************************************" << endl;
			cout << "***************ACCEDI/REGISTRATI**************" << endl;
			cout << " Sei nuovo? Registrati! (1) " << endl;
			cout << "Hai già un account? Accedi (2) " << endl;
			cout << "Digita il numero corrispondente: ";
			getline(cin, str);
			scelta_log = atoi(str.c_str());
		} while (scelta_log != 1 && scelta_log != 2);
		string username, password, cod_fiscale;


		if (scelta_log == 1)
			registrazione(clienti);

		if (login(clienti, username, password, cod_fiscale)) {
			system("CLS");
			int scelta_cl;
			do {
				do {
					cout << "**********************************************" << endl;
					cout << "*******MENU GESTIONE BIBLIOTECA/CLIENTI*******" << endl;
					cout << "Benvenuto/a " << username << endl;
					cout << "***Digita l'operazione da voler effettuare:***" << endl;
					cout << "(1) Visualizza la lista completa dei libri" << endl;
					cout << "(2) Ricerca per libro" << endl;
					cout << "(3) Ricerca per autore" << endl;
					cout << "(4) Prendi in prestito un libro" << endl;
					cout << "(5) Restituisci un libro" << endl;
					cout << "(6) Modifica username o password" << endl;
					cout << "(7) Esci" << endl << endl;
					cout << "Digita il numero corrispondente: ";
					getline(cin, str);
					scelta_cl = atoi(str.c_str());
				} while (scelta_cl != 1 && scelta_cl != 2 && scelta_cl != 3 && scelta_cl != 4 && scelta_cl != 5 && scelta_cl != 6 && scelta_cl != 7);
				string tmp;
				Libri l;
				vector<Libri> autore;
				switch (scelta_cl) {
				case 1:
					system("CLS");
					stampa_libri(biblioteca);
					break;
				case 2:
					system("CLS");
					cout << "Inserisci il titolo del libro da cercare : ";
					getline(cin, tmp);
					cout << endl;
					l = cerca_libro(biblioteca, tmp);
					cout << l << endl;
					break;
				case 3:
					system("CLS");
					cout << "Inserisci il nome dell'autore da cercare: ";
					getline(cin, tmp);
					autore = cerca_autore(biblioteca, tmp);
					stampa_libri(autore);
					cout << endl;
					break;
				case 4:
					system("CLS");
					modifica_prestito_vettore(biblioteca);
					modifica_prestito_piu(clienti, cod_fiscale);
					break;
				case 5:
					system("CLS");
					modifica_prestito_vettore(biblioteca);
					modifica_prestito_meno(clienti, cod_fiscale);
					break;
				case 6:
					system("CLS");
					int i;
					do {
						cout << "Cosa vuoi modificare? Username (0) o Password (1) ?" << endl;
						cout << "Digita il numero corrispondente: ";
						getline(cin, str);
						i = atoi(str.c_str());
					} while (i != 0 && i != 1);
					modifica(clienti, i, username, password, cod_fiscale);
					break;
				case 7:
					salva_libri(biblioteca);
					salva_clienti(clienti);
					return 0;
				}
			} while (scelta_cl);
		}
	}
	salva_libri(biblioteca);
	salva_clienti(clienti);
	return 0;
}