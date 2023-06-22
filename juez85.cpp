// Adrián Pérez

#include <fstream>
#include <iostream>
#include "set_eda.h"

using namespace std;


bool resuelveCaso() {
	int n, m, k;
	set<int> se;
	cin >> n;
	if (n == 0) { return false; }
	for (int i = 0; i < n; i++) {
		cin >> k;
		se.insert(k);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		pair<bool, int> p = se.lower_bound(k);
		if (p.first) {
			cout << p.second << '\n';
		}
		else { cout << "NO HAY\n"; }
	}
	cout << "---\n";
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

	//while (resuelveCaso()) {}

	return 0;
}