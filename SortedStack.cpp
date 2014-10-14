#include "StdAfx.h"
#include "SortedStack.h"

SortedStack::SortedStack(void) : m_OrderedFirst(NULL), m_StackTop(NULL), m_Size(0)
{
}

SortedStack::~SortedStack(void)
{
}

void SortedStack::push(int value) {
	StackElement* toInsert = new StackElement(value);
	toInsert->m_StackBelow = m_StackTop;
	m_StackTop = toInsert;

	StackElement* iterator = m_OrderedFirst;
	while ((iterator != NULL) && (iterator->m_Value < value)) {
		toInsert->m_OrderedPrev = iterator;
		iterator = iterator->m_OrderedNext;
	}
	toInsert->m_OrderedNext = iterator;
	if (toInsert->m_OrderedPrev) {
		toInsert->m_OrderedPrev->m_OrderedNext = toInsert;
	}
	if (iterator) {
		if (! iterator->m_OrderedPrev) {
			m_OrderedFirst = toInsert;
		}
		iterator->m_OrderedPrev = toInsert;
	}			
	if (! m_OrderedFirst) {  m_OrderedFirst = toInsert; }
	m_Size++;
}

int SortedStack::pop(void) {
	if (! m_StackTop) { return 0; }
	StackElement* toRemove = m_StackTop;
	int value = toRemove->m_Value;

	m_StackTop = toRemove->m_StackBelow;
	if (toRemove->m_OrderedPrev) {
		toRemove->m_OrderedPrev->m_OrderedNext = toRemove->m_OrderedNext;
	} else {
		m_OrderedFirst = toRemove->m_OrderedNext;
	}
	if (toRemove->m_OrderedNext) {
		toRemove->m_OrderedNext->m_OrderedPrev = toRemove->m_OrderedPrev;
	}
	m_Size--;
	delete toRemove;
	return value;
}

size_t SortedStack::removeGreater(int compareTo) {
	size_t countRemoved = 0;
	if (! m_OrderedFirst) { return countRemoved; }

	StackElement* iterator = m_OrderedFirst;
	while (iterator && (iterator->m_Value <= compareTo)) { iterator = iterator->m_OrderedNext; }
	if (! iterator) { return countRemoved; }
	if (iterator->m_OrderedPrev) { iterator->m_OrderedPrev->m_OrderedNext = NULL; }

	StackElement* stackAbove = NULL;
	iterator = m_StackTop;
	while (iterator != NULL) {
		if (iterator->m_Value > compareTo) {
			if (stackAbove) {
				stackAbove->m_StackBelow = iterator->m_StackBelow;
			} else {
				m_StackTop = iterator->m_StackBelow;
			}
			delete iterator;
			iterator = (stackAbove) ? stackAbove->m_StackBelow : m_StackTop;
			m_Size--;
			countRemoved++;
		} else {
			stackAbove = iterator;
			iterator = iterator->m_StackBelow;
		}
	}
	if (m_Size == 0) { m_OrderedFirst = NULL; }
	return countRemoved;
}

size_t SortedStack::get_Size(void) {
	return m_Size;
}

void SortedStack::displayStack(void) {
	StackElement* iterator = m_StackTop;

	printf("Displaying stack from top to bottom: \n");
	while (iterator != NULL) {
		printf("%d\n", iterator->m_Value);
		iterator = iterator->m_StackBelow;
	}
	printf("--\n");
}

void SortedStack::displayOrdered(void) {
	StackElement* iterator = m_OrderedFirst;

	printf("Displaying ordered list: \n");
	while (iterator != NULL) {
		printf("%d\n", iterator->m_Value);
		iterator = iterator->m_OrderedNext;
	}
	printf("--\n");
}

