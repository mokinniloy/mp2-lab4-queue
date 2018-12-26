#include <gtest.h>
#include "tqueue.h"

TEST(TQueue, can_create_queue) {
    ASSERT_NO_THROW(TQueue(5));
}

TEST(TQueue, cant_create_queue_with_negative_size) {
    ASSERT_ANY_THROW(TQueue(-2));
}

TEST(TQueue, can_put_element) {
	TQueue q = TQueue(5);
	TData val = 3;
	ASSERT_NO_THROW(q.Put(val));
}

TEST(TQueue, cant_put_element_else_queue_full) {
	TQueue q = TQueue(2);
	TData val = 3;
	q.Put(val);
	q.Put(val);
	ASSERT_EQ(true, q.IsFull());
}

TEST(TQueue, can_show_put_element) {
	TQueue q = TQueue(2);
	TData val = 3;
	q.Put(val);
	q.Put(val);
	ASSERT_EQ(3, q.TopElem());
}

TEST(TQueue, can_get_element) {
	TQueue q = TQueue(5);
	TData val = 3;
	q.Put(val);
	ASSERT_NO_THROW(q.Get());
}

TEST(TQueue, cant_get_element_else_queue_empty) {
	TQueue q = TQueue(2);
	ASSERT_EQ(true, q.IsEmpty());
}

TEST(TQueue, else_get_element_li_move) {
	TQueue q = TQueue(5);
	TData val1 = 3, val2 = 4;
	q.Put(val1);
	q.Put(val2);
	q.Get();
	ASSERT_EQ(val2, q.TopElem());
}

TEST(TQueue, can_put_element_in_circular_queue) {
	TQueue q = TQueue(3);
	TData val1 = 3, val2 = 4, val3 = 5;
	q.Put(val1);
	q.Put(val2);
	q.Put(val3);
	q.Get();
	ASSERT_NO_THROW(q.Put(val1));
}

TEST(TQueue, queue_is_circular) {
	TQueue q = TQueue(3);
	TData val1 = 3, val2 = 4, val3 = 5, val4 = 7;
	q.Put(val1);
	q.Put(val2);
	q.Put(val3);
	q.Get();
	q.Put(val3);
	ASSERT_EQ(val2, q.TopElem());
}





