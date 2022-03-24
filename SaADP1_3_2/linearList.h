#pragma once
enum linearList
{
	ArraySize = 9
};
struct LinearList
{
	int list[ArraySize];
	int numbOfItems;
};

void init(LinearList& linearList);
bool isEmpty(int numbOfItems);
bool isFull(int numbOfItems);
void search(int data);
void addItem(int* list, int data, int currentData, int& numbOfItems);
void deleteItem(int* list, int currentData, int& numbOfItems);