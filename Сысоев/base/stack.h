#ifndef __STACK_H__
#define __STACK_H__
using namespace std;
const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;//размер стека;
  int top;//индекс верхнего элемента;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  bool IsEmpty() { return top == -1; }
  bool IsFull() { return top == (size - 1); }
  T Pop() //Взять элемент
  {
	  if (IsEmpty())
		  throw "Error";
	  return pMem[top--];
  }
  void Push(T v)//Положить элемент;
  {
	  if (IsFull()) 
		  throw "Error";
	  pMem[++top] = v;
  }
  T GetTop() 
  {
	  if (IsEmpty())
		  throw "Error";
	  return pMem[top]; 
  }
  ~TStack()
  {
	  delete[] pMem;
  }
};

#endif
