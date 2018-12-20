#include "tqueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_size)
{
	TQueue q(5);

	EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	TQueue q(-5);

	EXPECT_EQ(DataErr, q.GetRetCode());
}

TEST(TQueue, created_queue_is_empty)
{
	TQueue q(5);

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_set_and_get_element)
{
	TQueue q(3);
	q.Put(9);
	
	EXPECT_EQ(9, q.Get());
}

TEST(TQueue, replenished_queue_is_not_empty)
{
	TQueue q(5);
	q.Put(7);
	
	EXPECT_EQ(false, q.IsEmpty());
}

TEST(TQueue, queue_after_get_is_not_full)
{
	TQueue q(3);
	q.Put(2); q.Put(3); q.Put(4);
	q.Get();
	
	EXPECT_EQ(false, q.IsFull());
}

TEST(TQueue, queue_return_first_element)
{
	TQueue q(3);
	q.Put(2); q.Put(3); q.Put(4);
	
	EXPECT_EQ(2, q.Get());
}

TEST(TQueue, cant_set_element_when_queue_is_full)
{
	TQueue q(3);
	q.Put(2); q.Put(3); q.Put(4);
	q.Put(5);
	
	EXPECT_EQ(DataFull, q.GetRetCode());
}

TEST(TQueue, cant_get_element_when_queue_is_empty)
{
	TQueue q(3);
	q.Get();
	EXPECT_EQ(DataEmpty, q.GetRetCode());
}

TEST(TQueue, queue_is_ring_buffer)
{
	TQueue q(3);
	q.Put(1); q.Put(2); q.Put(3);
	q.Get();
	q.Put(4);

	EXPECT_EQ(2, q.Get());
	EXPECT_EQ(3, q.Get());
	EXPECT_EQ(4, q.Get());
}