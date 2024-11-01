#include <string>
#include <vector>

using namespace std;

bool checkWin(const vector<string>& board, char player) {
    // ���� �˻�
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // ���� �˻�
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // �밢�� �˻�
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int solution(vector<string> board) {
    int numO = 0;
    int numX = 0;

    for (const string& row : board) {
        for (char cell : row) {
            if (cell == 'O') numO++;
            else if (cell == 'X') numX++;
        }
    }

    // O�� ���� X�� ������ ���ų�, X�� ���� O�� ������ 1 �̻��� ���
    if (numO < numX || numO > numX + 1) return 0;

    bool gameO = checkWin(board, 'O');
    bool gameX = checkWin(board, 'X');

    // �� ����� ���ÿ� �̱� �� ����
    if (gameO && gameX) return 0;

    // O�� �̰�ٸ� O�� ���� X�� ������ 1 ���ƾ� ��
    if (gameO && numO != numX + 1) return 0;

    // X�� �̰�ٸ� O�� ���� X�� ���� ���ƾ� ��
    if (gameX && numO != numX) return 0;

    return 1; // ��ȿ�� ���� ����
}