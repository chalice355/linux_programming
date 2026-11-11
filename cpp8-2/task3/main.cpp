// **********************************************
// 제 목 : 기본클래스 생성자를 명시적으로 지정하는 Shape 상속
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "shape.hpp"
using namespace std;

int main() {
    Circle x(0, 0, 2);
    Rect y(1, 1, 5, 10);
    Triangle z(2, 2, 5, 10);
    x.show();
    y.show();
    z.show();
}
