#include <iostream>
#include <string>
#include <vector>

int menu();

class book {
public:
	int ID;
	std::string Title;
	std::string Author;
	int Amount;
	float Price;

	void addBook()
	{
		char yn;
		do
		{
			system("cls");

			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";
			std::cout << "ID: ";

			while (!(std::cin >> ID) || ID <= 0)
			{
				system("cls");
				std::cout << "ADD NEW BOOK\n";
				std::cout << "*************\n";
				std::cout << "Invalid ID.\n";
				std::cout << "ID: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cin.ignore(1000, '\n');
			system("cls");

			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";
			std::cout << "Title: ";
			getline(std::cin, Title);
			system("cls");

			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";
			std::cout << "Author: ";
			getline(std::cin, Author);
			system("cls");

			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";
			std::cout << "Amount: ";
			while (!(std::cin >> Amount) || Amount <= 0)
			{
				system("cls");
				std::cout << "ADD NEW BOOK\n";
				std::cout << "*************\n";
				std::cout << "Invalid Amount.\n";
				std::cout << "Amount: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cin.ignore(1000, '\n');
			system("cls");

			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";
			std::cout << "Price: ";
			while (!(std::cin >> Price) || Price <= 0)
			{
				system("cls");
				std::cout << "ADD NEW BOOK\n";
				std::cout << "*************\n";
				std::cout << "Invalid Price.\n";
				std::cout << "Price: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			std::cin.ignore(1000, '\n');
			system("cls");

			do
			{
				system("cls");

				std::cout << "ADD NEW BOOK\n";
				std::cout << "*************\n";

				std::cout << "You entered: \n\n";
				std::cout << "ID: " << ID << "\n";
				std::cout << "Title: " << Title << "\n";
				std::cout << "Author: " << Author << "\n";
				std::cout << "Amount: " << Amount << "\n";
				std::cout << "Price: " << Price << "\n";

				std::cout << "\nCorrect? (y/n): ";
				std::cin >> yn;
				yn = tolower(yn);

				switch (yn)
				{
				case 'y':
					std::cout << "\nBook added successfully.\nPress ENTER to continue...";
					std::cin.get();
					std::cin.clear();
					std::cin.ignore();
					break;

				case 'n':
					std::cout << "\nPress ENTER to try again...\n";
					std::cin.get();
					std::cin.clear();
					std::cin.ignore();
					break;
				default:
					std::cout << "\nInvalid input.\nPress ENTER to try again...\n";
					std::cin.get();
					std::cin.clear();
					std::cin.ignore();
					break;
				}
			} while (yn != 'y' && yn != 'n');
		} while (yn == 'n');
	}
};

int main()
{
	book tempBook; //JUST FOR NOW

	do
	{
		system("cls");

		switch (menu())
		{
		case 1:
			tempBook.addBook();
			break;
		case 2:
			//debug
			system("cls");
			std::cout << "ADD EXISTING BOOK\n";
			std::cout << "******************\n";
			std::cin.clear();
			std::cin.ignore();
			std::cin.get();
			break;
			//
		case 3:
			//debug
			system("cls");
			std::cout << "DELETE BOOK\n";
			std::cout << "************\n";
			std::cin.clear();
			std::cin.ignore();
			std::cin.get();
			break;
			//
		case 4:
			system("cls");
			std::cout << "BROWSE STORAGE\n";
			std::cout << "***************\n";
			std::cin.clear();
			std::cin.ignore();
			std::cin.get();
			break;
		case -1:
			std::cout << "\nInvalid input.\nPress ENTER to try again...";
			std::cin.get();
			break;
		}
	} while (true);
}

int menu()
{
	int mode;

	std::cout << "BOOKSHOP INVENTORY SYSTEM\n";
	std::cout << "**************************\n";

	std::cout << "MENU: \n\n";
	std::cout << "1 - ADD NEW BOOK\n";
	std::cout << "2 - ADD EXISTING BOOK\n";
	std::cout << "3 - DELETE BOOK\n";
	std::cout << "4 - BROWSE STORAGE\n\n";

	while (!(std::cin >> mode) || (mode < 1 || mode > 4))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}

	return mode;
}