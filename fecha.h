#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <stdexcept>  
#include <iomanip>

using namespace std;

//Adrián Pérez y Rubén Gómez

class fecha {
private:
	int D;
	int M;
	int A;
public:
	fecha(int d, int m, int a) {
		if (check(d, m, a)) {
			D = d;
			M = m;
			A = a;
		}
		else { throw std::domain_error("Datos inválidos"); }
	}
	fecha() {
		D = 1; M = 1; A = 1;
	}

	bool check(int d, int m, int a) { return true; } // No hace falta comprobarlo
	int dia() { return D; }
	int mes() { return M; }
	int anno() { return A; }

	bool operator<(fecha const& f) {
		if (A < f.A) { return true; }
		if(A == f.A){
			if (M < f.M) { return true; }
			if (M == f.M) {
				if (D < f.D) { return true; }
			}
		}
		return false;
	}
	void read(std::istream& input = std::cin) {
		int d, m, a;
		char c;
		input >> d >> c >> m >> c >> a;
		*this = fecha(d, m, a);
	}

	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << D << '/'
			<< std::setfill('0') << std::setw(2) << M << '/'
			<< std::setfill('0') << std::setw(4) << A << '\n';
	}
};

inline std::ostream& operator<<(std::ostream& salida, fecha const& h) {
	h.print(salida);
	return salida;
}

inline std::istream& operator>>(std::istream& entrada, fecha& h) {
	h.read(entrada);
	return entrada;
}

#endif