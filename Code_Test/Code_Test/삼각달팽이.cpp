#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> triangle(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1, 0); // 각 행에 맞게 크기 설정 및 초기화
    }

    int num = 1; // 시작 숫자
    int row = 0, col = 0; // 현재 위치
    int direction = 0; // 현재 방향: 0 = 아래쪽, 1 = 오른쪽, 2 = 대각선 위쪽

    while (num <= n * (n + 1) / 2) {
        triangle[row][col] = num++; // 현재 위치에 숫자 채우기

        if (direction == 0) { // 아래쪽으로 이동
            if (row + 1 < n && triangle[row + 1][col] == 0) {
                row++;
            }
            else {
                direction = 1; // 방향 전환
                col++;
            }
        }
        else if (direction == 1) { // 오른쪽으로 이동
            if (col + 1 <= row && triangle[row][col + 1] == 0) {
                col++;
            }
            else {
                direction = 2; // 방향 전환
                row--;
                col--;
            }
        }
        else if (direction == 2) { // 대각선 위쪽으로 이동
            if (row - 1 >= 0 && col - 1 >= 0 && triangle[row - 1][col - 1] == 0) {
                row--;
                col--;
            }
            else {
                direction = 0; // 방향 전환
                row++;
            }
        }
    }

    // 결과를 담을 1차원 벡터 초기화
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            answer.push_back(triangle[i][j]); // 각 행의 숫자를 순서대로 추가
        }
    }

    return answer;
}
