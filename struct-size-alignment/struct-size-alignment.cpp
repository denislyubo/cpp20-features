#include <iostream>

struct SampleStructPack1
{
    bool flag;
    unsigned int timeout;
};

struct weekdays {
    u_char sunday:1;
    u_char monday:2;
    u_char friday:3;
    u_char saturday:4;
};

struct weekdaysflag {
    u_char sunday:1;
    u_char monday:2;
    u_char friday:3;
    bool flag;
};

typedef struct {
    u_char sunday:1;
} oneday;

typedef struct {
    u_char sunday:1;
    u_char monday:2;
} twoday;

typedef struct {
    u_char sunday:1;
    u_char monday:2;
    u_char friday:3;
} threday;


int main(int argc, char* argv[])
{
    std::cout << "Sizeof weekdays: " << sizeof(weekdays) << std::endl;
    std::cout << "Alignof weekdays: " << alignof(weekdays) << std::endl;

    std::cout << "Sizeof weekdaysflag: " << sizeof(weekdaysflag) << std::endl;
    std::cout << "Sizeof weekdaysflag::fag: " << sizeof(weekdaysflag::flag) << std::endl;
    std::cout << "Alignof weekdaysflag: " << alignof(weekdaysflag) << std::endl;

    std::cout << "Sizeof oneday: " << sizeof(oneday) << std::endl;
    std::cout << "Alignof oneday: " << alignof(oneday) << std::endl;

    std::cout << "Sizeof twoday: " << sizeof(twoday) << std::endl;
    std::cout << "Alignof twoday: " << alignof(twoday) << std::endl;

    std::cout << "Sizeof threday: " << sizeof(threday) << std::endl;
    std::cout << "Alignof threday: " << alignof(threday) << std::endl;

    weekdays day;
    std::cout << "Sizeof char : " << sizeof(u_char) << std::endl;
}