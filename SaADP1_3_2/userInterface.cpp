#include <iostream>
#include <string>
#include "userInterface.h"
#include "linearList.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Add an element to the list." << std::endl;
	std::cout << "2. Remove an element from the list." << std::endl;
	std::cout << "3. Display list on screen." << std::endl;
	std::cout << std::endl;
}

void printAdditionalMenu()
{
	std::cout << std::endl;
	std::cout << "1. Insert element before specified." << std::endl;
	std::cout << "2. Insert element after specified." << std::endl;
	std::cout << std::endl;
}

int userInput(int numberOfMenu)
{
	int option = 0;
	bool check = true;
	std::string optionInput;

	while (check)
	{
		try
		{
			std::cout << "   Enter a number, please: ";
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}

		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl;
			std::cout << std::endl;
			check = true;
		}

		if (check == false && numberOfMenu == MainMenu)
		{
			if (option < 1 || option > NumbOfOptionsMain)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
		else if (check = false && numberOfMenu == SecondMenu)
		{
			if (option < 1 || option > NumbOfOptionsMain)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
		else if (check == false && numberOfMenu == WorkOrExit)
		{
			if (option < 1 || option > TwoCases)
			{
				std::cout << "   There is no such menu item." << std::endl;
				std::cout << std::endl;
				check = true;
			}
		}
	}
	return option;
}
void workWithUser(LinearList& linearList)
{
	int* list = linearList.list;
	int& numbOfItems = linearList.numbOfItems;

	bool work = true;
	while (work)
	{
		printMainMenu();

		std::cout << "   What do you want to do? " << std::endl;
		std::cout << std::endl;
		int option = userInput(MainMenu);
		switch (option)
		{
		case(AddItem):
		{
			caseAddItem(list, numbOfItems);
			break;
		}
		case(DeleteItem):
		{
			caseDeleteItem(list, numbOfItems);
			break;
		}
		case(PrintQueue):
		{
			if (!isEmpty(numbOfItems)) { printList(list, numbOfItems); }
			else std::cout << "   List is empty." << std::endl;
			break;
		}
		default:
			break;
		}
		work = workOrExit();
	}
}

void caseAddItem(int* list, int& numbOfItems)
{
	if (isEmpty(numbOfItems))
	{
		int data = userInput(EnterItem);
		addItemIsEmpty(list, data, numbOfItems);
	}
	else if (!isFull(numbOfItems))
	{
		std::cout << "   Enter the element instead of/to the right of which you are going to add the element." << std::endl;
		int currentData = userInput(EnterItem);
		bool check = true;
		int index = search(list, currentData, check);
		if (check)
		{
			printAdditionalMenu();
			int beforeOrAfter = userInput(BeforeOrAfterInput);
			std::cout << "   Enter the item to add." << std::endl;
			int data = userInput(EnterItem);
			addItem(list, data, index, beforeOrAfter, numbOfItems);
			std::cout << std::endl;
			std::cout << "   Item added." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "   There is no such element." << std::endl;
		}
	}
	else if (isFull(numbOfItems))
	{
		std::cout << std::endl;
		std::cout << "   The list is full." << std::endl;
		std::cout << std::endl;
	}
}

void caseDeleteItem(int* list, int& numbOfItems)
{
	if (isEmpty(numbOfItems))
	{
		std::cout << "   Nothing to delete." << std::endl; //Это надо будет вставить в UserInterface
	}
	std::cout << "   Enter the element instead of/to the right of which you are going to add the element." << std::endl;
	int currentData = userInput(EnterItem);
	bool check = true;
	int index = search(list, currentData, check);
	if (check)
	{
		std::cout << "   Enter the item to delete." << std::endl;
		int data = userInput(EnterItem);
		int deletedItem = deleteItem(list, currentData, numbOfItems);
		std::cout << std::endl;
		std::cout << "   Item added." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "   There is no such element." << std::endl;
	}
}

bool workOrExit()
{
	std::cout << "   Continue (1) / exit (2)" << std::endl;
	int action = userInput(WorkOrExit);
	switch (action)
	{
	case(Continue):
	{
		return true;
		break;
	}
	case(Exit):
	{
		return false;
		break;
	}
	default:
		break;
	}
}