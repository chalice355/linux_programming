// **********************************************
// 제 목 : Point를 상속받은 ColorPoint 클래스 (실습문제 4번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "point.hpp"
using namespace std;

int main() {
    ColorPoint zeroPoint;       // BLACK색에 (0,0) 위치의 점
    zeroPoint.show();

    ColorPoint cp(5, 5);
    cp.setPoint(10, 20);
    cp.setColor("BLUE");
    cp.show();
}
