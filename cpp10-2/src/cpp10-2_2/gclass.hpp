// **********************************************
// 제 목 : 2개의 템플릿 매개변수를 가진 GClass와 swap 함수
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _GCLASS_HPP_
#define _GCLASS_HPP_

template <class T1, class T2>
class GClass {
    T1 data1;
    T2 data2;
public:
    GClass();
    void set(T1 a, T2 b);
    void get(T1& a, T2& b);
    void swap();                    
};

template <class T1, class T2>
GClass<T1, T2>::GClass() {
    data1 = 0;
    data2 = 0;
}

template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
    data1 = a;
    data2 = b;
}

template <class T1, class T2>
void GClass<T1, T2>::get(T1& a, T2& b) {
    a = data1;
    b = data2;
}

template <class T1, class T2>
void GClass<T1, T2>::swap() {
    T1 tmp = data1;                 
    data1 = data2;
    data2 = tmp;
}

#endif
