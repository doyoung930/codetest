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
                answer = { startPoint, endPoint }; // ���ο� �ִ� ��η� ������Ʈ
                found = true; // ��ΰ� �߰ߵ�
            }
        }
    }

    return found ? answer : vector<int>(); // ����� ������ �� ���� ��ȯ
}