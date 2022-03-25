#include <iostream>
#include "linearList.h"

void init(LinearList& linearList)
{
	for (int i = 0; i < ArraySize; i++)
	{
		linearList.list[i] = NULL;
	}
	linearList.numbOfItems = 0;
}

bool isEmpty(int numbOfItems) { return numbOfItems == 0; }
bool isFull(int numbOfItems) { return numbOfItems == ArraySize; }
int search(int* list, int data, bool& check)
{
	for (int index = 0; index < ArraySize; index++)
	{
		if (list[index] == data) { check = true; return index; }
		else check = false;
	}
}

void addItemIsEmpty(int* list, int data, int& numbOfItems)
{
	list[0] = data;
	numbOfItems++;
}
void addItem(int* list, int data, int index, int beforeOrAfter, int& numbOfItems)
{
	switch (beforeOrAfter)
	{
		case(Before):
		{
			for (int i = numbOfItems - 1; i >= index; i--)
			{
				list[i + 1] = list[i];
			}
			list[index] = data;
			numbOfItems++;
			break;
		}
		case(After):
		{
			for (int i = numbOfItems - 1; i >= index + 1; i--)
			{
				list[i + 1] = list[i];
			}
			list[index + 1] = data;
			numbOfItems++;
			break;
		}
		default:
			break;
	}
}
int deleteItem(int* list, int currentData, int& numbOfItems)
{
	bool check = true;
	int index = search(list, currentData, check);
	if (check)
	{
		if (index == numbOfItems - 1) { list[index] = NULL; numbOfItems--; }
		else
		{
			int deletedItem = list[index];
			list[index] = NULL;
			for (int i = index; i <= numbOfItems - 1; i++)
			{
				list[i + 1] = list[i];
			}
			numbOfItems--;
			return deletedItem;
		}
	}
	else
	{
		std::cout << "   There is no such element." << std::endl;
	}
	
}
void printList(int* list, int numbOfItems)
{
	/*for (int i = 0; i < numbOfItems; i++)
	{
		std::cout << "   " << list[i] << std::endl;
	}
	std::cout << std::endl;*/
	for (int i = 0; i < ArraySize; i++)
	{
		std::cout << "   " << list[i] << std::endl;
	}
	std::cout << std::endl;
}