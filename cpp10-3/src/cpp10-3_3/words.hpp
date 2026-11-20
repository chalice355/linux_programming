// **********************************************
// 제 목 : vector를 이용하여 사전에서 제일 뒤에 나오는 단어 찾기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _WORDS_HPP_
#define _WORDS_HPP_
#include <string>
#include <vector>
using namespace std;

string toLower(string s);               // 문자열을 모두 소문자로 바꾸어 리턴
string lastWord(vector<string>& sv);    // 사전에서 제일 뒤에 나오는 단어 리턴

#endif
