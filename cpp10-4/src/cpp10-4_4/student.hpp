// **********************************************
// 제 목 : Student 클래스와 max_element를 이용한 최우수학생 찾기
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_
#include <string>
using namespace std;

class Student {
    string name;    // 이름
    int score;      // 점수
public:
    Student(string name, int score);
    void show();                        // 이름과 성적 출력
    bool operator<(Student st);         // 점수를 비교하는 < 연산자 함수
};

#endif
