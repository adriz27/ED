//Adrián Pérez

#include <fstream>
#include <iostream>

using namespace std;


int resuelve() {
	int nsons, max = 0;
	cin >> nsons;
	for (int i = 0; i < nsons; i++) {
		int x = resuelve();
		if (max < x) { max = x; }
	}
	return max + 1;
}

void resuelveCaso() {
	cout << resuelve() << '\n';
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
	
	return 0;
}