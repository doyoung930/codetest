#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    // Step 1: 행렬 초기화
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = i * columns + j + 1;
        }
    }

    // Step 2: 각 회전에 대해 처리
    for (const auto& query : queries) {
        // 회전 범위의 인덱스를 0 기반으로 변환
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        // 회전할 테두리의 값을 저장할 벡터
        vector<int> border;

        // 상단 행 (좌에서 우로)
        for (int j = y1; j <= y2; ++j) {
            border.push_back(matrix[x1][j]);
        }

        // 우측 열 (위에서 아래로)
        for (int i = x1 + 1; i <= x2; ++i) {
            border.push_back(matrix[i][y2]);
        }

        // 하단 행 (우에서 좌로)
        for (int j = y2 - 1; j >= y1; --j) {
            border.push_back(matrix[x2][j]);
        }

        // 좌측 열 (아래에서 위로)
        for (int i = x2 - 1; i > x1; --i) {
            border.push_back(matrix[i][y1]);
        }

        // 테두리 값을 시계방향으로 한 칸 회전
        int last = border.back();
        border.pop_back();
        border.insert(border.begin(), last);

        // 회전된 값을 다시 행렬에 삽입
        int idx = 0;

        // 상단 행 (좌에서 우로)
        for (int j = y1; j <= y2; ++j) {
            matrix[x1][j] = border[idx++];
        }

        // 우측 열 (위에서 아래로)
        for (int i = x1 + 1; i <= x2; ++i) {
            matrix[i][y2] = border[idx++];
        }

        // 하단 행 (우에서 좌로)
        for (int j = y2 - 1; j >= y1; --j) {
            matrix[x2][j] = border[idx++];
        }

        // 좌측 열 (아래에서 위로)
        for (int i = x2 - 1; i > x1; --i) {
            matrix[i][y1] = border[idx++];
        }

        // 회전된 값 중 최소값을 찾고 결과에 추가
        answer.push_back(*min_element(border.begin(), border.end()));
    }

    return answer;
}
