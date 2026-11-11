# 8장 상속 (2) 실습과제

모든 과제는 리눅스에서 분할컴파일 구조로 작성하고 make로 빌드함

| 폴더 | 내용 |
| --- | --- |
| task2 | 실습과제 2 |
| task3 | 실습과제 3 |
| prob1 | 실습문제 1번 |
| prob3 | 실습문제 3번 |

# 실습과제 1
예제 8-3에서 SmartTV 객체 htv가 생성될 때 자동으로 호출되는 생성자를 순서대로 자세히 설명하시오. htv 생성시 지정된 인수가 각 생성자에 어떻게 전달되는지도 자세히 설명하시오.

```cpp
SmartTV htv("192.0.0.1", 32);
```
- SmartTV 객체 htv를 생성하면서 인수 "192.0.0.1"과 32를 전달

## 생성자 호출 순서
| 순서 | 호출되는 생성자 | 받는 인수 | 하는 일 |
| --- | --- | --- | --- |
| 1 | `SmartTV(string ipAddr, int size)` | ipAddr = "192.0.0.1", size = 32 | 컴파일러가 가장 먼저 호출, 본체를 실행하기 전에 초기화 리스트의 `WideTV(size, true)`로 이동 |
| 2 | `WideTV(int size, bool videoIn)` | size = 32, videoIn = true | 본체를 실행하기 전에 초기화 리스트의 `TV(size)`로 이동 |
| 3 | `TV(int size)` | size = 32 | TV는 기본클래스가 없으므로 바로 본체 실행, `this->size = 32` |
| 4 | `WideTV` 본체 실행 | | `this->videoIn = true` |
| 5 | `SmartTV` 본체 실행 | | `this->ipAddr = "192.0.0.1"` |

- 생성자의 **호출**은 파생클래스(SmartTV) → WideTV → TV 순서로 일어남
- 생성자 본체의 **실행**은 반대로 기본클래스부터 TV → WideTV → SmartTV 순서로 완료됨
- 파생클래스 객체는 기본클래스 멤버를 포함하므로, 기본클래스 부분이 먼저 초기화되어야 파생클래스 부분을 초기화할 수 있기 때문

## 인수 전달 과정
```cpp
SmartTV(string ipAddr, int size) : WideTV(size, true) {
    this->ipAddr = ipAddr;
}
```
- "192.0.0.1"은 ipAddr로, 32는 size로 전달됨
- `: WideTV(size, true)`는 기본클래스 생성자를 명시적으로 지정, size(32)와 상수 true를 WideTV 생성자에 전달
- ipAddr는 SmartTV 자신의 멤버이므로 SmartTV 본체에서 저장

```cpp
WideTV(int size, bool videoIn) : TV(size) {
    this->videoIn = videoIn;
}
```
- SmartTV로부터 size = 32, videoIn = true를 받음
- `: TV(size)`로 size(32)를 다시 TV의 매개변수 생성자에 전달
- videoIn(true)은 WideTV 본체에서 저장

```cpp
TV(int size) { this->size = size; }
```
- WideTV로부터 size = 32를 받아 멤버변수 size에 저장
- TV() 기본생성자가 아니라 TV(int size)가 호출되는 이유는 WideTV가 TV(size)로 명시했기 때문

## 결과
| 클래스 | 멤버 | 값 | 전달 경로 |
| --- | --- | --- | --- |
| TV | size | 32 | main → SmartTV → WideTV → TV |
| WideTV | videoIn | true | SmartTV의 초기화 리스트에서 상수로 지정 |
| SmartTV | ipAddr | "192.0.0.1" | main → SmartTV |

```
size=32
videoIn=true
IP=192.0.0.1
```

# 실습과제 2
예제 8-3에서 다음 결과가 나오도록 코드를 수정하시오. 각 클래스에 생성자와 멤버변수 설정함수를 추가해야 함.

## tv.hpp (클래스 선언부)
```cpp
#ifndef _TV_HPP_
#define _TV_HPP_
...
#endif
```
- 헤더파일 중복 포함 방지

