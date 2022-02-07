/// <seealso cref="Biblioteca.h"/>
#include "Biblioteca.h"
/// <seealso cref="Libri.h"/>
#include "Libri.h"

#include"Clienti.h"

string const DIPUSER = "DIPENDENTE";
string const DIPPASS = "DIPENDENTE123";

/// <summary>Funzione di caricamento dei libri nel vettore</summary> 
vector<Libri> carica_libri();

void salva_libri(vector<Libri> v);

//funzione che carica dal file Clienti.txt tutti gli utenti registrati
vector<Clienti> carica_clienti();

//funzione che salva sul file Clienti.txt i nuovi utenti registrari
void salva_clienti(vector<Clienti> &v);

//funzione che permettere di accedere al proprio profilo utente
bool login(vector<Clienti> vect, string& u, string& p, string& cf);

