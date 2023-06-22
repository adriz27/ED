// Adrián Pérez

#include <fstream>
#include <iostream>
#include "treemap_eda.h"
#include <vector>


using namespace std;

void lee(map<string, vector<bool>>& a, int linea, int n) {
	string cl;
	char c;
	cin.get(c);
	while (c != '\n') {
		if (c == ' ') { cin >> c; }
		cl = "";
		while (c != ' ' && c != '\n') {
			c = tolower(c);
			cl += c;
			cin.get(c);
		}
		if (cl.size() > 2) {
			if (!a.count(cl)) {
				a.insert(cl);
				vector<bool> v;
				for (int i = 0; i < n; i++) { v.push_back(false); }
				a[cl] = v;
				a[cl][linea] = true;
			}
			else {
				a.insert(cl);
				a[cl][linea] = true;
			}
		}
	}
}

void escribe(map<string, vector<bool>>& a) {
	while (!a.empty()) {
		string s = a.menorc();
		vector<bool> v = a[s];
		cout << s;
		for (int i = 0; i < v.size(); i++) {
			if (v[i]) { cout << " " << i + 1; }
		}
		cout << '\n';
		a.erase(s);
	}
	cout << "---" << '\n';
}

bool resuelveCaso() {
	int n;
	char c;
	cin >> n;
	cin.get(c);
	if (n == 0) { return false; }
	map<string, vector<bool>> palabras;
	for (int i = 0; i < n; i++) {
		lee(palabras, i, n);
	}
	escribe(palabras);
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()){}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	//while (resuelveCaso()) {}

	return 0;
}