#include "Tour.h"

// ����������� �� ���������
Tour::Tour() {
	count = 0;
}

// ����������� � ��������� ����������� �����
Tour::Tour(const char* n, const char* cn, int co) : name(n), country(cn), count(co) {
}

// ����������� �����������
Tour::Tour(const Tour& t) : name(t.name), country(t.country), count(t.count) {
}

// ����������
Tour::~Tour() {}

// ���� � ����������
int Tour::input(std::istream& cin) {
	std::cout << "Enter tour name: ";
	cin >> name;
	bool b = cin.eof();
	if (b)
		return 0;

	std::cout << "Enter country name: ";
	cin >> country;

	std::cout << "Enter city's count: ";
	cin >> count;

	return 1;
}

// ����� �� �����
void Tour::output(std::ostream& cout) const {
	cout << "Tour name: " << name << std::endl;
	cout << "Country name: " << country << std::endl;
	cout << "City's count: " << count << std::endl;
}

// ���� �� �����
int Tour::input(std::ifstream& cin) {
	cin >> name;
	bool b = cin.eof();
	if (b)
		return 0;
	cin >> country;
	cin >> count;
	return 1;
}

// ����� � ����
void Tour::output(std::ofstream& cout) const {
	cout << name;
	cout << country;
	cout << count << std::endl;
}

// ���������
int Tour::cmp(const Tour& t) const {
	int cond;
	if ((cond = name.cmp(t.name)) != 0)
		return cond;
	else if ((cond = country.cmp(t.country)) != 0)
		return cond;
	else if ((cond = count - t.count) != 0)
		return cond;
	return 0;
}

// ���������
int Tour::cmp(const OBJ& t) const {
	if (t.toMyString() == MyString("Tour"))
		return cmp((const Tour&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// �������� �� ���������
int Tour::equal(const Tour& t) const {
	return !name.cmp(t.name) && !country.cmp(t.country) && (count == t.count);
}

// �������� �� ���������
int Tour::equal(const OBJ& t) const {
	if (t.toMyString() == MyString("Tour"))
		return equal((const Tour&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// �������� ����� � ������������ ������
Tour* Tour::copy() {
	return new Tour(*this);
}

// ����������� ������
MyString Tour::toMyString() const {
	return MyString("Tour");
}

// ������������ ������
void Tour::dispose() {}
