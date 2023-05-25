#pragma once
#include "IO.h"
#include "MyString.h"

class Tour : public IO {
private:
	MyString name; // �������� ����
	MyString country; // ������ � ������� ��� ���
	int count; // ���-�� ���������� �������
public:
	Tour();
	Tour(const char*, const char*, int);
	Tour(const Tour&);
	~Tour();
	void dispose();
	int input(std::istream& cin = std::cin);
	void output(std::ostream& os = std::cout) const;
	int	equal(const Tour&) const;
	int cmp(const Tour&) const;
	MyString toMyString() const;
	int equal(const OBJ&) const;
	int cmp(const OBJ&) const;
	Tour* copy();
};
