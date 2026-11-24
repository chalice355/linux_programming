# 10장 STL 알고리즘 실습과제

모든 과제는 리눅스에서 분할컴파일 구조로 작성하고 make로 빌드함

| 폴더 | 내용 | 사용한 알고리즘 |
| --- | --- | --- |
| src/cpp10-4_1 | 실습과제 1, 정수 크기순 출력 | max_element, min_element, distance, sort |
| src/cpp10-4_2 | 실습과제 2, 사전에서 제일 뒤의 단어 | max_element |
| src/cpp10-4_3 | 실습과제 3, 사전 순서 출력 | sort |
| src/cpp10-4_4 | 실습과제 4, 최우수학생 | max_element, Student의 < 연산자 |
| src/cpp10-4_5 | 실습과제 5, 성적순 출력 | sort, greater, Student의 > 연산자 |
| src/cpp10-4_6 | 실습과제 6, my_max_element, my_min_element | 직접 구현한 템플릿 함수 |
| src/cpp10-4_7 | 실습과제 7, my_sort | 직접 구현한 템플릿 함수 |

- 클래스가 없는 과제(1~3)는 헤더파일에 함수 선언부, 소스파일에 함수 구현부를 작성함
- 템플릿 함수 과제(6, 7)는 함수가 호출하는 곳에서 구체화되어야 하므로 헤더파일에 정의를 모두 작성하고 소스파일은 main.cpp 하나로 구성함
- 알고리즘 함수는 `#include <algorithm>`, 이름 공간은 `using namespace std;`

# 실습과제 1
키보드로부터 정수 4개를 입력 받아 크기순으로 출력하는 코드를 작성하시오. STL의 vector클래스와 알고리즘을 이용하여 구현하시오.

## vecprint.hpp
```cpp
#ifndef _VECPRINT_HPP_
#define _VECPRINT_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
void printVector(vector<int>& v);
```
- 실행결과처럼 원소를 쉼표로 구분하여 출력하는 함수 선언

## vecprint.cpp
```cpp
void printVector(vector<int>& v) {
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) cout << ", ";
        cout << *it;
    }
    cout << endl;
}
```
- iterator로 처음부터 끝까지 순회하며 원소 출력
- 첫 번째 원소(it == v.begin()) 앞에는 쉼표를 붙이지 않고, 두 번째 원소부터 앞에 ", "를 붙임

## main.cpp
```cpp
#include <algorithm>
```
- max_element, min_element, sort를 사용하기 위해 포함

```cpp
for (int i = 0; i < 4; i++) {
    int n;
    cin >> n;
    v.push_back(n); // 키보드에서 읽은 정수를 벡터에 삽입
}
```
- 예제 10-13과 같이 정수를 하나씩 입력 받아 push_back()으로 벡터의 끝에 삽입

```cpp
it = max_element(v.begin(), v.end());
cout << "최대값은 " << distance(v.begin(), it) + 1 << "번째 값 " << *it << endl;
```
- max_element()는 최대값의 주소를 저장한 iterator객체를 리턴
- distance(v.begin(), it)는 처음 원소부터 it까지의 거리, 즉 인덱스(30은 2)를 리턴
- 몇 번째 값인지는 1부터 세므로 +1 하여 3번째로 출력
- *it로 최대값 30 출력

```cpp
it = min_element(v.begin(), v.end());
cout << "최소값은 " << distance(v.begin(), it) + 1 << "번째 값 " << *it << endl;
```
- 같은 방법으로 최소값 -50의 위치(4번째)와 값 출력
- 정렬하면 원소의 순서가 바뀌므로 위치는 정렬하기 전에 먼저 구해야 함

```cpp
sort(v.begin(), v.end());
cout << "오름차순 결과는 ";
printVector(v);
```
- sort()로 벡터 전체를 오름차순 정렬, 실행 결과 벡터 v의 원소 순서가 변경됨

```cpp
sort(v.begin(), v.end(), std::greater<int>());
cout << "내림차순 결과는 ";
printVector(v);
```
- 세 번째 매개변수로 std::greater<int>()를 전달하면 > 연산자로 비교하여 내림차순 정렬
- std::greater<int>()는 생성자를 직접 호출하여 만든 함수 객체(임시객체)

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o vecprint.o
TARGET = sorting
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, g++ -o sorting main.o vecprint.o로 링크

