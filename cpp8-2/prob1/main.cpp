// **********************************************
// 제 목 : Circle을 상속받아 이름을 추가한 NamedCircle 클래스 (실습문제 1번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "circle.hpp"
using namespace std;

int main() {
    NamedCircle waffle(3, "waffle");  // 반지름이 3이고 이름이 waffle인 원
    waffle.show();
}
