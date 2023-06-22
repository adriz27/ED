// Adrián Pérez

#include <fstream>
#include <iostream>
#include "hashmap_eda.h"
#include <vector>


using namespace std;



bool resuelve(unordered_map<string, int>& sports) {
	unordered_map<string, string> ids;
	string cl, deporte;
	getline(cin, deporte);
	if (!cin) { return false; }
	while (deporte != "_FIN_") {
		sports.insert(deporte);
		sports[deporte] = 0;
		getline(cin, cl);
		while (cl[0] >= 'a' && cl[0] <= 'z') {
			if (ids.count(cl)) {
				if (ids[cl] != deporte && ids[cl] != "NADA") {
					sports[ids[cl]]--;
					ids[cl] = "NADA";
				}
			}
			else {
				sports[deporte]++;
				ids.insert(cl);
				ids[cl] = deporte;
			}
			getline(cin, cl);
		}
		deporte = cl;
	}
	return true;
}

bool mayor(pair<string, int>& a, pair<string,int> &b) {
	return (a.second > b.second) || (a.second == b.second && a.first < b.first);
}

void escribe(unordered_map<string, int>& a) {
	vector<pair<string, int>> v;
	int n = a.size();
	for (int i = 0; i < n; i++) {
		v.push_back({ a.begin()->clave, a.begin()->valor });
		a.erase(a.begin()->clave);
	}
	sort(v.begin(), v.end(), &mayor);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	cout << "---" << '\n';
}

bool resuelveCaso() {
	unordered_map<string, int> deportes;
	if (!resuelve(deportes)) { return false; }
	escribe(deportes);
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