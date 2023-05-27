#pragma once
#include "MyString.h"

class Tour : public IO {
private:
	MyString name; // Название тура
	MyString country; // Страна в которую идёт тур
	int count; // Кол-во посещаемых городов
public:
	Tour();
	Tour(const char*, const char*, int);
	Tour(const Tour&);
	~Tour();
	int input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int input(std::ifstream&);
	void output(std::ofstream&) const;
	int cmp(const Tour&) const;
	int cmp(const OBJ&) const;
	int	equal(const Tour&) const;
	int equal(const OBJ&) const;
	Tour* copy();
	MyString toMyString() const;
	void dispose();
};
