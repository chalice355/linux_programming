# 실습과제 1
## 템플릿 함수의 2가지 매개변수는?
* 템플릿 매개변수(타입 매개변수) : template <class T>의 T, 함수에서 사용할 데이터 타입을 일반화한 매개변수
* 함수 매개변수 : (T& a, T& b)의 a,b, 일반 함수와 같이 함수에 전달되는 값을 받는 매개변수

## 템플릿 매개변수의 용도는?
* 함수나 클래스에서 사용하는 데이터 타입을 매개변수로 만들어 일반화함
* 타입만 다르고 코드가 같은 함수들을 여러 번 중복 작성하지 않고 하나의 템플릿으로 작성할 수 있음
* 함수를 호출하면 컴파일러가 전달된 인자의 타입을 보고 T를 int, double, char 등 구체적인 타입으로 바꾸어 함수를 생성함

## 함수 매개변수의 용도는?
* 함수에서 다른 부분인 값을 매개변수로 만들어 일반화함
* 함수를 호출할 때 인자로 전달된 값을 받아서 함수 안에서 사용
* 같은 코드로 다른 값을 처리할 수 있게 하여 코드 중복을 방지

## 템플릿함수의 정의는 호출과 같은 소스코드에 존재해야 하는 이유는?
* 컴파일러는 소스파일을 하나씩 따로 컴파일 하기 때문에, 구체화 하려면 호출하는 소스파일을 컴파일할 때 템플릿 함수의 본체가 보여야 함
* 본체를 별도의 cpp파일 안에 두고 헤더파일에는 선언만 해두면, main.cpp을 컴파일할 때 정의가 없어 구체화 불가하고 cpp에서는 호출이 없어 아무 함수도 만들지 않아 링크 시, 에러 발생

## 참고: 일반함수는 선언은 헤더파일에 정의는 소스파일로 분리하지만 템플릿 함수는 헤더파일에 정의를 작성해야 함. 그리고 호출하는 코드에서 헤더파일을 include하면 호출과 정의가 같은 코드에 존재

# 실습과제 2
## getmax.hpp (템플릿 함수 정의)
```cpp
#ifndef _GETMAX_HPP_
#define _GETMAX_HPP_
...
#endif
```
* 헤더파일 중복 포함 방지

```cpp
template <class T>
T getmax(T data[], int n) {
```
* T는 템플릿 매개변수, 배열 원소의 타입을 일반화
* data는 T의 타입 배열, n은 배열의 크기를 받는 함수 매개변수
* 리턴 타입도 T이므로 배열 원소와 같은 타입의 최댓값을 리턴

```cpp
T max = data[0];
```
* 첫 번째 원소를 최댓값으로 가정

```cpp
for (int i = 1; i < n; i++) {
        if(max < data[i])   max = data[i];  
    }
```
* 두 번째 원소부터 하나씩 max와 비교하고, 더 큰 값을 찾으면 max를 교체
* 첫 번째 원소를 가정값으로 가졌으므로, 다시 비교할 필요가 없어 두 번째 원소부터 시작.

```cpp
return max;
```
* 최댓값 리턴

## main.cpp
```cpp
#include <iostream>
#include "getmax.hpp"
using namespace std;
```
* cout, endl을 사용하기 위해 iostream 포함
* 템플릿 함수가 정의된 getmax.hpp를 포함하여 호출과 정의가 같은 소스코드에 존재

```cpp
int a[5]={-5, 10, 30, 20, 6};
double b[4]= {3.14, 1.5, -6.0, 0.5};
char c[3] = {'a', 'x', 'p'};
```
* 정수, 실수, 문자 배열 선언

```cpp
cout << "정수배열의 최대값은 " << getmax(a, 5) << endl;
cout << "실수배열의 최대값은 " << getmax(b, 4) << endl;
cout << "문자배열의 최대값은 " << getmax(c, 3) << endl;
```
* a는 int 배열이므로, int로 구체화 된 getmax가 호출되어 30 출력
* b는 double 배열이므로, double로 구체화되어 3.14 출력
* c는 char로 구체화되어 아스키코드값이 가장 큰 x 출력

## Makefile
```makefile
OBJS = main.o
TARGET = getmax
```
* 템플릿 함수는 헤더파일에만 있으므로 컴파일한 소스파일은 main.cpp 하나.
* 목적파일도 main.o 하나

