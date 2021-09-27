#pragma once

#include <iostream>
#include "Greske.h"
using namespace std;

template<typename T>
class Lista
{
protected:
	struct Node {
		T* data;
		Node* next;
		Node(T* data, Node* next = nullptr);
	};
	Node *prvi, *posl;
	// Metode
	void kopiraj(const Lista& l);
	void premesti(Lista& l);
	void isprazni();
public:
	// Konstruktori
	Lista();
	Lista(const Lista& l);
	Lista(Lista&& l);
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			isprazni();
			kopiraj(l);
		}
		return (*this);
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			isprazni();
			premesti(l);
		}
		return (*this);
	}
	~Lista();
	// Metode
	//virtual Lista* polimorfno_kopiraj() const { return new Lista(*this); }
	int dohvati_broj_podataka() const;
	// Operatori
	Lista& operator+=(const T& data) {
		Node* novi = new Node(data.polimorfno_kopiraj());
		if (prvi == nullptr) prvi = posl = novi;
		else posl = posl->next = novi;
		return *this;
	}
	T* operator-();
	T* operator*();
	friend ostream& operator<<(ostream& os, const Lista& l) {
		Node* tmp = l.prvi;
		while (tmp != nullptr) {
			os << *(tmp->data) << " ";
			tmp = tmp->next;
		}
		return os;
	}
};

template<typename T>
inline Lista<T>::Node::Node(T* data, Node* next)
{
	this->data = data;
	this->next = next;
}

template<typename T>
inline Lista<T>::Lista()
{
	prvi = posl = nullptr;
}

template<typename T>
inline Lista<T>::Lista(const Lista& l)
{
	kopiraj(l);
}

template<typename T>
inline Lista<T>::Lista(Lista&& l)
{
	premesti(l);
}

template<typename T>
inline Lista<T>::~Lista()
{
	isprazni();
}

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	for (Node* tmp = l.prvi; tmp != nullptr; tmp = tmp->next) {
		Node* novi = new Node(tmp->data);
		if (prvi == nullptr) posl = prvi = novi;
		else posl = posl->next = novi;
	}
}

template<typename T>
inline void Lista<T>::premesti(Lista& l)
{
	prvi = l.prvi;
	posl = l.posl;
	l.prvi = l.posl = nullptr;
}

template<typename T>
inline void Lista<T>::isprazni()
{
	while (prvi) {
		Node* tmp = prvi;
		prvi = prvi->next;
		delete tmp;
	}
	prvi = posl = nullptr;
}

template<typename T>
inline int Lista<T>::dohvati_broj_podataka() const
{
	int cnt = 0;
	Node* tmp = prvi;
	while (tmp != nullptr) {
		tmp = tmp->next;
		cnt++;
	}
	return cnt;
}

template<typename T>
inline T* Lista<T>::operator-()
{
	if (prvi == nullptr) throw GPraznaLista();
	if (prvi == posl) {
		T* res = prvi->data;
		delete prvi;
		prvi = posl = nullptr;
		return res;
	}
	Node* tmp = prvi;
	while (tmp->next != posl)
		tmp = tmp->next;
	tmp->next = nullptr;
	T* res = posl->data;
	delete posl;
	posl = tmp;
	tmp = nullptr;
	return res;
}

template<typename T>
inline T* Lista<T>::operator*()
{
	if (prvi == nullptr) throw GPraznaLista();
	Node* tmp = prvi;
	prvi = prvi->next;
	T* res = tmp->data;
	delete tmp;
	return res;
}
