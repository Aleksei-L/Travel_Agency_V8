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

// Оператор файлового вывода
std::ofstream& operator << (std::ofstream& os, const IO& r) {
	r.output(os);
	return os;
}

// Оператор файлового ввода
std::ifstream& operator >> (std::ifstream& is, IO& r) {
	r.input(is);
	return is;
}
