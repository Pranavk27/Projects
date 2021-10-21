#include <iostream>
#include <list>
#include <string>
#include <functional>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::function;

class Base
{
	static constexpr char pstr[5] = "abcd";
	public:
	Base(){}
	~Base() {
	cout << "Calling Base class destructor"<< endl;
	}

	static int CallFun(){int i =5; cout << pstr << endl;}

	virtual  int PrintList(list<int> &a) {}
	virtual int SetList(list<int> &a,function<void(list<int> &)> y){}
};

class Derived : public Base
{
	public:
	Derived() {}
	~Derived() {
	cout << "Calling Derived class destructor"<< endl;
	}

	public:
	int SetList(list<int> &a,function<void(list<int> &)> y)
	{
		y(a);
	}
	int PrintList(list<int> &a)
	{
		for_each(begin(a), end(a),
			       	[](decltype(*begin(a)) x){cout << x << endl;});
	}
};

int main()
{
	list<int> l = {1,2,3,4,5};
	Base *d = new Derived();
	char *p = (char *)d;
	d->SetList(l,[](list<int> &l) -> void { l.insert(l.begin(),10);});
	d->PrintList(l);
	return 0;
}
