// **********************************************
// 제 목 : vector에서 음수를 삭제한 후 평균값 구하기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _VECAVG_HPP_
#define _VECAVG_HPP_
#include <vector>
using namespace std;

void printVector(vector<int>& v);       // 벡터의 모든 원소 출력
void eraseNegative(vector<int>& v);     // 벡터에서 음수 원소를 모두 삭제
double average(vector<int>& v);         // 벡터 원소의 평균값 리턴

#endif
