#include <iostream>
#include <stack>
#include <string>
#include "infexToPostfixAndEvaluation.h"
using namespace std;


int priority(char c)
{
    if (c == '-' || c == '+')
        return 1;

    else if (c == '*' || c == '/')
        return 2;

    else if (c == '^')
        return 3;

    else
        return 0;
}

//-----------------------------------------------------

string infixToPrefix(string exp)
{
    stack<char> stk;
    string outPut = "";

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ') continue;

        else if (isdigit(exp[i]) || isalpha(exp[i]))
            outPut += exp[i];

        else if (exp[i] == '(')
            stk.push(exp[i]);

        else if (exp[i] == ')')
        {
            while (stk.top() != '(')
            {
                outPut += stk.top();
                stk.pop();
            }
            stk.pop();
        }

        else
        {
            while (!stk.empty() && priority(exp[i]) <= priority(stk.top()))
            {
                outPut += stk.top();
                stk.pop();
            }

            stk.push(exp[i]);
        }

    }

    while (!stk.empty())
    {
        outPut += stk.top();
        stk.pop();
    }

    return outPut;
}

//-----------------------------------------------------

float mathOperation(float operand1, float operand2, char theOperator)
{
    if (theOperator == '+')
        return operand1 + operand2;

    else if (theOperator == '-')
        return operand1 - operand2;

    else if (theOperator == '*')
        return operand1 * operand2;

    else if (theOperator == '/')
        return operand1 / operand2;

    else
        return 0;
}

//-----------------------------------------------------

float postfixEvaluate(string exp)
{
    stack<float> stk;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isdigit(exp[i]))
            stk.push(exp[i] - '0');
        else
        {
            float op2 = stk.top();
            stk.pop();

            float op1 = stk.top();
            stk.pop();

            float result = mathOperation(op1,op2,exp[i]);

            stk.push(result);
        }
    }

    return stk.top();
}

//-----------------------------------------------------
