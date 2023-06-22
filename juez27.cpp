// Adrián Pérez

#include <fstream>
#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;

bintree<int> binBusq(queue<int>& pre, int min, int max) {
	if (pre.empty()) { return {}; }
	int raiz = pre.front();
	pre.pop();
	bintree<int> iz = {}, dr = {};
	if (!pre.empty() && pre.front() < raiz && (pre.front() > min || min == 0)) { 
		iz = binBusq(pre, min, raiz);
	}
	if (!pre.empty() && pre.front() > raiz && (pre.front() < max || max == 0)) {
		dr = binBusq(pre, raiz, max);
	}
	return { iz, raiz, dr };
}

bool resuelveCaso() {
	queue<int> pre;
	int aux;
	char c;
	cin >> aux;
	if (!cin) { return false; }
	pre.push(aux);
	cin.get(c);
	while (c!= '\n') {
		cin >> aux;
		pre.push(aux);
		cin.get(c);
	}
	bintree<int> ab = binBusq(pre, 0, 0);
	vector<int> pos = ab.postorder();
	cout << pos[0];
	for (int i = 1; i < pos.size(); i++) {
		cout << " " << pos[i];
	}
	cout << '\n';
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