#include "Obj.h"

// �������� �������� �� ���������
int operator == (const OBJ& a, const OBJ& b) {
	return !a.cmp(b);
}

// �������� �������� �� �����������
int operator != (const OBJ& a, const OBJ& b) {
	return a.cmp(b);
}

// �������� �������� �� ���������
int operator < (const OBJ& a, const OBJ& b) {
	return a.cmp(b) < 0;
}

// �������� �������� �� ��������� ���� ���������
int operator <= (const OBJ& a, const OBJ& b) {
	return a.cmp(b) <= 0;
}

// �������� �������� �� ���������
int operator > (const OBJ& a, const OBJ& b) {
	return a.cmp(b) > 0;
}

// �������� �������� �� ��������� ���� ���������
int operator >= (const OBJ& a, const OBJ& b) {
	return a.cmp(b) >= 0;
}
