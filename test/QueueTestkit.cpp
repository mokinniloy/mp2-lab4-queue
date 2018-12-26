#include <gtest.h>
#include "TQueue.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	ASSERT_NO_THROW(TQueue q(10));
}

TEST(TQueue, can_create_queue_with_default_size)
{
	ASSERT_NO_THROW(TQueue q);
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue q(-10));
}

TEST(TQueue, can_put_element_in_queue)
{
	TQueue q(2);
	q.Put(10);

	EXPECT_EQ(q.GetRetCode(), DataOK);
}

TEST(TQueue, cant_put_element_in_full_queue)
{
	TQueue q(2);
	q.Put(0); q.Put(1); q.Put(2);

	EXPECT_EQ(q.GetRetCode(), DataFull);
}

TEST(TQueue, can_get_element_from_queue)
{
	TQueue q(2);
	q.Put(0); q.Put(1); q.Get();

	EXPECT_EQ(q.GetRetCode(), DataOK);
}

TEST(TQueue, first_received_element_was_inserted_first)
{
	TQueue q(3);
	q.Put(3); q.Put(2); q.Put(1);

	EXPECT_EQ(q.Get(), 3);
}

TEST(TQueue, last_received_element_was_inserted_last)
{
	TQueue q(3);
	q.Put(0); q.Put(1); q.Put(2);
	q.Get(); q.Get();

	EXPECT_EQ(q.Get(), 2);
}

TEST(TQueue, cant_get_element_from_empty_queue)
{
	TQueue q(5);
	q.Get();

	EXPECT_EQ(q.GetRetCode(), DataEmpty);
}

TEST(TQueue, is_empty_method_returns_false_being_applied_to_not_empty_queue)
{
	TQueue q(5);
	for (int i = 0; i < 5; ++i)
		q.Put(i);

	EXPECT_FALSE(q.IsEmpty());
}

TEST(TQueue, is_empty_method_returns_true_being_applied_to_empty_queue)
{
	TQueue q(5);

	EXPECT_TRUE(q.IsEmpty());
}

TEST(TQueue, is_full_method_returns_true_being_applied_to_full_queue)
{
	TQueue q(2);
	q.Put(0); q.Put(1);

	EXPECT_TRUE(q.IsFull());
}

TEST(TQueue, is_full_method_returns_false_being_applied_to_not_full_queue)
{
	TQueue q(2);
	q.Put(0);

	EXPECT_FALSE(q.IsFull());
}