// **********************************************
// 제 목 : 기본클래스 생성자를 명시적으로 지정하는 Shape 상속
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

class Shape {
private:
    int x, y;                   // 위치좌표 (private)
public:
    Shape(int x, int y);
    ~Shape();
    void showXY();
};

class Circle : public Shape {
    int radius;
public:
    Circle(int x, int y, int radius);
    ~Circle();
    void show();
};

class Rect : public Shape {
    int width, height;
public:
    Rect(int x, int y, int width, int height);
    ~Rect();
    void show();
};

class Triangle : public Shape {
    int base, height;
public:
    Triangle(int x, int y, int base, int height);
    ~Triangle();
    void show();
};

#endif
