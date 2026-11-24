// **********************************************
// 제 목 : sort와 동일하게 동작하는 템플릿 함수 my_sort
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _MYSORT_HPP_
#define _MYSORT_HPP_

// 두 매개 변수 a, b의 값을 교환하는 템플릿 함수
template <class T>
void myswap(T& a, T& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

// sort와 동일한 형태, 선택 정렬로 오름차순 정렬
// RandomIt : iterator 클래스명, 예) vector<int>::iterator
// first : 정렬을 시작할 원소의 주소를 저장한 iterator객체
// last  : 정렬할 마지막 원소의 다음 주소를 저장한 iterator객체
template< class RandomIt >
void my_sort(RandomIt first, RandomIt last) {
    RandomIt i, j, minIt;
    for (i = first; i != last; i++) {
        minIt = i;                          // i 위치의 원소를 최소값으로 가정
        for (j = i + 1; j != last; j++) {   // i 다음 원소부터 끝까지 조사
            if (*j < *minIt)                // 더 작은 원소를 찾으면
                minIt = j;                  // 그 원소의 주소를 저장
        }
        myswap(*i, *minIt);                 // 최소값을 i 위치로 이동
    }
}

#endif
