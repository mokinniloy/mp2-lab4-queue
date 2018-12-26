#include "gtest.h"
#include "tqueue.hpp"

TEST(TQueue, can_create_queue)
{
    TQueue queue;

    ASSERT_NO_THROW(queue = TQueue(20));
}

TEST(TQueue, can_put_element)
{
    TQueue queue(10);

    ASSERT_NO_THROW(queue.Put(1));
}

TEST(TQueue, can_get_element)
{
    TQueue queue(10);

    queue.Put(0);

    ASSERT_NO_THROW(queue.Get());
}

TEST(TQueue, can_get_next_index_outside_of_class)
{
    TQueue queue(10);
    int index = 10;

    ASSERT_NO_THROW(queue.GetNextIndex(index));
}

TEST(TQueue, queue_return_values_according_to_FIFO)
{
    TQueue queue(3);

    queue.Put(2);
    queue.Put(3);
    queue.Put(4);

    queue.Get();
    queue.Put(5);
    queue.Get();
    queue.Get();

    EXPECT_EQ(5, queue.Get());
}

TEST(TQueue, throws_when_trying_to_put_to_full_queue)
{
    TQueue queue(2);

    queue.Put(1);
    queue.Put(2);

    ASSERT_ANY_THROW(queue.Put(4));
}

TEST(TQueue, throws_when_trying_to_get_from_empty_queue)
{
    TQueue queue(1);

    ASSERT_ANY_THROW(queue.Get());
}

TEST(TQueue, throws_when_trying_to_create_negative_size_queue)
{
    TQueue queue;

    ASSERT_ANY_THROW(queue = TQueue(-2));
}