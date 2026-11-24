// **********************************************
// 제 목 : Student 클래스와 sort를 이용한 성적순 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "student.hpp"
using namespace std;

Student::Student(string name, int kor, int eng) {
    this->name = name;
    this->kor = kor;
    this->eng = eng;
    avg = (kor + eng) / 2.0;            // 2.0으로 나누어 실수 평균을 구함
}

void Student::show() {
    cout << name << " " << kor << " " << eng << " " << avg << endl;
}

bool Student::operator<(const Student& st) const {  // 피연산자1 < 피연산자2 -> true
    if (this->avg < st.avg) return true;
    else return false;
}

bool Student::operator>(const Student& st) const {  // 피연산자1 > 피연산자2 -> true
    if (this->avg > st.avg) return true;
    else return false;
}
