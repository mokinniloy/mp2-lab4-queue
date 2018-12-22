#include "tqueue.h"

#include "gtest.h"

TEST(TStack, cant_create_stack_with_negative_size)
{
	TStack stack(-5);

	EXPECT_EQ(stack.GetRetCode(), DataErr);
}

TEST(TStack, can_create_stack_with_positive_size)
{
	TStack stack(5);

	EXPECT_EQ(stack.GetRetCode(), DataOK);
}

TEST(TStack, can_create_stack_with_zero_size)
{
	TStack stack(0);

	EXPECT_EQ(stack.GetRetCode(), DataOK);
}

TEST(TStack, can_put_element_in_not_full_stack)
{
	TStack stack(5);
	stack.Put(0);

	EXPECT_EQ(stack.GetRetCode(), DataOK);
	EXPECT_EQ(stack.TopElem(), 0);

	stack.Put(1);

	EXPECT_EQ(stack.GetRetCode(), DataOK);
	EXPECT_EQ(stack.TopElem(), 1);
}

TEST(TStack, cant_put_element_in_full_stack)
{
	TStack stack(5);
	stack.Put(0);
	stack.Put(1);
	stack.Put(2);
	stack.Put(3);
	stack.Put(4);
	stack.Put(5);

	EXPECT_EQ(stack.GetRetCode(), DataFull);
}

TEST(TStack, cant_put_element_in_zero_stack)
{
	TStack stack(0);
	stack.Put(0);

	EXPECT_EQ(stack.GetRetCode(), DataNoMem);
}

TEST(TStack, cant_get_element_from_empty_stack)
{
	TStack stack(5);
	stack.Get();

	EXPECT_EQ(stack.GetRetCode(), DataEmpty);
}

TEST(TStack, cant_get_element_from_zero_stack)
{
	TStack stack(0);
	stack.Get();

	EXPECT_EQ(stack.GetRetCode(), DataNoMem);
}

TEST(TStack, can_get_element_from_not_empty_stack)
{
	TStack stack(5);
	stack.Put(0);
	stack.Put(1);
	stack.Put(2);

	EXPECT_EQ(stack.Get(), 2);
	EXPECT_EQ(stack.GetRetCode(), DataOK);
}

TEST(TStack, cant_check_top_element_from_empty_stack)
{
	TStack stack(5);
	stack.TopElem();

	EXPECT_EQ(stack.GetRetCode(), DataEmpty);
}

TEST(TStack, cant_check_top_element_from_zero_stack)
{
	TStack stack(0);
	stack.TopElem();

	EXPECT_EQ(stack.GetRetCode(), DataNoMem);
}

TEST(TStack, can_check_top_element_from_not_empty_stack)
{
	TStack stack(5);
	stack.Put(0);
	stack.Put(1);
	stack.Put(2);

	EXPECT_EQ(stack.TopElem(), 2);
	EXPECT_EQ(stack.GetRetCode(), DataOK);
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
	TQueue queue(-5);

	EXPECT_EQ(queue.GetRetCode(), DataErr);
}

TEST(TQueue, can_create_queue_with_positive_size)
{
	TQueue queue(5);

	EXPECT_EQ(queue.GetRetCode(), DataOK);
}

TEST(TQueue, can_create_queue_with_zero_size)
{
	TQueue queue(0);

	EXPECT_EQ(queue.GetRetCode(), DataOK);
}

TEST(TQueue, can_put_element_in_not_full_queue)
{
	TQueue queue(5);
	queue.Put(0);
	queue.Put(1);

	EXPECT_EQ(queue.GetRetCode(), DataOK);
	EXPECT_EQ(queue.TopElem(), 0);
}

TEST(TQueue, cant_put_element_in_full_queue)
{
	TQueue queue(5);
	queue.Put(0);
	queue.Put(1);
	queue.Put(2);
	queue.Put(3);
	queue.Put(4);
	queue.Put(5);

	EXPECT_EQ(queue.GetRetCode(), DataFull);
}

TEST(TQueue, cant_put_element_in_zero_queue)
{
	TQueue queue(0);
	queue.Put(0);

	EXPECT_EQ(queue.GetRetCode(), DataNoMem);
}

TEST(TQueue, cant_get_element_from_empty_queue)
{
	TQueue queue(5);
	queue.Get();

	EXPECT_EQ(queue.GetRetCode(), DataEmpty);
}

TEST(TQueue, cant_get_element_from_zero_queue)
{
	TQueue queue(0);
	queue.Get();

	EXPECT_EQ(queue.GetRetCode(), DataNoMem);
}

TEST(TQueue, can_get_element_from_not_empty_queue)
{
	TQueue queue(5);
	queue.Put(0);
	queue.Put(1);
	queue.Put(2);

	EXPECT_EQ(queue.Get(), 0);
	EXPECT_EQ(queue.GetRetCode(), DataOK);
}

TEST(TQueue, cant_check_top_element_from_empty_queue)
{
	TQueue queue(5);
	queue.TopElem();

	EXPECT_EQ(queue.GetRetCode(), DataEmpty);
}

TEST(TQueue, cant_check_top_element_from_zero_queue)
{
	TQueue queue(0);
	queue.TopElem();

	EXPECT_EQ(queue.GetRetCode(), DataNoMem);
}

TEST(TQueue, can_check_top_element_from_not_empty_queue)
{
	TQueue queue(5);
	queue.Put(0);
	queue.Put(1);
	queue.Put(2);

	EXPECT_EQ(queue.TopElem(), 0);
	EXPECT_EQ(queue.GetRetCode(), DataOK);
}