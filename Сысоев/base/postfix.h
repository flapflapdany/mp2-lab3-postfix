#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
  string oper = "+-*/()";
public:
  TPostfix(string _infix = "a+b")
  {
	  postfix = "";
	  for (int i = 0; i < _infix.length(); i++)
	  {
		  if (_infix[i] != ' ')
		  {
			  infix += _infix[i];
		  }
	  }
	  if (infix.length() < 1)
	  {
		  throw "Error";
	  }
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();// перевод в постфиксную форму
  double Calculate(double* val); // Ввод переменных, вычисление по постфиксной форме
  int Priority(char tmp); // сравнение приоритета элементов
  int CountLetter();
};

#endif
