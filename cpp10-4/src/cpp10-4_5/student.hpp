// **********************************************
// 제 목 : Student 클래스와 sort를 이용한 성적순 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_
#include <string>
using namespace std;

class Student {
    string name;    // 이름
    int kor, eng;   // 국어, 영어 성적
    double avg;     // 평균
public:
    Student(string name, int kor, int eng);
    void show();                                // 이름, 국어, 영어, 평균 출력
    bool operator<(const Student& st) const;    // 평균을 비교하는 < 연산자 함수
    bool operator>(const Student& st) const;    // 평균을 비교하는 > 연산자 함수
};

#endif
