//Adrián Pérez

#include "dcola.h"
#include <fstream>


using namespace std;


void resuelve(dcola<char>& c) {
	c.decode();
	cout << c.toString() << '\n';
}

bool resuelveCaso() {
	string s;
	dcola<char> cola;
	getline(cin, s);
	if (!cin) { return false; }
	for (int i = 0; i < s.size(); i++) {
		cola.push_back(s[i]);
	}
	resuelve(cola);
	return true;
}

int main() {

/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	while (resuelveCaso());

	return 0;
}