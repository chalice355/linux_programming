// **********************************************
// 제 목 : 동적 배열을 사용하는 템플릿 클래스 Container (교재 522쪽 12번)
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _CONTAINER_HPP_
#define _CONTAINER_HPP_

template <class T>
class Container {
    T* p;                           
    int size;                      
public:
    Container(int n);               
    ~Container();
    void set(int index, T value) { p[index] = value; }  
    T get(int index);               
};

template <class T>
Container<T>::Container(int n) {    
    p = new T[n];                   
    size = n;
}

template <class T>
Container<T>::~Container() {        
    delete[] p;                     
}

template <class T>
T Container<T>::get(int index) {    
    return p[index];
}

#endif
