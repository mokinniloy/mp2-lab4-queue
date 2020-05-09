#include "gtest.h"
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

/*-------------------------------------TQueue-------------------------------------*/

TEST(TQueue, can_create_queue)
{
	EXPECT_NO_THROW(TQueue q());
}

TEST(TQueue, can_put_element_to_queue)
{
	TQueue q;
	EXPECT_NO_THROW(q.Put(1));
}

TEST(TQueue, can_get_element_from_queue)
{
	TQueue q;
	q.Put(1);
	EXPECT_NO_THROW(q.Get());
}

TEST(TQueue, can_return_top_element)
{
	TQueue q;
	q.Put(1);
	EXPECT_NO_THROW(q.TopElem());
}

TEST(TQueue, get_works_right)
{
	TQueue q;
	q.Put(1);
	q.Put(2);
	EXPECT_EQ(q.Get(), 1);
}

TEST(TQueue, topelem_works_right)
{
	TQueue q;
	q.Put(1);
	q.Put(2);
	EXPECT_EQ(q.TopElem(), 1);
}

TEST(TQueue, topelem_not_get_element)
{
	TQueue q;
	q.Put(1);
	q.TopElem();
	EXPECT_NO_THROW(q.Get());
}

TEST(TQueue, cant_get_element_from_empty_queue)
{
	TQueue q;
	EXPECT_ANY_THROW(q.Get());
}

TEST(TQueue, cant_get_top_element_from_empty_queue)
{
	TQueue q;
	EXPECT_ANY_THROW(q.TopElem());
}
/*-------------------------------------9-------------------------------------*/