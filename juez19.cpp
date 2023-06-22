//Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

void resuelveCaso() {
	bintree<char> ab = leerArbol<char>('.');
	cout << ab.numNodos() << ' ' << ab.numHojas() << ' ' << ab.altura() << '\n';
}

int main() {

#ifndef DOMJUDGE
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
#endif

	return 0;
}