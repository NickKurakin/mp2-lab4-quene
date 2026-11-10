#include "header.h"

#include <iostream>
#include <map>

using namespace std;


Calc::Calc()
	{
		exp = "";
		priority['('] = 0;
		priority[')'] = 0;
		priority['*'] = 1;
		priority['/'] = 1;
		priority['+'] = 2;
		priority['-'] = 2;
	}

Calc::Calc(string str)
	{
		exp = str;
		priority['('] = 0;
		priority[')'] = 0;
		priority['+'] = 1;
		priority['-'] = 1;
		priority['*'] = 2;
		priority['/'] = 2;
	}

	void Calc::input(string str)
	{
		exp = str;
	}
	string Calc::getExp()
	{
		return exp;
	}

	string Calc::toPost()
	{
		string result = "";
		Stack<char> s;
		char c;
		for (int i = 0; i < exp.length(); i++)
		{
			c = exp[i];
			switch (c)
			{
				case ' ': break;
				case '(':
				{
					s.push(c);
					break;
				}
				case ')':
				{
					while (s.get() != '(')
					{
						result += s.get();
						s.del();
					}
					s.del();
					break;
				}
				case '+': case '-': case '*': case '/':
				{
					while (s.getSize() != 0 && priority[s.get()] >= priority[c])
					{
						result += s.get();
						s.del();
					}
					s.push(c);
					break;
				}
				default:
				{
					result += c;
					break;
				}
			}
		}
		while (s.getSize() != 0)
		{
			result += s.get();
			s.del();
		}
		return result;
	}
	double Calc::calculate(const map<char, double>& values)
	{
		string post = toPost();
		Stack<double> s;
		double a;
		double b;
		char c;
		for (int i = 0; i < post.length(); i++)
		{
			c = post[i];
			switch (c)
			{
				case '+':
				{
					b = s.get(); s.del();
					a = s.get(); s.del();
					s.push(a + b);
					break;
				}
				case '-': 
				{
					b = s.get(); s.del();
					a = s.get(); s.del();
					s.push(a - b);
					break;
				}
				case '*': 
				{
					b = s.get(); s.del();
					a = s.get(); s.del();
					s.push(a * b);
					break;
				}
				case '/':
				{
					b = s.get(); s.del();
					a = s.get(); s.del();
					s.push(a / b);
					break;
				}
				default:
				{
					s.push(values.at(c));
					break;
				}
			}
		}
		return s.get();
	}