```cpp
#include <string>
using namespace std;
```
- SmartTV의 멤버 ipAddr에 string을 사용하므로 string 헤더 포함

```cpp
class TV {
    int size;
public:
    TV();
    void setSize(int size);
    int getSize();
};
```
- 스크린 크기 size를 private 멤버로 가짐
- TV() 기본생성자, size 설정함수 setSize(), 반환함수 getSize() 선언

```cpp
class WideTV : public TV {
    bool videoIn;
public:
    WideTV();
    void setWideTV(int size, bool videoIn);
    bool getVideoIn();
};
```
- TV를 public 상속, 비디오 입력 여부 videoIn을 멤버로 가짐
- 기본생성자 WideTV(), size와 videoIn을 함께 설정하는 setWideTV() 선언

```cpp
class SmartTV : public WideTV {
    string ipAddr;
public:
    SmartTV();
    void setSmartTV(int size, bool videoIn, string ipAddr);
    string getIpAddr();
};
```
- WideTV를 public 상속, 인터넷 주소 ipAddr을 멤버로 가짐
- 기본생성자 SmartTV(), 세 멤버를 모두 설정하는 setSmartTV() 선언

## tv.cpp (클래스 구현부)
```cpp
#include <iostream>
#include "tv.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 tv.hpp 포함

```cpp
TV::TV() {
    size = 20;
    cout << "TV 생성" << endl;
}
```
- size를 20으로 초기화하고 "TV 생성" 출력

```cpp
void TV::setSize(int size) {
    this->size = size;
}
int TV::getSize() {
    return size;
}
```
- size 설정 및 반환

```cpp
WideTV::WideTV() {
    videoIn = true;
    cout << "WideTV 생성" << endl;
}
```
- 기본클래스 생성자를 지정하지 않았으므로 컴파일러가 TV()를 자동으로 먼저 호출
- 그 다음 videoIn을 true로 초기화하고 "WideTV 생성" 출력

```cpp
void WideTV::setWideTV(int size, bool videoIn) {
    setSize(size);
    this->videoIn = videoIn;
}
```
- size는 TV의 private 멤버이므로 직접 대입할 수 없고, 상속받은 setSize()로 설정
- videoIn은 자신의 멤버이므로 직접 저장

```cpp
SmartTV::SmartTV() {
    ipAddr = "";
    cout << "SmartTV 생성" << endl;
}
```
- 컴파일러가 WideTV()를 자동으로 먼저 호출하므로 TV 생성 → WideTV 생성 → SmartTV 생성 순서로 출력됨

```cpp
void SmartTV::setSmartTV(int size, bool videoIn, string ipAddr) {
    setWideTV(size, videoIn);
    this->ipAddr = ipAddr;
}
```
- size, videoIn은 상속받은 setWideTV()에 전달하여 설정
- ipAddr은 자신의 멤버이므로 직접 저장

## main.cpp (메인함수)
```cpp
#include <iostream>
#include "tv.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 tv.hpp 포함

```cpp
SmartTV htv;
```
- 기본생성자로 htv 생성, TV() → WideTV() → SmartTV() 순서로 생성자 본체가 실행됨

```cpp
htv.setSmartTV(50, false, "192.0.0.2");
```
- size = 50, videoIn = false, ipAddr = "192.0.0.2"로 설정

```cpp
cout << "size = " << htv.getSize() << endl;
cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
cout << "IP = " << htv.getIpAddr() << endl;
```
- 상속받은 getSize(), getVideoIn()과 자신의 getIpAddr()로 값 출력
- boolalpha는 bool 값을 0/1 대신 true/false로 출력하게 하는 조작자

## Makefile (빌드설정)
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o tv.o
TARGET = tv
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, make만 입력하면 실행됨
- g++ -o tv main.o tv.o로 링크

