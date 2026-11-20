// **********************************************
// 제 목 : vector를 이용하여 사전에서 제일 뒤에 나오는 단어 찾기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#include <cctype>
#include "words.hpp"

string toLower(string s) {
    string::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        *it = tolower(*it);                     // 한 문자씩 소문자로 변환
    return s;
}

string lastWord(vector<string>& sv) {
    string last = sv.front();                   // 첫 번째 단어를 제일 뒤의 단어로 가정
    vector<string>::iterator it;
    for (it = sv.begin() + 1; it != sv.end(); it++) {
        // 대소문자를 구분하지 않고 비교하기 위해 소문자로 바꾸어 비교
        if (toLower(*it) > toLower(last))
            last = *it;                         // 원래 단어(대소문자 유지)를 저장
    }
    return last;
}
