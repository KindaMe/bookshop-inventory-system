#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

const char separator = ' ';
const int nameWidth = 40;
const int numWidth = 10;

class book {
private:
	int ID = 0;
	std::string Title;
	std::string Author;
	int Amount = 1;
	float Price = 0;
public:
	void printBookDebug()
	{
		std::cout << "\n";
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << ID;
		std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << Title;
		std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << Author;
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << Amount;
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << Price;
		std::cout << "\n";
	}
	void initBook(std::vector<book>* storage)
	{
		if (storage->size() > 0)
		{
			int maxId = (*storage)[0].ID;

			for (int i = 1; i < storage->size(); i++)//look for max id
			{
				if ((*storage)[i].ID > maxId)
				{
					maxId = (*storage)[i].ID;
				}
			}
			for (int i = 1; i <= maxId + 1; i++)//iterate through all ids from 1 to max+1
			{
				bool taken = false;
				for (int j = 0; j < storage->size(); j++)//check if i is an id for any object in vector
				{
					if (i == (*storage)[j].ID)
					{
						taken = true;
						break;
					}
				}
				if (taken == false)
				{
					ID = i;
					break;
				}
				else
				{
					taken = false;
				}
			}
		}
		else
		{
			ID = 1;
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
	}
	int getID()
	{
		return ID;
	}
};

int menu();
void addBook(std::vector<book>* storage);
void browseStorage(std::vector<book> storage);
void deleteBook(std::vector<book>* storage);
void modifyBook(std::vector<book>* storage);
bool isStorageEmpty(std::vector<book> storage);

int main()
{
	std::vector<book>storage;

	do
	{
		system("cls");

		switch (menu())
		{
		case 0:
			system("cls");
			std::cout << "BOOKSHOP INVENTORY SYSTEM\n";
			std::cout << "**************************\n";

			std::cout << "\nSee you soon!";

			system("pause>0");
			system("cls");

			return 0;
		case 1:
			addBook(&storage);
			break;
		case 2:
			system("cls");
			std::cout << "MODIFY EXISTING BOOK\n";
			std::cout << "*********************\n";
			if (!(isStorageEmpty(storage)))
			{
				modifyBook(&storage);
			}
			break;
		case 3:
			system("cls");
			std::cout << "DELETE BOOK\n";
			std::cout << "************\n";
			if (!(isStorageEmpty(storage)))
			{
				deleteBook(&storage);
			}
			break;
		case 4:
			system("cls");
			std::cout << "BROWSE STORAGE\n";
			std::cout << "***************\n";
			if (!(isStorageEmpty(storage)))
			{
				browseStorage(storage);
			}
			break;
		default:
			system("cls");
			std::cout << "BOOKSHOP INVENTORY SYSTEM\n";
			std::cout << "**************************\n";
			std::cout << "Invalid input.\n\nPress ENTER to try again...";
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
	std::cout << "2 - MODIFY EXISTING BOOK\n";
	std::cout << "3 - DELETE BOOK\n";
	std::cout << "4 - BROWSE STORAGE\n\n";
	std::cout << "0 - EXIT\n\n";

	while (!(std::cin >> mode) || (mode < 0 || mode > 4))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}

	return mode;
}

void addBook(std::vector<book>* storage)
{
	book tempBook;
	char yn;

	tempBook.initBook(storage);

	do
	{
		system("cls");

		std::cout << "ADD NEW BOOK\n";
		std::cout << "*************\n";

		std::cout << "You entered: \n";

		std::cout << "\n";
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "ID";
		std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "TITLE";
		std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "AUTHOR";
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "AMOUNT";
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "PRICE";
		std::cout << "\n";

		tempBook.printBookDebug();

		std::cout << "\nCorrect? (y/n): ";
		std::cin >> yn;
		yn = tolower(yn);

		switch (yn)
		{
		case 'y':
			system("cls");
			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";

			storage->push_back(tempBook);
			std::cout << "Book added successfully.\n\nPress ENTER to continue...";
			std::cin.get();
			std::cin.clear();
			std::cin.ignore();
			goto label1;
		case 'n':
			system("cls");
			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";

			std::cout << "\nPress ENTER to continue...\n";
			std::cin.get();
			std::cin.clear();
			std::cin.ignore();
			goto label1;
		default:
			system("cls");
			std::cout << "ADD NEW BOOK\n";
			std::cout << "*************\n";

			std::cout << "Invalid input.\n\nPress ENTER to try again...\n";
			std::cin.get();
			std::cin.clear();
			std::cin.ignore();
			break;
		}
	} while (true);
label1: {}
}

void browseStorage(std::vector<book> storage)
{
	std::cout << "\n";
	std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "ID";
	std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "TITLE";
	std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "AUTHOR";
	std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "AMOUNT";
	std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "PRICE";
	std::cout << "\n";

	for (int i = 0; i < storage.size(); i++)
	{
		storage[i].printBookDebug();
	}

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
}

void deleteBook(std::vector<book>* storage)
{
	int id;
	char yn;
	bool broken = false;

	do
	{
		system("cls");
		std::cout << "DELETE BOOK\n";
		std::cout << "************\n";

		std::cout << "Enter [ID] to delete: ";
		if (!(std::cin >> id))
		{
			system("cls");
			std::cout << "DELETE BOOK\n";
			std::cout << "************\n";

			std::cout << "Invalid input.\n\nPress ENTER to try again...";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.get();
		}
		else
		{
			break;
		}
	} while (true);

	for (int i = 0; i < storage->size(); i++)
	{
		if ((*storage)[i].getID() == id)
		{
			do
			{
				system("cls");
				std::cout << "DELETE BOOK\n";
				std::cout << "************\n";

				std::cout << "You are trying to delete: \n";
				std::cout << "\n";
				std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "ID";
				std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "TITLE";
				std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "AUTHOR";
				std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "AMOUNT";
				std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "PRICE";
				std::cout << "\n";

				(*storage)[i].printBookDebug();

				std::cout << "\nCorrect? (y/n):";
				std::cin >> yn;
				yn = tolower(yn);

				switch (yn)
				{
				case 'y':

					system("cls");
					std::cout << "DELETE BOOK\n";
					std::cout << "************\n";

					(*storage).erase((*storage).begin() + i);

					std::cout << "ID [" << id << "] deleted.";
					std::cout << "\n\nPress ENTER to continue...";
					std::cin.clear();
					std::cin.ignore();
					std::cin.get();
					broken = true;
					goto label1;
				case 'n':
					system("cls");
					std::cout << "DELETE BOOK\n";
					std::cout << "************\n";

					std::cout << "\nPress ENTER to continue...";
					std::cin.clear();
					std::cin.ignore();
					std::cin.get();
					broken = true;
					goto label1;
				default:
					system("cls");
					std::cout << "DELETE BOOK\n";
					std::cout << "************\n";

					std::cout << "Invalid input.\n\nPress ENTER to try again...";
					std::cin.clear();
					std::cin.ignore();
					std::cin.get();
					broken = true;
					break;
				}
			} while (true);
			break;
		}
	}
label1: {}

	if (broken == false)
	{
		system("cls");
		std::cout << "DELETE BOOK\n";
		std::cout << "************\n";

		std::cout << "ID [" << id << "] does not exist.\n";
		std::cout << "\nPress ENTER to continue...";
		std::cin.clear();
		std::cin.ignore();
		std::cin.get();
	}
}

void modifyBook(std::vector<book>* storage)
{
	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
}

bool isStorageEmpty(std::vector<book> storage)
{
	if (storage.size() > 0)
	{
		return false;
	}
	else
	{
		std::cout << "No books available.";
		std::cin.get();
		std::cin.clear();
		std::cin.ignore();
		return true;
	}
}