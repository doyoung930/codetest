#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int startPoint = 0;
    int sum = 0;
    bool found = false;

    for (int endPoint = 0; endPoint < sequence.size(); endPoint++) {
        sum += sequence[endPoint];

        while (sum > k) {
            sum -= sequence[startPoint];
            startPoint++;
        }

        if (sum == k) {
            if (!found || (endPoint - startPoint < answer[1] - answer[0])) {
                answer = { startPoint, endPoint }; // 새로운 최단 경로로 업데이트
                found = true; // 경로가 발견됨
            }
        }
    }

    return found ? answer : vector<int>(); // 결과가 없으면 빈 벡터 반환
}