#pragma once
#include "IO.h"
#include "Client.h"
#include "Tour.h"

class Trip : public IO {
private:
	Client* client; // ��������� �� ��������� ������
	Tour* tour; // ��������� �� ��������� ���
	MyString about; // ���������� � �����������
	int days; // ���-�� ���� �������
	double price; // ��������� ������� � ������ ���-�� ����
	MyDate date; // ���� �������
public:
	Trip();
	Trip(Client*, Tour*, const char*, int, double, int, int, int);
	Trip(const Trip&);
	~Trip();
	Trip* copy();
	void dispose();
	int	equal(const Trip&) const;
	int	cmp(const Trip&) const;
	int	input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int equal(const OBJ&)const;
	int cmp(const OBJ&)const;
	MyString toMyString() const;
};
