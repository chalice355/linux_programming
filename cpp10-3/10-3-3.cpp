#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    vector<string> sv;
    string name;
    for (int i = 0; i < 5; i++) {
        cout << "문자열을 입력하라: ";
        getline(cin, name);
        sv.push_back(name);
    }
    name = sv.at(0); // 벡터의 첫 원소 sv[0]
    for (int i = 1; i < sv.size(); i++) {
        if (name < sv[i]) name = sv[i]; // sv[i] -> sv.at(i)
    }
    cout << "사전에서 가장 뒤에 나오는 단어는 " << name << endl;
}