/// <seealso cref="Biblioteca.h"/>
#include "Biblioteca.h"
/// <seealso cref="Libri.h"/>
#include "Libri.h"

#include"Clienti.h"

string const DIPUSER = "DIPENDENTE";
string const DIPPASS = "DIPENDENTE123";

/// <item>Funzione di caricamento dei libri nel vettore.</item> 
vector<Libri> carica_libri();

void salva_libri(vector<Libri> v);

/// <item>Funzione per il caricamento da file di tutti i clienti registrati nel sistema.</item>
vector<Clienti> carica_clienti();

/// <item>Funzione di salvataggio dei clienti sul file "Clienti.txt".</item>
void salva_clienti(vector<Clienti> &v);

/// <item>Funzione login per i clienti all'interno del sistema.</item>
bool login(vector<Clienti> vect, string& u, string& p, string& cf);

