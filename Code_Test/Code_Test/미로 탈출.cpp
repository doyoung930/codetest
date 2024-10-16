#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> s, e, l;

    // S, E, L 위치 저장
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') {
                s.first = i;
                s.second = j;
            }
            else if (maps[i][j] == 'E') {
                e.first = i;
                e.second = j;
            }
            else if (maps[i][j] == 'L') {
                l.first = i;
                l.second = j;
            }
        }
    }


    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(s.first, s.second)));
    bool visit[1001][1001];
    fill(&visit[0][0], &visit[1000][1001], false);
    visit[s.first][s.second] = true; // 시작 위치는 방문 체크.
    bool leverFlag = false;

    // 레버까지 도착하고 exit에 도달하지 못하는 경우가 있기에 exitFlag 사용해야함.
    bool exitFlag = false;

    while (!q.empty()) {
        int distance = q.front().first; // 이동 거리
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();

        // 레버를 당기지 않은 상태에서 레버에 도착
        if (leverFlag == false && l.first == i && l.second == j) {
            answer += distance;
            fill(&visit[0][0], &visit[1000][1001], false); // 방문 초기화
            leverFlag = true;
            while (!q.empty()) { // 큐 비우기
                q.pop();
            }
            q.push(make_pair(0, make_pair(i, j))); // 레버 위치부터 다시 시작
            continue;
        }
        else if (leverFlag == true && e.first == i && e.second == j) { // 레버 당긴 상태에서 exit 도착
            exitFlag = true;
            answer += distance;
            break;
        }

        // 상, 하, 좌, 우 이동
        // map[][] != 'X'로 벽만 아니라면 이동
        if (i - 1 >= 0 && visit[i - 1][j] == false && maps[i - 1][j] != 'X') {
            visit[i - 1][j] = true;
            q.push(make_pair(distance + 1, make_pair(i - 1, j)));
        }
        if (i + 1 < maps.size() && visit[i + 1][j] == false && maps[i + 1][j] != 'X') {
            visit[i + 1][j] = true;
            q.push(make_pair(distance + 1, make_pair(i + 1, j)));
        }
        if (j - 1 >= 0 && visit[i][j - 1] == false && maps[i][j - 1] != 'X') {
            visit[i][j - 1] = true;
            q.push(make_pair(distance + 1, make_pair(i, j - 1)));
        }
        if (j + 1 < maps[i].size() && visit[i][j + 1] == false && maps[i][j + 1] != 'X') {
            visit[i][j + 1] = true;
            q.push(make_pair(distance + 1, make_pair(i, j + 1)));
        }

    }


    // 레버는 도착했으나 exit에 도착 못하는 경우가 있어서 exitFlag 체크.
    if (answer == 0 || exitFlag == false) {
        answer = -1;
    }

    return answer;
}