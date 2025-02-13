#include <string>
#include <vector>

using namespace std;


bool checkPartition(int r1, int c1, int r2, int c2, const vector<string>& room) {
    if (r1 == r2) {
        if (c1 > c2) swap(c1, c2);

        return room[r1][c1 + 1] == 'X';
    }

    else if (c1 == c2) {
        if (r1 > r2) swap(r1, r2);

        return room[r1 + 1][c1] == 'X';
    }
    else {
        return (room[r1][c2] == 'X') && (room[r2][c1] == 'X');
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < 5; i++) {

        bool compliance = true;
        vector<pair<int, int>> participants;


        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (places[i][r][c] == 'P') {
                    participants.emplace_back(r, c);
                }
            }
        }

        for (int j = 0; j < participants.size() && compliance; j++) {
            for (int k = j + 1; k < participants.size() && compliance; k++) {
                int r1 = participants[j].first;
                int c1 = participants[j].second;

                int r2 = participants[k].first;
                int c2 = participants[k].second;

                int distance = abs(r1 - r2) + abs(c1 - c2);

                if (distance > 2) continue;

                if (distance == 1) {
                    compliance = false;
                }

                else if (distance == 2) {
                    if (!checkPartition(r1, c1, r2, c2, places[i])) {
                        compliance = false;
                    }
                }
            }
        }
        answer.push_back(compliance ? 1 : 0);
    }



    return answer;
}