//Adrián Pérez

#ifndef arbolbin_h
#define arbolbin_h


#include "bintree_eda.h"
#include <iostream>

using namespace std;

template<class T>
class arbolbin : public bintree<T> {
	using TreeNode = typename bintree<T>::TreeNode;
	using Link = std::shared_ptr<TreeNode>;

public:
	int numNodos() {
		return nodos(this->raiz);
	}
	int numHojas() {
		return hojas(this->raiz);
	}
	int altura() {
		return alt(this->raiz);
	}
	
	
private:
	int nodos(Link raiz) {
		int x = 0;
		if (raiz != nullptr) {
			x += nodos(raiz->left) + nodos(raiz->right) + 1;
		}
		return x;
	}
	int hojas(Link raiz) {
		int x = 0;
		if (raiz != nullptr) {
			if (raiz->left == nullptr && raiz->right == nullptr) { x++; }
			else { x += hojas(raiz->left) + hojas(raiz->right); }
		}
		return x;
	}
	int alt(Link raiz) {
		if (raiz == nullptr) { return 1; }
		int altura = alt(raiz->left), a = alt(raiz->right);
		if (a > altura) { altura = a; }
		return altura + 1;
	}
};

template <typename T>
inline arbolbin<T> leer_Arbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		arbolbin<T> iz = leer_Arbol(vacio);
		arbolbin<T> dr = leer_Arbol(vacio);
		return arbolbin<T>(iz, raiz, dr);
	}
}
#endif