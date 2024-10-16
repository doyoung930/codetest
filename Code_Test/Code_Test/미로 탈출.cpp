#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> s, e, l;

    // S, E, L ��ġ ����
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
    visit[s.first][s.second] = true; // ���� ��ġ�� �湮 üũ.
    bool leverFlag = false;

    // �������� �����ϰ� exit�� �������� ���ϴ� ��찡 �ֱ⿡ exitFlag ����ؾ���.
    bool exitFlag = false;

    while (!q.empty()) {
        int distance = q.front().first; // �̵� �Ÿ�
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();

        // ������ ����� ���� ���¿��� ������ ����
        if (leverFlag == false && l.first == i && l.second == j) {
            answer += distance;
            fill(&visit[0][0], &visit[1000][1001], false); // �湮 �ʱ�ȭ
            leverFlag = true;
            while (!q.empty()) { // ť ����
                q.pop();
            }
            q.push(make_pair(0, make_pair(i, j))); // ���� ��ġ���� �ٽ� ����
            continue;
        }
        else if (leverFlag == true && e.first == i && e.second == j) { // ���� ��� ���¿��� exit ����
            exitFlag = true;
            answer += distance;
            break;
        }

        // ��, ��, ��, �� �̵�
        // map[][] != 'X'�� ���� �ƴ϶�� �̵�
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


    // ������ ���������� exit�� ���� ���ϴ� ��찡 �־ exitFlag üũ.
    if (answer == 0 || exitFlag == false) {
        answer = -1;
    }

    return answer;
}