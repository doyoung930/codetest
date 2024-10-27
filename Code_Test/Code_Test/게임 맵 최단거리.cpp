#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� ����: ��, ��, ��, ��
const int directions[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();

    // BFS�� ���� ť
    queue<pair<int, int>> q;
    q.push({ 0, 0 }); // ���� ��ġ (0, 0)

    // �Ÿ� �迭 �ʱ�ȭ
    vector<vector<int>> distance(n, vector<int>(m, -1));
    distance[0][0] = 1; // ��� ������ �Ÿ��� 1 (�ڱ� �ڽ� ����)

    // BFS Ž��
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // ��ǥ ������ �����ߴ��� Ȯ��
        if (x == n - 1 && y == m - 1) {
            return distance[x][y]; // �ִ� �Ÿ� ��ȯ
        }

        // �� �������� �̵�
        for (const auto& dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            // �̵��� ��ġ�� ��ȿ���� Ȯ��
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maps[nx][ny] == 1 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1; // �Ÿ� ������Ʈ
                q.push({ nx, ny }); // ť�� �߰�
            }
        }
    }

    return -1; // ��ǥ ������ ������ �� ���� ���
}
