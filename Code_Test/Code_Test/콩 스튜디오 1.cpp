//N x N(N x N) 체스판에 N개의 퀸을 서로 공격하지 않도록 배치하세요.
//
//- 퀸은 수평, 수직, 대각선으로 공격할 수 있습니다.
//- 따라서 수평 및 수직 라인마다 퀸을 하나씩 배치해야 합니다.대각선 라인에는 최대 1개의 퀸만 배치할 수 있습니다.
//
//입력 STDIN으로 단일 숫자 N만 주어질 수 있습니다.
//
//배치 된 퀸의 좌표는 N줄에 걸 쳐 출력됩니다.
//
//인쇄된 결과 STDOUT의 예(입력(N)이 4일 때)
//
//0 1
//1 3
//2 0
//3 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'chess_puzzle' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

 // 퀸을 배치할 수 있는지 확인하는 함수
bool isSafe(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; i++) {
        int qCol = queens[i];
        // 수직, 대각선 공격 체크
        if (qCol == col || abs(qCol - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// 퀸을 배치하는 백트래킹 함수
bool solveNQueens(int row, int n, vector<int>& queens) {
    if (row == n) {
        return true; // 모든 퀸을 성공적으로 배치한 경우
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, queens)) {
            queens[row] = col; // 퀸을 배치
            if (solveNQueens(row + 1, n, queens)) {
                return true; // 다음 행으로 진행
            }
            // 실패한 경우 (백트래킹)
            queens[row] = -1;
        }
    }
    return false; // 배치 실패
}

void chess_puzzle(int n) {
    vector<int> queens(n, -1); // 각 행에 배치된 퀸의 열을 저장 (초기값 -1)

    if (solveNQueens(0, n, queens)) {
        for (int i = 0; i < n; i++) {
            cout << i << " " << queens[i] << "\n"; // 결과 출력
        }
    }
    else {
        cout << "No solution exists\n";
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    chess_puzzle(n);

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
