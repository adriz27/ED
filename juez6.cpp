//Adrián Pérez

#include <stack>
#include <fstream>
#include <iostream>
#include <stdexcept>  
#include <iomanip>
#include <string>

using namespace std;


bool resuelve(stack<char>& pila, char const& c) {
	bool b = true;
	if (c == '{' || c == '(' || c == '[') {
		pila.push(c);
	}
	else if(!pila.empty()){
		if (pila.top() == '(' && c == ')') { pila.pop(); }
		else if (pila.top() == '[' && c == ']') { pila.pop(); }
		else if (pila.top() == '{' && c == '}') { pila.pop(); }
		else { b = false; }
	}
	else { b = false; }
	return b;
}

bool resuelveCaso() {
	char c;
	string s;
	int i = 0;
	stack<char> pila;
	bool b = true;
	getline(cin, s);
	if (!cin) { return false; }
	while (i < s.size() && b) {
		c = s[i];
		i++;
		if (c == '{' || c == '(' || c == ')' || c == '[' || c == ']' || c == '}') {
			b = resuelve(pila, c);
		}
	}
	if (b && pila.empty()) { cout << "SI\n"; }
	else { cout << "NO\n"; }
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