```makefile
main.o : main.cpp vecprint.hpp
	$(CX) $(CXFLAGS) -c main.cpp

vecprint.o : vecprint.cpp vecprint.hpp
	$(CX) $(CXFLAGS) -c vecprint.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
정수 4개를 입력하시오: 10 -20 30 -50
최대값은 3번째 값 30
최소값은 4번째 값 -50
오름차순 결과는 -50, -20, 10, 30
내림차순 결과는 30, 10, -20, -50
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| vecprint.hpp | <img src="img/cpp104-1-1.png"> |
| vecprint.cpp | <img src="img/cpp104-1-2.png"> |
| main.cpp | <img src="img/cpp104-1-3.png"> |
| Makefile | <img src="img/cpp104-1-4.png"> |
| 실행결과 | <img src="img/cpp104-1-5.png"> |

# 실습과제 2
예제 10-13을 참고하여 반드시 STL의 vector클래스와 알고리즘을 이용하여 다음 처럼 동작하는 프로그램을 작성하시오.

## words.hpp
```cpp
#ifndef _WORDS_HPP_
#define _WORDS_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
void inputWords(vector<string>& sv, int n);
```
- 문자열 n개를 입력 받아 벡터에 삽입하는 함수 선언, 벡터에 원소를 추가해야 하므로 참조(&)로 전달

## words.cpp
```cpp
void inputWords(vector<string>& sv, int n) {
    for (int i = 0; i < n; i++) {
        string word;
        cout << "문자열을 입력하세요: ";
        getline(cin, word);
        sv.push_back(word);
    }
}
```
- getline()으로 한 줄을 입력 받아 push_back()으로 벡터의 끝에 삽입

## main.cpp
```cpp
vector<string> sv;
vector<string>::iterator it;
inputWords(sv, 5);
```
- string 타입 원소를 저장하는 벡터와 iterator 선언 후 문자열 5개 입력

```cpp
it = max_element(sv.begin(), sv.end());
cout << "사전에서 제일 뒤에 나오는 단어는 " << *it << endl;
```
- max_element()는 원소를 < 연산자로 비교하며, string의 < 연산자는 사전 순서로 비교함
- 따라서 사전에서 제일 뒤에 나오는 단어의 주소를 저장한 iterator가 리턴됨
- 반복문으로 직접 비교하지 않고 알고리즘 함수 하나로 해결

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o words.o
TARGET = words
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, g++ -o words main.o words.o로 링크

```makefile
main.o : main.cpp words.hpp
	$(CX) $(CXFLAGS) -c main.cpp

words.o : words.cpp words.hpp
	$(CX) $(CXFLAGS) -c words.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
문자열을 입력하세요: hello
문자열을 입력하세요: world
문자열을 입력하세요: book
문자열을 입력하세요: program
문자열을 입력하세요: c++
사전에서 제일 뒤에 나오는 단어는 world
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| words.hpp | <img src="img/cpp104-2-1.png"> |
| words.cpp | <img src="img/cpp104-2-2.png"> |
| main.cpp | <img src="img/cpp104-2-3.png"> |
| Makefile | <img src="img/cpp104-2-4.png"> |
| 실행결과 | <img src="img/cpp104-2-5.png"> |

# 실습과제 3
STL의 vector클래스와 알고리즘을 이용하여 다음 처럼 동작하는 프로그램을 작성하시오.

## words.hpp, words.cpp
- 실습과제 2와 동일, 문자열 n개를 입력 받는 inputWords() 함수

## main.cpp
```cpp
sort(sv.begin(), sv.end());
```
- sort()는 원소를 < 연산자로 비교하여 오름차순 정렬, string은 사전 순서로 비교되므로 사전 순서대로 정렬됨
- '+'(43)는 영문자보다 아스키코드 값이 작으므로 c++는 c로 시작하는 다른 단어들보다 앞에 오며, book 다음에 위치

```cpp
cout << "사전에서 나오는 순서" << endl;
for (it = sv.begin(); it != sv.end(); it++)
    cout << *it << endl;
```
- 정렬된 벡터를 iterator로 순회하며 한 줄에 하나씩 출력

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o words.o
TARGET = words
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, g++ -o words main.o words.o로 링크

