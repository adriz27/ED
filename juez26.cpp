// Adri�n P�rez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

void resuelveCaso() {
	bintree<int> ab = leerArbol(-1);
	if (ab.equilibrado()) { cout << "SI" << '\n'; }
	else { cout << "NO" << '\n'; }
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