#include <iostream>

template<typename T>
class TD;

template<typename T>
void f(T& param)
{  
}

template<typename T>
void g(T&& param)
{  
}

template<typename T>
void m(T param)
{  
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&) [N]) noexcept
{
    return N;
}

int main() 
{
    std::cout << "Hello" << std::endl;

    const int theAnswer = 42;
    auto xx = theAnswer;
    auto yy = &theAnswer;

    //TD<decltype(x)> cType;
    //TD<decltype(y)> yType;

    std::cout << typeid(xx).name() << '\n';
    std::cout << typeid(yy).name() << '\n';

    int x = 27;
    const int cx = x;
    const int& rx = x;

    f(x);
    f(cx);
    f(rx);

    g(x);
    g(cx);
    g(rx);
    g(27);

    m(x);
    m(cx);
    m(rx);
    m(27);

    const char name[] = "Briggs";
    const char* ptrToName = name;

    f(name);
    f(ptrToName);

    m(name);
    m(ptrToName);

    int keyVals[] = {1, 3, 7, 9, 11, 22, 35};
    std::cout <<"Array size: " << arraySize(keyVals) << std::endl;

    return 0;
}