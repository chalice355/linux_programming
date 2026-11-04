// **********************************************
// 제 목 : Shape 상속 (protected 멤버, 파생클래스에서 직접 접근)
// 날 짜 : 2026년 11월 4일
// 작성자 : 학번 이름
// **********************************************
#include <iostream>
#include "shape.hpp"
using namespace std;

int main() {
    Circle x; Rect y; Triangle z;
    x.setCircle(0, 0, 2);
    y.setRect(1, 1, 5, 10);
    z.setTriangle(2, 2, 3, 4);
    x.show(); y.show(); z.show();
}
