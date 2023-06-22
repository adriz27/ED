//Adrián Pérez


#include <deque>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

typedef struct {
	int num;
	int pos;
}tNum;

bool resuelveCaso() {
	int n, k, num;
	tNum max = { 0, 0 };
	cin >> n >> k;
	if (n == 0 || k == 0) { return false; }
	deque<tNum> cola;
	for (int i = 0; i < k; i++) {
		cin >> num;
		while (!cola.empty() && num > cola.back().num) {
			cola.pop_back();
		}
		cola.push_back({ num, i });
	}
	cout << cola.front().num;
	for (int i = k; i < n; i++) {
		cin >> num;
		if (cola.front().pos == i - k) { cola.pop_front(); }
		while (!cola.empty() && num > cola.back().num) {
			cola.pop_back();
		}
		cola.push_back({ num, i });
		cout << " " << cola.front().num;
	}
	cout << '\n';
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	//while (resuelveCaso());

	return 0;
}