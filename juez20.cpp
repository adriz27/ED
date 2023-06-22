//Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;

void escribe(vector<int>& v) {
	if (v.size() > 0) {
		cout << v[0];
		for (int i = 1; i < v.size(); i++) {
			cout << ' ' << v[i];
		}
	}
	cout << '\n';
}

void resuelveCaso() {
	bintree<int> ab = leerArbol<int>(-1);
	vector<int> v;
	ab.frontera(v);
	escribe(v);
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