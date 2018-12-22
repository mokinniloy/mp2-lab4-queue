#include <gtest.h>
#include "tstack.h"


TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack mstack(5));
}

TEST(TStack, cant_create_stack_with_negative_lenght)
{
	ASSERT_ANY_THROW(TStack mstack(-10));
}

TEST(TStack, can_put_element_into_stack)
{
	TStack mstack(5);

	mstack.Put(13);

	EXPECT_EQ(mstack.GetRetCode(), 0);
}

TEST(TStack, can_get_top_element_with_deleting)
{
	TStack mstack(5);

	mstack.Put(13);

	EXPECT_EQ(mstack.Get(), 13);
}

TEST(TStack, can_get_top_element_without_deleting)
{
	TStack mstack(5);

	mstack.Put(14);

	EXPECT_EQ(14, mstack.TopElem());
}
