// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

int resolver(bintree<int> ab, int &n) {
	int caudal;
	if (ab.right().empty()) {
		if (ab.left().empty()) { caudal = 1; }
		else { 
			caudal = resolver(ab.left(), n); 
			if (caudal > 2) { n++; }
		}
	}
	else {
		caudal = resolver(ab.right(), n);
		if (caudal > 2) { n++; }
		if (!ab.left().empty()) { 
			int c = resolver(ab.left(), n); 
			if (c > 2) { n++; }
			caudal += c;
		}
	}
	caudal -= ab.root();
	if (caudal < 0) { caudal = 0; }
	return caudal;
}

void resuelveCaso() {
	bintree<int> ab;
	int num = 0;
	ab = leerArbol(-1);
	if (!ab.empty()) { resolver(ab, num); }
	cout << num << '\n';
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