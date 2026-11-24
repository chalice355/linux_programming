// **********************************************
// 제 목 : vector와 알고리즘을 이용한 크기순 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "vecprint.hpp"
using namespace std;

void printVector(vector<int>& v) {
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) cout << ", ";      // 첫 원소 앞에는 쉼표를 붙이지 않음
        cout << *it;
    }
    cout << endl;
}
