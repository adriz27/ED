//Adrián Pérez

#ifndef cola_h
#define cola_h


#include "queue_eda.h"
#include <iostream>

using namespace std;

template<class T>
class cola : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void show(ostream& cout) {
		if (!this->empty()) {
			cout << this->front();
			this->pop();
		}
		while (!this->empty()) {
			cout << " " << this->front();
			this->pop();
		}
		cout << '\n';
	}

	void mezcla(cola& c) {
		Nodo* x = this->prim;
		if (this->empty()) { 
			this->prim = c.prim; 
			this->ult = c.ult;
			this->nelems = c.nelems;
			c.prim = nullptr;
			c.ult = nullptr;
			c.nelems = 0;
		}
		if (!c.empty() && c.prim->elem < this->prim->elem) {
			this->prim = c.prim;
			c.prim = c.prim->sig;
			this->prim->sig = x;
			this->nelems++;
			c.nelems--;
			x = this->prim;
		}
		while (!c.empty() && x->sig != nullptr) {
			if (x->sig->elem > c.prim->elem) {
				Nodo* y = x;
				x = c.prim;
				c.prim = x->sig;
				x->sig = y->sig;
				y->sig = x;
				this->nelems++;
				c.nelems--;
			}
			else {x = x->sig; }
		}
		if (!c.empty()) {
			x->sig = c.prim;
			this->ult = c.ult;
			c.prim = nullptr;
			c.ult = nullptr;
			this->nelems += c.nelems;
			c.nelems = 0;
		}
	}

	T eligeAfortunado(int const& d) {
		if (!this->empty()) {
			this->ult->sig = this->prim;
			Nodo* x = this->prim, * aux;
			int n = this->size();
			for (int i = 1; i < n; i++) {
				for (int j = 1; j < d; j++) {
					x = x->sig;
				}
				aux = x->sig;
				x->sig = x->sig->sig;
				x = x->sig;
				delete aux;
			}
			this->prim = x;
			this->ult = x;
			x->sig = nullptr;
			return x->elem;
		}
		else { return 0; }
	}

	void modify() {
		int N = this->size();
		if (N == 1) { return; }
		if(N==2){
			this->ult->sig = this->prim;
			this->prim = this->ult;
			this->ult = this->ult->sig;
			this->ult->sig = nullptr;
		}
		if (N > 2) {
			Nodo* x = this->prim->sig;
			this->prim->sig = x->sig;
			x->sig = this->prim;
			this->prim = x;
			x = x->sig;
			for (int i = 2; i < N - 2; i += 2) {
				Nodo* y = x->sig->sig;
				x->sig->sig = y->sig;
				y->sig = x->sig;
				x->sig = y;
				x = y->sig;
			}
			if (x->sig->sig != nullptr) {
				this->ult = x->sig;
				x->sig = x->sig->sig;
				x->sig->sig = this->ult;
				this->ult->sig = nullptr;
			}
		}
	}

	void duplica() {
		if (this->empty()) { return; }
		int n = this->size();
		Nodo* x = this->prim;
		for (int i = 1; i < n; i++) {
			Nodo* nuevo = new Nodo(x->elem, x->sig);
			x->sig = nuevo;
			this->nelems++;
			x = x->sig->sig;
		}
		Nodo* nuevo = new Nodo(x->elem, nullptr);
		x->sig = nuevo;
		this->ult = nuevo;
		this->nelems++;
	}

	void ej72() {
		int n = this->size();
		Nodo* x = this->prim;
		for (int i = 0; i < (n-1)/2; i++) {
			Nodo* y = x->sig;
			x->sig = y->sig;
			delete y;
			x = x->sig;
			this->nelems--;
		}
		if (n % 2 == 0) {
			Nodo* y = x->sig;
			x->sig = nullptr;
			delete y;
			this->ult = x;
			this->nelems--;
		}
	}

	void invertir() {
		int n = this->size();
		if (n == 0) { return; }
		Nodo* x = this->prim;
		Nodo* y = x->sig;
		this->prim = this->ult;
		this->ult = x;
		x->sig = nullptr;
		for (int i = 0; i < n-2; i++) {
			Nodo* z = y->sig;
			y->sig = x;
			x = y;
			y = z;
		}
		if (n != 1) { y->sig = x; }
	}

	void insertar(cola<T>& c, int pos) {
		if (pos == 0) {
			c.ult->sig = this->prim;
			this->prim = c.prim;
			c.prim = nullptr;
			c.ult = nullptr;
			this->nelems += c.nelems;
			c.nelems = 0;
			return;
		}
		if (pos == this->size()) {
			this->ult->sig = c.prim;
			this->ult = c.ult;
			c.prim = nullptr;
			c.ult = nullptr;
			this->nelems += c.nelems;
			c.nelems = 0;
			return;
		}
		Nodo* x = this->prim;
		for (int i = 1; i < pos; i++) { x = x->sig; }
		Nodo* y = x->sig;
		x->sig = c.prim;
		c.ult->sig = y;
		c.prim = nullptr;
		c.ult = nullptr;
		this->nelems += c.nelems;
		c.nelems = 0;
	}
	
	void ej73() {
		Nodo* x = this->prim;
		while (x->sig != nullptr) {
			if (x->sig->elem < x->elem) {
				Nodo*y = x->sig;
				x->sig = x->sig->sig;
				delete y;
				this->nelems--;
			}
			else {
				x = x->sig;
			}
		}
	}
};

#endif