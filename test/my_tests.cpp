#include "tqueue.h"
  #include <gtest.h>
  
   TEST(TQueue, can_create_queue)
  {
  	ASSERT_NO_THROW(TQueue st(10));
  }
  
   TEST(TQueue, can_put_element)
  {
  	TQueue st(10);
  	ASSERT_NO_THROW(st.Put(15));
  }
  
   TEST(TQueue, cant_put_if_queue_full)
  {
  	TQueue st(1);
  	st.Put(1);
  	st.Put(1);
  	EXPECT_EQ(DataFull, st.GetRetCode());
  }
  
   TEST(TQueue, put_function_put_correct_element)
  {
  	TQueue st(5);
  	st.Put(1);
  	EXPECT_EQ(1, st.TopElem());
  }
  
   TEST(TQueue, can_get_element)
  {
  	TQueue st(10);
  	st.Put(15);
  	st.Put(11);
  	st.Put(17);
  	st.Get();
  	EXPECT_EQ(11, st.Get());
  }
  
   TEST(TQueue, cant_get_if_no_mem)
  {
  	TQueue st(0);
  	st.Get();
  	EXPECT_EQ(DataNoMem, st.GetRetCode());
  }
  
   TEST(TQueue, function_topelem_return_correct_value)
  {
  	TQueue st(10);
  	st.Put(15);
  	EXPECT_EQ(15, st.TopElem());
  }
  
   TEST(TQueue, cant_topelem_if_no_mem)
  {
  	TQueue st(0);
  	st.TopElem();
  	EXPECT_EQ(DataNoMem, st.GetRetCode());
  }
  
   TEST(TQueue, function_topelem_not_change_Li)
  {
  	TQueue st(10);
  	st.Put(15);
  	st.Put(12);
  	st.TopElem();
  	EXPECT_EQ(15, st.Get());
  }
  
   TEST(TQueue, get_return_correct_element_multiple_times)
  {
  	TQueue st(5);
  	st.Put(1);
  	st.Put(2);
  	st.Get();
  	st.Get();
  	st.Put(3);
  	EXPECT_EQ(3, st.Get());
  }
  