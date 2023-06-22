// Adrián Pérez

#include <fstream>
#include <iostream>
#include "treemap_eda.h"
#include <queue>

using namespace std;

void lee(map<string, int>& a) {
	string cl;
	int val;
	char c;
	cin.get(c);
	while (c != '\n') {
		if (c == ' ') { cin >> c; }
		cl = "";
		while (c != ' ') {
			cl += c;
			cin.get(c);
		}
		a.insert(cl);
		cin >> val;
		a[cl] = val;
		cin.get(c);
	}
}


void resuelveCaso() {
	map<string, int> antes, despues;
	lee(antes);
	lee(despues);
	queue<string> added, deleted, changed;
	while (!despues.empty() && !antes.empty()) {
		string des = despues.menorc(), ant = antes.menorc();
		if (des < ant) {
			added.push(des);
			despues.erase(des);
		}
		else if (des == ant) {
			if (despues[des] != antes[ant]) { changed.push(des); }
			despues.erase(des);
			antes.erase(ant);
		}
		else {
			deleted.push(ant);
			antes.erase(ant);
		}
	}
	while (!despues.empty()) {
		added.push(despues.menorc());
		despues.erase(despues.menorc());
	}
	while (!antes.empty()) {
		deleted.push(antes.menorc());
		antes.erase(antes.menorc());
	}

	if (added.empty() && changed.empty() && deleted.empty()) { cout << "Sin cambios" << '\n'; }
	if (!added.empty()) {
		cout << "+";
		int n = added.size();
		for (int i = 0; i < n; i++) {
			cout << " " << added.front();
			added.pop();
		}
		cout << '\n';
	}
	if (!deleted.empty()) {
		cout << "-";
		int n = deleted.size();
		for (int i = 0; i < n; i++) {
			cout << " " << deleted.front();
			deleted.pop();
		}
		cout << '\n';
	}
	if (!changed.empty()) {
		cout << "*";
		int n = changed.size();
		for (int i = 0; i < n; i++) {
			cout << " " << changed.front();
			changed.pop();
		}
		cout << '\n';
	}
	cout << "---" << '\n';
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	char c;
	cin.get(c);
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	/*int numCasos;
	cin >> numCasos;
	char c;
	cin.get(c);
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/

	return 0;
}