#include "gtest.h"
#include "tqueue.hpp"

TEST (TQueue, ring_buffer_test)
{
    TQueue queue(2);

    queue.Put(1);
    queue.Put(2);
    queue.Get();
    queue.Put(3);

    ASSERT_NO_THROW(queue.Print());
}





