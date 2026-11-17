// **********************************************
// 제 목 : 2개의 템플릿 매개변수를 가진 GClass와 swap 함수
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "gclass.hpp"
using namespace std;

int main() {
    int a, b;
    GClass<int, int> x;
    x.set(2, 5);
    x.get(a, b);
    cout << "a=" << a << '\t' << "b=" << b << endl;
    x.swap();
    x.get(a, b);
    cout << "a=" << a << '\t' << "b=" << b << endl;

    double c, d;
    GClass<double, double> y;
    y.set(3.14, 6.28);
    y.get(c, d);
    cout << "c=" << c << '\t' << "d=" << d << endl;
    y.swap();
    y.get(c, d);
    cout << "c=" << c << '\t' << "d=" << d << endl;
    return 0;
}
