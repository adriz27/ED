#include "fecha.h"
#include <stack>
#include <fstream>

typedef struct {
	fecha f;
	int muertos;
}accidente;

void resuelve(stack<accidente>& pila, accidente const& a) {
	bool b = true;
	while (b && !pila.empty()) {
		if (pila.top().muertos <= a.muertos) {
			pila.pop();
		}
		else {
			pila.top().f.print();
			b = false;
		}
	}
	if(b) {
		cout << "NO HAY\n"; 
	}
	pila.push(a);
}

bool resuelveCaso() {
	int N;
	std::stack<accidente> pila;
	accidente acc;
	cin >> N;
	if (!cin) // fin de la entrada
		return false;
	for (int i = 0; i < N; i++) {
		acc.f.read();
		cin >> acc.muertos;
		resuelve(pila, acc);
	}
	cout << "---\n";
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

	return 0;
}