#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    int num = 0;
    cout << "정수 4개를 입력하시오 >> ";
    for(int i = 0; i < 4; i++){
        cin >> num;
        v.push_back(num);
    }
    int max = v[0];
    int min = v[0];
    for(int i = 1; i < 4; i++){
        if(max < v[i])   max = v[i];
        if(min > v[i])  min = v[i];
    }
    cout << "최대값은 " << max << ", 최소값은 " << min << endl;
}