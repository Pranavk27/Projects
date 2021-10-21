#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::vector;
using std::string;
using std::cout;
using std::unique_ptr;


void throwexcept() 
{
	throw;
}
template <class T>
class Vec : public vector<T>
{
	public:
	Vec(std::initializer_list<T> a) {
		for(auto x: a)
			this->push_back(x);
	}
	~Vec() {
		cout << "Destructing" << '\n';
	}
	void Print()
	{
		cout<<"Fun"<<'\n';
	}
};
class resOwner {
	std::shared_ptr<Vec<string>> res;
	//Vec<string> res;
	public:
	resOwner() : res(new Vec<string>({"new", "string" , "in", "list"})) {
	//resOwner() : res({"new", "string" , "in", "list"}) {
		std::cout << "Map some huge resources\n";
		throw "hi";
		// res will be destroyed even though exception happened
	}
	~resOwner() {
		// nothing need to do here
	}
};

int main() noexcept(true)
{
	resOwner r;
	//unique_ptr<Vec<string>> oV (new Vec<string>({"new", "string" , "in", "list"}));
	//Vec<string> oV = {"new", "string" , "in", "list"};
	//oV->Print();
	//throwexcept();
//	for(auto x : oV)
//		cout << x << '\n';
	return 0;
}
