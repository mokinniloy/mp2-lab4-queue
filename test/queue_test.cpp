#include "../gtest/gtest.h"
//#include "../include/TQueue.h"
#include "TQueue.h"
 
TEST(TQueue, can_create_tqueue) {
	ASSERT_NO_THROW(TQueue()) ;
}

TEST(TQueue, can_create_tqueue_with_positive_size) {
	ASSERT_NO_THROW( TQueue(10));
}

TEST(TQueue, throws_when_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue(-4));
}

TEST(TQueue, can_put_value ) {
	TQueue que(2);
	ASSERT_NO_THROW(que.Put(3));
}

TEST(TQueue, can_put_value_twice) {
	TQueue que(2);
	que.Put(3);
	ASSERT_NO_THROW(que.Put(3));
}

TEST(TQueue, can_get_value) {

	TQueue que(2);
	que.Put(7);
	ASSERT_NO_THROW(que.Get());
}

TEST(TQueue, can_correctly_get_value) {
	TQueue que(2);
	que.Put(7);
	EXPECT_EQ(7, que.Get());
}

TEST(TQueue, cant_get_elem_when_queue_is_empty)
{
	TQueue que(2);
	ASSERT_ANY_THROW(que.Get());
}

TEST(TQueue, cant_put_elem_when_queue_is_full)
{
	TQueue que(2);
	que.Put(10);
	que.Put(10);
	ASSERT_ANY_THROW(que.Put(10));
}

TEST(TQueue, queue_is_not_empty_after_put_operation) {
	TQueue que(4);
	que.Put(5);
	ASSERT_NE(true, que.IsEmpty());
}

TEST(TQueue, get_function_deletes_top_element) {
	TQueue que(4);
	que.Put(1);
	que.Put(2);
	que.Put(3);
	for (int i = 0; i < 3; ++i)
		que.Get();
	ASSERT_EQ(true, que.IsEmpty());
}

TEST(TQueue, TopElem_function_doesnt_delete_top_element) {
	TQueue que(4);
	que.Put(1);
	que.Put(2);
	que.Put(3);
	for (int i = 0; i < 3; ++i)
		que.TopElem();
	ASSERT_NE(true, que.IsEmpty());
}

//12 tests from TQueue