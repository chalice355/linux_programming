// **********************************************
// 제 목 : vector에서 음수를 삭제한 후 평균값 구하기
// 날 짜 : 2026년 11월 20일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <iomanip>
#include <vector>
#include "vecavg.hpp"
using namespace std;

int main() {
    vector<int> v;
    int num;

    cout << "숫자를 입력하세요: ";
    for (int i = 0; i < 5; i++) {
        cin >> num;
        v.push_back(num);
    }
    cout << "초기 벡터 원소 : ";
    printVector(v);

    eraseNegative(v);
    cout << "음수를 삭제 후 벡터원소 : ";
    printVector(v);

    if (v.empty())
        cout << "남은 원소가 없어 평균을 구할 수 없습니다." << endl;
    else
        cout << "평균값 : " << fixed << setprecision(1) << average(v) << endl;
    return 0;
}
