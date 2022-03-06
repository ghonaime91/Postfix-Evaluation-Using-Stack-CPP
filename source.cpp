#include <iostream>
#include <stack>
#include <string>
#include "infexToPostfixAndEvaluation.h"

using namespace std;



int main()
{
	string infixExp = "(3+2)+7/2*((7+3)*2)";

	//first we convert it to postfix
	string postFix = infixToPrefix(infixExp);
	cout <<"The Experssion after convertion form infix to postfix:\n\n"<< postFix << endl;

	//then we evaluate the postfix experssion = 75
	float result = postfixEvaluate(postFix);
	cout << "\n\nThe final result after evaluation:\n\n"<<result<<endl;


	system("pause>0");
}


