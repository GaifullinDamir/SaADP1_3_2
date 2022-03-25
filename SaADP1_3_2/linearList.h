#pragma once
enum linearList
{
	ArraySize = 9,
	Before = 0,
	After = 1
};
struct LinearList
{
	int list[ArraySize];
	int numbOfItems;
};

void init(LinearList& linearList);
bool isEmpty(int numbOfItems);
bool isFull(int numbOfItems);
int search(int* list, int data);
void addItem(int* list, int data, int currentData, int beforeOrAfter, int& numbOfItems);
void deleteItem(int* list, int currentData, int& numbOfItems);