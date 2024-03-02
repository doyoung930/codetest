/// 카카오 인텔리전쉽 2024 도넛과 막대기 문제

/// 잘모르겠음 다시풀어봐야됨 -----------------------------------
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

map<int, vector<int>> graph;
map<int, int> arrive_check;
set<int> explored;
stack<int> frontier;
int new_vertex;


void dfs(vector<int>& answer) {
    for (const auto& next_frontier : graph[new_vertex]) {
        frontier.push(next_frontier);
    }

    while (!frontier.empty()) {
        int now = frontier.top();
        frontier.pop();
        explored.insert(now);

        if (graph.find(now) == graph.end()) {
            answer[2] += 1;
        }
        else if (graph[now].size() == 2) {
            answer[3] += 1;
        }
        else if (graph[now].size() == 1) {
            if (explored.find(graph[now][0]) != explored.end()) answer[1] += 1;
            else frontier.push(graph[now][0]);
        }
    }
}

vector<int> solution(vector<vector<int>> edges) {

    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        arrive_check[edges[i][1]] = 1;
    }

    for (const auto& element : graph) {
        if (arrive_check.find(element.first) == arrive_check.end() && element.second.size() >= 2) { new_vertex = element.first; break; }
    }

    vector<int> answer;

    answer.push_back(0); answer.push_back(0); answer.push_back(0); answer.push_back(0);

    answer[0] = new_vertex;

    dfs(answer);

    return answer;
}

/// 