#include <iostream>
#include <unordered_set>
#include <functional>
using namespace std;

class Observer {
public:
	virtual void update() = 0;
};

class Subject {
public:
	void addObserver(const shared_ptr<Observer>& optr)
	{
		objs_.insert(optr);
	}
	void eraseObserver(const shared_ptr<Observer>& optr)
	{
		objs_.erase(optr);
	}
	void notify()
	{
		for (auto& iter : objs_)
		{
			iter->update();
		}
	}
private:
	unordered_set<shared_ptr<Observer>> objs_;
};




class concreteObserver
	:public Observer
{
public:
	template < typename T >
	concreteObserver(T&& str) : str_(std::forward<T>(str))
	{

	}
	virtual void update()
	{
		cout << str_ << endl;
	}
private:
	string str_;
};


int main()
{
	shared_ptr<concreteObserver> o1(new concreteObserver("heheda"));
	shared_ptr<concreteObserver> o2(new concreteObserver("papapa"));

	vector<string> datas{ "hehe1","hehe2","papa2","she", "wuyoug","yanshih" };

	Subject hehe;
	hehe.addObserver(o1);
	hehe.addObserver(o2);
	for (auto& str : datas)
	{
		hehe.addObserver(shared_ptr<concreteObserver>(new concreteObserver(str)));
	}
	hehe.notify();
	return 0;
}
