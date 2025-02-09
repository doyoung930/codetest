#include <string>
#include <vector>
#include <iostream>

using namespace std;

int func(int diff, int level, int time_cur, int time_prev) {
    int n = 0;
    if (diff > level) {
        n = diff - level;
        return (time_cur + time_prev) * n + time_cur;
    }
    else {
        return time_cur;
    }

}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;


    int level = 0;


    while (true) {
        level++;
        long long n = 0;
        int time_prev = 0;
        for (int i = 0; i < diffs.size(); i++) {
            n += func(diffs[i], level, times[i], time_prev);
            time_prev = times[i];
        }

        if (limit >= n) return level;


    }

    return level;
}