/*
  Evaluation Of postfix Expression in C++ 
  Input Postfix expression must be in a desired format. 
  Operands must be integers and there should be space in between two operands.
  Only '+'  ,  '-'  , '*' and '/'  operators are expected. 
*/
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int s[100];
int top= -1;
bool isoperator(char c)		// Function to verify whether a character is operator symbol or not. 
{
	if(c=='+'||c=='/'||c=='*'||c=='-')
		return true;
	else
		false;
}
int performe_operation(int operend1,int operend2,char op)	// Function to perform an operation and return output. 
{
	if(op== '+')
		return(operend1+operend2);
	else if(op=='-')
		return(operend1-operend2);
	else if(op=='/')
		return(operend1/operend2);
	else if(op=='*'){
		return(operend1*operend2);
	}
	else
		cout<<"unexpected error!!!";
	return false;
}
bool isnumeric(char C)	// Function to verify whether a character is numeric digit. 
{	
	if(C >= '0' && C <= '9')
		return true;
	else
	    return false;
}
int Evaluate_postfix(string exp)	// Function to evaluate Postfix expression and return output
{
	for(int i=0;i<exp.length();i++)
	{
		// Scanning each character from left. 
		// If character is a delimitter, move on.
		if(exp[i]==' '||exp[i]==',')
		{
			continue;
		}
		else if(isnumeric(exp[i]))
		{
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit.
			int operand=0;
			while(isnumeric(exp[i]))
			{
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit.
				operand=(operand*10)+(exp[i]-'0');
				i++;
			}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
			i--;
			top++;
			// Push operand on stack.
			s[top]=operand;
		}
		// If character is operator, pop two elements from stack, perform operation and push the result back.
		else if(isoperator(exp[i]))
		{
			int operend2= s[top];
			top--;
			int operend1= s[top];
			top--;
			int result;
			result=performe_operation(operend1,operend2,exp[i]);
			top++;
			s[top]=result;
		}
		
	}
	// If expression is in correct format, Stack will finally have one element. This will be the output. 
	return s[top];
}
int main()
{
	cout<<"Enter the expression : ";
	string exp;
	getline(cin,exp);
	int result=Evaluate_postfix(exp);
	cout<<endl<<"The output is : "<<result;
}
