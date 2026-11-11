// **********************************************
// 제 목 : Point를 상속받은 ColorPoint 클래스 (실습문제 3번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _POINT_HPP_
#define _POINT_HPP_
#include <string>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x, int y);
    int getX();
    int getY();
protected:
    void move(int x, int y);
};

class ColorPoint : public Point {
    string color;
public:
    ColorPoint(int x, int y, string color);
    void setPoint(int x, int y);
    void setColor(string color);
    void show();
};

#endif
