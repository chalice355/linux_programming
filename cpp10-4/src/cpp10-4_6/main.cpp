// **********************************************
// 제 목 : max_element, min_element와 동일하게 동작하는 템플릿 함수
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <vector>
#include "myalgo.hpp"
using namespace std;

int main() {
    vector<int> v; // 정수 벡터 생성
    vector<int>::iterator it;
    cout << "5개의 정수를 입력하세요>> ";
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        v.push_back(n); // 키보드에서 읽은 정수를 벡터에 삽입
    }

    it = my_max_element(v.begin(), v.end());
    cout << "최대값: " << *it << endl;

    it = my_min_element(v.begin(), v.end());
    cout << "최소값: " << *it << endl;
    return 0;
}
