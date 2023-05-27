#pragma once
#include "IO.h"

typedef FILE* File;

class MyDate : public IO {
private:
	int day; // День
	int month; // Месяц
	int year; // Год
	static int daytab[2][13]; // Кол-во дней в месяцах
	static const char* MonthName[13]; // Названия месяцев
	static const char* DayNames[8]; // Названия дней недели
public:
	MyDate();
	MyDate(int, int, int);
	MyDate(char*);
	MyDate(const MyDate&);
	~MyDate();
	int	input(std::istream& cin = std::cin);
	void output(std::ostream& cout = std::cout) const;
	int input(std::ifstream&);
	void output(std::ofstream&) const;
	int	cmp(const MyDate&) const;
	int cmp(const OBJ&) const;
	int	equal(const MyDate&) const;
	int equal(const OBJ&) const;
	int getDay();
	int getDay() const;
	int getMonth();
	int getMonth() const;
	int getYear();
	int getYear() const;
	char* getDayOfWeek() const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void addDays(long);
	void addMonth(long);
	void addYears(long);
	int validate();
	static int isYearLeap(int);
	unsigned long toLong() const;
	char* toChar();
	static int dayOfYear(int, int, int);
	static void dayOfMonth(int, int, int*, int*);
	MyDate parser(char*);
	MyDate* copy();
	MyString toMyString() const;
	void dispose();
	MyDate& operator = (const MyDate);
	operator const char* ();
	MyDate& operator += (long);
	MyDate& operator ++ ();
	MyDate operator ++ (int);
	MyDate& operator -- ();
	MyDate operator -- (int);
	friend int operator == (const MyDate&, const MyDate&);
	friend int operator != (const MyDate&, const MyDate&);
	friend int operator <= (const MyDate&, const MyDate&);
	friend int operator >= (const MyDate&, const MyDate&);
	friend int operator < (const MyDate&, const MyDate&);
	friend int operator > (const MyDate&, const MyDate&);
	friend MyDate operator + (const MyDate&, long);
	friend long operator - (const MyDate&, const MyDate&);
};
