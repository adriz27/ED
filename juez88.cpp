// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

int resolver(bintree<int> ab, int& n) {
	if (ab.empty()) {return 0;}
	if (ab.root() % 2 == 0) {
		int iz = resolver(ab.left(), n), dr = resolver(ab.right(), n);
		n = max(n, iz + dr + 1);
		return max(iz, dr) + 1;
	}
	else {
		resolver(ab.left(), n);
		resolver(ab.right(), n);
		return 0;
	}
}

void resuelveCaso() {
	bintree<int> ab = leerArbol(-1);
	int n = 0;
	resolver(ab, n);
	cout << n << '\n';
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

	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/

	return 0;
}