```makefile
main.o : main.cpp words.hpp
	$(CX) $(CXFLAGS) -c main.cpp

words.o : words.cpp words.hpp
	$(CX) $(CXFLAGS) -c words.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
사전에서 나오는 순서
book
c++
hello
program
world
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| words.hpp | <img src="img/cpp104-3-1.png"> |
| words.cpp | <img src="img/cpp104-3-2.png"> |
| main.cpp | <img src="img/cpp104-3-3.png"> |
| Makefile | <img src="img/cpp104-3-4.png"> |
| 실행결과 | <img src="img/cpp104-3-5.png"> |

# 실습과제 4
이름, 점수를 저장하는 Student 클래스를 작성하라. Student 객체를 비교하는 < 연산자 함수를 정의하라. STL의 vector클래스와 알고리즘 max_element을 이용하여 다음 처럼 동작하는 프로그램을 작성하시오.

## student.hpp
```cpp
#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
class Student {
    string name;
    int score;
public:
    Student(string name, int score);
    void show();
    bool operator<(Student st);
};
```
- 이름 name과 점수 score를 멤버로 가짐
- 실행결과를 보고 필요한 멤버함수로 생성자(이름과 점수 저장)와 show()(이름과 성적 출력)를 선언
- max_element()가 객체의 크기를 비교할 때 사용하는 < 연산자 함수 선언

## student.cpp
```cpp
Student::Student(string name, int score) {
    this->name = name;
    this->score = score;
}
```
- 매개변수를 멤버변수에 저장

```cpp
void Student::show() {
    cout << "이름:" << name << endl;
    cout << "성적:" << score << "점" << endl;
}
```
- 실행결과의 형식대로 출력

```cpp
bool Student::operator<(Student st) {   // 피연산자1 < 피연산자2 -> true
    if (this->score < st.score) return true;
    else return false;
}
```
- 강의노트의 Circle 예제와 같은 형태, 점수를 비교하여 왼쪽 객체의 점수가 작으면 true
- `a < b`는 `a.operator<(b)`로 호출됨

## main.cpp
```cpp
vector<Student> st;
vector<Student>::iterator it;
for (int i = 0; i < 3; i++) {
    string name;
    int score;
    cout << "이름과 성적을 입력: ";
    cin >> name >> score;
    st.push_back(Student(name, score));
}
```
- Student 객체를 저장하는 벡터 생성
- 이름과 점수를 입력 받아 생성자를 직접 호출하여 이름없는 임시객체를 만든 뒤 벡터에 삽입

```cpp
it = max_element(st.begin(), st.end());
cout << "최우수학생은" << endl;
it->show();
```
- max_element()가 Student의 < 연산자로 객체를 비교하여 점수가 가장 높은 객체의 주소를 리턴
- iterator는 포인터처럼 사용하므로 it->show()로 멤버함수 호출

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o student.o
TARGET = student
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, g++ -o student main.o student.o로 링크

```makefile
main.o : main.cpp student.hpp
	$(CX) $(CXFLAGS) -c main.cpp

student.o : student.cpp student.hpp
	$(CX) $(CXFLAGS) -c student.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
이름과 성적을 입력: 홍길동 50
이름과 성적을 입력: 임꺽정 70
이름과 성적을 입력: 장길산 60
최우수학생은
이름:임꺽정
성적:70점
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| student.hpp | <img src="img/cpp104-4-1.png"> |
| student.cpp | <img src="img/cpp104-4-2.png"> |
| main.cpp | <img src="img/cpp104-4-3.png"> |
| Makefile | <img src="img/cpp104-4-4.png"> |
| 실행결과 | <img src="img/cpp104-4-5.png"> |

# 실습과제 5
3명 학생의 이름, 국어, 영어성적을 입력 받아 각 학생의 평균값을 구한 후 성적순으로 출력하는 C++프로그램을 작성하라 → Student 클래스정의, < 연산자함수정의, sort 함수 이용할 것

## student.hpp
```cpp
#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
class Student {
    string name;
    int kor, eng;
    double avg;
public:
    Student(string name, int kor, int eng);
    void show();
    bool operator<(const Student& st) const;
    bool operator>(const Student& st) const;
};
```
- 이름, 국어, 영어 성적과 평균을 멤버로 가짐
- 평균을 비교하는 < 연산자 함수와, 내림차순 정렬에 사용할 > 연산자 함수 선언
- std::greater<Student>는 내부에서 const 객체끼리 > 연산자로 비교하므로, 연산자 함수의 매개변수를 const 참조로, 함수를 const 멤버함수로 선언해야 함

## student.cpp
```cpp
Student::Student(string name, int kor, int eng) {
    this->name = name;
    this->kor = kor;
    this->eng = eng;
    avg = (kor + eng) / 2.0;
}
```
- 국어, 영어 성적을 저장하고 평균을 계산
- 2로 나누면 정수 나눗셈이 되어 소수점이 버려지므로 2.0으로 나누어 실수 평균을 구함

