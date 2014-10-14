// 184-Easy-SortedStack.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "SortedStack.h"
#include <random>

int _tmain(int argc, _TCHAR* argv[])
{
	std::random_device rd;
	SortedStack myStack;

	// Generate a random number between 1-40. Call this number n.
	size_t N_SIZE = (rd() % 10) + 1;

	//Generate n random numbers between -1000 to 1000 and push them on your list
	printf("Pushing %d numbers...\n--", N_SIZE);
	for (size_t ii = 0; ii < N_SIZE; ii++) {
		int value = (rd() % 2001) - 1000;
		myStack.push(value);
	}

	//Display stack and sorted order
	myStack.displayStack();
	myStack.displayOrdered();

	getchar();

	//Generate a random number between -1000 and 1000 can call it x
	//Remove greater X from your list. (all integers greater than x)
	int X_CUTOFF = (rd() % 2001) - 1000;
	printf("Removing numbers greater than %d...\n--", X_CUTOFF);
	myStack.removeGreater(X_CUTOFF);
	
	//Display stack and sorted order
	myStack.displayStack();
	myStack.displayOrdered();

	getchar();

	//pop your list (size of list / 2) times (50% of your list is removed)
	size_t N_TO_POP = myStack.get_Size() / 2;
	printf("Popping %d numbers...\n--", N_TO_POP);
	for (size_t ii = 0; ii < N_TO_POP; ii++) {
		myStack.pop();
	}

	//Display stack and sorted order
	myStack.displayStack();
	myStack.displayOrdered();

	getchar();

	return 0;
}

