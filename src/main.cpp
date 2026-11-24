#include <iostream>
#include <map>

#include "header.h"

using namespace std;

void printTForwardList(TForwardList<int> l)
{
	for (int i = 0; i < l.getSize(); i++)
	{
		cout << l.get(i) << " ";
	}
	cout << endl;
}

int main()
{
	TForwardList<int> l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	TForwardList<int> l2(l);
	l.pushBack(4);
	l.pushBack(5);
	printTForwardList(l);
	printTForwardList(l2);

	l.push(6, 4);
	l2.pushFront(6);
	printTForwardList(l);
	printTForwardList(l2);

	l2 = l;
	l.Erase(3);
	l2.EraseFront();
	l2.EraseBack();
	printTForwardList(l);
	printTForwardList(l2);

	system("pause");

	return 0;
}