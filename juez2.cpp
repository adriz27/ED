//Adrian Perez


#include <vector>
#include <algorithm>
#include <fstream>
#include "pelicula.h"


bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0) { return false; }
	vector<pelicula>pelis(n);
	for (pelicula& p : pelis) {
		p.read(cin);
	}
	sort(pelis.begin(), pelis.end());
	for (int i = 0; i < n; i++) {
		pelis[i].print(cout);
	}
	cout << "---\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
/*#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso()){}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif*/

	while (resuelveCaso()) {}

	return 0;
}
