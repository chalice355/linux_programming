// **********************************************
// 제 목 : vector를 이용한 최대값, 최소값 구하기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <vector>
#include "minmax.hpp"
using namespace std;

int main() {
    vector<int> v;
    int num;

    cout << "정수 4개를 입력하시오: ";
    for (int i = 0; i < 4; i++) {
        cin >> num;
        v.push_back(num);                       // 벡터의 끝에 원소 추가
    }
    cout << "최대값은 " << getMax(v) << ", 최소값은 " << getMin(v) << "입니다." << endl;
    return 0;
}
