// **********************************************
// 제 목 : TV 상속관계에서 생성자와 멤버변수 설정함수 추가
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "tv.hpp"
using namespace std;

int main() {
    SmartTV htv;
    htv.setSmartTV(50, false, "192.0.0.2");
    cout << "size = " << htv.getSize() << endl;
    cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP = " << htv.getIpAddr() << endl;
}
