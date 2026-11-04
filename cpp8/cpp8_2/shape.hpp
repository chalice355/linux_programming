// **********************************************
// 제 목 : Shape 객체 포인터를 이용한 업캐스팅/다운캐스팅
// 날 짜 : 2026년 11월 4일
// 작성자 : 학번 이름
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
    void setRadius(int radius);
    void show();                    // 반지름 부분 출력
};

class Rect : public Shape {
    int width, height;
public:
    void setSize(int width, int height);
    void show();
};

class Triangle : public Shape {
    int base, height;
public:
    void setSize(int base, int height);
    void show();
};

#endif
