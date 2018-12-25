#include <gtest.h>
#include "tqueue.h"

TEST(TQueue, can_create_with_positive_size)
{
	ASSERT_NO_THROW(TQueue(10));
}

TEST(TQueue, cant_create_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue(-10));
}

TEST(TQueue, can_put_if_queue_is_not_full)
{
	TQueue q(10);

	q.Put(10);

	EXPECT_EQ(q.GetRetCode(), 0);
}

TEST(TQueue, cant_put_if_queue_is_full)
{
	TQueue q(1);

	q.Put(1);
	q.Put(1);

	EXPECT_EQ(q.GetRetCode(), DataFull);
}

TEST(TQueue, can_get_element_if_queue_is_not_empty)
{
	TQueue q(2);

	q.Put(1);

	EXPECT_EQ(q.Get(), 1);
}

TEST(TQueue, cant_get_element_if_queue_is_empty)
{
	TQueue q(4);

	q.Get();

	EXPECT_EQ(q.GetRetCode(), DataEmpty);
}

TEST(TQueue, can_get_top_element_from_queue)
{
	TQueue q(4);

	q.Put(123);

	EXPECT_EQ(q.TopElem(), 123);
}

TEST(TQueue, can_get_top_element_without_deleting)
{
	TQueue q(4);

	q.Put(123);
	q.TopElem();

	EXPECT_EQ(q.Get(), 123);
}

TEST(TQueue, can_create_queue_with_zero_size)
{
	ASSERT_NO_THROW(TQueue q(0));
}

TEST(TQueue, cant_get_top_element_without_deleting_if_empty)
{
	TQueue q(4);

	q.TopElem();

	EXPECT_EQ(q.GetRetCode(), DataEmpty);
}