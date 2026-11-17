// **********************************************
// 제 목 : 템플릿 클래스 MyQueue
// 날 짜 : 2026년 11월 17일
// 작성자 : 2001218 임성배
// **********************************************
#include <iostream>
#include <string>
#include "myqueue.hpp"
using namespace std;

int main() {
    MyQueue<int> iQueue;                
    iQueue.enqueue(1);
    iQueue.enqueue(2);
    iQueue.enqueue(3);
    cout << "int 큐 : ";
    while (!iQueue.isEmpty())
        cout << iQueue.dequeue() << ' ';
    cout << endl;

    MyQueue<double> dQueue;             
    dQueue.enqueue(1.5);
    dQueue.enqueue(2.5);
    cout << "double 큐 : " << dQueue.dequeue() << ' ';
    cout << dQueue.dequeue() << endl;

    MyQueue<char>* p = new MyQueue<char>();   
    p->enqueue('a');
    p->enqueue('b');
    p->enqueue('c');
    cout << "char 큐 : ";
    while (!p->isEmpty())
        cout << p->dequeue() << ' ';
    cout << endl;
    delete p;

    MyQueue<string> sQueue;         
    sQueue.enqueue("first");
    sQueue.enqueue("second");
    cout << "string 큐 : " << sQueue.dequeue() << ' ';
    cout << sQueue.dequeue() << endl;

    cout << "빈 큐에서 꺼내기 : ";
    iQueue.dequeue();     
    return 0;
}
