// Adrián Pérez

#include <fstream>
#include <iostream>
#include <string>
#include "bintree_eda.h"

using namespace std;


bool resuelveCaso() {
	vector<int> pre, in, post;
	bintree<int> ab;
	int num, p=0;
	char aux;
	cin >> num;
	if (!cin) { return false; }
	pre.push_back(num);
	cin.get(aux);
	while (aux != '\n') {
		cin >> num;
		pre.push_back(num);
		cin.get(aux);
	}
	cin >> num;
	if (!cin) { return false; }
	in.push_back(num);
	cin.get(aux);
	while (aux != '\n') {
		cin >> num;
		in.push_back(num);
		cin.get(aux);
	}
	ab = ab.crearArbol(pre, p, in);
	post = ab.postorder();
	if (!ab.empty()) { cout << post[0]; }
	for (int i = 1; i < post.size(); i++) {
		cout << ' ' << post[i];
	}
	cout << '\n';
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
	

	return 0;
}