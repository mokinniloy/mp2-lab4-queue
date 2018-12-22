#include "tstack.h"
#include "tqueue.h"
#include "TProc.h"
#include "TJobStream.h"
#include "gtest.h"
TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue que());
}

TEST(TQueue, new_queue_is_empty)
{
	TQueue que;

	EXPECT_TRUE(que.IsEmpty());
}

TEST(TQueue, queue_with_element_not_empty)
{
	TQueue que;
	que.Put(1);

	EXPECT_FALSE(que.IsEmpty());
}

TEST(TQueue, queue_can_be_full)
{
	const int size = 5;
	TQueue que(size);
	for (int i = 0; i < size; i++)
		que.Put(1);
	EXPECT_TRUE(que.IsFull());
}

TEST(TQueue, queue_after_get_operation_not_full)
{
	TQueue que(3);
	que.Put(0);
	que.Put(1);
	que.Put(2);

	que.Get();

	EXPECT_FALSE(que.IsFull());
}

TEST(TQueue, get_operation_take_first_element)
{
	TQueue que(3);
	que.Put(0);
	que.Put(1);
	que.Put(2);

	EXPECT_EQ(0, que.Get());
}

TEST(TQueue, throws_when_get_from_empty_queue)
{
	TQueue que(2);

	ASSERT_ANY_THROW(que.Get());
}

TEST(TQueue, cant_put_in_full_queue)
{
	const int size = 3;
	TQueue que(size);
	for (int i = 0; i < size; i++)
		que.Put(1);

	ASSERT_ANY_THROW(que.Put(1));
}

TEST(TQueue, gettopelem_show_top_element)
{
	const int size = 3;
	TQueue que(size);
	for (int i = 0; i < size; i++)
		que.Put(i);

	EXPECT_EQ(0, que.GetTopElem());
}

TEST(TQueue, gettopelem_not_take_element_from_queue)
{
	const int size = 3;
	TQueue que(size);
	for (int i = 0; i < size; i++)
		que.Put(1);

	que.GetTopElem();

	EXPECT_TRUE(que.IsFull());
}

TEST(TQueue, can_be_round_queue)
{
	const int size = 3;
	TQueue que(size);
	for (int i = 0; i < size; i++)
		que.Put(1);
	que.Get();

	ASSERT_NO_THROW(que.Put(1));
}