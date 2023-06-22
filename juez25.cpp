// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

vector<bool> criba(int n) {
	vector<bool> v;
	for (int i = 0; i < n + 1; i++) {
		v.push_back(true);
	}
	v[0] = false;
	v[1] = false;
	for (int i = 2; i < n + 1; i++) {
		if (v[i]) {
			for (int j = 2; j * i < n + 1; j++) {
				v[j * i] = false;
			}
		}
	}
	return v;
}

void resuelveCaso(vector<bool>& cr) {
	bintree<int> ab = leerArbol(-1);
	int mult = 0, prof = 1;
	if (!ab.mult7(mult, prof, cr)) { cout << "NO HAY" << '\n'; }
	else { cout << mult << ' ' << prof << '\n'; }
}

int main() {

	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		int numCasos;
		cin >> numCasos;
		vector<bool> cr = criba(5000);
		for(int i = 0; i < numCasos; i++){
			resuelveCaso(cr);
		}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	int numCasos;
	cin >> numCasos;
	vector<bool> cr = criba(5000);
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso(cr);
	}
	return 0;
}