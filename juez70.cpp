//Adrián Pérez

#include "cola.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) { return false; }
	cola<int> cola;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cola.push(num);
	}
	cola.modify();
	cola.show(cout);

	return true;
}

int main() {

	/*#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

		while (resuelveCaso());

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif*/

	while (resuelveCaso());

	return 0;
}