#pragma once
#include "Vector.h"
#include "IO.h"

class Table : public Vector {
private:
	T buf; // Буфер для промежуточного хранения клиента
	T* current; // Указатель на первый свободный в таблице
public:
	Table();
	Table(int s, T b);
	~Table();
	T* end() const;
	int length();
	T* erase(T* pos);
	void clear();
	void resize(int plusSize);
	T* insert(const T& newClient);
	int input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	void sort();
	int search(const T& tempClient);
	int replace(const T& oldClient, const T& newClient);
	int remove(const T& badClient);
	// Перегрузка операторов
	friend std::ostream& operator << (std::ostream& os, const Table& r);
	friend std::istream& operator >> (std::istream& is, Table& r);
};
