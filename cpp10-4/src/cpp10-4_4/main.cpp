// **********************************************
// 제 목 : Student 클래스와 max_element를 이용한 최우수학생 찾기
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.hpp"
using namespace std;

int main() {
    vector<Student> st;
    vector<Student>::iterator it;
    for (int i = 0; i < 3; i++) {
        string name;
        int score;
        cout << "이름과 성적을 입력: ";
        cin >> name >> score;
        st.push_back(Student(name, score)); // 생성자 직접호출 -> 이름없는 임시객체 생성
    }

    it = max_element(st.begin(), st.end()); // Student의 < 연산자로 비교
    cout << "최우수학생은" << endl;
    it->show();
    return 0;
}
