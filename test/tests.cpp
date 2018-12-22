#include "gtest/gtest.h"
#include "TQueue.h"
//#include "C:\Users\1\Documents\Visual Studio 2015\Projects\mp2-lab4-queue\include\TQueue.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue q(10));
}

TEST(TQueue, can_create_queue_with_empty_argument)
{
	ASSERT_NO_THROW(TQueue q());
}

TEST(TQueue, can_create_queue_with_0_argument)
{
	ASSERT_NO_THROW(TQueue q(0));
}


TEST(TQueue, throw_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue q(-1));
}

TEST(TQueue, can_put_elem)
{
	TQueue q(1);
	q.Put(5);
	ASSERT_NO_THROW(TQueue q());
}

TEST(TQueue, throw_when_put_elem_in_full_queue)
{
	TQueue q(1);
	q.Put(5);
	ASSERT_ANY_THROW(q.Put(5));
}

TEST(TQueue, can_get_elem)
{
	TQueue q(1);
	q.Put(5);
	ASSERT_NO_THROW(q.Get());
}

TEST(TQueue, can_get_elem_correctly)
{
	TQueue q(1);
	q.Put(5);
	ASSERT_EQ(5, q.Get());
}

TEST(TQueue, throw_when_get_elem_from_empty_queue)
{
	TQueue q(1);
	q.Put(5);
	q.Get();
	ASSERT_ANY_THROW(q.Get());
}

TEST(TQueue, ring_buffer)
{
	TQueue q(3);
	q.Put(5);
	q.Put(5);
	q.Put(5);
	q.Get();
	ASSERT_NO_THROW(q.Put(6));
}

TEST(TQueue, ring_buffer_2)
{
	TQueue q(3);
	q.Put(5);
	q.Put(5);
	q.Put(5);
	q.Get(); 
	q.Put(6);
	EXPECT_EQ(6, q.Get());
}

TEST(TQueue, get_next_index)
{
	TQueue q(3);
	EXPECT_EQ(2, q.GetNextIndex(1));
}

TEST(TQueue, get_next_index_2)
{
	TQueue q(3);
	EXPECT_EQ(0, q.GetNextIndex(2));
}

TEST(TQueue, is_empty)
{
	TQueue q(1);
	int res = -1;
	res = q.IsEmpty();
	EXPECT_EQ(1, res);
}

TEST(TQueue, top_elem)
{
	TQueue q(3);
	q.Put(5);
	q.Put(5);
	q.Put(5);
	q.Get();
	q.Put(6);
	EXPECT_EQ(6, q.TopElem());
}

TEST(TQueue, top_elem_2)
{
	TQueue q(3);
	q.Put(5);
	EXPECT_EQ(5, q.TopElem());
}

TEST(TQueue, top_elem_3)
{
	TQueue q(0);
	ASSERT_ANY_THROW(q.TopElem());
}

TEST(TQueue, print_queue)
{
	TQueue q(3);
	q.Put(1);
	q.Put(2);
	q.Put(3);
	ASSERT_NO_THROW(q.Print());
}

TEST(TQueue, isFull)
{
	TQueue q(3);
	q.Put(1);
	q.Put(2);
	EXPECT_EQ(0, q.IsFull());
}

TEST(TQueue, isFull_2)
{
	TQueue q(3);
	q.Put(1);
	q.Put(2);
	q.Put(3);
	EXPECT_EQ(1, q.IsFull());
}

TEST(TQueue, isFull_3)
{
	TQueue q(3);
	q.Put(5);
	q.Put(5);
	q.Put(5);
	q.Get();
	q.Put(6);
	EXPECT_EQ(1, q.IsFull());
}