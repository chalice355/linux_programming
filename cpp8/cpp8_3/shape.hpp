// **********************************************
// 제 목 : Shape 상속 (protected 멤버, 파생클래스에서 직접 접근)
// 날 짜 : 2026년 11월 4일
// 작성자 : 학번 이름
// **********************************************
#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

class Shape {
protected:
    int x, y;                       // 위치좌표 (protected)
public:
    void setXY(int x, int y);
};

class Circle : public Shape {
    int radius;
public:
    void setCircle(int x, int y, int radius);
    void show();
};

class Rect : public Shape {
    int width, height;
public:
    void setRect(int x, int y, int width, int height);
    void show();
};

class Triangle : public Shape {
    int base, height;
public:
    void setTriangle(int x, int y, int base, int height);
    void show();
};

#endif
