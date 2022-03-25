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
void addItem(int* list, int data, int currentData, int beforeOrAfter, int& numbOfItems)
{
	if (isEmpty(numbOfItems))
	{
		list[0] = data;
	}
	else if (isFull(numbOfItems))
	{
		std::cout << "   The list is full." << std::endl;
	}
	else
	{
		bool check = true;
		int index = search(list, currentData, check);
		switch (beforeOrAfter)
		{
			case(Before):
			{
				for (int i = numbOfItems - 1; i > index ; i--)
				{
					list[i + 1] = list[i];
				}
				list[index] = data;
				break;
			}
			case(After):
			{
				for (int i = numbOfItems - 1; i > index + 1; i--)
				{
					list[i + 1] = list[i];
				}
				list[index + 1] = data;
				break;
			}
			default:
				break;
		}
	}
}