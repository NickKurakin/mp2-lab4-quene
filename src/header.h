#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <class T>
struct ListElem
{
	T elem;
	ListElem<T>* next = nullptr;
};

template <class T>
class TForwardList
{
private:
	ListElem<T>* firstElem;
	ListElem<T>* lastElem;
	size_t sz;
public:
	TForwardList()
	{
		firstElem = nullptr;
		lastElem = nullptr;
		sz = 0;
	}
	TForwardList(const TForwardList& l)
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
	TForwardList(const std::vector<T>& v)
	{
		firstElem = nullptr;
		lastElem = nullptr;
		sz = 0;
		for (size_t i = 0; i < v.size(); i++)
		{
			pushBack(v[i]);
		}
	}
	~TForwardList()
	{
		clear();
	}

	void clear()
	{
		while (firstElem != nullptr) {
			ListElem<T>* tmp = firstElem;
			firstElem = tmp->next;
			delete tmp;
		}
		lastElem = nullptr;
	}

	bool isEmpty()
	{
		return sz == 0;
	}

	TForwardList& operator=(const TForwardList& l)
	{
		if (this == &l) return *this;

		clear();

		ListElem<T>* tmp = l.firstElem;
		for (size_t i = 0; i < l.sz; i++)
		{
			pushBack(tmp->elem);
			tmp = tmp->next;
		}
		return *this;
	}

	void pushFront(T el)
	{
		ListElem<T>* newElem = new ListElem<T>;
		newElem->elem = el;
		newElem->next = firstElem;
		firstElem = newElem;
		if (isEmpty())
		{
			lastElem = newElem;
		}
		sz++;
	}

	void pushBack(T el)
	{
		ListElem<T>* newElem = new ListElem<T>;
		newElem->elem = el;
		if (isEmpty())
		{
			firstElem = newElem;
			lastElem = newElem;
		}
		else
		{
			lastElem->next = newElem;
			lastElem = newElem;
		}
		sz++;
	}
	void push(T el, size_t pos)
	{
		if (pos > sz) throw pos;
		else if (pos == 0) pushFront(el);
		else if (pos == sz) pushBack(el);
		else
		{
			ListElem<T>* newElem = new ListElem<T>;
			newElem->elem = el;

			ListElem<T>* tmp = firstElem;
			for (size_t i = 0; i < pos-1; i++) tmp = tmp->next;

			newElem->next = tmp->next;
			tmp->next = newElem;

			sz++;
		}
	}

	size_t getSize() const
	{
		return sz;
	}

	T getFront() const
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

	void EraseFront()
	{
		if (isEmpty()) throw 0;
		ListElem<T>* tmp = firstElem;
		firstElem = tmp->next;
		delete tmp;
		sz--;
		if (isEmpty())
		{
			lastElem = nullptr;
		}
	}

	void EraseBack()
	{
		if (isEmpty()) throw 0;
		ListElem<T>* tmp = lastElem;
		lastElem = nullptr;
		delete tmp;
		sz--;
		if (isEmpty())
		{
			firstElem = nullptr;
		}
		else
		{
			ListElem<T>* tmp = firstElem;
			while (tmp->next != nullptr) tmp = tmp->next;
			lastElem = tmp;
		}
	}
	void Erase(size_t pos)
	{
		if (pos >= sz) throw pos;
		else if (pos == 0) EraseFront();
		else if (pos == sz-1) EraseBack();
		else
		{
			ListElem<T>* tmp = firstElem;
			for (size_t i = 0; i < pos-1; i++) tmp = tmp->next;

			ListElem<T>* tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			delete tmp2;

			sz--;
		}
	}
};

template <class T>
class Quene
{
private:
	TForwardList<T> list;
public:
	Quene() : list() {}
	Quene(const TForwardList<T>& l) : list(l) {}
	Quene(const Quene& q) : list(q.list) {}

	Quene& operator=(const Quene& q)
	{
		list = q.list;
		return *this;
	}

	size_t getSize()
	{
		return list.getSize();
	}

	void push(T el)
	{
		list.pushBack(el);
	}

	T get()
	{
		if (list.getSize() == 0) throw 0;
		return list.getFront();
	}
	
	void del()
	{
		if (list.getSize() == 0) throw 0;
		list.EraseFront();
	}
};