// **********************************************
// 제 목 : Shape 객체 포인터를 이용한 업캐스팅/다운캐스팅
// 날 짜 : 2026년 11월 4일
// 작성자 : 학번 이름
// **********************************************
#include <iostream>
#include "shape.hpp"
using namespace std;

int main() {
    Circle x; Rect y; Triangle z;
    Shape* shape = nullptr;

    // 원
    shape = &x;                          // 업캐스팅
    shape->setXY(0, 0);                  // 기본클래스 멤버 호출
    ((Circle*)shape)->setRadius(2);      // 다운캐스팅 후 파생클래스 멤버 호출

    // 직사각형
    shape = &y;                          // 업캐스팅
    shape->setXY(1, 1);
    ((Rect*)shape)->setSize(5, 10);      // 다운캐스팅

    // 삼각형
    shape = &z;                          // 업캐스팅
    shape->setXY(2, 2);
    ((Triangle*)shape)->setSize(3, 4);   // 다운캐스팅

    // 출력
    shape = &x;
    shape->showXY();
    ((Circle*)shape)->show();

    shape = &y;
    shape->showXY();
    ((Rect*)shape)->show();

    shape = &z;
    shape->showXY();
    ((Triangle*)shape)->show();
}
