#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    string a;
    for (auto& v : ingredient)
    {
        a += to_string(v);

        if (a.size() >= 4) {
            if ("1231" == a.substr(a.size() - 4, a.size())) {
                answer++;
                a = a.substr(a.begin(), a.size() - 4);
                continue;
            }

        }

    }
    return answer;
}