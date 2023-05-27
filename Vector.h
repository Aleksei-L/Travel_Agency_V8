#pragma once
#include "Client.h"

class Vector {
private:
	T* v; // Массив для хранения объектов вектора (сам вектор)
	int size; // Размер вектора
public:
	Vector();
	Vector(int);
	Vector(const Vector&);
	~Vector();
	T* begin() const;
	T* end() const;
	int getSize();
	T& item(int);
	void resize(int);
	T& operator [] (int);
};
