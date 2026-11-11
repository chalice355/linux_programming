// **********************************************
// 제 목 : 기본클래스 생성자를 명시적으로 지정하는 Shape 상속
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "shape.hpp"
using namespace std;

Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
    cout << "Shape생성 , ";
}
Shape::~Shape() {
    cout << "Shape소멸" << endl;
}
void Shape::showXY() {
    cout << "좌표 (" << x << "," << y << ")에 ";
}

Circle::Circle(int x, int y, int radius) : Shape(x, y) {
    this->radius = radius;
    cout << "Circle생성" << endl;
}
Circle::~Circle() {
    cout << "Circle소멸 , ";
}
void Circle::show() {
    showXY();
    cout << "반지름 " << radius << "인 원" << endl;
}

Rect::Rect(int x, int y, int width, int height) : Shape(x, y) {
    this->width = width;
    this->height = height;
    cout << "Rect생성" << endl;
}
Rect::~Rect() {
    cout << "Rect소멸 , ";
}
void Rect::show() {
    showXY();
    cout << "폭" << width << ", 높이" << height << "인 직사각형" << endl;
}

Triangle::Triangle(int x, int y, int base, int height) : Shape(x, y) {
    this->base = base;
    this->height = height;
    cout << "Triangle생성" << endl;
}
Triangle::~Triangle() {
    cout << "Triangle소멸 , ";
}
void Triangle::show() {
    showXY();
    cout << "밑변" << base << ", 높이" << height << "인 삼각형" << endl;
}
