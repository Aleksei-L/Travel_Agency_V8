#pragma once
#include "MyString.h"
#include "MyDate.h"

class Client : public IO {
private:
	MyString name; // Имя клиента
	MyString city; // Адрес клиента
	int phone; // Телефон клиента
	double age; // Возраст клиента
	MyDate birth; // Дата рождения клиента
public:
	Client();
	Client(const char*, const char*, int, int, int, int, int);
	Client(const Client&);
	~Client();
	int	input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int input(std::ifstream&);
	void output(std::ofstream&) const;
	int cmp(const Client&) const;
	int cmp(const OBJ&) const;
	int equal(const Client&) const;
	int equal(const OBJ&) const;
	Client* copy();
	MyString toMyString() const;
	void dispose();
	friend int operator == (const Client&, const Client&);
	friend int operator != (const Client&, const Client&);
	friend int operator < (const Client&, const Client&);
	friend int operator <= (const Client&, const Client&);
	friend int operator > (const Client&, const Client&);
	friend int operator >= (const Client&, const Client&);
	friend std::ostream& operator << (std::ostream&, const Client&);
	friend std::istream& operator >> (std::istream&, Client&);
};
