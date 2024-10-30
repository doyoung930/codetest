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

    // BFS를 위한 큐
    queue<pair<int, int>> q;
    q.push({ startN, startM }); // 시작 위치

    // 거리 배열 초기화
    vector<vector<int>> distance(maxN, vector<int>(maxM, -1));
    distance[startN][startM] = 0; // 출발 지점의 거리는 0

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
                return distance[x][y] + 1; // 최단 거리 반환
            }
            // 이동할 위치가 유효한지 확인
            if (distance[nx][ny] >= 0) continue;


            distance[nx][ny] = distance[x][y] + 1; // 거리 업데이트
            q.push({ nx, ny }); // 큐에 추가


        }
    }
    return -1;
}