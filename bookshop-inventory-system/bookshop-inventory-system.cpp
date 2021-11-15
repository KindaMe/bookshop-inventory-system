#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

const char separator = ' ';
const int nameWidth = 40;
const int numWidth = 10;

class book {
public:
	int ID = 0;
	std::string Title;
	std::string Author;
	int Amount = 1;
	float Price = 0;

	void printBookDebug()
	{
		std::cout << "\n";
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << ID;
		std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << Title;
		std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << Author;
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << Amount;
		std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << Price;
		std::cout << "\n";
		std::cout << std::string(110, '-');
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

	void changeTitle()
	{
		system("cls");
		std::cout << "MODIFY TITLE\n";
		std::cout << "*************\n";

		std::cout << "Current title: " << Title << "\n\n";

		std::cin.ignore(1000, '\n');
		std::cout << "Enter new title: ";
		getline(std::cin, Title);
	}
	void changeAuthor()
	{
		system("cls");
		std::cout << "MODIFY AUTHOR\n";
		std::cout << "**************\n";

		std::cout << "Current author: " << Author << "\n\n";

		std::cin.ignore(1000, '\n');
		std::cout << "Enter new author: ";
		getline(std::cin, Author);
	}
	void changeAmount()
	{
		int value;

		do
		{
			system("cls");
			std::cout << "MODIFY AMOUNT\n";
			std::cout << "**************\n";

			std::cout << "Current amount: " << Amount << "\n\n";
			std::cout << "Enter amount to add (+/-): ";

			if (!(std::cin >> value))
			{
				system("cls");
				std::cout << "MODIFY AMOUNT\n";
				std::cout << "**************\n";

				std::cout << "Invalid input.";
			}
			else if ((Amount + value) < 0)
			{
				system("cls");
				std::cout << "MODIFY AMOUNT\n";
				std::cout << "**************\n";

				std::cout << "Not enough books available.";
			}
			else
			{
				Amount += value;
				break;
			}
			std::cout << "\n\nPress ENTER to continue...";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin.get();
		} while (true);
	}
	void changePrice()
	{
		float value;
		do
		{
			system("cls");
			std::cout << "MODIFY PRICE\n";
			std::cout << "*************\n";

			std::cout << "Current price: " << Price << "\n\n";
			std::cout << "Enter new price: ";
			if (!(std::cin >> value))
			{
				system("cls");
				std::cout << "MODIFY PRICE\n";
				std::cout << "*************\n";

				std::cout << "Invalid input.";
			}
			else if (value <= 0)
			{
				system("cls");
				std::cout << "MODIFY PRICE\n";
				std::cout << "*************\n";

				std::cout << "Price must be higher then 0.";
			}
			else
			{
				Price = value;
				break;
			}
			std::cout << "\n\nPress ENTER to continue...";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin.get();
		} while (true);
	}
};

int menu();
int modifyMenu(book modifiedBook);

void addBook(std::vector<book>* storage);
void modifyID(std::vector<book>* storage);
void deleteBook(std::vector<book>* storage);
void browseStorage(std::vector<book> storage);
bool isStorageEmpty(std::vector<book> storage);

void readStorage(std::vector<book>* storage);
void writeStorage(std::vector<book> storage);

int main()
{
	std::vector<book>storage;
	readStorage(&storage);

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
			std::cout << "\ngithub.com/KindaMe";

			system("pause>0");
			system("cls");

			return 0;
		case 1:
			addBook(&storage);
			break;
		case 2:
			system("cls");
			std::cout << "BROWSE STORAGE\n";
			std::cout << "***************\n";
			if (!(isStorageEmpty(storage)))
			{
				modifyID(&storage);
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

void readStorage(std::vector<book>* storage)
{
	std::ifstream file;
	book tempBook;
	int counter = 0;
	std::string line;

	file.open("book_storage.txt");
	while (getline(file, line))
	{
		switch (counter % 5)
		{
		case 0:
			tempBook.ID = stoi(line);
			break;
		case 1:
			tempBook.Title = line;
			break;
		case 2:
			tempBook.Author = line;
			break;
		case 3:
			tempBook.Amount = stoi(line);
			break;
		case 4:
			tempBook.Price = stof(line);
			storage->push_back(tempBook);
			break;
		}

		counter++;
	}

	file.close();
}

void writeStorage(std::vector<book> storage)
{
	std::ofstream file;
	file.open("book_storage.txt");
	for (int i = 0; i < storage.size(); ++i) {
		file << storage[i].ID << std::endl;
		file << storage[i].Title << std::endl;
		file << storage[i].Author << std::endl;
		file << storage[i].Amount << std::endl;
		file << storage[i].Price << std::endl;
	}
	file.close();
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
		std::cout << std::string(110, '-');

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
			writeStorage(*storage);
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
	std::cout << std::string(110, '-');

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
		if ((*storage)[i].ID == id)
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
				std::cout << std::string(110, '-');

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
					writeStorage(*storage);

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

int modifyMenu(book modifiedBook)
{
	int mode;
	system("cls");
	std::cout << "MODIFY EXISTING BOOK\n";
	std::cout << "*********************\n";

	std::cout << "\n";
	std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "ID";
	std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "TITLE";
	std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "AUTHOR";
	std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "AMOUNT";
	std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << "PRICE";
	std::cout << "\n";
	std::cout << std::string(110, '-');
	modifiedBook.printBookDebug();

	std::cout << "\n\n1 - TITLE\n";
	std::cout << "2 - AUTHOR\n";
	std::cout << "3 - AMOUNT\n";
	std::cout << "4 - PRICE\n\n";
	std::cout << "0 - BACK\n\n";

	while (!(std::cin >> mode) || (mode < 0 || mode > 4))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}

	return mode;
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

void modifyID(std::vector<book>* storage)
{
	int id;

	do
	{
		do
		{
			system("cls");
			std::cout << "MODIFY EXISTING BOOK\n";
			std::cout << "*********************\n";

			std::cout << "Enter [ID] you want to modify: ";

			if (!(std::cin >> id))
			{
				system("cls");
				std::cout << "MODIFY EXISTING BOOK\n";
				std::cout << "*********************\n";

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

		for (int i = 0; i < (*storage).size(); i++)
		{
			if ((*storage)[i].ID == id)
			{
				id = i;
				goto label1;
			}
		}
		system("cls");
		std::cout << "MODIFY EXISTING BOOK\n";
		std::cout << "*********************\n";

		std::cout << "Invalid ID.\n\nPress ENTER to try again...";
		std::cin.clear();
		std::cin.ignore();
		std::cin.get();
	} while (true);
label1: {}
	do
	{
		switch (modifyMenu((*storage)[id]))
		{
		case 0:
			goto label2;
		case 1:
			(*storage)[id].changeTitle();
			break;
		case 2:
			(*storage)[id].changeAuthor();
			break;
		case 3:
			(*storage)[id].changeAmount();
			break;
		case 4:
			(*storage)[id].changePrice();
			break;
		default:
			system("cls");
			std::cout << "MODIFY EXISTING BOOK\n";
			std::cout << "*********************\n";
			std::cout << "Invalid input.\n\nPress ENTER to try again...";
			std::cin.get();
			break;
		}
	} while (true);
label2: {}
	writeStorage(*storage);
}