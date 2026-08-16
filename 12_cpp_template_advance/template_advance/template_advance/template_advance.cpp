#include <iostream>

using namespace std;

template<size_t N = 2>
class Stack
{
private:
	int _a[N];
	int _top;
	int _size;
};




int main()
{
	Stack<> st0;
	Stack<5> st1;
	Stack<10> st2;

	return 0;
}