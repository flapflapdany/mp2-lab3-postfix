#include "postfix.h"
#include "stack.h"
using namespace std;

string TPostfix::ToPostfix()
{
	TStack<char> OperStack(MaxStackSize);
	for (int i = 0; i < infix.length(); i++)
	{
		if (oper.find(infix[i]) == string::npos)
		{
			postfix += infix[i];
		}
		else if (oper.find(infix[i]) != string::npos)
		{
			if (OperStack.IsEmpty())
			{
				OperStack.Push(infix[i]);
			}
			else
			{
				if (Priority(infix[i]) == Priority(OperStack.GetTop()))
				{
					if (infix[i] == '(')
					{
						OperStack.Push(infix[i]);
					}
					else
						if (infix[i] == ')')
						{
							while (OperStack.GetTop() != '(')
							{
								postfix += OperStack.Pop();
							}
							OperStack.Pop();
						}
						else
						{
							postfix += OperStack.Pop();
							OperStack.Push(infix[i]);
						}
				}
				else if (Priority(infix[i]) < Priority(OperStack.GetTop()))
				{
					if (infix[i] == '(')
					{
						OperStack.Push(infix[i]);
					}
					else if (infix[i] == ')')
					{
						while (OperStack.GetTop() != '(')
						{
							postfix += OperStack.Pop();
						}
						OperStack.Pop();
					}
					else
					{
						while ((!OperStack.IsEmpty()) && (OperStack.GetTop() != '('))
						{

							postfix += OperStack.Pop();
						}
						OperStack.Push(infix[i]);
					}
				}
				else if (Priority(infix[i]) > Priority(OperStack.GetTop()))
				{
					OperStack.Push(infix[i]);
				}
			}
		}
	}
	while (!OperStack.IsEmpty())
	{
		postfix += OperStack.Pop();
	}
	return postfix;
}

int TPostfix::Priority(char tmp)
{
	if (tmp == '/' || tmp == '*')
		return 3;
	if (tmp == '+' || tmp == '-')
		return 2;
	if (tmp == ')')
		return 1;
	if (tmp == '(')
		return 0;
	throw "Error";
}
double TPostfix::Calculate(double* val)
{
	if (postfix == "")
	{
		throw "Error";
	}
	string tmp = "";
	for (int i = 0; i < infix.length(); i++)
	{
		if (oper.find(infix[i]) == string::npos)//если символ i = пустой строке,то записываем в массив
		{
			tmp += infix[i];
		}
	}
	int count = tmp.size();
	TStack<double> Res(count);
	double* values1;
	values1 = new double[count]();
	if (count == CountLetter())
	{
		for (int i = 0; i < count; i++)
		{
			values1[i] = val[i];
		}
	}
	else
	{
		int k = 0;
		for (int i = 0; i < count; i++)
		{
			if (oper.find((tmp[i])) == string::npos)
			{
				values1[i] = val[k++];
			}
			for (int j = i + 1; j < count; j++)
			{
				if ((oper.find((tmp[i])) == string::npos)||(tmp[i] != ' '))//хмм...
				{
					if ((tmp[i] == tmp[j]) && (tmp[i] != ' '))
					{
						values1[j] = values1[i];
						tmp[j] = ' ';
					}
				}
			}
		}
	}
	int j = 0;
	for (int i = 0; i < postfix.length(); i++)
	{
		if (oper.find(postfix[i]) == string::npos)//тут нужно посмотреть;
		{
			Res.Push(values1[j]);
			j++;
		}
		else if (oper.find(postfix[i]) != string::npos)
		{
			double a = Res.GetTop();
			Res.Pop();
			double b = Res.GetTop();
			Res.Pop();
			if (postfix[i] == '+')
				Res.Push(b + a);
			else if (postfix[i] == '-')
				Res.Push(b - a);
			else if (postfix[i] == '*')
				Res.Push(b * a);
			else if (postfix[i] == '/')
			{
				if (a == 0.0)
					throw "Error";
				Res.Push(b / a);
			}
			
		}
	}
  return Res.GetTop();
}
int TPostfix::CountLetter()
{
	int res = 0;
	string tmp = "";
	for (int i = 0; i < infix.size(); i++)
	{
		if (oper.find(infix[i]) == string::npos)
		{
			res++;
			tmp += infix[i];
		}
	}
	for (int i = 0; i < tmp.length(); i++)
	{
		for (int j = i+1; j < tmp.length(); j++)
		{
			if ((tmp[i] == tmp[j])&&(tmp[i]!= ' '))
			{
				res--;
				tmp[j] = ' ';
			}
		}
	}
	return res;
}
