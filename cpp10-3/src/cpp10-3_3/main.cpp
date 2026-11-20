// **********************************************
// 제 목 : vector를 이용하여 사전에서 제일 뒤에 나오는 단어 찾기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <string>
#include <vector>
#include "words.hpp"
using namespace std;

int main() {
    vector<string> sv;
    string word;

    for (int i = 0; i < 5; i++) {
        cout << "문자열을 입력하세요: ";
        getline(cin, word);
        sv.push_back(word);                     // 벡터의 끝에 단어 추가
    }
    cout << "사전에서 제일 뒤에 나오는 단어는 " << lastWord(sv) << " 입니다." << endl;
    return 0;
}
