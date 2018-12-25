#include "tstack.h"
#include "tqueue.h"

#include <gtest.h>

#include <iostream>
using namespace std;

TEST(TStack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack(5));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
    TStack st(-1);
    EXPECT_EQ(DataNoMem, st.GetRetCode());
}

TEST(TStack, can_put_element_in_stack)
{
    TStack st(2);
    ASSERT_NO_THROW(st.Put(3));
    EXPECT_EQ(DataOK, st.GetRetCode());
}

TEST(TStack, cant_put_element_in_full_stack)
{
    TStack st(3);
    st.Put(1);
    st.Put(2);
    st.Put(3);
    st.Put(4);
    EXPECT_EQ(DataFull, st.GetRetCode());
}

TEST(TStack, top_elem_is_changing_after_putting_new_elem)
{
    TStack st(3);
    st.Put(1);
    st.Put(2);
    EXPECT_EQ(2, st.TopElem());
}

TEST(TStack, can_get_element_from_stack)
{
    TStack st(3);
    st.Put(1);
    ASSERT_NO_THROW(st.Get());
    EXPECT_EQ(DataOK, st.GetRetCode());
}

TEST(TStack, get_return_correct_element)
{
    TStack st(3);
    st.Put(1);
    st.Put(2);
    EXPECT_EQ(2, st.Get());
}

TEST(TStack, cant_get_element_in_empty_stack)
{
    TStack st(3);
    st.Get();
    EXPECT_EQ(DataEmpty, st.GetRetCode());
}

TEST(TStack, top_elem_is_changing_after_getting_elem)
{
    TStack st(3);
    st.Put(1);
    st.Put(2);
    st.Get();
    EXPECT_EQ(1, st.TopElem());
}

TEST(TStack, top_elem_does_not_change_after_put_in_full_stack)
{
    TStack st(3);
    st.Put(1);
    st.Put(2);
    st.Put(3);
    st.Put(4);
    EXPECT_EQ(3, st.TopElem());
}

TEST(TStack, cant_get_top_elem_in_empty_stack)
{
    TStack st(2);
    st.TopElem();
    EXPECT_EQ(DataEmpty, st.GetRetCode());
}

TEST(TQueue, can_create_queue_with_positive_length)
{
    ASSERT_NO_THROW(TQueue q(2));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
    TQueue q(-2);
    EXPECT_EQ(DataNoMem, q.GetRetCode());
}

TEST(TQueue, can_get_element)
{
    TQueue q(2);
    q.Put(2);
    q.Put(3);
    ASSERT_NO_THROW(q.Get());
    EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, get_return_correct_element)
{
    TQueue q(2);
    q.Put(2);
    q.Put(3);
    EXPECT_EQ(2, q.Get());
}

TEST(TQueue, get_return_correct_element_multiple_times)
{
    TQueue q(3);
    q.Put(2);
    q.Put(3);
    q.Put(4);
    q.Get();
    q.Get();
    q.Get();
    q.Put(5);
    EXPECT_EQ(5, q.Get());
}

TEST(TQueue, top_element_is_changing_after_getting)
{
    TQueue q(3);
    q.Put(2);
    q.Put(3);
    q.Get();
    EXPECT_EQ(3, q.TopElem());
}

TEST(TQueue, top_elem_func_doesnt_delete_top_element)
{
    TQueue q(3);
    q.Put(2);
    q.Put(3);
    q.TopElem();
    EXPECT_EQ(2, q.TopElem());
}

TEST(TQueue, can_put_element)
{
    TQueue q(3);
    ASSERT_NO_THROW(q.Put(2));
    EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, can_put_element_multiple_times)
{
    TQueue q(3);
    q.Put(1);
    q.Put(2);
    q.Put(3);
    q.Get();
    ASSERT_NO_THROW(q.Put(2));
    EXPECT_EQ(DataOK, q.GetRetCode());
}

TEST(TQueue, put_func_put_correct_element)
{
    TQueue q(3);
    q.Put(1);
    EXPECT_EQ(1, q.TopElem());
}
