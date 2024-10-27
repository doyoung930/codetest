#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 방향 벡터: 동, 서, 남, 북
const int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    // BFS를 위한 큐
    queue<pair<int, int>> q;
    q.push({ 0, 0 }); // 시작 위치 (0, 0)

    // 거리 배열 초기화
    vector<vector<int>> distance(n, vector<int>(m, -1));
    distance[0][0] = 1; // 출발 지점의 거리는 1 (자기 자신 포함)

    // BFS 탐색
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 목표 지점에 도달했는지 확인
        if (x == n - 1 && y == m - 1) {
            return distance[x][y]; // 최단 거리 반환
        }

        // 네 방향으로 이동
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            // 이동할 위치가 유효한지 확인
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1; // 거리 업데이트
                q.push({ nx, ny }); // 큐에 추가
            }
        }
    }

    return -1; // 목표 지점에 도달할 수 없는 경우
}
