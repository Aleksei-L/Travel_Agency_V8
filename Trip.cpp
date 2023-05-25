#include "Trip.h"

// ����������� �� ���������
Trip::Trip() {
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

// ������������ ������
void Trip::dispose() {
	delete client;
	delete tour;
}

// ����������
Trip::~Trip() {
	dispose();
}

// �������� ����� � ������������ ������
Trip* Trip::copy() {
	return new Trip(*this);
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

// ���������
int Trip::cmp(const Trip& t) const {
	int cond;

	if (t.about.length() != 0 && (cond = about.cmp(t.about)))
		return cond;
	else if ((cond = (days == t.days)))
		return cond;
	else if ((cond = (price == t.price)))
		return cond;
	else if ((cond = date.cmp(t.date)))
		return cond;
	else if ((cond = client->cmp(*t.client)))
		return cond;
	return tour->cmp(*t.tour);
}

// ���� ������
int Trip::input(std::istream& cin) {
	std::cout << "Enter info about tour: ";
	cin >> about;

	bool b1 = cin.eof();
	if (b1)
		return 0;

	std::cout << "Enter number of days: ";
	cin >> days;
	std::cout << "Enter price: ";
	cin >> price;
	std::cout << "Enter date: ";
	cin >> date;

	if (!client) {
		client = new Client();
		client->input(cin);
	}

	if (!tour) {
		tour = new Tour();
		tour->input(cin);
	}

	return 1;
}

// ����� ������
void Trip::output(std::ostream& cout) const {
	client->output(cout);
	tour->output(cout);
	cout << "Info about tour: " << about << std::endl;
	cout << "Number of days: " << days << std::endl;
	cout << "Price: " << price << std::endl;
	cout << "Date: " << date << std::endl;
}

// ����������� ������
MyString Trip::toMyString()const {
	return MyString("Trip");
}

// �������� �� ���������
int Trip::equal(const OBJ& o) const {
	if (o.toMyString() == MyString("Trip"))
		return equal((const Trip&)o);
	std::cout << "Type error" << std::endl;
	exit(1);
}

// ���������
int Trip::cmp(const OBJ& o) const {
	if (o.toMyString() == MyString("Trip"))
		return cmp((const Trip&)o);
	std::cout << "Type error" << std::endl;
	exit(1);
}