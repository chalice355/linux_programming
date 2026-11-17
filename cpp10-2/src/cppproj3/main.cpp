#include "max.hpp"

int main(void)
{
    MaxFinder m;
    m.input();      // 두 정수 입력
    m.findMax();    // 최대값 계산
    m.print();      // 결과 출력
    return 0;
}