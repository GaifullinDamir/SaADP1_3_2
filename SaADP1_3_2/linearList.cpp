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