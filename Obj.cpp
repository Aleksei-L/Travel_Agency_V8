#include "Obj.h"

// Оператор проверки на равенство
int operator == (const OBJ& a, const OBJ& b) {
	return !a.cmp(b);
}

// Оператор проверки на неравенство
int operator != (const OBJ& a, const OBJ& b) {
	return a.cmp(b);
}

// Оператор проверки на меньшесть
int operator < (const OBJ& a, const OBJ& b) {
	return a.cmp(b) < 0;
}

// Оператор проверки на меньшесть либо равенство
int operator <= (const OBJ& a, const OBJ& b) {
	return a.cmp(b) <= 0;
}

// Оператор проверки на большесть
int operator > (const OBJ& a, const OBJ& b) {
	return a.cmp(b) > 0;
}

// Оператор проверки на большесть либо равенство
int operator >= (const OBJ& a, const OBJ& b) {
	return a.cmp(b) >= 0;
}
