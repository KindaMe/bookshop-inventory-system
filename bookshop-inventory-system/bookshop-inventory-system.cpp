#include <iostream>

int menu();

int main()
{
	switch (menu())
	{
	case 1:
		std::cout << "ADD NEW BOOK\n";
		std::cout << "*************\n";
		break;
	case 2:
		std::cout << "ADD EXISTING BOOK\n";
		std::cout << "******************\n";
		break;
	case 3:
		std::cout << "DELETE BOOK\n";
		std::cout << "************\n";
		break;
	}

	system("pause>0");
}

int menu()
{
	int mode;
	do
	{
		std::cout << "BOOKSHOP INVENTORY SYSTEM\n";
		std::cout << "**************************\n";

		std::cout << "MENU: \n\n";
		std::cout << "1 - ADD NEW BOOK\n";
		std::cout << "2 - ADD EXISTING BOOK\n";
		std::cout << "3 - DELETE BOOK\n\n";

		std::cin >> mode;

		system("cls");
	} while (mode < 1 || mode > 3);

	return mode;
}