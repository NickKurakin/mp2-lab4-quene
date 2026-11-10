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

	system("pause");

	return 0;
}