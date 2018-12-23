#include <gtest.h>
#include "tqueue.h"


TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue q1(5));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue q1(-5););
}

TEST(TQueue, get_element_is_correct)
{
	TQueue q1(5);
	q1.Put(1);
	q1.Put(2);
	ASSERT_EQ(1, q1.Get());
}
TEST(TQueue, can_get_element)
{
	TQueue q1(5);
	q1.Put(1);
	ASSERT_NO_THROW(q1.Get());
}

TEST(TQueue, top_element_is_different_after_get)
{
	TQueue q1(5);
	q1.Put(1);
	q1.Put(2);
	q1.Get();
	ASSERT_EQ(2, q1.TopElem());
}

TEST(TQueue, get_element_after_get_and_put_is_correct)
{
	TQueue q1(5);
	q1.Put(1);
	q1.Put(2);
	q1.Put(3);
	q1.Get();
	q1.Get();
	q1.Get();
	q1.Put(10);
	ASSERT_EQ(10, q1.Get());
}

TEST(TQueue, top_elem_doesnt_delete_element)
{
	TQueue q1(5);
	q1.Put(1);
	q1.Put(2);
	q1.TopElem();
	ASSERT_EQ(1, q1.TopElem());
}

TEST(TQueue, can_put_element)
{
	TQueue q1(5);
	ASSERT_NO_THROW(q1.Put(1));
}

TEST(TQueue, can_put_multiple_times)
{
	TQueue q1(5);
	q1.Put(1);
	q1.Put(2);
	q1.Put(3);
	ASSERT_NO_THROW(q1.Put(2));
}

TEST(TQueue, put_element_is_correct)
{
	TQueue q1(5);
	q1.Put(1);
	ASSERT_EQ(1, q1.Get());
}

TEST(TQueue, element_cant_change_when_put_element_in_full_queue)
{
	TQueue q1(2);
	q1.Put(1);
	q1.Put(2);
	q1.Put(3);
	q1.Get();
	ASSERT_EQ(2, q1.TopElem());

}
