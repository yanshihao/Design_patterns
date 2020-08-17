#include <iostream>
#include <functional>
using namespace std;

class Contex {
public:
	template <typename T>
	Contex( T&& func ): func_( std::forward<T>(func) )
	{
	}

	void getResult()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << func_(i, i) << endl;
		}
	}

private:
	std::function<int(int, int)> func_;
};


int main()
{
	Contex c([](int a, int b) { return a + b; });
	c.getResult();
	cout << "*******************************************" << endl;
	Contex d([](int a, int b) { return 3 * a + 4 * b; });
	d.getResult();
	return 0;
}
