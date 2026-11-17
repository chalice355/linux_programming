// **********************************************
// 제 목 : 동적 배열을 사용하는 템플릿 클래스 Container (교재 522쪽 12번)
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "container.hpp"
using namespace std;

int main() {
    Container<char> c(26);         
    for (int i = 0; i < 26; i++)   
        c.set(i, 'a' + i);
    for (int i = 25; i >= 0; i--)  
        cout << c.get(i);
    cout << endl;
    return 0;
}