```cpp
void Student::show() {
    cout << name << " " << kor << " " << eng << " " << avg << endl;
}
```
- 이름, 국어, 영어, 평균 출력, 평균 85.0은 85로 출력됨

```cpp
bool Student::operator<(const Student& st) const {
    if (this->avg < st.avg) return true;
    else return false;
}
bool Student::operator>(const Student& st) const {
    if (this->avg > st.avg) return true;
    else return false;
}
```
- 평균을 비교하여 < 는 왼쪽이 작으면, > 는 왼쪽이 크면 true 리턴

## main.cpp
```cpp
#include <functional>
```
- std::greater를 사용하기 위해 포함

```cpp
cout << i + 1 << "번째 학생의 이름,국어,영어성적을 입력: ";
cin >> name >> kor >> eng;
st.push_back(Student(name, kor, eng));
```
- 3명의 정보를 입력 받아 임시객체를 생성하여 벡터에 삽입

```cpp
sort(st.begin(), st.end(), std::greater<Student>());
```
- 성적순(1등부터)으로 출력해야 하므로 내림차순 정렬
- 강의노트의 std::greater<int>()와 같이 std::greater<Student>()를 전달하면 Student의 > 연산자로 비교하여 평균이 높은 순서로 정렬됨
- sort(st.begin(), st.end());로 쓰면 < 연산자로 비교하여 평균이 낮은 순서(오름차순)로 정렬됨

```cpp
int rank = 1;
for (it = st.begin(); it != st.end(); it++) {
    cout << rank << "등 : ";
    it->show();
    rank++;
}
```
- 정렬된 순서대로 등수를 붙여 출력

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o student.o
TARGET = student
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, g++ -o student main.o student.o로 링크

```makefile
main.o : main.cpp student.hpp
	$(CX) $(CXFLAGS) -c main.cpp

student.o : student.cpp student.hpp
	$(CX) $(CXFLAGS) -c student.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
1번째 학생의 이름,국어,영어성적을 입력: lee 80 90
2번째 학생의 이름,국어,영어성적을 입력: kim 50 50
3번째 학생의 이름,국어,영어성적을 입력: han 60 70
1등 : lee 80 90 85
2등 : han 60 70 65
3등 : kim 50 50 50
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| student.hpp | <img src="img/cpp104-5-1.png"> |
| student.cpp | <img src="img/cpp104-5-2.png"> |
| main.cpp | <img src="img/cpp104-5-3.png"> |
| Makefile | <img src="img/cpp104-5-4.png"> |
| 실행결과 | <img src="img/cpp104-5-5.png"> |

# 실습과제 6
아래 결과가 나오도록 max_element, min_element 함수와 동일하게 동작하는 템플릿 함수 my_max_element, my_min_element 함수를 정의하시오.

## myalgo.hpp
```cpp
#ifndef _MYALGO_HPP_
#define _MYALGO_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
template< class ForwardIt >
ForwardIt my_max_element(ForwardIt first, ForwardIt last) {
```
- 강의노트의 max_element 원형과 같은 형태
- ForwardIt : iterator 클래스명, 예) vector<int>::iterator
- first : 조사할 첫번째 원소의 주소를 저장한 iterator객체
- last : 조사할 마지막 원소의 다음 주소를 저장한 iterator객체

```cpp
    if (first == last) return last;
```
- 조사할 원소가 없으면 max_element와 같이 last 리턴

```cpp
    ForwardIt maxIt = first;
    ForwardIt it;
    for (it = first; it != last; it++) {
        if (*maxIt < *it)
            maxIt = it;
    }
    return maxIt;
}
```
- 첫번째 원소의 주소를 최대값의 주소로 가정
- main에서 쓰는 `for (it = v.begin(); it != v.end(); it++)`와 같은 반복문, 함수 안에서는 first가 v.begin(), last가 v.end() 역할
- 값이 아니라 위치(iterator)를 저장하고 리턴하므로 main에서 *it로 값을 꺼냄
- 비교는 STL과 같이 < 연산자만 사용하므로 < 연산자가 정의된 Student, Circle 객체에도 사용 가능

```cpp
template< class ForwardIt >
ForwardIt my_min_element(ForwardIt first, ForwardIt last) { ... }
```
- 같은 방법으로 *it < *minIt이면 minIt을 교체하여 최소값의 주소 리턴

## main.cpp
```cpp
#include "myalgo.hpp"
```
- STL의 알고리즘 대신 직접 작성한 템플릿 함수를 사용하므로 <algorithm> 대신 myalgo.hpp 포함

```cpp
for (int i = 0; i < 5; i++) {
    int n;
    cin >> n;
    v.push_back(n); // 키보드에서 읽은 정수를 벡터에 삽입
}
```
- 예제 10-13과 같이 정수를 하나씩 입력 받아 push_back()으로 벡터의 끝에 삽입

```cpp
it = my_max_element(v.begin(), v.end());
cout << "최대값: " << *it << endl;
it = my_min_element(v.begin(), v.end());
cout << "최소값: " << *it << endl;
```
- ForwardIt가 vector<int>::iterator로 구체화되어 호출됨
- 문제의 main은 벡터를 초기화만 하지만, 실행결과처럼 숫자를 입력 받기 위해 예제와 같이 입력 부분을 작성

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = myalgo
```
- 템플릿 함수는 헤더파일에만 있으므로 컴파일할 소스파일은 main.cpp 하나, 목적파일도 main.o 하나

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- g++ -o myalgo main.o로 링크

