//Adrián Pérez

#include <fstream>
#include <iostream>
#include "cola.h"

using namespace std;

void resuelveCaso() {
	int x;
	cola<int> c1, c2;
	cin >> x;
	while (x != 0) {
		c1.push(x);
		cin >> x;
	}
	cin >> x;
	while (x != 0) {
		c2.push(x);
		cin >> x;
	}
	c1.mezcla(c2);
	c1.show(cout);
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {resuelveCaso();}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) { resuelveCaso(); }
	*/
	return 0;
}
