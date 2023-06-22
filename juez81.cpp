// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

bool resolver(bintree<char> a1, bintree<char> a2) {
	if (a1.empty() && !a2.empty() || !a1.empty() && a2.empty()) {return false;}
	if (a1.empty()) { return true; }
	return resolver(a1.right(), a2.left()) && resolver(a1.left(), a2.right());
}

void resuelveCaso() {
	bintree<char> ab;
	int num = 0;
	ab = leerArbol('.');
	bintree<char> a1 = ab.left(), a2 = ab.right();
	if (resolver(a1, a2)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
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