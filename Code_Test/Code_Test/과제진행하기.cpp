
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(const tuple<string, int, int>& a, const tuple<string, int, int>& b) {
    return get<1>(a) < get<1>(b);
}

int after_study(int start, int time) {
    int start_h = start / 100, start_m = start % 100;
    int time_h = time / 60, time_m = time % 60;
    return ((start_h + time_h + (start_m + time_m) / 60) * 100 + (start_m + time_m) % 60);
}

int remaining_time(const tuple<string, int, int>& cur, const tuple<string, int, int>& next, int elapsed) {
    int h = get<1>(next) / 100 - elapsed / 100;
    int m = get<1>(next) % 100 - elapsed % 100;
    int total_time = h * 60 + m;
    return max(get<2>(cur) - total_time, 0); // 남은 시간이 음수가 되지 않도록 보장
}

vector<string> solution(vector<vector<string>> plans) {
    int n = plans.size();
    vector<string> answer;
    deque<tuple<string, int, int>> list, wait;

    for (const auto& plan : plans) {
        int start_time = stoi(plan[1]) * 100 + stoi(plan[1].substr(3, 2));
        list.emplace_back(plan[0], start_time, stoi(plan[2]));
    }

    sort(list.begin(), list.end(), compare); // 시작 시간 기준으로 정렬
    int current_time = get<1>(list.front()); // 현재 시간

    while (!list.empty() || !wait.empty()) {
        tuple<string, int, int> current_task;

        if (!wait.empty() && (list.empty() || current_time < get<1>(list.front()))) {
            // 대기 중인 과제가 있고, 현재 시간이 다음 시작 시간보다 이전인 경우
            current_task = wait.front();
            wait.pop_front();
        }
        else {
            // 대기 중인 과제가 없거나 현재 시간이 과제를 시작할 시간인 경우
            current_task = list.front();
            list.pop_front();
            current_time = get<1>(current_task); // 현재 시간 갱신
        }

        if (!list.empty() && after_study(current_time, get<2>(current_task)) > get<1>(list.front())) {
            // 현재 과제가 다음 과제 시작 시간보다 늦게 끝나는 경우
            get<2>(current_task) = remaining_time(current_task, list.front(), current_time);
            wait.push_front(current_task);
            current_time = get<1>(list.front());
        }
        else {
            // 현재 과제가 다음 과제보다 먼저 끝나는 경우
            answer.push_back(get<0>(current_task));
            current_time = after_study(current_time, get<2>(current_task));
        }
    }

    return answer;
}