```makefile
main.o : main.cpp tv.hpp
	$(CX) $(CXFLAGS) -c main.cpp

tv.o : tv.cpp tv.hpp
	$(CX) $(CXFLAGS) -c tv.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

## 소스파일, Makefile, 실행결과
| 구분 | 이미지 |
| --- | --- |
| tv.hpp | <img src="task2/task2-1.png"> |
| tv.cpp | <img src="task2/task2-2.png"> |
| main.cpp | <img src="task2/task2-3.png"> |
| Makefile | <img src="task2/task2-4.png"> |
| 실행결과 | <img src="task2/task2-5.png"> |

# 실습과제 3
위치좌표(x, y)를 멤버로 갖는 Shape 클래스를 선언하고 이를 상속한 파생클래스 Circle, Rect, Triangle 클래스를 작성하시오. Shape의 멤버변수는 private로 선언하고, 파생클래스 생성자를 정의할 때 호출할 기본클래스의 생성자를 명시적으로 지정할 것.

## shape.hpp (클래스 선언부)
```cpp
class Shape {
private:
    int x, y;
public:
    Shape(int x, int y);
    ~Shape();
    void showXY();
};
```
- x, y를 private으로 선언
- 좌표를 받는 매개변수 생성자, 소멸자, 좌표 출력함수 showXY() 선언

```cpp
class Circle : public Shape {
    int radius;
public:
    Circle(int x, int y, int radius);
    ~Circle();
    void show();
};
```
- Shape를 public 상속, 좌표와 반지름을 받는 생성자와 소멸자 선언

```cpp
class Rect : public Shape { ... };
class Triangle : public Shape { ... };
```
- Rect(폭, 높이), Triangle(밑변, 높이)도 같은 구조로 생성자, 소멸자, show() 선언

## shape.cpp (클래스 구현부)
```cpp
#include <iostream>
#include "shape.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 shape.hpp 포함

```cpp
Shape::Shape(int x, int y) {
    this->x = x;
    this->y = y;
    cout << "Shape생성 , ";
}
```
- 좌표를 저장하고 "Shape생성 , "을 줄바꿈 없이 출력, 뒤이어 파생클래스 생성자의 출력이 같은 줄에 이어짐

```cpp
Shape::~Shape() {
    cout << "Shape소멸" << endl;
}
```
- 소멸자는 파생클래스 소멸자가 끝난 뒤 실행되므로 줄의 마지막에 출력하고 줄바꿈

```cpp
void Shape::showXY() {
    cout << "좌표 (" << x << "," << y << ")에 ";
}
```
- private 멤버 x, y를 출력하는 함수, 파생클래스는 이 함수로 좌표를 출력

```cpp
Circle::Circle(int x, int y, int radius) : Shape(x, y) {
    this->radius = radius;
    cout << "Circle생성" << endl;
}
```
- `: Shape(x, y)`로 호출할 기본클래스 생성자를 명시적으로 지정
- x, y는 private이라 Circle에서 직접 저장할 수 없으므로 Shape 생성자에 전달하여 초기화
- Shape 생성자가 먼저 실행된 뒤 radius를 저장하고 "Circle생성" 출력

```cpp
Circle::~Circle() {
    cout << "Circle소멸 , ";
}
```
- 파생클래스 소멸자가 먼저 실행되고, 끝나면 Shape 소멸자가 자동으로 호출됨

```cpp
void Circle::show() {
    showXY();
    cout << "반지름 " << radius << "인 원" << endl;
}
```
- showXY()로 좌표를 출력한 뒤 반지름 출력

```cpp
Rect::Rect(int x, int y, int width, int height) : Shape(x, y) { ... }
Triangle::Triangle(int x, int y, int base, int height) : Shape(x, y) { ... }
```
- Rect, Triangle도 같은 방식으로 Shape(x, y)를 명시적으로 지정하고 소멸자, show()를 구현

## main.cpp (메인함수)
```cpp
#include <iostream>
#include "shape.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 shape.hpp 포함

```cpp
Circle x(0, 0, 2);
Rect y(1, 1, 5, 10);
Triangle z(2, 2, 5, 10);
```
- 매개변수 생성자로 객체 생성, 각 객체마다 Shape 생성자 → 파생클래스 생성자 순서로 실행

```cpp
x.show();
y.show();
z.show();
```
- 각 도형 정보 출력

```cpp
}
```
- main()이 끝나면 지역객체가 생성의 역순(z → y → x)으로 소멸
- 각 객체마다 파생클래스 소멸자 → Shape 소멸자 순서로 실행

## Makefile (빌드설정)
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o shape.o
TARGET = shapes
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, make만 입력하면 실행됨
- g++ -o shapes main.o shape.o로 링크

```makefile
main.o : main.cpp shape.hpp
	$(CX) $(CXFLAGS) -c main.cpp

