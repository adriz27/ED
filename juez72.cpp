//Adrián Pérez

#include "cola.h"
#include "horas.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) { return false; }
	cola<horas> cola;
	horas h;
	for (int i = 0; i < n; i++) {
		h.read(cin);
		cola.push(h);
	}
	cola.ej72();
	cola.show(cout);

	return true;
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		while (resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	//while (resuelveCaso());

	return 0;
}