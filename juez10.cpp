//Adrián Pérez

#include "cola.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


bool resuelveCaso() {
	int n, m, pos, num;
	cin >> n;
	if (!cin) { return false; }
	cola<int> cola, c2;
	for (int i = 0; i< n; i++) {
		cin >> num;
		cola.push(num);
	}
	cin >> m >> pos;
	for (int i = 0; i < m; i++) {
		cin >> num;
		c2.push(num);
	}
	cola.insertar(c2, pos);
	cola.show(cout);

	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	//while (resuelveCaso());

	return 0;
}