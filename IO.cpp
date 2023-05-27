#include "IO.h"

// �������� ������
std::ostream& operator << (std::ostream& os, const IO& r) {
	r.output(os);
	return os;
}

// �������� �����
std::istream& operator >> (std::istream& is, IO& r) {
	r.input(is);
	return is;
}

// �������� ��������� ������
std::ofstream& operator << (std::ofstream& os, const IO& r) {
	r.output(os);
	return os;
}

// �������� ��������� �����
std::ifstream& operator >> (std::ifstream& is, IO& r) {
	r.input(is);
	return is;
}
