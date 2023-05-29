#include "Table.h"
#include "Trip.h"

int main() {
	Client cl, cl2;
	Client* bufCl = &cl, * bufCl2 = &cl2;
	Table tCl(2, bufCl);

	Tour to, to2;
	Tour* bufTo = &to, * bufTo2 = &to2;
	Table tTo(2, bufTo);

	Trip tr, tr2;
	Trip* bufTr = &tr, * bufTr2 = &tr2;
	Table tTr(2, bufTr);

	Table* p = &tCl;
	IO* buf_1 = bufCl, * buf_2 = bufCl2;
	char endline;
	int ind, i, position, code, count;

	while (true) {
		std::cout << "Select the program operation mode:" << std::endl;
		std::cout << "1) Input all tables" << std::endl;
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
			std::cout << std::endl;
			tCl.append("Client.txt");
			std::cout << std::endl;
			tTo.append("Tour.txt");
			std::cout << std::endl;
			for (count = 0; count < tTr.getSize(); count++) {
				std::cout << "Enter index of Client table element or -1 for input with keyboard CTRL-Z for exit" << std::endl;
				int ind_cl;
				std::cin >> ind_cl;
				if (std::cin.eof()) {
					std::cin.clear();
					break;
				}
				std::cout << "Enter index of Tour table element or -1 for input with keyboard CTRL-Z for exit" << std::endl;
				int ind_to;
				std::cin >> ind_to;
				Client* pCl = (Client*)((ind_cl == -1) ? 0 : tCl[ind_cl]);
				if (pCl == 0) {
					pCl = bufCl;
					bufCl->input();
				}
				Tour* pTo = (Tour*)((ind_to == -1) ? 0 : tTo[ind_to]);
				if (pTo == 0) {
					pTo = bufTo;
					bufTo->input();
				}
				Trip pTr(pCl->copy(), pTo->copy(), "a", 1, 2, 1, 1, 1);
				pTr.input();
				tTr.insert(&pTr);
				std::cout << std::endl;
			}
			tTr.save("Trip.txt");
			std::cout << std::endl;
			break;
		case 2:
			std::cout << std::endl;
			std::cout << *p;
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl;
			p->sort();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			std::cout << "Enter element for search" << std::endl;
			buf_1->input();
			i = p->search(buf_1);
			if (i >= 0)
				std::cout << std::endl << "Element position: " << i << std::endl;
			else
				std::cout << std::endl << "Not found" << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			std::cout << "Enter position for Erase:" << std::endl;
			std::cin >> position;
			std::cin.get(endline);
			p->erase(p->begin() + position);
			std::cout << std::endl;
			break;
		case 6:
			std::cout << std::endl;
			std::cout << "Enter element for Remove:" << std::endl;
			buf_1->input();
			i = p->remove(buf_1);
			if (i == 0)
				std::cout << std::endl << "Not found" << std::endl;
			std::cout << std::endl;
			break;
		case 7:
			std::cout << std::endl;
			std::cout << "Enter old element for Replace:" << std::endl;
			buf_1->input();
			std::cout << "Enter new element for Replace:" << std::endl;
			buf_2->input();
			i = p->replace(buf_1, buf_2);
			if (i == 0)
				std::cout << std::endl << "Not found" << std::endl;
			std::cout << std::endl;
			break;
		case 8:
			std::cout << std::endl;
			std::cout << "1 - Client, 2 - Tour, 3 - Trip" << std::endl;
			std::cin >> ind;
			if (ind == 1) {
				p = &tCl;
				buf_1 = bufCl;
				buf_2 = bufCl2;
			}
			else if (ind == 2) {
				p = &tTo;
				buf_1 = bufTo;
				buf_2 = bufTo2;
			}
			else if (ind == 3) {
				p = &tTr;
				buf_1 = bufTr;
				buf_2 = bufTr2;
			}
			else
				std::cout << "Error choise" << std::endl;
			std::cout << std::endl;
			break;
		case 9:
			std::cout << std::endl;
			tCl.save("Client.txt");
			tTo.save("Tour.txt");
			tTr.save("Trip.txt");
			std::cout << std::endl;
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