```makefile
main.o : main.cpp myalgo.hpp
	$(CX) $(CXFLAGS) -c main.cpp
```
- main.o는 main.cpp와 myalgo.hpp에 의존, 템플릿 함수를 수정하면 main.cpp가 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
5개의 정수를 입력하세요>> 30 -7 250 6 120
최대값: 250
최소값: -7
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| myalgo.hpp | <img src="img/cpp104-6-1.png"> |
| main.cpp | <img src="img/cpp104-6-2.png"> |
| Makefile | <img src="img/cpp104-6-3.png"> |
| 실행결과 | <img src="img/cpp104-6-4.png"> |

# 실습과제 7
아래 결과가 나오도록 sort 함수와 동일하게 동작하는 템플릿 함수 my_sort 함수를 정의하시오.

## mysort.hpp
```cpp
#ifndef _MYSORT_HPP_
#define _MYSORT_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
template <class T>
void myswap(T& a, T& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}
```
- 10장 템플릿에서 배운 myswap 템플릿 함수, 두 원소의 값을 교환할 때 사용
- 참조 매개변수이므로 호출한 곳의 원소가 직접 교환됨

```cpp
template< class RandomIt >
void my_sort(RandomIt first, RandomIt last) {
```
- 강의노트의 sort 원형과 같은 형태, 리턴값 없음
- first : 정렬을 시작할 원소의 주소, last : 정렬할 마지막 원소의 다음 주소

```cpp
    RandomIt i, j, minIt;
    for (i = first; i != last; i++) {
        minIt = i;
```
- **선택 정렬** 방식, i 위치에 남은 원소 중 가장 작은 값을 차례로 채움
- i 위치의 원소를 최소값으로 가정

```cpp
        for (j = i + 1; j != last; j++) {
            if (*j < *minIt)
                minIt = j;
        }
```
- i 다음 원소부터 끝까지 조사하여 가장 작은 원소의 주소를 minIt에 저장
- sort와 같이 < 연산자로 비교하므로 오름차순 정렬

```cpp
        myswap(*i, *minIt);
    }
}
```
- 찾은 최소값을 i 위치의 원소와 교환
- *i, *minIt는 원소(int)이므로 myswap의 T는 int로 구체화됨
- 반복이 끝나면 first부터 last 앞까지 오름차순으로 정렬됨

## main.cpp
```cpp
vector<int> v={30,-7,250,6,120};
vector<int>::iterator it;
my_sort(v.begin(), v.end());
```
- 문제에 주어진 main, RandomIt가 vector<int>::iterator로 구체화되어 벡터 전체를 정렬

```cpp
for (it = v.begin(); it < v.end(); it++)
    cout << *it << ' ';
```
- 정렬된 원소 출력

## Makefile
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o
TARGET = mysort
```
- 템플릿 함수는 헤더파일에만 있으므로 컴파일할 소스파일은 main.cpp 하나, 목적파일도 main.o 하나

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- g++ -o mysort main.o로 링크

```makefile
main.o : main.cpp mysort.hpp
	$(CX) $(CXFLAGS) -c main.cpp
```
- main.o는 main.cpp와 mysort.hpp에 의존, 템플릿 함수를 수정하면 main.cpp가 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

```
-7 6 30 120 250
```
## 실행결과
| 구분 | 이미지 |
| --- | --- |
| mysort.hpp | <img src="img/cpp104-7-1.png"> |
| main.cpp | <img src="img/cpp104-7-2.png"> |
| Makefile | <img src="img/cpp104-7-3.png"> |
| 실행결과 | <img src="img/cpp104-7-4.png"> |

