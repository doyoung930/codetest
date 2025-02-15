#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> triangle(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1, 0); // �� �࿡ �°� ũ�� ���� �� �ʱ�ȭ
    }

    int num = 1; // ���� ����
    int row = 0, col = 0; // ���� ��ġ
    int direction = 0; // ���� ����: 0 = �Ʒ���, 1 = ������, 2 = �밢�� ����

    while (num <= n * (n + 1) / 2) {
        triangle[row][col] = num++; // ���� ��ġ�� ���� ä���

        if (direction == 0) { // �Ʒ������� �̵�
            if (row + 1 < n && triangle[row + 1][col] == 0) {
                row++;
            }
            else {
                direction = 1; // ���� ��ȯ
                col++;
            }
        }
        else if (direction == 1) { // ���������� �̵�
            if (col + 1 <= row && triangle[row][col + 1] == 0) {
                col++;
            }
            else {
                direction = 2; // ���� ��ȯ
                row--;
                col--;
            }
        }
        else if (direction == 2) { // �밢�� �������� �̵�
            if (row - 1 >= 0 && col - 1 >= 0 && triangle[row - 1][col - 1] == 0) {
                row--;
                col--;
            }
            else {
                direction = 0; // ���� ��ȯ
                row++;
            }
        }
    }

    // ����� ���� 1���� ���� �ʱ�ȭ
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            answer.push_back(triangle[i][j]); // �� ���� ���ڸ� ������� �߰�
        }
    }

    return answer;
}
