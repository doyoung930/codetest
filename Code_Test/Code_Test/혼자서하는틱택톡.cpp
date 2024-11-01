#include <string>
#include <vector>

using namespace std;

bool checkWin(const vector<string>& board, char player) {
    // 가로 검사
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // 세로 검사
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // 대각선 검사
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

    // O의 수가 X의 수보다 많거나, X의 수가 O의 수보다 1 이상일 경우
    if (numO < numX || numO > numX + 1) return 0;

    bool gameO = checkWin(board, 'O');
    bool gameX = checkWin(board, 'X');

    // 두 사람이 동시에 이길 수 없음
    if (gameO && gameX) return 0;

    // O가 이겼다면 O의 수는 X의 수보다 1 많아야 함
    if (gameO && numO != numX + 1) return 0;

    // X가 이겼다면 O의 수는 X의 수와 같아야 함
    if (gameX && numO != numX) return 0;

    return 1; // 유효한 게임 상태
}