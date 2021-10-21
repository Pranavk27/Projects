#include <iostream>
using namespace std;

class Singleton{
	private:
		static Singleton* single;
		Singleton(int value) { val = value;}
		int val;
		Singleton(const Singleton&){}
	public:
		static Singleton* GetInstance(int value)
		{
			if(single == NULL)
			{
				single = new Singleton(value);
			}
			return single;
		}
		void print()
		{
			cout << "In same class "  <<  val << endl;
		}
};

Singleton* Singleton::single = NULL;

int main()
{
	Singleton* s = Singleton::GetInstance(2);
	Singleton* p = Singleton::GetInstance(3);
	s->print();
	p->print();
	return 0;
}

