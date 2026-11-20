// **********************************************
// 제 목 : vector를 이용한 최대값, 최소값 구하기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#include "minmax.hpp"

int getMax(vector<int>& v) {
    int max = v.front();                        // 첫 번째 원소를 최대값으로 가정
    vector<int>::iterator it;
    for (it = v.begin() + 1; it != v.end(); it++) {
        if (*it > max) max = *it;               // 더 큰 값이 있으면 교체
    }
    return max;
}

int getMin(vector<int>& v) {
    int min = v.front();                        // 첫 번째 원소를 최소값으로 가정
    vector<int>::iterator it;
    for (it = v.begin() + 1; it != v.end(); it++) {
        if (*it < min) min = *it;               // 더 작은 값이 있으면 교체
    }
    return min;
}
