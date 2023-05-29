#include "Client.h"

// Конструктор по умолчанию
Client::Client() {
	phone = 0;
	age = 0.0;
}

// Конструктор с заданными параметрами полей
Client::Client(const char* n, const char* c, int p, int a, int d, int m, int y) :name(n), city(c), phone(p), age(a), birth(d, m, y) {
}

// Конструктор копирования
Client::Client(const Client& t) : name(t.name), city(t.city), phone(t.phone), age(t.age), birth(t.birth) {
}

// Деструктор
Client::~Client() {
	dispose();
}

// Ввод с клавиатуры
int Client::input(std::istream& cin) {
	std::cout << "Enter client name: ";
	cin >> name;
	bool b = cin.eof();
	if (b)
		return 0;

	std::cout << "Enter city: ";
	cin >> city;

	std::cout << "Enter phone: ";
	cin >> phone;

	std::cout << "Enter age: ";
	cin >> age;

	std::cout << "Enter birth's day, month and year:" << std::endl;
	cin >> birth;

	return 1;
}

// Вывод на экран
void Client::output(std::ostream& cout) const {
	cout << "Client name: " << name << std::endl;
	cout << "City: " << city << std::endl;
	cout << "Phone: " << phone << std::endl;
	cout << "Age: " << age << std::endl;
	cout << "Birth day: " << birth << std::endl;
}

// Ввод из файла
int Client::input(std::ifstream& cin) {
	cin >> name;
	bool b = cin.eof();
	if (b)
		return 0;
	cin >> city;
	cin >> phone;
	cin >> age;
	cin >> birth;
	return 1;
}

// Вывод в файл
void Client::output(std::ofstream& cout) const {
	cout << name;
	cout << city;
	cout << phone << std::endl;
	cout << age << std::endl;
	cout << birth;
}

// Сравнение
int Client::cmp(const Client& t) const {
	int cond;
	if ((cond = name.cmp(t.name)) != 0)
		return cond;
	else if ((cond = city.cmp(t.city)) != 0)
		return cond;
	else if ((cond = phone - t.phone) != 0)
		return cond;
	else if ((cond = age - t.age) != 0)
		return cond;
	else if ((cond = birth.cmp(t.birth)))
		return cond;
	return 0;
}

// Сравнение
int Client::cmp(const OBJ& t) const {
	if (t.toMyString() == MyString("Client"))
		return cmp((const Client&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// Проверка на равенство
int Client::equal(const Client& t) const {
	return !name.cmp(t.name) && !city.cmp(t.city) && (phone == t.phone) && (age == t.age) && !birth.cmp(t.birth);
}

// Проверка на равенство
int Client::equal(const OBJ& t) const {
	if (t.toMyString() == MyString("Book"))
		return equal((const Client&)t);
	std::cout << "Type error" << std::endl;
	exit(1);

}

// Создание копии в динамической памяти
Client* Client::copy() {
	return new Client(*this);
}

// Определение класса
MyString Client::toMyString() const {
	return MyString("Client");
}

// Освобождение памяти
void Client::dispose() {
}

// Оператор проверки на равенство
int operator == (const Client& a, const Client& b) {
	return !a.cmp(b);
}

// Оператор проверки на неравенство
int operator != (const Client& a, const Client& b) {
	if (a.cmp(b) != 0)
		return 1;
	return 0;
}

// Оператор проверки на меньшесть
int operator < (const Client& a, const Client& b) {
	return a.cmp(b) < 0;
}

// Оператор проверки на меньшесть либо равенство
int operator <= (const Client& a, const Client& b) {
	return a.cmp(b) <= 0;
}

// Оператор проверки на большесть
int operator > (const Client& a, const Client& b) {
	return a.cmp(b) > 0;
}

// Оператор проверки на большесть либо равенство
int operator >= (const Client& a, const Client& b) {
	return a.cmp(b) >= 0;
}

// Оператор вывода
std::ostream& operator << (std::ostream& os, const Client& r) {
	r.output(os);
	return os;
}

// Оператор ввода
std::istream& operator >> (std::istream& is, Client& r) {
	r.input(is);
	return is;
}
