#include"tproc.h"
#include"tjobstream.h"
#include <gtest.h>

TEST(TProc, cant_create_proc_with_negative_or_zero_parameters)
{
	ASSERT_ANY_THROW(TProc(-4, -2, 0));
}
TEST(TJobStream, cant_create_job_with_negative_or_zero_probability)
{
	ASSERT_ANY_THROW(TJobStream(0,0));
}
TEST(TProc, can_create_proc_with_positie_parameters)
{
	ASSERT_NO_THROW(TProc(400, 2, 8));
}
TEST(TJobStream, can_create_job_with_positive_probability_and_less_or_eq_one)
{
	ASSERT_NO_THROW(TJobStream(0.5,0.5));
}
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack(5));
}
TEST(TStack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack(-1));
}
TEST(TStack, can_get_and_set_element)
{
	TStack temp(3);
	temp.Put(4);
	temp.Put(2);
	EXPECT_EQ(2, temp.Get().GetCyclesOnTask());
}
TEST(TStack, cant_get_elment_from_empty_stack)
{
	TStack temp(4);
	ASSERT_ANY_THROW(temp.Get());
}
TEST(TStack, cant_get_elment_from_stack_without_mem)
{
	TStack temp(0);
	ASSERT_ANY_THROW(temp.Get());
}
TEST(TStack, can_detect_if_stack_is_empty)
{
	TStack temp(3);
	EXPECT_EQ(1, temp.IsEmpty());
}
TEST(TStack, can_detect_if_stack_is_not_empty)
{
	TStack temp(3);
	temp.Put(11);
	EXPECT_EQ(0, temp.IsEmpty());
}
TEST(TStack, can_detect_if_stack_is_not_full)
{
	TStack temp(3);
	temp.Put(11);
	EXPECT_EQ(0, temp.IsFull());
}
TEST(TStack, can_detect_if_stack_is_full)
{
	TStack temp(1);
	temp.Put(8);
	EXPECT_EQ(1, temp.IsFull());
}
TEST(TStack, get_throws_when_stack_is_empty)
{
	TStack temp(3);
	ASSERT_ANY_THROW(temp.Get());
}
TEST(TStack, put_throws_when_stack_is_full)
{
	TStack temp(2);
	temp.Put(10);
	temp.Put(12);
	ASSERT_ANY_THROW(temp.Put(1));
}
TEST(TStack, can_print_values)
{
	TStack temp(3);
	for (int i = 0; i < 3; i++)
		temp.Put(i);
	ASSERT_NO_THROW(temp.Print());
}
TEST(TStack, can_detect_if_stack_is_valid)
{
	TStack temp(3);
	for (int i = 0; i < 3; i++)
		temp.Put(i);
	EXPECT_EQ(1, temp.IsValid());
}
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
TEST(TQueue, can_detect_if_queue_is_valid)
{
	TStack temp(3);
	for (int i = 0; i < 3; i++)
		temp.Put(i);
	EXPECT_EQ(1, temp.IsValid());
}