// **********************************************
// 제 목 : vector와 max_element를 이용하여 사전에서 제일 뒤에 나오는 단어 찾기
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

    // string의 < 연산자로 비교하여 사전에서 제일 뒤에 나오는 단어의 주소를 리턴
    it = max_element(sv.begin(), sv.end());
    cout << "사전에서 제일 뒤에 나오는 단어는 " << *it << endl;
    return 0;
}
