#include <gtest.h>
#include "tqueue.h"

TEST(TQueue, can_create_queue_with_positive_size) 
{
	ASSERT_NO_THROW(TQueue q(3));
}

TEST(TQueue, create_empty_queue)
{
	TQueue q(3);

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, cant_put_with_no_mem)
{
	TQueue q(0);

	q.Put(3);

	EXPECT_EQ(DataNoMem, q.GetRetCode());
}

TEST(TQueue, can_put_if_ok)
{
	TQueue q(1);

	q.Put(4);

	EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, cant_put_if_full)
{
	TQueue q(1);

	q.Put(1);
	q.Put(2);

	EXPECT_EQ(DataFull, q.GetRetCode());
}

TEST(TQueue, cant_get_elem_with_no_mem)
{
	TQueue q(0);

	EXPECT_EQ(DataNoMem, q.Get());
}

TEST(TQueue, cant_get_elem_if_empty)
{
	TQueue q(7);

	EXPECT_EQ(DataEmpty, q.Get());
}

TEST(TQueue, can_get_elem_if_ok)
{
	TQueue q(3);

	q.Put(3);
	q.Put(2);

	EXPECT_EQ(3, q.Get());
}

TEST(TQueue, can_get_elem_in_queue1)
{
	TQueue q(2);

	q.Put(1);
	q.Put(2);
	q.Get();
	q.Put(3);
	int k = q.Get();

	EXPECT_EQ(2, k);
}

TEST(TQueue, can_get_elem_in_queue2)
{
	TQueue q(2);

	q.Put(1);
	q.Put(2);
	q.Get();
	q.Put(3);
	q.Get();

	EXPECT_EQ(3, q.Get());
}
