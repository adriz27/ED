//Adrián Pérez

#ifndef dcola_h
#define dcola_h


#include "deque_eda.h"
#include "stack_eda.h"
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

template<class T>
class dcola : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void decode() {
		paso1();
		paso2();
	}
	
	string toString() {
		string s;
		Nodo* x = this->fantasma->sig;
		for (int i = 0; i < this->size(); i++) {
			s += x->elem;
			x = x->sig;
		}
		return s;
	}

private:
	void paso2() {
		int n = this->size();
		Nodo* x = this->fantasma->sig;
		bool cons = false;
		stack<T> pila;
		for (int i = 0; i < n; i++) {
			if (vocal(x->elem)) {
				if (cons) {
					int m = pila.size();
					Nodo* y = x->ant;
					for (int j = 1; j < m; j++) {
						y = y->ant;
					}
					for (int j = 0; j < m; j++) {
						y->elem = pila.top();
						pila.pop();
						y = y->sig;
					}
					cons = false;
				}
			}
			else{
				if (!cons) { cons = true; }
				pila.push(x->elem);
			}
			x = x->sig;
		}
		if (cons) {
			int m = pila.size();
			Nodo* y = x->ant;
			for (int j = 1; j < m; j++) {
				y = y->ant;
			}
			for (int j = 0; j < m; j++) {
				y->elem = pila.top();
				pila.pop();
				y = y->sig;
			}
			cons = false;
		}
	}

	void paso1() {
		dcola<char> d, c;
		d.copia(*this);
		while (this->size() > 0) {
			this->pop_back();
		}
		while (!d.empty()) {
			this->push_back(d.front());
			d.pop_front();
			if (!d.empty()) {
				c.push_front(d.front());
				d.pop_front();
			}
		}
		while (!c.empty()) {
			this->push_back(c.front());
			c.pop_front();
		}
	}

	bool vocal(char l) {
		return l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' || l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U';
	}
};
#endif

