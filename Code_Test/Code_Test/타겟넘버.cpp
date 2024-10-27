// 프로그래머스 타겟 넘버 DFS

#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int index, int currentSum, int target) {
    // 모든 숫자를 사용한 경우
    if (index == numbers.size()) {
        return currentSum == target ? 1 : 0; // 타겟과 일치하면 1, 아니면 0 반환
    }

    // 현재 숫자를 더하는 경우와 빼는 경우의 결과를 합산
    return dfs(numbers, index + 1, currentSum + numbers[index], target) +
        dfs(numbers, index + 1, currentSum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, 0, 0, target);
}