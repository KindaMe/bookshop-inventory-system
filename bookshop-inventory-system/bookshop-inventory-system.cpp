#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
		std::cout
			<< "| "
			<< "ID: " << ID << " | "
			<< "Title: " << Title << " | "
			<< "Author: " << Author << " | "
			<< "Amount: " << Amount << " | "
			<< "Price: " << Price << " |"
			<< "\n";
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
void browseStorage(std::vector<book>* storage);
void deleteBook(std::vector<book>* storage);

int main()
{
	std::vector<book>storage;

	do
	{
		system("cls");

		switch (menu())
		{
		case 1:
			addBook(&storage);
			break;
		case 2:
			system("cls");
			std::cout << "ADD EXISTING BOOK\n";
			std::cout << "******************\n";
			std::cin.clear();
			std::cin.ignore();
			std::cin.get();
			break;
		case 3:
			system("cls");
			std::cout << "DELETE BOOK\n";
			std::cout << "************\n";
			deleteBook(&storage);
			break;
		case 4:
			system("cls");
			std::cout << "BROWSE STORAGE\n";
			std::cout << "***************\n";
			browseStorage(&storage);
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
		tempBook.printBookDebug();

		std::cout << "\nCorrect? (y/n): ";
		std::cin >> yn;
		yn = tolower(yn);

		switch (yn)
		{
		case 'y':
			storage->push_back(tempBook);
			std::cout << "\nBook added successfully.\nPress ENTER to continue...";
			std::cin.get();
			std::cin.clear();
			std::cin.ignore();
			break;
		case 'n':
			std::cout << "\nPress ENTER to continue...\n";
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
}

void browseStorage(std::vector<book>* storage)
{
	if (storage->size() > 0)
	{
		for (int i = 0; i < storage->size(); i++)
		{
			(*storage)[i].printBookDebug();
		}
	}
	else
	{
		std::cout << "No books available.\n";
	}

	std::cout << "\nPress ENTER to continue...";
	std::cin.clear();
	std::cin.ignore();
	std::cin.get();
}

void deleteBook(std::vector<book>* storage)
{
	int id;
	char yn;
	bool broken = false;

	std::cout << "Enter [ID] to delete: ";
	std::cin >> id;

	for (int i = 0; i < storage->size(); i++)
	{
		if ((*storage)[i].getID() == id)
		{
			system("cls");
			std::cout << "DELETE BOOK\n";
			std::cout << "************\n";

			std::cout << "You are trying to delete: \n";
			(*storage)[i].printBookDebug();
			std::cout << "\nCorrect? (y/n):";
			std::cin >> yn;
			yn = tolower(yn);

			switch (yn)
			{
			case 'y':
				(*storage).erase((*storage).begin() + i);

				system("cls");
				std::cout << "DELETE BOOK\n";
				std::cout << "************\n";

				std::cout << "ID [" << id << "] deleted.";
				std::cout << "\n\nPress ENTER to continue...";
				std::cin.clear();
				std::cin.ignore();
				std::cin.get();
				broken = true;
				break;
			case 'n':
				system("cls");
				std::cout << "DELETE BOOK\n";
				std::cout << "************\n";

				std::cout << "Press ENTER to continue...";
				std::cin.clear();
				std::cin.ignore();
				std::cin.get();
				broken = true;
				break;
			}
			break;
		}
	}
	if (broken == false)
	{
		system("cls");
		std::cout << "DELETE BOOK\n";
		std::cout << "************\n";

		std::cout << "ID [" << id << "] does not exist.\n\n";
		std::cout << "Press ENTER to continue...";
		std::cin.clear();
		std::cin.ignore();
		std::cin.get();
	}
}