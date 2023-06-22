// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

void resolver(bintree<int> ab, vector<int>& perfil, int& lvl, int n) {
	if (n > lvl) {
		perfil.push_back(ab.root());
		lvl++;
	}
	if (!ab.left().empty()) { resolver(ab.left(), perfil, lvl, n + 1); }
	if (!ab.right().empty()) { resolver(ab.right(), perfil, lvl, n + 1); }
}

void resuelveCaso() {
	bintree<int> ab = leerArbol(-1);
	vector<int> perfil;
	int lvl = 0;
	if (!ab.empty()) {
		resolver(ab, perfil, lvl, 1);
		cout << perfil[0];
		for (int i = 1; i < perfil.size(); i++) {
			cout << " " << perfil[i];
		}
	}
	cout << '\n';
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