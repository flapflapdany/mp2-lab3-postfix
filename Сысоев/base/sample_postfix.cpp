#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
  string expression;
  double res;

  setlocale(LC_ALL, "Russian");
  cout << "Введите арифметическое выражение: ";
  getline(cin, expression);
  TPostfix postfix(expression);
  cout << expression << endl;
  double* values;
  values = new double[int(postfix.CountLetter())];
  cout << "Введите аргументы" << endl;

  for (int i = 0; i < int(postfix.CountLetter()); i++)
  {
	  cin >> values[i];
  }
  cout << "Арифметическое выражение: " << postfix.GetInfix() << endl;
  postfix.ToPostfix();
  cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
  res = postfix.Calculate(values);
  cout << res << endl;
  return 0;
}
