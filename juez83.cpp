// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

int resolver(bintree<char> ab, int& maxi) {
	int m;
	if (ab.left().empty() || ab.right().empty()) { 
		m = 1; 
		if (!ab.right().empty()) { resolver(ab.right(), maxi); }
		if (!ab.left().empty()) { resolver(ab.left(), maxi); }
	}
	else {
		m = min(resolver(ab.right(), maxi), resolver(ab.left(), maxi)) + 1;
	}
	maxi = max(m, maxi);
	return m;
}

void resuelveCaso() {
	bintree<char> ab;
	int num = 0;
	ab = leerArbol('.');
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