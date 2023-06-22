//Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;


bool resuelveCaso() {
	char c;
	cin >> c;
	if (!cin) { return false; }
	if (c == 'N') {
		bintree<int> ab = leerArbol<int>(-1);
		cout << ab.minimo() << '\n';
	}
	else if (c == 'P') {
		bintree<string> ab = leerArbol<string>("#");
		cout << ab.minimo() << '\n';
	}
	return true;
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		while (resuelveCaso()) {}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif
	

	return 0;
}