#pragma once
#include "Vector.h"

class Table : public Vector {
private:
	T buf; // Буфер для промежуточного хранения
	T* current; // Указатель на первый свободный в таблице
public:
	Table();
	Table(int, T);
	~Table();
	int input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int input(std::ifstream&);
	void output(std::ofstream&) const;
	T* insert(const T&);
	void resize(int);
	T* end() const;
	int length();
	T* erase(T*);
	void clear();
	void sort();
	int search(const T&);
	int replace(const T&, const T&);
	int remove(const T&);
	int append(const char*);
	int save(const char*);
	friend std::ostream& operator << (std::ostream&, const Table&);
	friend std::istream& operator >> (std::istream&, Table&);
};