shape.o : shape.cpp shape.hpp
	$(CX) $(CXFLAGS) -c shape.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

## 소스파일, Makefile, 실행결과
| 구분 | 이미지 |
| --- | --- |
| shape.hpp | <img src="task3/task3-1.png"> |
| shape.cpp | <img src="task3/task3-2.png"> |
| main.cpp | <img src="task3/task3-3.png"> |
| Makefile | <img src="task3/task3-4.png"> |
| 실행결과 | <img src="task3/task3-5.png"> |

# 실습문제 1번
교재에 주어진 Circle 클래스를 상속받아 이름을 추가한 NamedCircle 클래스를 작성하여 아래 main()이 실행되도록 하시오.

```
반지름이 3인 waffle
```

## circle.hpp (클래스 선언부)
```cpp
#include <string>
using namespace std;
```
- NamedCircle의 멤버 name에 string을 사용하므로 string 헤더 포함

```cpp
class Circle {
    int radius;
public:
    Circle(int radius = 0);
    int getRadius();
    void setRadius(int radius);
    double getArea();
};
```
- 교재에 주어진 Circle 클래스, 분할컴파일을 위해 선언부만 헤더파일에 작성
- radius는 private이므로 파생클래스에서도 직접 접근 불가
- 디폴트 매개변수(radius = 0)는 선언부에만 작성

```cpp
class NamedCircle : public Circle {
    string name;
public:
    NamedCircle(int radius, string name);
    void show();
};
```
- Circle을 public 상속하고 원의 이름 name을 추가
- 반지름과 이름을 받는 생성자, 출력함수 show() 선언

## circle.cpp (클래스 구현부)
```cpp
#include <iostream>
#include "circle.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 circle.hpp 포함

```cpp
Circle::Circle(int radius) {
    this->radius = radius;
}
int Circle::getRadius() { return radius; }
void Circle::setRadius(int radius) { this->radius = radius; }
double Circle::getArea() { return 3.14 * radius * radius; }
```
- 교재에 주어진 Circle 멤버함수 구현, 구현부에는 디폴트 매개변수를 쓰지 않음

```cpp
NamedCircle::NamedCircle(int radius, string name) : Circle(radius) {
    this->name = name;
}
```
- `: Circle(radius)`로 기본클래스 생성자를 명시적으로 지정하여 radius를 Circle에 전달
- radius는 private이므로 NamedCircle 본체에서 직접 저장할 수 없고 Circle 생성자로 초기화해야 함
- 지정하지 않으면 Circle(0)이 호출되어 반지름이 0이 됨
- name은 자신의 멤버이므로 본체에서 저장

```cpp
void NamedCircle::show() {
    cout << "반지름이 " << getRadius() << "인 " << name << endl;
}
```
- private 멤버 radius는 상속받은 public 함수 getRadius()로 읽어서 출력

## main.cpp (메인함수)
```cpp
#include <iostream>
#include "circle.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 circle.hpp 포함

```cpp
NamedCircle waffle(3, "waffle");
```
- 반지름 3, 이름 waffle인 원 생성, Circle(3) → NamedCircle 본체 순서로 실행

```cpp
waffle.show();
```
- "반지름이 3인 waffle" 출력

## Makefile (빌드설정)
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o circle.o
TARGET = circle
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, make만 입력하면 실행됨
- g++ -o circle main.o circle.o로 링크

