#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int startN = -1;
int startM = -1;
int goalN = -1;
int goalM = -1;
bool getStartPos = false;
bool getGoalPos = false;

const int directions[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void GetStartPos(vector<string> board) {

    int maxN = board.size();
    int maxM = board[0].size();

    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j < maxM; j++) {
            if (board[i][j] == 'R') {
                startN = i;
                startM = j;
                getStartPos = true;
            }
            else if (board[i][j] == 'G') {
                goalN = i;
                goalM = j;
                getGoalPos = true;
            }

            if (getStartPos && getGoalPos) return;
        }
    }
}


int solution(vector<string> board) {
    int answer = 0;
    int maxN = board.size();
    int maxM = board[0].size();

    GetStartPos(board);

    // BFS�� ���� ť
    queue<pair<int, int>> q;
    q.push({ startN, startM }); // ���� ��ġ

    // �Ÿ� �迭 �ʱ�ȭ
    vector<vector<int>> distance(maxN, vector<int>(maxM, -1));
    distance[startN][startM] = 0; // ��� ������ �Ÿ��� 0

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (const auto& dir : directions) {
            bool isMeetD = false;
            int nx = x;
            int ny = y;
            while (true) {
                if (nx < 0 || nx >= maxN || ny < 0 || ny >= maxM) break;
                if (board[nx][ny] == 'D') break;
                nx += dir[0];
                ny += dir[1];
            }
            nx -= dir[0];
            ny -= dir[1];
            if (board[nx][ny] == 'G') {
                return distance[x][y] + 1; // �ִ� �Ÿ� ��ȯ
            }
            // �̵��� ��ġ�� ��ȿ���� Ȯ��
            if (distance[nx][ny] >= 0) continue;


            distance[nx][ny] = distance[x][y] + 1; // �Ÿ� ������Ʈ
            q.push({ nx, ny }); // ť�� �߰�


        }
    }
    return -1;
}