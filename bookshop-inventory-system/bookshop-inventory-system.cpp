#include <iostream>
#include <string>
#include <vector>

int menu();
void addBook();

class book {
public:
	int ID;
	std::string Title;
	std::string Author;
	int Amount;
	float Price;

	book(int id, std::string title, std::string author, int amount, float price)
	{
		ID = id;
		Title = title;
		Author = author;
		Amount = amount;
		Price = price;
	}
};

int main()
{
	std::vector<book> storage;

	do
	{
		system("cls");

		switch (menu())
		{
		case 1:
			addBook();
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

void addBook()
{
	char yn;

	int localID;
	std::string localTitle;
	std::string localAuthor;
	int localAmount;
	float localPrice;

	do
	{
		system("cls");

		std::cout << "ADD NEW BOOK\n";
		std::cout << "*************\n";
		std::cout << "ID: ";

		while (!(std::cin >> localID) || localID <= 0)
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
		getline(std::cin, localTitle);
		system("cls");

		std::cout << "ADD NEW BOOK\n";
		std::cout << "*************\n";
		std::cout << "Author: ";
		getline(std::cin, localAuthor);
		system("cls");

		std::cout << "ADD NEW BOOK\n";
		std::cout << "*************\n";
		std::cout << "Amount: ";
		while (!(std::cin >> localAmount) || localAmount <= 0)
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
		while (!(std::cin >> localPrice) || localPrice <= 0)
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

		book tempBook(localID, localTitle, localAuthor, localAmount, localPrice);
		do
		{
			system("cls");

			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";

			std::cout << "You entered: \n\n";
			std::cout << "ID: " << tempBook.ID << "\n";
			std::cout << "Title: " << tempBook.Title << "\n";
			std::cout << "Author: " << tempBook.Author << "\n";
			std::cout << "Amount: " << tempBook.Amount << "\n";
			std::cout << "Price: " << tempBook.Price << "\n";

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