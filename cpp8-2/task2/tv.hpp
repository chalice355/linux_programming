// **********************************************
// 제 목 : TV 상속관계에서 생성자와 멤버변수 설정함수 추가
// 날 짜 : 2026년 11월 11일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _TV_HPP_
#define _TV_HPP_
#include <string>
using namespace std;

class TV {
    int size;                   // 스크린 크기
public:
    TV();
    void setSize(int size);
    int getSize();
};

class WideTV : public TV {      // TV를 상속받는 WideTV
    bool videoIn;
public:
    WideTV();
    void setWideTV(int size, bool videoIn);
    bool getVideoIn();
};

class SmartTV : public WideTV { // WideTV를 상속받는 SmartTV
    string ipAddr;              // 인터넷 주소
public:
    SmartTV();
    void setSmartTV(int size, bool videoIn, string ipAddr);
    string getIpAddr();
};

#endif
