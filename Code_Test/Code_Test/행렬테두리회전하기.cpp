#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    // Step 1: ��� �ʱ�ȭ
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = i * columns + j + 1;
        }
    }

    // Step 2: �� ȸ���� ���� ó��
    for (const auto& query : queries) {
        // ȸ�� ������ �ε����� 0 ������� ��ȯ
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;

        // ȸ���� �׵θ��� ���� ������ ����
        vector<int> border;

        // ��� �� (�¿��� ���)
        for (int j = y1; j <= y2; ++j) {
            border.push_back(matrix[x1][j]);
        }

        // ���� �� (������ �Ʒ���)
        for (int i = x1 + 1; i <= x2; ++i) {
            border.push_back(matrix[i][y2]);
        }

        // �ϴ� �� (�쿡�� �·�)
        for (int j = y2 - 1; j >= y1; --j) {
            border.push_back(matrix[x2][j]);
        }

        // ���� �� (�Ʒ����� ����)
        for (int i = x2 - 1; i > x1; --i) {
            border.push_back(matrix[i][y1]);
        }

        // �׵θ� ���� �ð�������� �� ĭ ȸ��
        int last = border.back();
        border.pop_back();
        border.insert(border.begin(), last);

        // ȸ���� ���� �ٽ� ��Ŀ� ����
        int idx = 0;

        // ��� �� (�¿��� ���)
        for (int j = y1; j <= y2; ++j) {
            matrix[x1][j] = border[idx++];
        }

        // ���� �� (������ �Ʒ���)
        for (int i = x1 + 1; i <= x2; ++i) {
            matrix[i][y2] = border[idx++];
        }

        // �ϴ� �� (�쿡�� �·�)
        for (int j = y2 - 1; j >= y1; --j) {
            matrix[x2][j] = border[idx++];
        }

        // ���� �� (�Ʒ����� ����)
        for (int i = x2 - 1; i > x1; --i) {
            matrix[i][y1] = border[idx++];
        }

        // ȸ���� �� �� �ּҰ��� ã�� ����� �߰�
        answer.push_back(*min_element(border.begin(), border.end()));
    }

    return answer;
}
