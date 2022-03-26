#pragma once
enum linearList
{
	ArraySize = 9,
	Before = 1,
	After = 2
};
struct LinearList
{
	int list[ArraySize];
	int numbOfItems;
};

void init(LinearList& linearList);
bool isEmpty(int numbOfItems);
bool isFull(int numbOfItems);
int search(int* list, int data, bool& check);
void addItemIsEmpty(int* list, int data, int& numbOfItems);
void addItem(int* list, int data, int& numbOfItems);
void deleteItem(int* list, int index, int& numbOfItems);
void printList(int* list, int numbOfItems);