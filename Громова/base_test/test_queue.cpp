#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> st(5));
}

TEST(TQueue, can_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> st(-5));
}

TEST(TQueue, can_PushBack)
{
	TQueue<int>q(5);
	q.PushBack(0);
	q.PushBack(0);
	ASSERT_NO_THROW(q.PushBack(0));
}

TEST(TQueue, can_PopFront)
{
	TQueue<int>q(5);
	q.PushBack(1);
	ASSERT_NO_THROW(q.PopFront());
}

TEST(TQueue, cant_Push_if_stack_full)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++) 
	{
		q.PushBack(1);
	}
	ASSERT_ANY_THROW(q.PushBack(1));
}

TEST(TQueue, cant_pop_if_queue_empty)
{
	TQueue<int> q(3);

	ASSERT_ANY_THROW(q.PopFront());
}

TEST(TQueue, check_IsFull_if_queue_IsFull)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
	{
		q.PushBack(1);
	}
	EXPECT_TRUE(q.IsFull());
}

TEST(TQueue, check_IsEmpty_if_queue_IsEmpty)
{
	TQueue<int> q(3);

	EXPECT_TRUE(q.IsEmpty());
}

TEST(TQueue, check_IsEmpty_if_not_queue_IsEmpty)
{
	TQueue<int> q(3);
	for (int i = 0; i < 3; i++)
	{
		q.PushBack(1);
	}
	EXPECT_FALSE(q.IsEmpty());
}

TEST(TQueue, check_IsFull_if_not_Stack_IsFull)
{
	TQueue<int> q(3);

	EXPECT_FALSE(q.IsFull());
}