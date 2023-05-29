#include "Trip.h"

// ����������� �� ���������
Trip::Trip() : days(0), price(0) {
	client = (Client*)0;
	tour = (Tour*)0;
}

// ����������� � ��������� ������
Trip::Trip(Client* c, Tour* t, const char* a, int ds, double p, int d, int m, int y) : about(a), days(ds), price(p), date(d, m, y) {
	client = c->copy();
	tour = t->copy();
}

// ����������� �����������
Trip::Trip(const Trip& t) : about(t.about), days(t.days), price(t.price), date(t.date) {
	if (t.client)
		client = t.client->copy();
	if (t.tour)
		tour = t.tour->copy();
}

// ����������
Trip::~Trip() {
	dispose();
}

// ���� � ����������
int Trip::input(std::istream& cin) {
	if (!client) {
		client = new Client();
		client->input(cin);
	}

	if (!tour) {
		tour = new Tour();
		tour->input(cin);
	}

	std::cout << "Enter info about tour: ";
	cin >> about;
	std::cout << "Enter number of days: ";
	cin >> days;
	std::cout << "Enter price: ";
	cin >> price;
	std::cout << "Enter date: " << std::endl;
	cin >> date;

	return 1;
}

// ����� �� �����
void Trip::output(std::ostream& cout) const {
	client->output(cout);
	tour->output(cout);
	cout << "Info about tour: " << about << std::endl;
	cout << "Number of days: " << days << std::endl;
	cout << "Price: " << price << std::endl;
	cout << "Date: " << date << std::endl;
}

// ���� �� �����
int Trip::input(std::ifstream& cin) {
	client->input(cin);
	tour->input(cin);
	cin >> about;
	cin >> days;
	cin >> price;
	cin >> date;
	return 1;
}

// ����� � ����
void Trip::output(std::ofstream& cout) const {
	client->output(cout);
	tour->output(cout);
	cout << about;
	cout << days << std::endl;
	cout << price << std::endl;
	cout << date;
}

// ���������
int Trip::cmp(const Trip& t) const {
	int cond;

	if (t.about.length() != 0 && ((cond = about.cmp(t.about)) != 0))
		return cond;
	else if ((cond = days - t.days) != 0)
		return cond;
	else if ((cond = price - t.price) != 0)
		return cond;
	else if ((cond = date.cmp(t.date)))
		return cond;
	else if ((cond = client->cmp(*t.client)) != 0)
		return cond;
	return tour->cmp(*t.tour) != 0;
}

// ���������
int Trip::cmp(const OBJ& t) const {
	if (t.toMyString() == MyString("Trip"))
		return cmp((const Trip&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// �������� �� ���������
int Trip::equal(const Trip& t) const {
	int a = 1;
	a = a && client->equal(*t.client);
	a = a && tour->equal(*t.tour);
	a = a && ((t.about.length() != 0) ? about.equal(t.about) : 1);
	a = a && (days == t.days);
	a = a && (price == t.price);
	a = a && ((t.date.getDay() != 0 && t.date.getMonth() != 0 && t.date.getYear() != 0) ? date.equal(t.date) : 1);
	return a;
}

// �������� �� ���������
int Trip::equal(const OBJ& t) const {
	if (t.toMyString() == MyString("Trip"))
		return equal((const Trip&)t);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// �������� ����� � ������������ ������
Trip* Trip::copy() {
	return new Trip(*this);
}

// ����������� ������
MyString Trip::toMyString() const {
	return MyString("Trip");
}

// ������������ ������
void Trip::dispose() {
	delete client;
	delete tour;
}
