//Adrián Pérez

#include "cola.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


bool resuelveCaso() {
	int num;
	cin >> num;
	if (!cin) { return false; }
	cola<int> cola;
	while (num != 0) {
		cola.push(num);
		cin >> num;
	}
	cola.duplica();
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