//정수 배열이 주어지면, 두 숫자의 인덱스를 반환하여 두 숫자를 더하면 특정 목표에 도달하도록 합니다.
//각 입력에 대해 정확히 하나의 솔루션이 있다고 가정할 수 있 습니다.
//예를 들어
//숫자 = [2, 7, 11, 15], 목표 = 9 인 경우
//
//nums[0] + nums[1] = 2 + 7 = 9 이므로
//
//[0, 1]을 반환합니다.
//
//반환 형식은 0 부터 시작하는 인덱스 이며 오름차 순으로 정렬됩니다.


//---


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cctype>
// 두 수의 합을 찾는 함수
std::vector<int> twoSum(const std::vector<int>&nums, int target) {
    std::unordered_map<int, int> numMap; // 숫자와 그 인덱스를 저장할 해시 맵
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i]; // 목표값에서 현재 숫자를 뺀 보수
        // 보수가 해시 맵에 존재하는지 확인
        if (numMap.find(complement) != numMap.end()) {
            return { numMap[complement], i }; // 보수의 인덱스와 현재 인덱스를 반환
        }
        numMap[nums[i]] = i; // 현재 숫자와 인덱스를 해시 맵에 저장
    }
    return {}; // 문제의 제약 조건에 따라 항상 해답이 존재하므로 도달하지 않음
}

int main() {
    std::vector<int> nums = { 2, 7, 11, 15 }; // 입력 배열
    int target = 9; // 목표값
    std::vector<int> result = twoSum(nums, target); // 두 수의 합을 찾는 함수 호출

    // 결과 출력
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
    return 0;
}
//이 프로그램은 주어진 정수 배열 nums에서 두 숫자의 합이 목표값 target이 되는 두 숫자의 인덱스를 찾습니다.다음은 프로그램이 동작하는 단계별 설명입니다 :
//
//해시 맵 초기화 : std::unordered_map<int, int>를 사용하여 각 숫자와 그 숫자의 인덱스를 저장할 해시 맵 numMap을 생성합니다.
//
//배열 순회 : for 루프를 사용하여 배열 nums를 처음부터 끝까지 순회합니다.루프의 인덱스는 i입니다.
//
//보수 계산 : 현재 숫자 nums[i]에 대해 목표값 target에서 이 숫자를 뺀 값을 complement로 계산합니다.이는 현재 숫자와 합쳐서 목표값이 되는 숫자를 의미합니다.
//
//보수 확인 : 해시 맵 numMap에 complement가 존재하는지 확인합니다.존재한다면, 이 보수의 인덱스와 현재 인덱스 i를 벡터로 반환합니다.이때 반환된 인덱스는 오름차순으로 정렬되어 있습니다.
//
//해시 맵 업데이트 : 보수가 해시 맵에 없으면, 현재 숫자 nums[i]와 그 인덱스 i를 해시 맵에 추가합니다.이렇게 하면 이후 숫자에서 이 숫자를 보수로 사용할 수 있습니다.
//
//결과 출력 : main 함수에서는 예제 배열{ 2, 7, 11, 15 }와 목표값 9를 사용하여 twoSum 함수를 호출하고, 반환된 인덱스를[0, 1] 형태로 출력합니다.
//
//이 프로그램은 해시 맵을 사용하여 각 숫자에 대해 보수를 효율적으로 찾기 때문에 시간 복잡도는 O(n)입니다.또한, 문제의 제약 조건에 따라 항상 정확한 한 쌍의 해가 존재한다고 가정하므로, 모든 경우에 올바른 결과를 반환합니다.
