#include "tqueue.h"

#include "gtest.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue a(1));
}

TEST(TQueue, cant_create_queu_with_negative_val)
{
	ASSERT_ANY_THROW(TQueue a(-1));
}

TEST(TQueue, can_add_value)
{
	TQueue a(1);
	ASSERT_NO_THROW(a.Put(5));
}

TEST(TQueue, can_get_value )
{
	TQueue a(1);
	a.Put(5);
	ASSERT_EQ(5, a.Get());
}

TEST(TQueue, cant_put_if_no_mem)
{
	TQueue st(0);

	st.Put(5);

	EXPECT_EQ(DataNoMem, st.GetRetCode());
}

TEST(TQueue, cant_put_if_queue_full)
{
	TQueue st(1);
	st.Put(5);
	st.Put(5);

	EXPECT_EQ(DataFull, st.GetRetCode());
}

TEST(TQueue, can_put_if_ok_1)
{
	TQueue st(1);
	st.Put(5);

	EXPECT_EQ(DataOK, st.GetRetCode());
}

TEST(TQueue, can_put_if_ok_2)
{
	TQueue st(1);
	st.Put(5);

	EXPECT_EQ(5, st.TopElem());
}

TEST(TQueue, cant_get_if_no_mem)
{
	TQueue st(0);
	st.Get();

	EXPECT_EQ(DataNoMem, st.GetRetCode());
}

TEST(TQueue, cant_get_if_queue_empty)
{
	TQueue st(1);
	st.Get();

	EXPECT_EQ(DataEmpty, st.GetRetCode());
}

TEST(TQueue, cant_top_elem_if_no_mem)
{
	TQueue st(0);
	st.TopElem();

	EXPECT_EQ(DataNoMem, st.GetRetCode());
}

TEST(TQueue, cant_top_elem_if_queue_empty)
{
	TQueue st(1);
	st.TopElem();

	EXPECT_EQ(DataEmpty, st.GetRetCode());
}

TEST(TQueue, can_top_elem_if_ok_1)
{
	TQueue st(1);
	st.Put(5);
	st.TopElem();

	EXPECT_EQ(DataOK, st.GetRetCode());
}

TEST(TQueue, can_top_elem_if_ok_2)
{
	TQueue st(1);
	st.Put(5);

	EXPECT_EQ(5, st.TopElem());
}

TEST(TQueue, can_put_if_ok_circular_buffer_1)
{
	TQueue st(2);
	st.Put(1);
	st.Put(2);
	st.Get();
	st.Put(3);

	EXPECT_EQ(DataOK, st.GetRetCode());
}

TEST(TQueue, cant_put_if_ok_circular_buffer_2)
{
	TQueue st(2);
	st.Put(1);
	st.Put(2);
	st.Get();
	st.Put(3);
	st.Get();

	EXPECT_EQ(3, st.TopElem());
}

TEST(TQueue, can_get_if_ok_circular_buffer_1)
{
	TQueue st(2);
	st.Put(1);
	st.Put(2);
	st.Get();
	st.Put(3);
	st.Get();

	EXPECT_EQ(DataOK, st.GetRetCode());
}

TEST(TQueue, can_get_if_ok_circular_buffer_2)
{
	TQueue st(2);
	st.Put(1);
	st.Put(2);
	st.Get();
	st.Put(3);
	int k = st.Get();

	EXPECT_EQ(2, k);
}

TEST(TQueue, can_top_elem_if_ok_circular_buffer)
{
	TQueue st(2);
	st.Put(1);
	st.Put(2);
	st.Get();
	st.Put(3);
	st.Get();

	EXPECT_EQ(DataOK, st.GetRetCode());
}

