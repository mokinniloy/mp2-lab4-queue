#include<gtest.h>
#include"tqueue.h"
TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue(5));
}
TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue(-1));
}
TEST(TQueue, can_get_and_set_element)
{
	TQueue temp(3);
	temp.Put(8);
	temp.Put(4);
	EXPECT_EQ(8, temp.Get().GetCyclesOnTask());
}
TEST(TQueue, cant_get_elment_from_empty_queue)
{
	TQueue temp(4);
	ASSERT_ANY_THROW(temp.Get());
}
TEST(TQueue, cant_get_elment_from_queue_without_mem)
{
	TQueue temp(0);
	ASSERT_ANY_THROW(temp.Get());
}
TEST(TQueue, can_detect_if_queue_is_empty)
{
	TQueue temp(3);
	EXPECT_EQ(1, temp.IsEmpty());
}
TEST(TQueue, can_detect_if_queue_is_not_empty)
{
	TQueue temp(3);
	temp.Put(11);
	EXPECT_EQ(0, temp.IsEmpty());
}
TEST(TQueue, can_detect_if_queue_is_not_full)
{
	TQueue temp(3);
	temp.Put(11);
	EXPECT_EQ(0, temp.IsFull());
}
TEST(TQueue, can_detect_if_queue_is_full)
{
	TQueue temp(1);
	temp.Put(8);
	EXPECT_EQ(1, temp.IsFull());
}
TEST(TQueue, get_throws_when_queue_is_empty)
{
	TQueue temp(3);
	ASSERT_ANY_THROW(temp.Get());
}
TEST(TQueue, put_throws_when_queue_is_full)
{
	TQueue temp(2);
	temp.Put(10);
	temp.Put(12);
	ASSERT_ANY_THROW(temp.Put(1));
}
TEST(TQueue, can_print_values)
{
	TQueue temp(3);
	for (int i = 0; i < 3; i++)
		temp.Put(i);
	ASSERT_NO_THROW(temp.Print());
}
TEST(TQueue, can_detect_if_queue_is_valid)
{
	TStack temp(3);
	for (int i = 0; i < 3; i++)
		temp.Put(i);
	EXPECT_EQ(1, temp.IsValid());
}