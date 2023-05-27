#pragma once
#include <fstream>
#include "Obj.h"

class IO : public OBJ {
public:
	virtual int input(std::istream& cin = std::cin) = 0;
	virtual void output(std::ostream& cout = std::cout) const = 0;
	virtual int input(std::ifstream&) = 0;
	virtual void output(std::ofstream&) const = 0;
	friend std::ostream& operator << (std::ostream&, const IO&);
	friend std::istream& operator >> (std::istream&, IO&);
	friend std::ofstream& operator << (std::ofstream&, const IO&);
	friend std::ifstream& operator >> (std::ifstream&, IO&);
};
