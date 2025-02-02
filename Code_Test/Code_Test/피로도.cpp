#include <string>
#include <vector>

#define MAX 8

using namespace std;

bool visited[MAX] = { 0 };
int answer = 0;


void DFS(int k, vector<vector<int>>& dungeons, int size, int count) {
    if (count > answer) answer = count;

    for (int i = 0; i < size; i++) {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            DFS(k - dungeons[i][1], dungeons, size, count + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int size = dungeons.size();

    DFS(k, dungeons, size, 0);

    return answer;
}