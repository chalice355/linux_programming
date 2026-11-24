// **********************************************
// 제 목 : sort와 동일하게 동작하는 템플릿 함수 my_sort
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <vector>
#include "mysort.hpp"
using namespace std;

int main() {
    vector<int> v={30,-7,250,6,120};
    vector<int>::iterator it;
    my_sort(v.begin(), v.end());
    for (it = v.begin(); it < v.end(); it++)
        cout << *it << ' ';
    cout << endl;
    return 0;
}
