#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

template<typename T>
concept Iterable = requires(T p)
{
    std::declval<T>().begin()++ != std::declval<T>().end();   
};

template<typename T>
concept ClassicArray = requires(T p)
{
    p[0];
    {sizeof(p)/sizeof(*p)} -> std::convertible_to<int>;
};

template<typename T>
requires Iterable<T> || ClassicArray<T>
void print(T&& arr)
{
    std::cout << "+++++++++++++++++++++" << std::endl;
    for (auto item : arr)
    {
        std::cout << item << " " << std::endl;
    }
    std::cout << "----------------------" << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<int> coll{25, 42, 2, 0, 122, 5, 7};

    std::ranges::sort(coll);

    for (const auto& elem : std::views::take(coll, 5)) 
    {
        std::cout << elem << " " << std::endl;
    }

    auto v = coll
                | std::views::filter([] (auto elem) {return elem % 2 ==0;})
                | std::views::transform([] (auto elem) {return elem * elem;});

    print(v);

    print(std::vector<int>{1,7,9});

    int arr[3] ={1,7,9};
    print(arr);

    //print({2,4,9});
    
    return 0;
}