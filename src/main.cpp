#include <iostream>
#include <map>

#include "header.h"

using namespace std;

void printList(List<int> l)
{
	for (int i = 0; i < l.getSize(); i++)
	{
		cout << l.get(i) << " ";
	}
	cout << endl;
}

int main()
{
	List<int> l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	List<int> l2(l);
	l.pushBack(4);
	l.pushBack(5);
	printList(l);
	printList(l2);

	l.push(6, 4);
	l2.pushFirst(6);
	printList(l);
	printList(l2);

	l2 = l;
	l.del(3);
	l2.delFirst();
	l2.delBack();
	printList(l);
	printList(l2);

	Stack<int> s(l2);
	int tmp = s.getSize();
	for (int i = 0; i < tmp; i++)
	{
		cout << s.get() << " ";
		s.del();
	}
	cout << endl;

	Stack<int> s2;
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.get();
	tmp = s2.getSize();
	for (int i = 0; i < tmp; i++)
	{
		cout << s2.get() << " ";
		s2.del();
	}
	cout << endl;

	map<char, double> values;
	values['a'] = 1;
	values['b'] = 2;
	values['c'] = 3;
	values['d'] = 4;

	Calc exp("a + b");
	cout << exp.toPost() << endl;
	cout << exp.calculate(values) << endl;
	exp.input("a+b*c");
	cout << exp.toPost() << endl;
	cout << exp.calculate(values) << endl;
	exp.input("a+b-c+d");
	cout << exp.toPost() << endl;
	cout << exp.calculate(values) << endl;
	exp.input("(a+b)*(c-d)");
	cout << exp.toPost() << endl;
	cout << exp.calculate(values) << endl;
	exp.input("a-(b+c)*d");
	cout << exp.toPost() << endl;
	cout << exp.calculate(values) << endl;


	system("pause");

	return 0;
}