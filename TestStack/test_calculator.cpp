#include "../my_stack/Calculator.h"

#include "gtest.h"

TEST(TCalculator, can_create_calculator_with_positive_size_of_str)
{
    std::string a = "1+1";
    ASSERT_NO_THROW(TCalculator calc(a));
}
TEST(TCalculator, can_get_infix_form_of_calculator)
{
    std::string a="2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(b=calc.get_infix());
    EXPECT_EQ(a, b);
}
TEST(TCalculator, can_set_infix_form_of_calculator)
{
    std::string a = "2+(3*5)";
    std::string b;
    TCalculator calc(a);
    ASSERT_NO_THROW(calc.set_infix(b));
    EXPECT_EQ(calc.get_infix(), b);
}
TEST(TCalculator, can_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";
    std::string b="235*+";
    std::string c;
    TCalculator calc(a);
    ASSERT_NO_THROW(c=calc.get_postfix());
    EXPECT_EQ(c, b);
}
TEST(TCalculator, cant_get_correct_postfix_form_of_calculator_if_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";
    std::string b = "235*+";
    std::string c;
    TCalculator calc(a);
    c = calc.get_postfix();
    EXPECT_NE(c, b);
}
TEST(TCalculator, check_expression_return_true_when_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";
    
    
    TCalculator calc(a);
    bool check;
    ASSERT_NO_THROW(check=calc.CheckExpression());
    EXPECT_EQ(1, check);
}
TEST(TCalculator, check_expression_return_false_when_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";


    TCalculator calc(a);
    bool check;
    ASSERT_NO_THROW(check = calc.CheckExpression());
    EXPECT_EQ(0, check);
}
TEST(TCalculator, can_calculate_if_the_number_of_brackets_is_correct)
{
    std::string a = "2+(3*5)";
    std::string b = "(5^2-24)+((13*13)/169+(((32-21)+2)/13))+((20000*23)/46-(10*(10*100)))";//3

    TCalculator calc(a);
    TCalculator calc2(b);

    double check, check2;
    ASSERT_NO_THROW(check = calc.CalcPostfix());
    ASSERT_NO_THROW(check2 = calc2.Calculation());
    EXPECT_EQ(17, check);
    EXPECT_EQ(3, check2);
}

TEST(TCalculator, cant_calculate_if_the_number_of_brackets_is_incorrect)
{
    std::string a = "2+((3*5)";
    std::string b = "2+(3*5)*";

    TCalculator calc(a);
    TCalculator cal2(b);
    double check,check2;
    ASSERT_ANY_THROW(check = calc.CalcPostfix());
    EXPECT_NE(17, check);
    ASSERT_ANY_THROW(check2 = calc.CalcPostfix());
    EXPECT_NE(17, check);
}

