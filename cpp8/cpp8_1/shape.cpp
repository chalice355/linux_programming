// **********************************************
// 제 목 : Shape 상속 (private 멤버, 기본클래스 함수로 접근)
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
void Shape::showXY() {
    cout << "좌표 (" << x << "," << y << ")에 ";
}

void Circle::setCircle(int x, int y, int radius) {
    setXY(x, y);                    // 기본클래스 멤버함수로 x, y 설정
    this->radius = radius;
}
void Circle::show() {
    showXY();                       // 기본클래스 멤버함수로 x, y 출력
    cout << "반지름 " << radius << "인 원" << endl;
}

void Rect::setRect(int x, int y, int width, int height) {
    setXY(x, y);
    this->width = width;
    this->height = height;
}
void Rect::show() {
    showXY();
    cout << "폭" << width << ", 높이" << height << "인 직사각형" << endl;
}

void Triangle::setTriangle(int x, int y, int base, int height) {
    setXY(x, y);
    this->base = base;
    this->height = height;
}
void Triangle::show() {
    showXY();
    cout << "밑변" << base << ", 높이" << height << "인 삼각형" << endl;
}
