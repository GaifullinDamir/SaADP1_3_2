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
int search(int* list, int data)
{
	for (int index = 0; index < ArraySize; index++)
	{
		if (list[index] == data) { return index; }
		else std::cout << "   There is no such element." << std::endl;
	}
}
void addItem(int* list, int data, int currentData, int& numbOfItems)
{

}