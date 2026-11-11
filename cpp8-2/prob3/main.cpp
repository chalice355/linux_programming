// **********************************************
// 제 목 : Point를 상속받은 ColorPoint 클래스 (실습문제 3번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "point.hpp"
using namespace std;

int main() {
    ColorPoint cp(5, 5, "RED");
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show();
}
