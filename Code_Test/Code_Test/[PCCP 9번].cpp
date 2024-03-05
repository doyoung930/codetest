#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    int n; // ������ ������ ���� board�� ���̸� ����
    int count = 0; // ���� ������ ��ĥ�� ĭ�� ������ ������ ����
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