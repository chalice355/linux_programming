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
        *it = tolower(*it);
    return s;
}

string lastWord(vector<string>& sv) {
    string last = sv.front();
    vector<string>::iterator it;
    for (it = sv.begin() + 1; it != sv.end(); it++) {
        if (toLower(*it) > toLower(last))
            last = *it;
    }
    return last;
}
