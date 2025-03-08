//N x N(N x N) ü���ǿ� N���� ���� ���� �������� �ʵ��� ��ġ�ϼ���.
//
//- ���� ����, ����, �밢������ ������ �� �ֽ��ϴ�.
//- ���� ���� �� ���� ���θ��� ���� �ϳ��� ��ġ�ؾ� �մϴ�.�밢�� ���ο��� �ִ� 1���� ���� ��ġ�� �� �ֽ��ϴ�.
//
//�Է� STDIN���� ���� ���� N�� �־��� �� �ֽ��ϴ�.
//
//��ġ �� ���� ��ǥ�� N�ٿ� �� �� ��µ˴ϴ�.
//
//�μ�� ��� STDOUT�� ��(�Է�(N)�� 4�� ��)
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

 // ���� ��ġ�� �� �ִ��� Ȯ���ϴ� �Լ�
bool isSafe(int row, int col, vector<int>& queens) {
    for (int i = 0; i < row; i++) {
        int qCol = queens[i];
        // ����, �밢�� ���� üũ
        if (qCol == col || abs(qCol - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// ���� ��ġ�ϴ� ��Ʈ��ŷ �Լ�
bool solveNQueens(int row, int n, vector<int>& queens) {
    if (row == n) {
        return true; // ��� ���� ���������� ��ġ�� ���
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, queens)) {
            queens[row] = col; // ���� ��ġ
            if (solveNQueens(row + 1, n, queens)) {
                return true; // ���� ������ ����
            }
            // ������ ��� (��Ʈ��ŷ)
            queens[row] = -1;
        }
    }
    return false; // ��ġ ����
}

void chess_puzzle(int n) {
    vector<int> queens(n, -1); // �� �࿡ ��ġ�� ���� ���� ���� (�ʱⰪ -1)

    if (solveNQueens(0, n, queens)) {
        for (int i = 0; i < n; i++) {
            cout << i << " " << queens[i] << "\n"; // ��� ���
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
