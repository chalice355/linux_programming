// **********************************************
// 제 목 : 템플릿 클래스 Box
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <string>
#include "box.hpp"

int main() {
    Box<int> intBox(100);
    std::cout << "정수 상자: " << intBox.getValue() << "\n";

    Box<double> doubleBox(3.14);
    std::cout << "실수 상자: " << doubleBox.getValue() << "\n";

    Box<std::string> strBox("안녕하세요");
    std::cout << "문자열 상자: " << strBox.getValue() << "\n";

    strBox.setValue("템플릿 기초 완료!");
    std::cout << "변경된 문자열 상자: " << strBox.getValue() << "\n";
    return 0;
}
