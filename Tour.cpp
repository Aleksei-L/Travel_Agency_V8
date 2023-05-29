#include "Tour.h"

// Конструктор по умолчанию
Tour::Tour() {
	count = 0;
}

// Конструктор с заданными параметрами полей
Tour::Tour(const char* n, const char* cn, int co) : name(n), country(cn), count(co) {
}

// Конструктор копирования
Tour::Tour(const Tour& t) : name(t.name), country(t.country), count(t.count) {
}

// Деструктор
Tour::~Tour() {}

// Ввод с клавиатуры
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

// Вывод на экран
void Tour::output(std::ostream& cout) const {
	cout << "Tour name: " << name << std::endl;
	cout << "Country name: " << country << std::endl;
	cout << "City's count: " << count << std::endl;
}

// Ввод из файла
int Tour::input(std::ifstream& cin) {
	cin >> name;
	bool b = cin.eof();
	if (b)
		return 0;
	cin >> country;
	cin >> count;
	return 1;
}

// Вывод в файл
void Tour::output(std::ofstream& cout) const {
	cout << name;
	cout << country;
	cout << count << std::endl;
}

// Сравнение
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

// Сравнение
int Tour::cmp(const OBJ& t) const {
	if (t.toMyString() == MyString("Tour"))
		return cmp((const Tour&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// Проверка на равенство
int Tour::equal(const Tour& t) const {
	return !name.cmp(t.name) && !country.cmp(t.country) && (count == t.count);
}

// Проверка на равенство
int Tour::equal(const OBJ& t) const {
	if (t.toMyString() == MyString("Tour"))
		return equal((const Tour&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// Создание копии в динамической памяти
Tour* Tour::copy() {
	return new Tour(*this);
}

// Определение класса
MyString Tour::toMyString() const {
	return MyString("Tour");
}

// Освобождение памяти
void Tour::dispose() {}
