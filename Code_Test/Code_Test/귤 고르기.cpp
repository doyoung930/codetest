#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}


int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> m;

    for (int i = 0; i < tangerine.size(); i++)
    {
        m[tangerine[i]]++;
    }

    vector<pair<int, int>> vec(m.begin(), m.end());

    sort(vec.begin(), vec.end(), cmp);

    int sum = 0;


    for (int i = 0; i < vec.size(); i++)
    {
        sum += vec[i].second;
        answer++;
        if (k <= sum) break;
    }



    return answer;
}