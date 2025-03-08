//숫자가 "행복한지" 판단하는 알고리즘을 작성하세요.
//행복한 숫자는 다음 과정으로 정의되는 숫자입니다.임의의 양의 정수에서 시작하여 해당 숫자를 
// 숫자의 제곱 합으로 대체 하고 숫자가 1이 될 때까지(1이 되면 숫자는 그대로 유지됨) 
// 이 과정을 반복하거나 1을 포함하지 않는 순환에서 끝없이 반복합니다.이 과정이 1로 끝나는 숫자는 행복한 숫자입니다.
//
//예: 19는 행복한 숫자입니다.
//
//1 ^ 2 + 9 ^ 2 = 82
//8 ^ 2 + 2 ^ 2 = 68
//6 ^ 2 + 8 ^ 2 = 100
//1 ^ 2 + 0 ^ 2 + 0 ^ 2 = 1
//
////===
//
//cpp


#include <iostream>          // 입력과 출력을 위한 라이브러리
#include <unordered_set>     // 중복된 숫자를 추적하기 위한 해시셋
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cctype>
// 숫자의 각 자리 숫자의 제곱 합을 계산하는 함수
int sumOfSquares(int num) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;    // 마지막 자리 숫자 추출
        sum += digit * digit;    // 자리 숫자의 제곱을 합산
        num /= 10;               // 다음 자리 숫자로 이동
    }
    return sum;
}

int main() {
    int number;
    std::cout << "양의 정수를 입력하세요: ";
    std::cin >> number;

    // 입력값이 양의 정수인지 검증
    if (number <= 0) {
        std::cout << "양의 정수를 입력해주세요." << std::endl;
        return 1;
    }

    std::unordered_set<int> seenNumbers; // 이미 본 숫자를 저장할 해시셋
    int currentNumber = number;

    // 현재 숫자가 1이 아니고 이전에 본 숫자가 아닐 때까지 반복
    while (currentNumber != 1 && seenNumbers.find(currentNumber) == seenNumbers.end()) {
        seenNumbers.insert(currentNumber);           // 현재 숫자를 해시셋에 추가
        currentNumber = sumOfSquares(currentNumber);  // 제곱 합으로 숫자 대체
    }

    // 결과 출력
    if (currentNumber == 1) {
        std::cout << number << "은(는) 행복한 숫자입니다." << std::endl;
    }
    else {
        std::cout << number << "은(는) 행복한 숫자가 아닙니다." << std::endl;
    }

    return 0;
}
//프로그램 작동 원리 설명 :
//
//라이브러리 포함 : 프로그램은 입력과 출력을 위해 <iostream>을, 중복된 숫자를 추적하기 위해 <unordered_set>을 포함합니다.
//
//sumOfSquares 함수 : 이 함수는 주어진 숫자의 각 자리 숫자를 추출하여 제곱한 후 모두 합산합니다.예를 들어, 숫자가 19라면 1² + 9² = 82를 반환합니다.
//
//메인 함수 시작 : 사용자로부터 양의 정수를 입력받습니다.입력된 숫자가 양의 정수가 아닌 경우, 오류 메시지를 출력하고 프로그램을 종료합니다.
//
//중복 숫자 추적 : seenNumbers라는 해시셋을 사용하여 이전에 등장한 숫자들을 저장합니다.이는 사이클을 감지하기 위함입니다.
//
//행복한 숫자 판별 루프 : 현재 숫자가 1이 아니고, 이전에 본 숫자가 아닐 때까지 반복합니다.매 반복마다 현재 숫자를 seenNumbers에 추가하고, sumOfSquares 함수를 호출하여 다음 숫자를 계산합니다.
//
//결과 출력 : 루프가 종료된 후, 현재 숫자가 1이면 입력된 숫자는 행복한 숫자임을 출력하고, 그렇지 않다면 행복한 숫자가 아님을 출력합니다.
//
//이 과정을 통해 프로그램은 주어진 숫자가 행복한 숫자인지 효과적으로 판단할 수 있습니다.

//
// 행복한지 판단하는 알고리즘 작성하는 것으로
// 처음에는 100이 나와야만 1이 나온다 생각하여 100을 리턴하는 것으로 생각하였으나
// 함수안에서 조건문을 더 쓸 필요는 없다고 생각하여 
// while 문에 조건을 1 이거나 이전에 본 숫자이면 중단하도록 조건 사용
// unordered_Set 사용 이유는 평균 시간 복잡도가 O(1)이기 때문에 빠르기 떄문에 사용
//  