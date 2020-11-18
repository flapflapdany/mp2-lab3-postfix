#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, can_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_Push_and_Pop_element)
{
	TStack<int> st(5);
	st.Push(10);
	EXPECT_EQ(10, st.Pop());
}

TEST(TStack, cant_Push_if_stack_full)
{
	TStack<int> st(3);
	for (int i = 0; i < 3; i++) 
	{
		st.Push(1);
	}
	ASSERT_ANY_THROW(st.Push(1));
}

TEST(TStack, cant_pop_if_stack_empty)
{
	TStack<int> st(3);

	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, check_IsFull_if_Stack_IsFull)
{
	TStack<int> st(3);
	for (int i = 0; i < 3; i++)
	{
		st.Push(1);
	}
	EXPECT_TRUE(st.IsFull());
}

TEST(TStack, check_IsEmpty_if_Stack_IsEmpty)
{
	TStack<int> st(3);

	EXPECT_TRUE(st.IsEmpty());
}

TEST(TStack, check_IsEmpty_if_not_Stack_IsEmpty)
{
	TStack<int> st(3);
	for (int i = 0; i < 3; i++)
	{
		st.Push(1);
	}
	EXPECT_FALSE(st.IsEmpty());
}

TEST(TStack, check_IsFull_if_not_Stack_IsFull)
{
	TStack<int> st(3);

	EXPECT_FALSE(st.IsFull());
}