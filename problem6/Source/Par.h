#pragma once

#include <iostream>
using namespace std;

template<typename T>
class Par
{
private:
	T* first;
	T* second;
public:
	// Konstruktor
	Par(const T* first = nullptr, const T* second = nullptr);
	~Par();
	// Getteri
	T& dohvati_prvi() const;
	T& dohvati_drugi() const;
	// Setteri
	void postavi_prvi(const T* t);
	void postavi_drugi(const T* t);
	// Operatori
	friend bool operator==(const Par& p1, const Par& p2) {
		return (*p1.first == *p2.first && *p1.second == *p2.second);
	}
	friend ostream& operator<<(ostream& os, const Par& p) {
		return os << "[" << *p.first << "," << *p.second << "]";
	}
};

template<typename T>
inline Par<T>::Par(const T* first, const T* second)
{
	this->first = const_cast<T*>(first);
	this->second = const_cast<T*>(second);
}

template<typename T>
inline Par<T>::~Par()
{
	first = second = nullptr;
}

template<typename T>
inline T& Par<T>::dohvati_prvi() const
{
	return *(this->first);
}

template<typename T>
inline T& Par<T>::dohvati_drugi() const
{
	return *(this->second);
}

template<typename T>
inline void Par<T>::postavi_prvi(const T* t)
{
	this->first = const_cast<T*>(t);
}

template<typename T>
inline void Par<T>::postavi_drugi(const T* t)
{
	this->second = const_cast<T*>(t);
}
