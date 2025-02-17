#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 균형잡힌 문자열 판단
bool isBalanced(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
    }
    return balance == 0;
}

// 올바른 문자열 판단
bool isCorrect(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else {
            balance--;
            if (balance < 0) return false; // ')'가 먼저 나오면 올바르지 않음
        }
    }
    return true;
}

// 재귀적으로 변환하는 함수
string recursiveConvert(const string& w) {
    if (w.empty()) return ""; // 빈 문자열 반환

    // u와 v 분리
    string u = "", v = "";
    int balance = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') balance++;
        else balance--;

        u += w[i];

        if (balance == 0) {
            v = w.substr(i + 1); // v는 나머지 부분
            break;
        }
    }

    if (isCorrect(u)) {
        // u가 올바른 문자열이면 v에 대해 재귀적으로 수행
        return u + recursiveConvert(v);
    }
    else {
        // u가 올바른 문자열이 아닐 경우
        string result = "("; // '(' 추가
        result += recursiveConvert(v); // v에 대해 재귀 호출
        result += ")"; // ')' 추가

        // u의 첫 번째와 마지막 문자를 제거하고 나머지 문자열의 괄호를 뒤집기
        for (int j = 1; j < u.size() - 1; j++) {
            if (u[j] == '(') result += ')';
            else result += '(';
        }

        return result; // 최종 결과 반환
    }
}

string solution(string p) {
    return recursiveConvert(p); // 변환 함수 호출
}

// 테스트 코드
int main() {
    cout << solution("(()())()") << endl; // "(()())()"
    cout << solution(")(") << endl;       // "()"
    cout << solution("()))((()") << endl; // "()(())()"
    return 0;
}
