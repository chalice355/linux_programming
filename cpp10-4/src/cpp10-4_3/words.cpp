// **********************************************
// 제 목 : vector와 sort를 이용하여 사전 순서로 출력
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "words.hpp"
using namespace std;

void inputWords(vector<string>& sv, int n) {
    for (int i = 0; i < n; i++) {
        string word;
        cout << "문자열을 입력하세요: ";
        getline(cin, word);
        sv.push_back(word);     // 키보드에서 읽은 문자열을 벡터에 삽입
    }
}
