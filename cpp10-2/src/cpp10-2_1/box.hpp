// **********************************************
// 제 목 : 템플릿 클래스 Box
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _BOX_HPP_
#define _BOX_HPP_

template <class T>
class Box {
    T val;                        
public:
    Box(T v);
    T getValue();
    void setValue(T v);
};

template <class T>
Box<T>::Box(T v) {
    val = v;
}

template <class T>
T Box<T>::getValue() {
    return val;
}

template <class T>
void Box<T>::setValue(T v) {
    val = v;
}

#endif
