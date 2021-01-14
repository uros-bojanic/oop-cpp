#pragma once

#include "Greske.h"
using namespace std;

template <typename T>
class Lista
{
private:
    struct Node {
        T data;
        Node* next;
        // Konstruktor
        Node(const T& data, Node* next = nullptr);
    };
    Node *prvi, *posl;
    mutable Node *tek, *pret;
    int n;
    // Metode
    void isprazni();
public:
    // Konstruktori
    Lista();
    ~Lista();
    // Zabrana kopiranja
    Lista(const Lista& l) = delete;
    void operator=(const Lista& l) = delete;
    Lista& dodaj_na_kraj(const T& t) {
        Node* novi = new Node(t);
        if (prvi == nullptr) {
            prvi = novi;
        }
        else {
            posl->next = novi;
        }
        posl = novi;
        n++;
        return *this;
    }
    Lista& postavi_tekuci_na_prvi() {
        tek = prvi;
        pret = nullptr;
        return *this;
    }
    Lista& pomeri_tekuci_na_sledeci() {
        pret = tek;
        if (tek != nullptr) tek = tek->next;
        return *this;
    }
    bool postoji_tekuci() const {
        return tek != nullptr;
    }
    T& dohvati_tekuci_element() const {
        if (tek == nullptr) throw GNePostojiElement();
        return tek->data;
    }
    Lista& izbaci_tekuci() {
        if (tek == nullptr) throw GNePostojiElement();
        Node* tmp = tek;
        tek = tek->next;
        if (pret == nullptr) prvi = tek;
        else pret->next = tek;
        if (tek == nullptr) posl = pret;
        delete tmp;
        n--;
        return *this;
    }
};

template<typename T>
inline Lista<T>::Node::Node(const T& data, Node* next)
{
    this->data = data;
    this->next = next;
}

template<typename T>
inline Lista<T>::Lista()
{
    prvi = posl = tek = pret = nullptr;
    n = 0;
}

template<typename T>
inline Lista<T>::~Lista()
{
    isprazni();
}

template<typename T>
inline void Lista<T>::isprazni()
{
    while (prvi != nullptr) {
        Node* tmp = prvi;
        prvi = prvi->next;
        delete tmp;
    }
    posl = tek = pret = nullptr;
    n = 0;
}