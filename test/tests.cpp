#include <gtest.h>
#include "tqueue.h"
#include <vector>

TEST(TQueue, can_create_queue) {
	ASSERT_NO_THROW(TQueue(4));
}

TEST(TQueue, can_create_queue_with_default_parameter) {
	ASSERT_NO_THROW(TQueue());
}

TEST(TQueue, cant_create_queue_with_negative_quantity) {
	ASSERT_ANY_THROW(TQueue(-4));
}

TEST(TQueue, can_put_elements) {
	TQueue q = TQueue(4);
	ASSERT_NO_THROW(q.Put(1));
}

TEST(TQueue, can_check_emptiness) {
	TQueue q = TQueue(4);
	ASSERT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_check_fullness) {
	TQueue q = TQueue(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	ASSERT_EQ(true, q.IsFull());
}

TEST(TQueue, can_get_elements) {
	TQueue q = TQueue(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	std::vector<int> v;
	while (!q.IsEmpty())
		v.push_back(q.Get());
	ASSERT_EQ(std::vector<int>({ 0, 1, 2, 3 }), v);
}

TEST(TQueue, can_get_top_element) {
	TQueue q = TQueue(4);
	std::vector<int> v;
	for (int i = 0; i < 4; ++i) {
		q.Put(i);
		v.push_back(q.TopElem());
	}
	ASSERT_EQ(std::vector<int>({ 0, 1, 2, 3 }), v);
}

TEST(TQueue, cant_put_to_full_queue) {
	TQueue q = TQueue(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	q.Put(5);
	ASSERT_NE(DataOK, q.GetRetCode());
}

TEST(TQueue, cant_get_from_empty_stack) {
	TQueue q = TQueue(4);
	q.Get();
	ASSERT_NE(DataOK, q.GetRetCode());
}

TEST(TQueue, get_function_deletes_top_element) {
	TQueue q = TQueue(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	for (int i = 0; i < 4; ++i)
		q.Get();
	ASSERT_EQ(true, q.IsEmpty());
	ASSERT_NE(true, q.IsFull());
}

TEST(TQueue, TopElem_function_doesnt_delete_top_element) {
	TQueue q = TQueue(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	for (int i = 0; i < 4; ++i)
		q.TopElem();
	ASSERT_NE(true, q.IsEmpty());
	ASSERT_EQ(true, q.IsFull());
}

TEST(TQueue, can_put_after_gets) {
	TQueue q = TQueue(4);
	for (int i = 0; i < 4; ++i)
		q.Put(i);
	q.Get();
	q.Get();
	q.Put(0);
	q.Put(0);
	ASSERT_EQ(true, q.IsFull());
}

TEST(TQueue, cant_create_queue_with_zero_capacity) {
	ASSERT_ANY_THROW(TQueue(0));
}

TEST(TQueue, can_work_with_combinations_of_put_get_and_TopElem) {
	TQueue q = TQueue(10);
	for (int i = 0; i < 10; ++i) {
		q.Put(i);
		int x = q.TopElem();
		q.Get();
		q.Put(i);
	}
	for (int i = 0; i < 10; ++i) {
		q.Get();
		q.Put(i);
		q.TopElem();
		q.Get();
	}
	ASSERT_EQ(true, q.IsEmpty());
	ASSERT_NE(true, q.IsFull());
}