// ���α׷��ӽ� Ÿ�� �ѹ� DFS

#include <string>
#include <vector>

using namespace std;

int dfs(const vector<int>& numbers, int index, int currentSum, int target) {
    // ��� ���ڸ� ����� ���
    if (index == numbers.size()) {
        return currentSum == target ? 1 : 0; // Ÿ�ٰ� ��ġ�ϸ� 1, �ƴϸ� 0 ��ȯ
    }

    // ���� ���ڸ� ���ϴ� ���� ���� ����� ����� �ջ�
    return dfs(numbers, index + 1, currentSum + numbers[index], target) +
        dfs(numbers, index + 1, currentSum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, 0, 0, target);
}