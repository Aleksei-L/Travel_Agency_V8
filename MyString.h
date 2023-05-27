#pragma once
#include "IO.h"

class MyString : public IO {
private:
	char* s; // Указатель на строку
	char* cur; // Указатель на первый свободный элемент
	int len; // Длина строки
	int realSize() const;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
	int input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int input(std::ifstream&);
	void output(std::ofstream&) const;
	int cmp(const MyString&) const;
	int cmp(const OBJ&) const;
	int equal(const MyString&) const;
	int equal(const OBJ&) const;
	int length();
	int length() const;
	MyString* copy();
	MyString toMyString() const;
	void dispose();
	MyString& operator = (const MyString&);
	operator char* ();
	char& operator [] (int);
	MyString& operator += (const MyString&);
	friend int operator == (const MyString&, const MyString&);
	friend int operator != (const MyString&, const MyString&);
	friend int operator <(const MyString&, const MyString&);
	friend int operator <= (const MyString&, const MyString&);
	friend int operator > (const MyString&, const MyString&);
	friend int operator >= (const MyString&, const MyString&);
	friend MyString operator + (const MyString&, const MyString&);
};
