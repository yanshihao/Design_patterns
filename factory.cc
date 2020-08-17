#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Operation {
public:
	virtual double caculate(double, double) = 0;
};

class AddOperation
	: public Operation
{
	double caculate(double a, double b) { return a + b; }
};

class SubOperation
	: public Operation
{
	double caculate(double a, double b) { return a - b; }
};

class MultOperation
	: public Operation
{
	double caculate(double a, double b) { return a * b; }
};

class DivOperation
	: public Operation
{
	double caculate(double a, double b) { return a / b; }
};

shared_ptr<Operation> operationFactory(char ch)
{
	switch (ch)
	{
	case '+':
		return shared_ptr<Operation>(new AddOperation());
	case '-':
		return shared_ptr<Operation>(new SubOperation());
	case '*':
		return shared_ptr<Operation>(new MultOperation());
	case '/':
		return shared_ptr<Operation>(new DivOperation());
	default:
		break;
	}
}


int main()
{
	int num1, num2;
	char op;
	while (cin >> num1 >> op >> num2)
	{
		auto option = operationFactory(op);
		cout << option->caculate(num1, num2) << endl;
	}
	return 0;
}
