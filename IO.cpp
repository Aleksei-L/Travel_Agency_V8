#include "IO.h"

// Оператор вывода
std::ostream& operator << (std::ostream& os, const IO& r) {
	r.output(os);
	return os;
}

// Оператор ввода
std::istream& operator >> (std::istream& is, IO& r) {
	r.input(is);
	return is;
}
