// **********************************************
// 제 목 : Circle을 상속받아 이름을 추가한 NamedCircle 클래스 (실습문제 1번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "circle.hpp"
using namespace std;

Circle::Circle(int radius) {
    this->radius = radius;
}
int Circle::getRadius() {
    return radius;
}
void Circle::setRadius(int radius) {
    this->radius = radius;
}
double Circle::getArea() {
    return 3.14 * radius * radius;
}

NamedCircle::NamedCircle(int radius, string name) : Circle(radius) {
    this->name = name;
}
void NamedCircle::show() {
    cout << "반지름이 " << getRadius() << "인 " << name << endl;
}
