/*
  Infix to postfix conversion in C++ 
  Input Postfix expression must be in a desired format. 
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', and '/' operators are expected. 
*/
#include<bits/stdc++.h>
using namespace std;
char s[100];
int top=-1;
//Function to verify whether a character is alphanumeric chanaracter (letter or numeric digit) or not.
bool isoperand(char c)			
{
	if(c>='a'&&c<='z')
		return true;
	if(c>='A'&&c<='Z')
		return true;
	if(c>='0'&&c<='9')
		return true;
	else
		return false;
}
bool isoperator(char c)			// Function to verify whether a character is operator symbol or not.
{
	if(c=='+'||c=='*'||c=='/'||c=='-')
		return true;
	else
		return false;
}
// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int opweight(char c)
{
	if(c=='*'||c=='/')
		return 2;
	if(c=='+'||c=='-')
		return 1;
}
bool HasHigherPrec(char a, char b)			// Function to verify whether an operator has higher precedence over other
{
	int op1=opweight(a);
	int op2=opweight(b);
	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1==op2)
	{
		if(a=='$')   //if operator is right-asspciative
			return false;
		else
			return true;
	}
	if(op1>op2)
		return true;
	else
		return false;
}
void InfixToPostfix(string exp)			// Function to convert Infix expression to postfix 
{
	string res="";			// Initialize postfix as empty string.
	for(int i=0;i<exp.length();i++)
	{
		// Scanning each character from left. 
		// If character is a delimitter, move on. 
		if(exp[i] == ' ' || exp[i] == ',') 
			continue; 
		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		if(isoperator(exp[i]))
		{
			while(top!=-1&&HasHigherPrec(s[top],exp[i]))
			{
				res=res+s[top];
				top--;
			}
			top++;
			s[top]=exp[i];			
		}
		// Else if character is an operand
		else if(isoperand(exp[i]))
		{
			res=res+exp[i];
		}
	}
	while(top!=-1)
	{
		res=res+s[top];
		top--;
	}
	cout<<"Postfix notation : "<<res;
}
int main()
{
	cout<<"Enter infix notation : ";
	string exp;
	getline(cin,exp);
	InfixToPostfix(exp);
}
