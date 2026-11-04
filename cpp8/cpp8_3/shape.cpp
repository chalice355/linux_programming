// **********************************************
// 제 목 : Shape 상속 (protected 멤버, 파생클래스에서 직접 접근)
// 날 짜 : 2026년 11월 4일
// 작성자 : 학번 이름
// **********************************************
#include <iostream>
#include "shape.hpp"
using namespace std;

void Shape::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}

void Circle::setCircle(int x, int y, int radius) {
    this->x = x;                    // protected이므로 파생클래스에서 직접 접근
    this->y = y;
    this->radius = radius;
}
void Circle::show() {
    cout << "좌표 (" << x << "," << y << ")에 반지름 " << radius << "인 원" << endl;
}

void Rect::setRect(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
void Rect::show() {
    cout << "좌표 (" << x << "," << y << ")에 폭" << width << ", 높이" << height << "인 직사각형" << endl;
}

void Triangle::setTriangle(int x, int y, int base, int height) {
    this->x = x;
    this->y = y;
    this->base = base;
    this->height = height;
}
void Triangle::show() {
    cout << "좌표 (" << x << "," << y << ")에 밑변" << base << ", 높이" << height << "인 삼각형" << endl;
}
