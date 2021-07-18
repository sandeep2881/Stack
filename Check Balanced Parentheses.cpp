/*
  C++ Program to check for balanced parentheses in an expression using stack.
  Given an expression as string comprising of opening and closing characters
  of parentheses - (), curly braces - {} and square brackets - [], we need to 
  check whether symbols are balanced or not. 
*/

#include<bits/stdc++.h>
using namespace std;
char s[1000];
int top=-1;

// Function to check whether two characters are opening 
// and closing of same type. 
bool check_pair(char open,char close)
{
	if(open=='('&&close==')')
		return true;
	else if(open=='{'&&close=='}')
		return true;
	else if(open=='['&&close==']')
		return true;
	else
		return false;
}
bool check_parentheses(string exp)
{
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
		{
			top++;
			s[top]=exp[i];
		}
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
		{
			if((top==-1)|| !check_pair(s[top],exp[i]))
				return false;
			else
				top--;
		}
	}
	if(top==-1)
		return true;
}
int main(){
	string exp;
	cout<<"enter a string "<<endl;
	cin>>exp;
	if(check_parentheses(exp))
		cout<<"BALANCED!!!";
	else
		cout<<"UNBALANCED!!!";
}

