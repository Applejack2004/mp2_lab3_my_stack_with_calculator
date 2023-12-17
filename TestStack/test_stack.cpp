#include "../my_stack/Tstack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> st());
}


TEST(TStack, can_get_length)
{
    TStack<int> st;
    
 
    int i = st.GetNum();
  EXPECT_EQ(0, i);
}


TEST(TStack, new_stack_is_empty)
{
    TStack<int> st;

    int sostoyanie = st.Empty();

  EXPECT_EQ(1, sostoyanie);
}


TEST(TStack, can_push_and_pop)
{
    TStack<int> st;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    ASSERT_NO_THROW(st.Push(a1));
    ASSERT_NO_THROW(st.Push(a2));
    ASSERT_NO_THROW(st.Push(a3));
    int b1, b2, b3;
    ASSERT_NO_THROW( b1 = st.Pop());
    ASSERT_NO_THROW( b2 = st.Pop());
    ASSERT_NO_THROW( b3 = st.Pop());
    EXPECT_EQ(a1, b3); 
    EXPECT_EQ(a2, b2);
    EXPECT_EQ(a3, b1);

   
}




TEST(TStack, throws_when_use_pop_on_empty_stack)
{
    TStack<int> st;
  ASSERT_ANY_THROW(st.Pop());
}

//TEST(Tstack, throws_when_use_push_on_overflow_stack)
//{
//    Tstack<int> st(3);
//    st.Push(1);
//    st.Push(1);
//    st.Push(1);
//    ASSERT_ANY_THROW(st.Push(1));
//}
//
TEST(TStack, throws_when_use_TOP_on_empty_stack)
{
    TStack<int> st;
 
    ASSERT_ANY_THROW(st.Top());
}
//
//TEST(Tstack, return_true_when_use_Full_on_full_stack)
//{
//    Tstack<int> st(3);
//    st.Push(1);
//    st.Push(1);
//    st.Push(1);
//    bool b1 = st.Full();
//    EXPECT_EQ(1, b1);
//}
//TEST(Tstack, return_false_when_use_Full_on_not_full_stack)
//{
//    Tstack<int> st(3);
//    st.Push(1);
//    st.Push(1);
//   
//    bool b1 = st.Full();
//    EXPECT_EQ(0, b1);
//}
TEST(TStack, return_true_when_use_Empty_on_empty_stack)
{
    TStack<int> st;
   
    bool b1 = st.Empty();
    EXPECT_EQ(1, b1);
}
TEST(TStack, return_false_when_use_Empty_on_not_empty_stack)
{
    TStack<int> st;
    st.Push(1);
    st.Push(1);

    bool b1 = st.Empty();
    EXPECT_EQ(0, b1);
}

