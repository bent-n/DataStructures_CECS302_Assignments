//William Benton Parrish
//10-11-15
//Assignment 3
//Question 3

//Write a program to evaluate a postfix expression.

#include<stack>
#include<string>
#include<iostream>
using namespace std;
bool isOperator(char);
bool isNum(char);
double eval(double,double,char);



double postExpEval(string expression)
{
	int length=expression.length();
    stack <double> operands;
    //stack <char> operands;
    char c;
	for(int i=0;i<length;i++)
	{
		c=expression[i];
		if(c==' '||c==',')
		 continue;
		if(isNum(c))
		{
			operands.push(c-'0');
			
		}
		if(isOperator(c))
		{
			double op1=operands.top();
			operands.pop();
			double op2=operands.top();
			double result=eval(op1,op2,c);
			operands.push(result);	
			if(i==length-1)
			 return result;
		}
		
	}
	
	
	
	
}

bool isNum(char c)
{
	if(c>='0'&&c<='9')
		return 1;
	return 0;
}

bool isOperator(char c)
{
	if(c=='*'||c=='+'||c=='-'||c=='/')
		return 1;
	return 0;
}

double eval(double operand1, double operand2, char operation)
{
	if(operation=='*')
		return operand1*operand2;
	else if(operation=='+')
		return operand1+operand2;
	else if(operation=='-')
		return operand1-operand2;
	else if(operation=='/')
		return operand1/operand2;
}

int main()
{
	string expression="91+";
	double result=postExpEval(expression);
	cout<<result;
	
	
	
}
