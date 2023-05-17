#pragma once
#include "Obj.h"

class IO :public OBJ {
public:
	virtual int input(std::istream& cin = std::cin) = 0;
	virtual void output(std::ostream& cout = std::cout) const = 0;
	friend std::ostream& operator << (std::ostream&, const IO&);
	friend std::istream& operator >> (std::istream&, IO&);
};
