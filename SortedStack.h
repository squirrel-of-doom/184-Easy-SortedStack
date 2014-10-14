#pragma once

class SortedStack
{
public:
	SortedStack(void);
	~SortedStack(void);

public:
	void    push(int value);
	int     pop(void);
	size_t  get_Size(void);
	size_t  removeGreater(int compareTo);
	void    displayStack(void);
	void    displayOrdered(void);

private:
	struct StackElement
	{
	public:
		StackElement(int value) : m_Value(value), m_OrderedNext(NULL), m_OrderedPrev(NULL), m_StackBelow(NULL)
		{
		}

		int m_Value;
		StackElement* m_OrderedNext;
		StackElement* m_OrderedPrev;
		StackElement* m_StackBelow;
	};

private:
	StackElement* m_StackTop;
	StackElement* m_OrderedFirst;
	size_t        m_Size;

};