```makefile
main.o : main.cpp circle.hpp
	$(CX) $(CXFLAGS) -c main.cpp

circle.o : circle.cpp circle.hpp
	$(CX) $(CXFLAGS) -c circle.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

## 소스파일, Makefile, 실행결과
| 구분 | 이미지 |
| --- | --- |
| circle.hpp | <img src="prob1/prob1-1.png"> |
| circle.cpp | <img src="prob1/prob1-2.png"> |
| main.cpp | <img src="prob1/prob1-3.png"> |
| Makefile | <img src="prob1/prob1-4.png"> |
| 실행결과 | <img src="prob1/prob1-5.png"> |

# 실습문제 3번
교재에 주어진 Point 클래스를 상속받은 ColorPoint 클래스를 작성하고 전체 프로그램을 완성하시오.

```
BLUE색으로 (30,40)에 위치한 점입니다.
```

## point.hpp (클래스 선언부)
```cpp
class Point {
    int x, y;
public:
    Point(int x, int y);
    int getX();
    int getY();
protected:
    void move(int x, int y);
};
```
- 교재에 주어진 Point 클래스, x, y는 private
- move()는 protected이므로 외부(main)에서는 호출할 수 없고 파생클래스에서만 호출 가능

```cpp
class ColorPoint : public Point {
    string color;
public:
    ColorPoint(int x, int y, string color);
    void setPoint(int x, int y);
    void setColor(string color);
    void show();
};
```
- Point를 public 상속하고 색 color를 추가
- 좌표와 색을 받는 생성자, 좌표/색 설정함수, 출력함수 선언

## point.cpp (클래스 구현부)
```cpp
#include <iostream>
#include "point.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 point.hpp 포함

```cpp
Point::Point(int x, int y) { ... }
int Point::getX() { return x; }
int Point::getY() { return y; }
void Point::move(int x, int y) { ... }
```
- 교재에 주어진 Point 멤버함수 구현

```cpp
ColorPoint::ColorPoint(int x, int y, string color) : Point(x, y) {
    this->color = color;
}
```
- Point에는 기본생성자가 없으므로 `: Point(x, y)`로 기본클래스 생성자를 반드시 명시해야 함, 생략하면 컴파일 오류
- color는 자신의 멤버이므로 본체에서 저장

```cpp
void ColorPoint::setPoint(int x, int y) {
    move(x, y);
}
```
- x, y는 private이라 직접 바꿀 수 없으므로 protected 멤버함수 move()를 호출하여 좌표 변경

```cpp
void ColorPoint::setColor(string color) {
    this->color = color;
}
void ColorPoint::show() {
    cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
}
```
- 색 설정
- x, y는 public 함수 getX(), getY()로 읽어서 출력

## main.cpp (메인함수)
```cpp
#include <iostream>
#include "point.hpp"
using namespace std;
```
- cout, endl 사용을 위해 iostream 포함
- 클래스 선언부가 있는 point.hpp 포함

```cpp
ColorPoint cp(5, 5, "RED");
cp.setPoint(30, 40);
cp.setColor("BLUE");
cp.show();
```
- (5,5) 위치의 RED 점을 생성
- 좌표를 (30,40), 색을 BLUE로 바꾼 뒤 출력

## Makefile (빌드설정)
```makefile
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o point.o
TARGET = point
```
- 컴파일러(g++), 컴파일 옵션(-g 디버그 정보, -Wall 모든 경고), 목적파일 목록, 실행파일 이름을 변수로 지정

```makefile
$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
```
- 첫 번째 rule, make만 입력하면 실행됨
- g++ -o point main.o point.o로 링크

```makefile
main.o : main.cpp point.hpp
	$(CX) $(CXFLAGS) -c main.cpp

point.o : point.cpp point.hpp
	$(CX) $(CXFLAGS) -c point.cpp
```
- 각 소스파일을 목적파일로 컴파일, 소스파일이나 헤더파일이 수정되면 다시 컴파일됨

```makefile
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
```
- make clean 입력 시 실행파일과 목적파일 삭제

## 소스파일, Makefile, 실행결과
| 구분 | 이미지 |
| --- | --- |
| point.hpp | <img src="prob3/prob3-1.png"> |
| point.cpp | <img src="prob3/prob3-2.png"> |
| main.cpp | <img src="prob3/prob3-3.png"> |
| Makefile | <img src="prob3/prob3-4.png"> |
| 실행결과 | <img src="prob3/prob3-5.png"> |

