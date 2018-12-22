#include "gtest.h"
#include "tqueue.h"
#include "tjobstream.h"
#include "tproc.h"

TEST(TQueue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue q);
}

TEST(TQueue, can_put_elem_to_queue)
{
    TQueue q;
    ASSERT_NO_THROW(q.Put(8));
}

TEST(TQueue, can_get_elem_from_queue)
{
    TQueue q;
    q.Put(8);
    ASSERT_NO_THROW(q.Get());
}

TEST(TQueue, top_elem_is_correct)
{
    TQueue q;
    q.Put(8);
    EXPECT_EQ(8,q.Get());
}

TEST(TQueue, full_empty_full)
{
    TQueue q(1);
    q.Put(3);
    q.Get();
    ASSERT_NO_THROW(q.Put(7));
}

TEST(TQueue, top_elem_works_correct)
{
    TQueue q(1);
    q.Put(9);
    EXPECT_EQ(9,q.TopElem());
    EXPECT_TRUE(q.IsFull());
}

TEST(TQueue, full_empty_full_empty)
{
    TQueue q(1);
    q.Put(3);
    q.Get();
    q.Put(2);
    EXPECT_EQ(2,q.Get());
}

TEST(TJobStream, can_create_tjobstream)
{
    ASSERT_NO_THROW(TJobStream a(4));
}

TEST(TJobStream, can_get_next_value)
{
    bool fl=false;
    TJobStream a(4,0.1);
    for (int i=0;i<100;++i)
        if (a.next()!=-1)
            fl=true;
    EXPECT_TRUE(fl);
}

TEST(TJobStream, can_get_minus_one)
{
    bool fl=false;
    TJobStream a(4,0.9);
    for (int i=0;i<100;++i)
        if (a.next()==-1)
            fl=true;
    EXPECT_TRUE(fl);
}

TEST(TProc, can_create_tproc)
{
    ASSERT_NO_THROW(TProc a);
}

TEST(TProc, can_perform_task)
{
    TProc a(0.9);
    bool fl=false;
    a.push();
    for (int i=0;i<100;++i)
        if (a.task_ready())
            fl=true;
    EXPECT_TRUE(fl);
}

TEST(TProc, cannot_perform_task)
{
    TProc a(0.1);
    bool fl=false;
    a.push();
    for (int i=0;i<100;++i)
        if (!a.task_ready())
            fl=true;
    EXPECT_TRUE(fl);
}

