#include "tqueue.h"
#include <gtest.h>
#include <iostream>

using namespace std;

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue q(3));
}

TEST(TQueue, can_get_element)
{
	TQueue q(3);
	q.Put(3);
	q.Put(4);
	ASSERT_NO_THROW(q.Get());
	EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, get_correct_element)
{
	TQueue q(3);
	q.Put(3);
	q.Put(4);
	EXPECT_EQ(3, q.Get());
}

TEST(TQueue, can_put_element)
{
	TQueue q(3);
	ASSERT_NO_THROW(q.Put(2));
	EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, put_correct_element)
{
	TQueue q(3);
	q.Put(1);
	EXPECT_EQ(1, q.TopElem());
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue(-1));
}

TEST(TQueue, return_zero_when_queue_is_empty)
{
	TQueue q(1);
	EXPECT_EQ(0, q.GetRetCode());
}

TEST(TQueue, create_empty_queue)
{
	TQueue q(3);

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, cant_get_elem_with_no_mem)
{
	TQueue q(0);

	EXPECT_EQ(-1, q.Get());
}

TEST(TQueue, can_create_queue_with_empty_argument)
{
	ASSERT_NO_THROW(TQueue q());
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