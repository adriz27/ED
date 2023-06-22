// Adrián Pérez

#include <fstream>
#include <iostream>
#include "hashmap_eda.h"

using namespace std;

void resuelveCaso() {
	int n, max = 0, start = -1;
	cin >> n;
	unordered_map<int, int> mapa;
	for (int i = 0; i < n; i++) {
		int j;
		cin >> j;
		if (mapa.count(j)) {
			if (start < mapa[j]) { start = mapa[j]; }
			mapa[j] = i;
		}
		else {
			mapa.insert(j);
			mapa[j] = i;
		}
		if (i - start > max) { max = i - start; }
	}
	cout << max << '\n';
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