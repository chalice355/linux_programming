// **********************************************
// 제 목 : Shape 상속 (private 멤버, 기본클래스 함수로 접근)
// 날 짜 : 2026년 11월 4일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _SHAPE_HPP_
#define _SHAPE_HPP_

class Shape {
private:
    int x, y;                       // 위치좌표 (private)
public:
    void setXY(int x, int y);       // 좌표 설정
    void showXY();                  // 좌표 출력
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
