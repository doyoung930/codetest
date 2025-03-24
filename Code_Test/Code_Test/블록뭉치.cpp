#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> c) {

	vector<int> answer;
	int n = c.size();

	for (int i = 0; i < n; i++) {

		bool left = true, right = true;

		for (int k = 0; k < i; k++) {
			int a = (k % 5) + 1;
			if ( c[i - k - 1] != a) {
				left = false;
				break;
			}
		}

		for (int k = 0; k < n - i - 1; k++) {
			int a = 5 - (k % 5);
			if (c[i + k + 1] != a) {
				right = false;
				break;
			}
		}

		if (left && right) {
			
			answer.push_back(i + 1);
			answer.push_back(c[i]);

			return answer;
		}
	}
}

int main() {
	// 첫 번째 테스트 케이스
	vector<int> test1 = { 2, 1, 3, 5, 4 };
	vector<int> result1 = solution(test1);
	cout << "[" << result1[0] << ", " << result1[1] << "]" << endl; // 예상 출력: [3, 3]

	// 두 번째 테스트 케이스
	vector<int> test2 = { 4, 5, 4 };
	vector<int> result2 = solution(test2);
	cout << "[" << result2[0] << ", " << result2[1] << "]" << endl; // 예상 출력: [1, 4]

	return 0;
}