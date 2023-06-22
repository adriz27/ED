//Adrián Pérez

#include <fstream>
#include "cola.h"

using namespace std;

bool resuelveCaso() {
	int N = 1, s;
	cin >> N >> s;
	if (N == 0 && s == 0) { return false; }
	cola<int> c;
	for (int i = 1; i < N + 1; i++) { c.push(i); }
	cout << c.eligeAfortunado(s) << '\n';
	return true;
}

int main() {
	/*
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/

	while (resuelveCaso()) {}

	return 0;
}
