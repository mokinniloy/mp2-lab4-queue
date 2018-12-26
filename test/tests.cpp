#include "tstack.h"
#include "tqueue.h"
#include "TProc.h"
#include "TJobStream.h"
#include "gtest.h"

TEST(TQueue, can_create_the_queue)
{
	ASSERT_NO_THROW(TQueue(3));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue(-1));
}

TEST(TQueue, can_put_the_element)
{
	TQueue q(1);
	q.Put(5);
	ASSERT_NO_THROW(q.Get());
}

//TEST(TQueue, cant_put_the_element_in_full_queue)
//{
//	TQueue q(1);
//	q.Put(5);
//	EXPECT_EQ(q.Put(2), SetRetCode(DataFull));
//}

TEST(TQueue, can_return_element )
{
	TQueue q(1);
	q.Put(3);
	EXPECT_EQ(3, q.Get());
}

TEST(TQueue, return_zero_when_queue_is_empty)
{
	TQueue q(1);
	EXPECT_EQ(0, q.Get());
}

TEST(TQueue, can_get_next_index)
{
	TQueue q(3);
	EXPECT_EQ(2, q.GetNextIndex(1));
}

TEST(TQueue, banding_of_queue)
{
	TQueue q(3);
	EXPECT_EQ(0, q.GetNextIndex(2));
}

TEST(TJobStream, can_create_object)
{
	ASSERT_NO_THROW(TJobStream(0.7, 0.6));
}

TEST(TJobStream, cant_create_with_negative_values)
{
	ASSERT_ANY_THROW(TJobStream(-0.5, 0.8));
}

TEST(TJobStream, can_generate_task)
{
	TJobStream task(1, 1);
	task.taskGeneration();
	EXPECT_EQ(1, task.getTaskNum());
}

TEST(TJobStream, can_generate_task_completion)
{
	TJobStream task(1, 1);
	task.taskGeneration();
	EXPECT_EQ(1, task.taskWork());
}

TEST(TJobStream, can_return_index_of_task)
{
	TJobStream task(1, 1);
	task.taskGeneration();
	task.taskGeneration();
	task.taskGeneration();
	EXPECT_EQ(3, task.getTaskNum());
}

TEST(TJobStream, cant_return_index_of_nonexistent_task)
{
	TJobStream task(1, 1);
	ASSERT_ANY_THROW(task.getTaskNum());
}

TEST(TProc, can_create_object)
{
	ASSERT_NO_THROW(TProc());
}

TEST(TProc, can_return_count_of_work_tacts_and_check_for_execution)
{
	TProc p;
	TQueue q(1);
	q.Put(4);
	p.BusynessOfProc(q);
	EXPECT_EQ(1, p.GetCountOfWorkTacts());
}

TEST(TProc, can_return_count_of_free_tact_and_check_for_executions)
{
	TProc p;
	TQueue q(1);
	p.BusynessOfProc(q);
	EXPECT_EQ(1, p.GetCountOfFreeTacts());
}