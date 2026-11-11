// **********************************************
// 제 목 : TV 상속관계에서 생성자와 멤버변수 설정함수 추가
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "tv.hpp"
using namespace std;

TV::TV() {
    size = 20;
    cout << "TV 생성" << endl;
}
void TV::setSize(int size) {
    this->size = size;
}
int TV::getSize() {
    return size;
}

WideTV::WideTV() {
    videoIn = true;
    cout << "WideTV 생성" << endl;
}
void WideTV::setWideTV(int size, bool videoIn) {
    setSize(size);              // size는 TV의 private 멤버이므로 TV의 함수로 설정
    this->videoIn = videoIn;
}
bool WideTV::getVideoIn() {
    return videoIn;
}

SmartTV::SmartTV() {
    ipAddr = "";
    cout << "SmartTV 생성" << endl;
}
void SmartTV::setSmartTV(int size, bool videoIn, string ipAddr) {
    setWideTV(size, videoIn);   // size, videoIn은 WideTV의 함수로 설정
    this->ipAddr = ipAddr;
}
string SmartTV::getIpAddr() {
    return ipAddr;
}
