// Adrián Pérez

#include <fstream>
#include <iostream>
#include "hashmap_eda.h"
#include <vector>


using namespace std;

typedef struct {
	string eq;
	int pr;
	int time;
}tResult;

bool lee(unordered_map<string, unordered_map<string, int>>& ranq) {
	string pr, eq, res;
	int time;
	cin >> eq;
	while (eq != "FIN") {
		if (!ranq.count(eq)) { ranq.insert(eq); }
		cin >> pr >> time >> res;
		if (!ranq[eq].count(pr)) {
			ranq[eq].insert(pr);
			ranq[eq][pr] = 0;
			if (res == "AC") { ranq[eq][pr] = time; }
			else { ranq[eq][pr]--; }
		}
		else {
			if (res == "AC") { ranq[eq][pr] = time - 20 * ranq[eq][pr]; }
			else { ranq[eq][pr]--; }
		}
		cin >> eq;
	}
	return true;
}

bool mayor(tResult& a, tResult& b) {
	return a.pr > b.pr || (a.pr == b.pr && (a.time < b.time || (a.time == b.time && a.eq < b.eq)));
}


void escribe(unordered_map<string, unordered_map<string, int>>& ranq) {
	vector<tResult> v;
	int n = ranq.size();
	for (int i = 0; i < n; i++) {
		tResult x;
		x.eq = ranq.begin()->clave;
		x.pr = 0;
		x.time = 0;
		int m = ranq[x.eq].size();
		for (int j = 0; j < m; j++) {
			string s = ranq[x.eq].begin()->clave;
			int n = ranq[x.eq][s];
			if (n > 0) {
				x.pr++;
				x.time += n;
			}
			ranq[x.eq].erase(s);
		}
		v.push_back(x);
		ranq.erase(x.eq); 
	}
	sort(v.begin(), v.end(), &mayor);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].eq << " " << v[i].pr << " " << v[i].time << '\n';
	}
	cout << "---" << '\n';
}

bool resuelveCaso() {
	unordered_map<string, unordered_map<string, int>> ranq;
	lee(ranq);
	escribe(ranq);
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	/*int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}*/

	return 0;
}