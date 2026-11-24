// **********************************************
// 제 목 : Student 클래스와 sort를 이용한 성적순 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "student.hpp"
using namespace std;

int main() {
    vector<Student> st;
    vector<Student>::iterator it;
    for (int i = 0; i < 3; i++) {
        string name;
        int kor, eng;
        cout << i + 1 << "번째 학생의 이름,국어,영어성적을 입력: ";
        cin >> name >> kor >> eng;
        st.push_back(Student(name, kor, eng)); // 생성자 직접호출 -> 이름없는 임시객체 생성
    }

    // Student의 > 연산자로 비교하여 평균이 높은 순서(내림차순)로 정렬
    sort(st.begin(), st.end(), std::greater<Student>());

    int rank = 1;
    for (it = st.begin(); it != st.end(); it++) {
        cout << rank << "등 : ";
        it->show();
        rank++;
    }
    return 0;
}
