#include <iostream>
#include <map>

using namespace std;

template <class T>
struct ListElem
{
	T elem;
	ListElem<T>* next = nullptr;
	ListElem<T>* previous = nullptr;
};

template <class T>
class List
{
private:
	ListElem<T>* firstElem;
	ListElem<T>* lastElem;
	size_t sz;
public:
	List()
	{
		firstElem = nullptr;
		lastElem = nullptr;
		sz = 0;
	}
	List(const List& l)
	{
		firstElem = nullptr;
		lastElem = nullptr;
		sz = 0;
		ListElem<T>* tmp = l.firstElem;
		for (size_t i = 0; i < l.sz; i++)
		{
			pushBack(tmp->elem);
			tmp = tmp->next;
		}
	}
	~List()
	{
		while (firstElem != nullptr) {
			ListElem<T>* tmp = firstElem;
			firstElem = tmp->next;
			delete tmp;
		}
	}

	List& operator=(const List& l)
	{
		if (this == &l) return *this;

		while (firstElem != nullptr)
		{
			delBack();
		}

		ListElem<T>* tmp = l.firstElem;
		for (size_t i = 0; i < l.sz; i++)
		{
			pushBack(tmp->elem);
			tmp = tmp->next;
		}
		return *this;
	}

	void pushFirst(T el)
	{
		ListElem<T>* newElem = new ListElem<T>;
		newElem->elem = el;
		if (sz == 0)
		{
			firstElem = newElem;
			lastElem = newElem;
		}
		else
		{
			firstElem->previous = newElem;
			newElem->next = firstElem;
			firstElem = newElem;
		}
		sz++;
	}

	void pushBack(T el)
	{
		ListElem<T>* newElem = new ListElem<T>;
		newElem->elem = el;
		if (sz == 0)
		{
			firstElem = newElem;
			lastElem = newElem;
		}
		else
		{
			lastElem->next = newElem;
			newElem->previous = lastElem;
			lastElem = newElem;
		}
		sz++;
	}
	void push(T el, size_t pos)
	{
		if (pos > sz) throw pos;
		else if (pos == 0) pushFirst(el);
		else if (pos == sz) pushBack(el);
		else
		{
			ListElem<T>* newElem = new ListElem<T>;
			newElem->elem = el;

			ListElem<T>* tmp = firstElem;
			for (size_t i = 0; i < pos; i++) tmp = tmp->next;

			newElem->previous = tmp->previous;
			newElem->next = tmp;
			tmp->previous->next = newElem;
			tmp->previous = newElem;

			sz++;
		}
	}

	size_t getSize() const
	{
		return sz;
	}

	T getFirst() const
	{
		if (sz == 0) throw 0;
		return firstElem->elem;
	}
	T getBack() const
	{
		if (sz == 0) throw 0;
		return lastElem->elem;
	}
	T get(size_t pos) const
	{
		if (pos >= sz) throw pos;

		ListElem<T>* tmp = firstElem;
		for (size_t i = 0; i < pos; i++) tmp = tmp->next;

		return tmp->elem;
	}

	void delFirst()
	{
		if (sz == 0) throw 0;
		if (sz == 1)
		{
			ListElem<T>* tmp = firstElem;
			delete tmp;
			firstElem = nullptr;
			lastElem = nullptr;
		}
		else
		{
			ListElem<T>* tmp = firstElem;
			firstElem = tmp->next;
			firstElem->previous = nullptr;
			delete tmp;
		}
		sz--;
	}

	void delBack()
	{
		if (sz == 0) throw 0;
		if (sz == 1)
		{
			ListElem<T>* tmp = lastElem;
			delete tmp;
			firstElem = nullptr;
			lastElem = nullptr;
		}
		else
		{
			ListElem<T>* tmp = lastElem;
			lastElem = tmp->previous;
			lastElem->next = nullptr;
			delete tmp;
		}

		sz--;
	}
	void del(size_t pos)
	{
		if (pos >= sz) throw pos;
		else if (pos == 0) delFirst();
		else if (pos == sz-1) delBack();
		else
		{
			ListElem<T>* tmp = firstElem;
			for (size_t i = 0; i < pos; i++) tmp = tmp->next;

			tmp->previous->next = tmp->next;
			tmp->next->previous = tmp->previous;
			delete tmp;

			sz--;
		}
	}
};

template <class T>
class Stack
{
private:
	List<T> list;
public:
	Stack() : list() {}
	Stack(const List<T>& l) : list(l) {}
	Stack(const Stack& s) : list(s.list) {}

	Stack& operator=(const Stack& s)
	{
		list = s.list;
		return *this;
	}

	size_t getSize()
	{
		return list.getSize();
	}

	void push(T el)
	{
		list.pushFirst(el);
	}

	T get()
	{
		if (list.getSize() == 0) throw 0;
		return list.getFirst();
	}
	
	void del()
	{
		if (list.getSize() == 0) throw 0;
		list.delFirst();
	}
};

class Calc
{
private:
	string exp;
	map<char, int> priority;
public:
	Calc();
	Calc(string str);

	void input(string str);
	string getExp();

	string toPost();
	double calculate(const map<char,double>&);
};