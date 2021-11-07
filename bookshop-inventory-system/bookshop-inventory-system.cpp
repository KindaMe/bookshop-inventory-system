#include <iostream>

int menu();

int main()
{
	switch (menu())
	{
	case 1:
		std::cout << "Add new book";
		break;
	case 2:
		std::cout << "Add existing book";
		break;
	case 3:
		std::cout << "Delete book";
		break;
	}
}

int menu()
{
	std::cout << "**************************\n";
	std::cout << "BOOKSHOP INVENTORY SYSTEM\n";
	std::cout << "**************************\n";
	int mode;
	std::cout << "Menu: \n\n";
	std::cout << "1 - Add new book\n";
	std::cout << "2 - Add existing book\n";
	std::cout << "3 - Delete book\n\n";

	std::cin >> mode;

	system("cls");

	return mode;
}