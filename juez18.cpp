//Adrián Pérez

#include <fstream>
#include <iostream>

using namespace std;


int resuelve(int k) {
	int nsons, tot = 0;
	cin >> nsons;
	if (nsons == 0 && k <= 0) { tot++; }
	for (int i = 0; i < nsons; i++) {
		tot += resuelve(k-1);
	}
	return tot;
}

bool resuelveCaso() {
	int k;
	cin >> k;
	if (!cin) { return false; }
	cout << resuelve(k) << '\n';
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