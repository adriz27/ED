// Adrián Pérez

#include <fstream>
#include <iostream>
#include "treemap_eda.h"

using namespace std;

bool resuelveCaso() {
	int n;
	string basura;
	cin >> n;
	getline(cin, basura);
	if (n == 0) { return false; }
	map<string, int, less<string>> dicc;
	for (int i = 0; i < n; i++) {
		string nombre, corr;
		getline(cin, nombre);
		dicc.insert(nombre);
		getline(cin, corr);
		if (corr == "CORRECTO") { dicc[nombre]++; }
		else if (corr == "INCORRECTO") { dicc[nombre]--; }
	}
	while (!dicc.empty()) {
		string nombre = dicc.menorc();
		int nota = dicc[nombre];
		if (nota != 0) { cout << nombre << ", " << nota << '\n'; }
		dicc.erase(nombre);
	}
	cout << "---" << '\n';
	return true;
}

int main() {

	#ifndef DOMJUDGE
		std::ifstream in("casos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf());
	#endif

	while(resuelveCaso()){}

	#ifndef DOMJUDGE
		std::cin.rdbuf(cinbuf);
		system("PAUSE");
	#endif

	//while(resuelveCaso()){}

	return 0;
}