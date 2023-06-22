
#ifndef PELICULA_H
#define PELICULA_H

#include "horas.h"
#include <string>


class pelicula {
private:
	horas inicio; 
	horas fin; 
	string nombre; 
public:
	// constructora
	pelicula(horas ini, horas dur, string nom) {
		fin = ini + dur;
		inicio = ini;
		nombre = nom;
	}
	pelicula() {
		inicio = horas();
		fin = horas();
		nombre = "";
	}

	// observadoras
	horas getfin() const { return fin; }
	horas getinicio() const { return inicio; }
	string getnombre() const { return nombre; }


	// operador de comparación
	bool operator<(pelicula const& p) {
		return fin < p.fin || (fin == p.fin && nombre < p.nombre);
	}


	void read(std::istream& input = std::cin) {
		horas dur;
		string n;
		char c;
		inicio.read(input);
		input >> c;
		dur.read(input);
		getline(input, n);
		*this = pelicula(inicio, dur, n);
	}

	void print(std::ostream& o = std::cout) const {
		fin.print(o);
		o << " " << nombre << "\n";
	}
};

#endif