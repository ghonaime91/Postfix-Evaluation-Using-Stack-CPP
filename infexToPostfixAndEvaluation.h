#pragma once
#include <iostream>
#include <string>

using std::string;

int priority(char c);
string infixToPrefix(string exp);
float mathOperation(float operand1,float operand2,char theOperator);
float postfixEvaluate(string exp);