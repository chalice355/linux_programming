// **********************************************
// 제 목 : max_element, min_element와 동일하게 동작하는 템플릿 함수
// 날 짜 : 2026년 11월 24일
// 작성자 : 2001218 임성배
// **********************************************
#ifndef _MYALGO_HPP_
#define _MYALGO_HPP_

// max_element와 동일한 형태
// ForwardIt : iterator 클래스명, 예) vector<int>::iterator
// first : 조사할 첫번째 원소의 주소를 저장한 iterator객체
// last  : 조사할 마지막 원소의 다음 주소를 저장한 iterator객체
template< class ForwardIt >
ForwardIt my_max_element(ForwardIt first, ForwardIt last) {
    if (first == last) return last;     // 조사할 원소가 없으면 last 리턴
    ForwardIt maxIt = first;            // 첫번째 원소의 주소를 최대값의 주소로 가정
    ForwardIt it;
    for (it = first; it != last; it++) {
        if (*maxIt < *it)               // 피연산자1 < 피연산자2 -> true
            maxIt = it;                 // 더 큰 원소의 주소를 저장
    }
    return maxIt;                       // 최대값의 주소를 저장한 iterator객체 리턴
}

// min_element와 동일한 형태
template< class ForwardIt >
ForwardIt my_min_element(ForwardIt first, ForwardIt last) {
    if (first == last) return last;
    ForwardIt minIt = first;            // 첫번째 원소의 주소를 최소값의 주소로 가정
    ForwardIt it;
    for (it = first; it != last; it++) {
        if (*it < *minIt)               // 더 작은 원소를 찾으면
            minIt = it;                 // 그 원소의 주소를 저장
    }
    return minIt;                       // 최소값의 주소를 저장한 iterator객체 리턴
}

#endif
