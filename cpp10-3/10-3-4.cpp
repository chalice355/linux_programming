#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    vector<int>::iterator it;
    int num = 0;
    int sum = 0;
    double avg = 0;
    cout << "숫자 5개를 입력하시오 >> ";
    for(int i = 0; i < 5; i++){
        cin >> num;
        v.push_back(num);
    }
    cout << "초기 벡터 원소 ";
    for (it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    it = v.begin();
    while(it != v.end()){
        if(*it < 0) it = v.erase(it);
        else it++;
    }
    cout << "음수를 지운 후 벡터 원소: ";
    for (it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "평균값: ";
    for (it = v.begin(); it != v.end(); it++)
        sum += *it;
    if(v.size() > 0){
        avg = (double)sum / v.size();
        cout << "평균값: " << avg << endl; 
    }
    return 0;
}