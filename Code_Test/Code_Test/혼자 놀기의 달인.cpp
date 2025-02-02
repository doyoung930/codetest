#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int max = 0, second_max = 0;

    vector<bool> visited(cards.size(), false);

    for (int i = 0; i < cards.size(); i++) {
        if (!visited[i]) {
            int current_num = i;
            int count = 0;

            while (!visited[current_num]) {
                visited[current_num] = true;
                current_num = cards[current_num] - 1;
                count++;
            }

            if (max < count) {
                second_max = max;
                max = count;
            }
            else if (second_max < count) {
                second_max = count;
            }

        }
    }
    answer = max * second_max;
    return answer;
}
