#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    int m[10001] = { 0 }; // m 배열 초기화
    int b[10001] = { 0 }; // b 배열 초기화
    int bSize = 0; // b의 고유한 토핑 개수

    // b 배열에 topping의 개수를 세고, bSize를 계산
    for (int i = 0; i < topping.size(); i++) {
        if (b[topping[i]] == 0) {
            bSize++; // 새로운 토핑 추가
        }
        b[topping[i]]++;
    }

    int mSize = 0; // m의 고유한 토핑 개수

    for (int i = 0; i < topping.size(); i++) {
        // m에 topping[i] 추가
        if (m[topping[i]] == 0) {
            mSize++; // 새로운 토핑 추가
        }
        m[topping[i]]++;

        // b에서 topping[i] 제거
        b[topping[i]]--;
        if (b[topping[i]] == 0) {
            bSize--; // 토핑 제거
        }

        // mSize와 bSize 비교
        if (mSize == bSize) {
            answer++;
        }
    }

    return answer;
}
