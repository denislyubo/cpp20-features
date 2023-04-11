// spaceship-operator.cpp : Defines the entry point for the application.
//

#include "spaceship-operator.h"

using namespace std;

class Value {
private:
	long id;

public:
	constexpr Value(long i) noexcept
		:id{ i } {

	}

	bool operator== (const Value& rhs) const {
		return id == rhs.id;
	}

	auto operator<=> (const Value& rhs) const {
		return id <=> rhs.id;
	}
};

int main()
{
	cout << "Hello CMake." << endl;
	Value a{ 5 }, b{ 8 };

	cout << "a is less then b " << std::boolalpha << (a < b) << endl;
	return 0;
}
