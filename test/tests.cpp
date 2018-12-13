#include <gtest.h>

#include "tqueue.h"

TEST(TQueue, can_create)
{
  EXPECT_NO_THROW(TQueue qu(5));
}

TEST(TQueue, can_put)
{
  TQueue qu(5);

  EXPECT_NO_THROW(qu.Put(1));
}

TEST(TQueue, can_get)
{
  TQueue qu(5);

  qu.Put(1);

  EXPECT_NO_THROW(qu.Get());
}

TEST(TQueue, cant_get_from_empty)
{
  TQueue qu(5);

  EXPECT_ANY_THROW(qu.Get());
}

TEST(TQueue, cant_put_in_full)
{
  const int SZ = 5;
  TQueue qu(SZ);

  for(int i = 0; i < SZ; ++i)
    qu.Put(1);

  EXPECT_ANY_THROW(qu.Put(1));
}

TEST(TQueue, get_value_that_put)
{
  const int EL = 1;
  TQueue qu(5);

  qu.Put(EL);

  EXPECT_EQ(EL, qu.Get());
}

TEST(TQueue, get_value_from_begin)
{
  const int SZ = 5;
  const int EL = 1;
  TQueue qu(SZ);

  for(int i = 0, j = EL; i < SZ; ++i)
    qu.Put(j++);

  EXPECT_EQ(EL, qu.Get());
}
