#include "header.h"

using namespace std;

struct Group {
    int count;
    set<int> possibleY;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int height, width;
bool visited[500][500];
vector<vector<int>> g_map; // ��
vector<Group> groups;   // ���� ���


// ��ȯ�ϴ� ���� ���� ���
Group bfs(int sx, int sy) {
    queue<pair<int, int>> q;

    set<int> possibleY;

    q.push({ sx, sy });
    possibleY.insert(sy);
    visited[sx][sy] = true;

    int count = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny <0 || nx >= height || ny >= width
                || g_map[nx][ny] == 0 || visited[nx][ny]) continue;

            visited[nx][ny] = true;

            q.push({ nx,ny });

            count++;

            possibleY.insert(ny);
        }
    }

    return { count, possibleY };
}

void init(vector<vector<int>> land) {
    g_map = land;
    height = land.size();
    width = land[0].size();

    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            if (visited[i][j] || land[i][j] == 0) continue;
            groups.push_back(bfs(i, j));
        }
    }

}


// land_rows�� 2���� �迭 land�� �� ����, land_cols�� 2���� �迭 land�� �� �����Դϴ�.
int solution(vector<vector<int>> land) {
    init(land);
    int answer[501] = { 0 };
    int maxNum = 0;
    for (int i = 0; i < groups.size(); i++) {
        for (auto it : groups[i].possibleY) {
            answer[it] += groups[i].count;
            maxNum = max(maxNum, answer[it]);
        }
    }
    return maxNum;
}
int main() {

    vector<vector<int>>land = { {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1} };


    std::cout << solution(land) << std::endl;
    return 0;
}
 