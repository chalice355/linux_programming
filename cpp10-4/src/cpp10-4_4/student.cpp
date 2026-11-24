// **********************************************
// 제 목 : Student 클래스와 max_element를 이용한 최우수학생 찾기
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "student.hpp"
using namespace std;

Student::Student(string name, int score) {
    this->name = name;
    this->score = score;
}

void Student::show() {
    cout << "이름:" << name << endl;
    cout << "성적:" << score << "점" << endl;
}

bool Student::operator<(Student st) {   // 피연산자1 < 피연산자2 -> true
    if (this->score < st.score) return true;
    else return false;
}
