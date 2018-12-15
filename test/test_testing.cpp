#include "gtest.h"
#include "tqueue.hpp"

TEST (TQueue, ring_buffer_test)
{
    TQueue queue(2);

    queue.Put(1);
    queue.Put(2);
    std::cout << queue.Get() << std::endl;
    queue.Put(3);
    std::cout << queue.Get() << std::endl << queue.Get() << std::endl;

    ASSERT_ANY_THROW(queue.Print());
}





