#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    int n; // 정수를 저장할 변수 board의 길이를 저장
    int count = 0; // 같은 색으로 색칠된 칸의 개수를 저장할 변수
    if (h > 0) {
        if (board[h][w] == board[h - 1][w]) {
            count++;
        }
    }
    if (w > 0) {
        if (board[h][w] == board[h][w - 1]) {
            count++;
        }
    }
    if ((h + 1) < board.size()) {
        if (board[h][w] == board[h + 1][w]) {
            count++;
        }
    }
    if ((w + 1) < board[0].size()) {
        if (board[h][w] == board[h][w + 1]) {
            count++;
        }
    }


    answer = count;
    return answer;
}