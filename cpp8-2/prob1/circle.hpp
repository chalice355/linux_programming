// **********************************************
// 제 목 : Circle을 상속받아 이름을 추가한 NamedCircle 클래스 (실습문제 1번)
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_
#include <string>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int radius = 0);
    int getRadius();
    void setRadius(int radius);
    double getArea();
};

class NamedCircle : public Circle {   // Circle을 상속받은 NamedCircle
    string name;                      // 원의 이름
public:
    NamedCircle(int radius, string name);
    void show();
};

#endif
