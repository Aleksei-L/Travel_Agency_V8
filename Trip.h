#pragma once
#include "Client.h"
#include "Tour.h"

class Trip : public IO {
private:
	Client* client; // Указатель на структуру Клиент
	Tour* tour; // Указатель на структуру Тур
	MyString about; // Информация о турагенстве
	int days; // Кол-во дней поездки
	double price; // Стоимость поездки с учётом кол-ва дней
	MyDate date; // Дата поездки
public:
	Trip();
	Trip(Client*, Tour*, const char*, int, double, int, int, int);
	Trip(const Trip&);
	~Trip();
	int	input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int input(std::ifstream&);
	void output(std::ofstream&) const;
	int	cmp(const Trip&) const;
	int cmp(const OBJ&)const;
	int	equal(const Trip&) const;
	int equal(const OBJ&)const;
	Trip* copy();
	MyString toMyString() const;
	void dispose();
};
