#include "Table.h"
#include "Trip.h"

int main() {
	Trip l, l2;
	Trip* buf = &l, * buf2 = &l2;
	Table t(2, buf);

	Client b, b2;
	Client* bufb = &b, * bufb2 = &b2;
	Table t1(2, bufb);

	Tour r, r2;
	Tour* bufr = &r, * bufr2 = &r2;
	Table t2(2, bufr);

	Table* p = &t;
	IO* buf_1 = NULL, * buf_2 = NULL;
	char endline;
	int ind, i, position, code, count;

	/*
	int size, code, ;
	std::cout << "Enter Table's size: ";
	std::cin >> size;
	Client first, second;
	Client* buf = &first;
	Table myT(size, buf);*/

	while (true) {
		std::cout << "Select the program operation mode:" << std::endl;
		//std::cout << "Now you work with " << p->item(0)->toMyString() << " table" << std::endl;
		std::cout << "1) Input table" << std::endl;
		std::cout << "2) Output table" << std::endl;
		std::cout << "3) Sort table" << std::endl;
		std::cout << "4) Search client in table" << std::endl;
		std::cout << "5) Erase client from table" << std::endl;
		std::cout << "6) Remove client from table" << std::endl;
		std::cout << "7) Replace client in table" << std::endl;
		std::cout << "8) Change table mode" << std::endl;
		std::cout << "9) Save table" << std::endl;
		std::cout << "10) Exit" << std::endl;
		std::cin >> code;
		switch (code) {
		case 1:
			t1.append("Client.txt");
			std::cout << t1;
			t2.append("Tour.txt");
			std::cout << t2;
			for (count = 0; count < t.getSize(); count++) {
				std::cout << "Enter index of element Client Table or -1 for input with keyboard CTRL Z for exit" << std::endl;
				int ind_b;
				std::cin >> ind_b;
				if (std::cin.eof()) {
					std::cin.clear();
					break;
				}
				std::cout << "Enter index of element Client Tour or -1 for input with keyboard CTRL Z for exit" << std::endl;
				int ind_r;
				std::cin >> ind_r;
				Client* pb = (Client*)((ind_b == -1) ? 0 : t1[ind_b]);
				Tour* pr = (Tour*)((ind_r == -1) ? 0 : t2[ind_r]);
				Trip l(pb->copy(), pr->copy(), "a", 1, 2, 1, 1, 1);
				l.input();
				t.insert(&l);
			}
			t.save("Trip.txt");
			break;
		case 2:
			std::cout << std::endl;
			std::cout << "Elements:" << std::endl;
			std::cout << *p;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl;
			p->sort();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << "input element for find" << std::endl;
			buf_1->input();
			i = p->search(buf_1);
			if (i >= 0)
				std::cout << "position=" << i << std::endl;
			else
				std::cout << "no found" << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			std::cout << "Enter position for Erase:" << std::endl;
			std::cin >> position;
			std::cin.get(endline);
			//myT.erase(myT.begin() + position - 1);
			p->erase(p->begin() + position);
			std::cout << std::endl;
			break;
		case 6:
			std::cout << std::endl;
			std::cout << "Enter element for Remove:" << std::endl;
			//std::cin >> first;
			buf_1->input();
			i = p->remove(buf_1);
			if (i == 0)
				std::cout << "No fonud" << std::endl;
			//myT.remove(&first);
			std::cout << std::endl;
			break;
		case 7:
			std::cout << std::endl;
			std::cout << "Enter old element for Replace:" << std::endl;
			//std::cin >> first;
			buf_1->input();
			std::cout << "Enter new element for Replace:" << std::endl;
			//std::cin >> second;
			buf_2->input();
			i = p->replace(buf_1, buf_2);
			//myT.replace(&first, &second);
			if (i == 0)
				std::cout << "No found" << std::endl;
			std::cout << std::endl;
			break;
		case 8:
			std::cout << "1 - Client, 2 - Tour, 3 - Trip" << std::endl;
			std::cin >> ind;
			if (ind == 1) {
				p = &t1;
				buf_1 = bufb;
				buf_2 = bufb2;
			}
			else if (ind == 2) {
				p = &t2;
				buf_1 = bufr;
				buf_2 = bufr2;
			}
			else if (ind == 3) {
				p = &t;
				buf_1 = buf;
				buf_2 = buf2;
			}
			else
				std::cout << "Error choise" << std::endl;
			break;
		case 9:
			t1.save("Client.txt");
			t2.save("Tour.txt");
			t.save("Trip.txt");
			break;
		case 10:
			return 0;
		default:
			std::cout << std::endl;
			std::cout << "Unknown command" << std::endl;
			std::cout << std::endl;
		}
	}
}
