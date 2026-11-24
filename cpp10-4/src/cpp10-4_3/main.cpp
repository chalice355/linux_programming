// **********************************************
// 제 목 : vector와 sort를 이용하여 사전 순서로 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "words.hpp"
using namespace std;

int main() {
    vector<string> sv; // 문자열 벡터 생성
    vector<string>::iterator it;
    inputWords(sv, 5);

    sort(sv.begin(), sv.end());     // 사전 순서(오름차순)로 정렬

    cout << "사전에서 나오는 순서" << endl;
    for (it = sv.begin(); it != sv.end(); it++)
        cout << *it << endl;
    return 0;
}
