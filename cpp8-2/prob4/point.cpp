// **********************************************
// 제 목 : Point를 상속받은 ColorPoint 클래스 (실습문제 4번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "point.hpp"
using namespace std;

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
int Point::getX() {
    return x;
}
int Point::getY() {
    return y;
}
void Point::move(int x, int y) {
    this->x = x;
    this->y = y;
}

ColorPoint::ColorPoint(int x, int y, string color) : Point(x, y) {
    this->color = color;
}
void ColorPoint::setPoint(int x, int y) {
    move(x, y);                 // protected 멤버함수이므로 파생클래스에서 호출 가능
}
void ColorPoint::setColor(string color) {
    this->color = color;
}
void ColorPoint::show() {
    cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
}
