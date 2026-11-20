// **********************************************
// 제 목 : vector에서 음수를 삭제한 후 평균값 구하기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include "vecavg.hpp"
using namespace std;

void printVector(vector<int>& v) {
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
}

void eraseNegative(vector<int>& v) {
    vector<int>::iterator it = v.begin();
    while (it != v.end()) {
        if (*it < 0)
            it = v.erase(it);
        else
            it++;
    }
}

double average(vector<int>& v) {
    int sum = 0;
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
        sum += *it;
    return (double)sum / v.size();
}
