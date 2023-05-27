#pragma once
#include <iostream>
class MyString;

class OBJ {
public:
	virtual ~OBJ() {}
	virtual int cmp(const OBJ&) const = 0;
	virtual int equal(const OBJ&) const = 0;
	virtual OBJ* copy() = 0;
	virtual MyString toMyString() const = 0;
	virtual void dispose() = 0;
	friend int operator == (const OBJ&, const OBJ&);
	friend int operator != (const OBJ&, const OBJ&);
	friend int operator < (const OBJ&, const OBJ&);
	friend int operator <= (const OBJ&, const OBJ&);
	friend int operator > (const OBJ&, const OBJ&);
	friend int operator >= (const OBJ&, const OBJ&);
};

typedef OBJ* T;
