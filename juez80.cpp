// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

bool resolver(bintree<int> ab, int& num) {
	int iz = 0, der = 0;
	if (!ab.left().empty()) {
		if (ab.root() - 18 < ab.left().root()) { return false; }
		if (!resolver(ab.left(), iz)) { return false; }
		if(!ab.right().empty()){
			if (ab.left().root() - 2 < ab.right().root()) { return false; }
			if (!resolver(ab.right(), der)) { return false; }
		}
	}
	else if (!ab.right().empty()) { return false; }
	num = max(iz, der) + 1;
	return true;
}

void resuelveCaso() {
	bintree<int> ab;
	int num = 0;
	ab = leerArbol(-1);
	if (ab.empty() || resolver(ab, num)) {
		cout << "SI " << num << '\n';
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