```makefile
main.o : main.cpp getmax.hpp
	$(CX) $(CXFLAGS) -c main.cpp
```
* main.o는 main.cpp와 getmax.hpp에 의존
* 템플릿 함수를 수정하면 main.cpp가 다시 컴파일됨

## 실행결과

| 구분 | 이미지 |
| --- | --- |
| getmax.hpp | <img src="cpp10_2/cpp10-1-1.png"> |
| main.cpp | <img src="cpp10_2/cpp10-1-2.png"> |
| Makefile | <img src="cpp10_2/cpp10-1-3.png"> |
| 실행결과 | <img src="cpp10_2/cpp10-1-4.png"> |

# 실습과제 3
```cpp
class Circle{
    int radius;
public:
    Circle(int radius = 1);
    int getRadius();
```
* 반지름 radius를 멤버로 갖는 Circle 클래스
* 디폴트 매개변수는 선언부에만 작성

```cpp
bool operator>(Circle op2);
```
* Circle 객체끼리 비교하는 > 연산자 함수를 멤버 함수로 선언
* a > b는 컴파일러에 의해 a.operator>(b)로 변환되어 호출
* 비교 결과가 참 또는 거짓이므로 리턴 타입은 bool

```cpp
template <class T>
T bigger(T a, T b){
    return (a>b)? a:b;
}
```
* 두 매개변수를 비교하여 큰 값을 리턴
* 템플릿이므로 헤더 파일에 작성

## circle.cpp
```cpp
#include "circle.hpp"
```
* 클래스 선언부 포함

```cpp
Circle::Circle(int radius){
    this->radius = radius;
}
int Circle::getRadius(){
    return radius;
}
```
* 생성자와 getRadius() 구현

```cpp
bool Circle::operator>(Circle op2){
    return radius > op2.radius;
}
```
* 자신(왼쪽)의 반지름과 op2(오른쪽)의 반지름을 비교
* op2.radius는 private 멤버지만, 같은 Circle 클래스의 멤버함수 안이므로 접근 가능
* 자신의 반지름이 더 크면 true, 아니면 false 리턴

```cpp
#include <iostream>
#include "circle.hpp"
using namespace std;
```
* cout, endl을 사용하기 위해 iostream 포함
* 템플릿 함수가 정의된 circle.hpp를 포함하여 호출과 정의가 같은 소스파일에 존재하게 함

```cpp
int a=20, b=50, c;
c = bigger(a,b);
cout << "20과 50 중 큰 값은 " << c << endl;
```
* T가 int로 구체화하고, > 연산자로 비교하여 더 큰 값을 출력
* a보다 b가 크므로, b가 리턴되어 c에 복사되고 50으로 출력

```cpp
Circle donut(10), pizza(20), y;
y = bigger(donut, pizza);
cout << "donut과 pizza 중 큰 반지름은 " << y.getRadius() << endl;
```
* 반지름 10인 donut, 반지름 20인 pizza 객체 생성
* y는 기본값 1로 생성
* 10 > 20은 false이므로, pizza가 리턴되어 y에 복사되고 20을 출력

```cpp
return (a>b)? a:b;
```
* 정상종료

## Makefile
```makefile
OBJS = main.o circle.o
TARGET = bigger
```
* main.cpp와 circle.cpp를 각각 컴파일하여 링크

```makefile
main.o : main.cpp circle.hpp
	$(CX) $(CXFLAGS) -c main.cpp

circle.o : circle.cpp circle.hpp
	$(CX) $(CXFLAGS) -c circle.cpp
```
* 각각 목적파일로 컴파일하고, 헤더파일 수정 시, 둘 다 다시 컴파일

## 실행결과

| 구분 | 이미지 |
| --- | --- |
| circle.hpp | <img src="cpp10_3/cpp10-2-1.png"> |
| circle.cpp | <img src="cpp10_3/cpp10-2-2.png"> |
| main.cpp | <img src="cpp10_3/cpp10-2-3.png"> |
| Makefile | <img src="cpp10_3/cpp10-2-4.png"> |
| 실행결과 | <img src="cpp10_3/cpp10-2-5.png"> |
