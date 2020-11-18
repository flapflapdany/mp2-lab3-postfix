#include "postfix.h"
#include <gtest.h>
#include "postfix.cpp"

TEST(TPostfix, can_create_postfix)
{
  ASSERT_NO_THROW(TPostfix p);, 
}

TEST(TPostfix, get_infix)
{
	TPostfix p("a+b");

	EXPECT_EQ("a+b", p.GetInfix());
}

TEST(TPostfix, get_postfix)
{
	TPostfix p("(a+b)*c");
	EXPECT_EQ("ab+c*", p.ToPostfix());
}

TEST(TPostfix, check_CountValue)
{
	TPostfix p("a+b*c");
	EXPECT_EQ(3, p.CountLetter());
}

TEST(TPostfix, can_check_priority)
{
	TPostfix p("(a+b)*c");
	char el1 = '+', el2 = '*';
	EXPECT_TRUE(p.Priority(el1) < p.Priority(el2));
}

TEST(TPostfix, check_calculate)
{
	TPostfix p("a + b * c / d - e + f");
	p.ToPostfix();
	double* values;
	values = new double[p.CountLetter()];

	for (int i = 0; i < p.CountLetter(); i++)
	{
		values[i] = i + 1;
	}

	EXPECT_EQ(p.Calculate(values), 3.5);
}

TEST(TPostfix, can_count_different_variables)
{
	TPostfix p("a+b+a+b+a");
	int res = p.CountLetter();
	EXPECT_EQ(2, res);
}

TEST(TPostfix, convert_infix_with_brackets)
{
	TPostfix p("(a+b)*c");
	p.ToPostfix();
	EXPECT_EQ(p.GetPostfix(), "ab+c*");
}

TEST(TPostfix, check_calculate1)
{
	TPostfix p("a + a * a");
	p.ToPostfix();
	double* values;
	values = new double[3];
	for (int i = 0; i < 3; i++)
	{
		values[i] = 2;
	}
	EXPECT_EQ(p.Calculate(values) , 6);
}

TEST(TPostfix, can_count_variables)
{
	TPostfix p("(a+b+c)*d");
	int res = p.CountLetter();
	EXPECT_EQ(4, res);
}