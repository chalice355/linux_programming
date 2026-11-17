// **********************************************
// 제 목 : 템플릿 클래스 MyQueue
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _MYQUEUE_HPP_
#define _MYQUEUE_HPP_
#include <iostream>
using namespace std;

template <class T>
class MyQueue {
    int front;             
    int rear;             
    int count;           
    T data[100];           
public:
    MyQueue();
    void enqueue(T element);  
    T dequeue();              
    bool isEmpty();
};

template <class T>
MyQueue<T>::MyQueue() { 
    front = 0;
    rear = 0;
    count = 0;  
}

template <class T>
void MyQueue<T>::enqueue(T element) {
    if (count == 100) {
        cout << "queue full" << endl;
        return;
    }
    data[rear] = element;
    rear = (rear + 1) % 100;            
    count++;
}

template <class T>
T MyQueue<T>::dequeue() {
    if (count == 0) {
        cout << "queue empty" << endl; 
        return T();
    }
    T retData = data[front];
    front = (front + 1) % 100;
    count--;
    return retData;
}

template <class T>
bool MyQueue<T>::isEmpty() {
    return count == 0;
}

#endif
