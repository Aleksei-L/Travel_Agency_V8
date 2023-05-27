#pragma once
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
