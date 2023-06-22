// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;


void resuelveCaso() {
	bintree<int> ab = leerArbol<int>(-1);
	int suma = 0;
	cout << ab.equipos(suma) << " " ;
	cout << suma << '\n';
}

int main() {

	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		int numCasos;
		cin >> numCasos;
		for (int i = 0; i < numCasos; i++) {
			resuelveCaso();
		}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	return 0;
}