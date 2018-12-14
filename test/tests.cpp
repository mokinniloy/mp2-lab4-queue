#include <gtest.h>
#include "tqueue.h"
TEST(TQueue, can_create_queue) {
	ASSERT_NO_THROW(TQueue(4));
}
TEST(TQueue, check_DefMemSize_1) {
	ASSERT_NO_THROW(TQueue());
}
TEST(TQueue, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue(-4));
}
TEST(TQueue, can_put_elements) {
	TQueue q(5);
	ASSERT_NO_THROW(q.Put(10));
}

TEST(TQueue, can_get_elements) {
	TQueue q(5);
	for (int i = 0; i < 5; ++i) q.Put(i);
	for (int i = 0; i < 5; ++i) ASSERT_EQ(i, q.Get());
}

TEST(TQueue, check_IsEmpty) {
	TQueue q(10);
	q.Put(5);
	q.Get();
	ASSERT_EQ(1, q.IsEmpty());
}
TEST(TQueue, check_IsFull) {
	TQueue q(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	ASSERT_EQ(1, q.IsFull());
}

TEST(TQueue, can_get_top_element) {
	TQueue q(4);
	for (int i = 0; i < 4; ++i) {
		q.Put(i);
		ASSERT_EQ(0, q.TopElem());
	}
	q.Get();
	ASSERT_EQ(1, q.TopElem());
}




TEST(TQueue, cant_put_to_full_queue) {
	TQueue q(10);
	for (int i = 0; i < 10; ++i)
		q.Put(i);
	q.Put(10);
	ASSERT_NE(DataOK, q.GetRetCode());
}

TEST(TQueue, queue_with_size_equal_0_get)
{
	TQueue q(0);
	q.Get();
	EXPECT_EQ(q.GetRetCode(), DataNoMem);
}

TEST(TQueue, queue_with_size_equal_0_put)
{
	TQueue q(0);
	q.Put(5);
	EXPECT_EQ(q.GetRetCode(), DataFull);
}

  
TEST(TQueue, check_DefMemSize_2)
{
	TQueue q;
	for (int i = 0; i < 25; ++i) q.Put(i);
	EXPECT_EQ(q.IsFull(), 1);
}

TEST(TQueue, SetRetCode_is_correct_on_DataEmpty)
{
	TQueue  q(1);
	q.Get();
	q.Get();
	EXPECT_EQ(q.GetRetCode(), DataEmpty);
}

TEST(TQueue, Get_delete_topEelement) {
	TQueue q(10);
	for (int i = 0; i < 10; ++i)
		q.Put(i);
	for (int i = 0; i < 10; ++i)
		q.Get();
	ASSERT_EQ(1, q.IsEmpty());
}


TEST(TQueue, TopElem_doesnt_delete_Element) {
	TQueue q (10);
	for (int i = 0; i < 10; ++i)
		q.Put(i);
	for (int i = 0; i < 10; ++i)
		q.TopElem();
	ASSERT_NE(1, q.IsEmpty());
	ASSERT_EQ(0, q.TopElem());
}
