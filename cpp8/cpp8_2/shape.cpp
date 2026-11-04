// **********************************************
// 제 목 : Shape 객체 포인터를 이용한 업캐스팅/다운캐스팅
// 날 짜 : 2026년 11월 4일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "shape.hpp"
using namespace std;

void Shape::setXY(int x, int y) {
    this->x = x;
    this->y = y;
}
void Shape::showXY() {
    cout << "좌표 (" << x << "," << y << ")에 ";
}

void Circle::setRadius(int radius) {
    this->radius = radius;
}
void Circle::show() {
    cout << "반지름 " << radius << "인 원" << endl;
}

void Rect::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}
void Rect::show() {
    cout << "폭" << width << ", 높이" << height << "인 직사각형" << endl;
}

void Triangle::setSize(int base, int height) {
    this->base = base;
    this->height = height;
}
void Triangle::show() {
    cout << "밑변" << base << ", 높이" << height << "인 삼각형" << endl;
}
