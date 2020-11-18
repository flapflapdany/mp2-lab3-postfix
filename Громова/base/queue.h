#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
const int MaxSize = 100;

template <class T>
class TQueue
{
	T* pMem;
	int size;
	int last;
	int first;
	int count;
public:
	TQueue(int size)
	{
		this->size = size;
		first = -1;
		last = 0;
		count = 0;
		if ((size < 0) || (size > MaxSize))
			throw "Error";
		pMem = new T[size];
	}
	TQueue(TQueue& v)
	{
		size = v.size;
		pMem = new T[size];
		count = v.count;
		first = v.first;
		last = v.last;
		for (int i = 0; i < size; i++)
			pMem[i] = v.pMem[i];
	}
	bool IsEmpty() { return count == 0; }
	bool IsFull() { return count == size; }
	int GetLeg() { return last; }
	T GetFirst() { return pMem[(first + 1) % size]; }
	T GetLast() { return pMem[last]; }
	void PushBack(T data)
	{
		if (IsFull())
			throw "Error";
		else
		{
			count++;
			pMem[last] = data;
			last = (last + 1) % size;
		}
	}
	T PopFront()
	{
		if (IsEmpty())
			throw "Error";
		count--;
		first = (first + 1) % size;
		return pMem[first];
	}
	~TQueue()
	{
		delete[] pMem;
	}
};

#endif