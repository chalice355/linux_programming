// **********************************************
// 제 목 : vector와 알고리즘을 이용한 크기순 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <vector>
#include <algorithm>
#include "vecprint.hpp"
using namespace std;

int main() {
    vector<int> v; // 정수 벡터 생성
    vector<int>::iterator it;
    cout << "정수 4개를 입력하시오: ";
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        v.push_back(n); // 키보드에서 읽은 정수를 벡터에 삽입
    }

    it = max_element(v.begin(), v.end());
    cout << "최대값은 " << distance(v.begin(), it) + 1 << "번째 값 " << *it << endl;

    it = min_element(v.begin(), v.end());
    cout << "최소값은 " << distance(v.begin(), it) + 1 << "번째 값 " << *it << endl;

    sort(v.begin(), v.end());                       // 오름차순 정렬
    cout << "오름차순 결과는 ";
    printVector(v);

    sort(v.begin(), v.end(), std::greater<int>());  // 내림차순 정렬
    cout << "내림차순 결과는 ";
    printVector(v);
    return 0;
}
