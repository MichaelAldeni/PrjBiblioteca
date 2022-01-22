#include "Libri.h"

Libri::Libri(string n, float prz) {
	id = current_id++;
	nome = n;
	prezzo_prestito = prz;
	prestato = false;
}

void Libri::modifica_prestito() {
	if (prestato == false)
		prestato = true;
	else prestato = false;
	return;
}