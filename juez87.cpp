// Adrián Pérez

#include <fstream>
#include <iostream>
#include "set_eda.h"

using namespace std;

bool resuelveCaso() {
	int n, m, k, a, b;
	set<int> s;
	cin >> n;
	if (!cin) { return false; }
	cin >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		s.insert(k);
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << s.count_interval(a, b) << '\n';
	}
	cout << "---\n";
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

	//while (resuelveCaso()) {}

	return 0;
}