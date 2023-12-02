#include "Calculator.h"
//#include "../Google Test2/pch.h"


bool TCalculator::CheckExpression()
{
    if (c.Empty() == false)
    {
        this->c.Clear();
    }
    int res = 0;
    for (int i = 0; i < inf.size(); i++)
    {
        if (inf[i] == '(')
        {
            c.Push(inf[i]);
        }
        if (inf[i] == ')')
        {
            if (!c.Empty())
            {
                c.Pop();
            }
            else
                res = 1;
        }
    }
    if (!c.Empty())
        res = 1;
    if (res == 0)
    {
        return true;
    }
    else
        return false;
}

double TCalculator::Calculation()
{
    c.Clear(); d.Clear();
    std::string str = '(' + inf + ')';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') c.Push(str[i]);
        if (str[i] == ')')
        {
            if (c.Empty())
            {
                throw "STACK IS EMPTY";
            }
            char el = c.Pop();
            while (el != '(')
            {
                double x2 = d.Pop();
                double x1 = d.Pop();
                double y = 0;
                if (el == '+')
                {
                    y = x1 + x2;
                }
                if (el == '-')
                {
                    y = x1 - x2;
                }
                if (el == '*')
                {
                    y = x1 * x2;
                }
                if (el == '/')
                {
                    y = x1 / x2;
                }
                if (el == '^')
                {
                    y = pow(x1,x2);
                }
                d.Push(y); 
                if (c.Empty())
                {
                    throw"STACK IS EMPTY";
                }
                el = c.Pop();


            }
        }
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            size_t pos;
            double x = std::stod(&str[i], &pos);
            d.Push(x);
            i = i + pos - 1;

        }
        if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
        {
            if (c.Empty())
            {
                throw"STACK IS EMPTY";
            }
            
            char el = c.Pop();
            while (prioritet(el) >= prioritet(str[i]))
            {
                double y;
                double x2 = d.Pop();
                double x1 = d.Pop();
                if (el == '+')
                {
                    y = x1 + x2;
                }
                if (el == '-')
                {
                    y = x1 - x2;
                }
                if (el == '*')
                {
                    y = x1 * x2;
                }
                if (el == '/')
                {
                    y = x1 / x2;
                }
                if (el == '^')
                {
                    y = pow(x1, x2);
                }
                d.Push(y);
                if (c.Empty())
                {
                    throw"STACK IS EMPTY";
                }
                el = c.Pop();
            }
            c.Push(el);
            c.Push(str[i]);
        }

    }
    double res = d.Pop();
    if (!d.Empty())
    {
        throw "Extra number";
    }
    if (!c.Empty())
    {
        throw "Extra operation";
    }
    return res;
}

void TCalculator::set_infix(std::string str)
{
    inf = str;
}

std::string TCalculator::get_postfix()
{
    return postf;
}

std::string TCalculator::get_infix()
{
    return inf;
}

double TCalculator::CalcPostfix()
{
    if (d.Empty() == false)
    {
        this->d.Clear();
    }
    for (int i = 0; i < postf.length(); i++)
    {
        if (postf[i] >= '0' && postf[i] <= '9')
        {
            d.Push(postf[i] - '0');
        }
        
        
        if ((postf[i] == '+') || (postf[i] == '-') || (postf[i] == '*') || (postf[i] == '/') || (postf[i] == '^'))
        {
                double x1 = 0; double x2 = 0;double  y = 0;
                if (d.Empty() == false)
                {
                    x2 = d.Pop();
                }
                if (d.Empty() == false)
                {
                    x1 = d.Pop();
                }
                if (postf[i] == '+')
                    y = x1 + x2;
                if (postf[i] == '-')
                    y = x1 - x2;//вопрос
                if (postf[i] == '*')
                    y = x1 * x2;
                if (postf[i] == '/')
                    y = x1 / x2;
                if (postf[i] == '^')
                    y = pow(x1, x2);

                d.Push(y);

        }
        
    }
    double res;
    if(d.Empty()==false)
    {
        res = d.Pop();
    }
    else
    {
        throw "stack is empty";
    }

    
    if (!d.Empty())
    {
        throw "problems with res";
    }
   return res;
}

void TCalculator::ToPostfix()
{
    //if (CheckExpression() == 0)
    //{
    //    throw "the_number_of_brackets_is_incorrect";
    //}
    if (c.Empty() == false)
    {
        this->c.Clear();
    }
    std::string str = '(' + inf + ')';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            c.Push('(');
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            postf += str[i];
        }
        if (str[i] == ')')
        {
            char opelement = c.Pop();
            while (opelement!='(')
            {
                postf += opelement;
                opelement = c.Pop();
            }
        }
        if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/') || (str[i] == '^'))
        {
            char opelement = c.Pop();
            /*while (prioritet(opelement) >= prioritet(str[i]))
            {
                postf += opelement;
                opelement = c.Pop();
            }*/
            while(prioritet(opelement) >= prioritet(str[i]))
            {
                postf += opelement;
                opelement = c.Pop();
            }
            c.Push(opelement);
            c.Push(str[i]);
        }


    }

}



