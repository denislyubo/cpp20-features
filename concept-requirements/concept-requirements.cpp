// concept-requirements.cpp : Defines the entry point for the application.
//

#include "concept-requirements.h"

using namespace std;

template<typename T>
concept IsPointer = requires(T p) {
	*p;
	p == nullptr;
	{p < p} -> std::convertible_to<bool>;
};


auto maxValue(auto a, auto b)
{
	return b < a ? a : b;
}


auto maxValue(IsPointer auto a, IsPointer auto b)
requires std::three_way_comparable_with<decltype(*a), decltype(*b)>
{
	return maxValue(*a, *b);
}

int main()
{
	int x = 42;
	int y = 77;
	cout << maxValue(x, y) << endl;

	int* xp = &x;
	int* yp = &y;
	cout << maxValue(&xp, &yp) << endl;

	double d = 49.9;
	std::cout << maxValue(xp, &d) << endl;

	return 0;
}
