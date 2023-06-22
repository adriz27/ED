//Adrián Pérez

#include <queue>
#include <stack>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void print(queue<int>& c) {
	if (!c.empty()) {
		cout << c.front();
		c.pop();
	}
	while (!c.empty()) {
		cout << " " << c.front();
		c.pop();
	}
	cout << '\n';
}

void resuelve(queue<int>& c) {
	stack<int> neg;
	queue<int> pos;
	int n = c.size();
	for (int i = 0; i < n; i++) {
		if (c.front() > 0) { pos.push(c.front()); }
		else { neg.push(c.front()); }
		c.pop();
	}
	while (!neg.empty()) {
		c.push(neg.top());
		neg.pop();
	}
	while (!pos.empty()) {
		c.push(pos.front());
		pos.pop();
	}
}

bool resuelveCaso() {
	int n, num;
	cin >> n;
	if (n == 0) { return false; }
	queue<int> cola;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cola.push(num);
	}
	resuelve(cola);
	print(cola);

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