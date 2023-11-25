#include "../my_stack/Tstack.h"

#include "gtest.h"

TEST(Tstack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(Tstack<int> st(3));
}
TEST(Tstack, cant_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(Tstack<int> st(-12));
}

TEST(Tstack, can_get_length)
{
    Tstack<int> st(3);
 

  EXPECT_EQ(-1, st.get_top());
}


TEST(Tstack, new_stack_is_empty)
{
    Tstack<int> st(3);

    int sostoyanie = st.Empty();

  EXPECT_EQ(1, sostoyanie);
}


TEST(Tstack, can_push_and_pop)
{
    Tstack<int> st(5);
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




TEST(Tstack, throws_when_use_pop_on_empty_stack)
{
    Tstack<int> st(3);
  ASSERT_ANY_THROW(st.Pop());
}

TEST(Tstack, throws_when_use_push_on_overflow_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(1);
    st.Push(1);
    ASSERT_ANY_THROW(st.Push(1));
}

TEST(Tstack, throws_when_use_TOP_on_empty_stack)
{
    Tstack<int> st(3);
 
    ASSERT_ANY_THROW(st.TOP());
}

TEST(Tstack, return_true_when_use_Full_on_full_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(1);
    st.Push(1);
    bool b1 = st.Full();
    EXPECT_EQ(1, b1);
}
TEST(Tstack, return_false_when_use_Full_on_not_full_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(1);
   
    bool b1 = st.Full();
    EXPECT_EQ(0, b1);
}
TEST(Tstack, return_true_when_use_Empty_on_empty_stack)
{
    Tstack<int> st(3);
   
    bool b1 = st.Empty();
    EXPECT_EQ(1, b1);
}
TEST(Tstack, return_false_when_use_Empty_on_not_empty_stack)
{
    Tstack<int> st(3);
    st.Push(1);
    st.Push(1);

    bool b1 = st.Empty();
    EXPECT_EQ(0, b1);
}

