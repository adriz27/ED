// Adrián Pérez

#include <fstream>
#include <iostream>
#include "bintree_eda.h"

using namespace std;
typedef enum {comp, semi, nada}tClase;

/*int resolver(bintree<char> ab, tClase& c) {
	if (c == nada) { return 0; }
	int m = 0;
	if (ab.left().empty() || ab.right().empty()) {
		m = 1;
		if (!ab.left().empty()) {
			if (c == semi) { c = nada; }
			else  if (c == comp) { c = semi; }
			if (resolver(ab.left(), c) > 1) { c = nada; }
		}
		if (!ab.right().empty()) { c = nada; }
	}
	else {
		int iz = resolver(ab.left(), c), der = resolver(ab.right(), c);
		if (der + 1 == iz) { 
			if (c == semi) { c = nada; }
			else if (c == comp){ c = semi; }
		}
		else if (der != iz) { c = nada; }
		m = min(der, iz) + 1;
	}
	return m;
}*/

int resolver(bintree<char> ab, tClase& c) {
	if (ab.empty()) { return 0; }
	int iz = resolver(ab.left(), c);
	if (c == nada) { return 0; }
	int dr = resolver(ab.right(), c);
	if (c == nada) { return 0; }
	if (iz < 0) { iz = -iz; }
	if (dr < 0) { c = nada; return 0; }
	if (iz != dr) {
		if (iz - 1 == dr){
			if (c == comp) { c = semi; }
			else { c = nada; }
			return -iz;
		}
		else { 
			c = nada; 
			return 0;
		}
	}
	else {
		return iz + 1;
	}
}


void resuelveCaso() {
	bintree<char> ab;
	tClase c = comp;
	ab = leerArbol('.');
	if (!ab.empty()) { resolver(ab, c); }
	if(c == comp){ cout << "COMPLETO\n"; }
	else if (c == semi) { cout << "SEMICOMPLETO\n"; }
	else { cout << "NADA\n"; }
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