#include <string>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int>> sets;
    string num_str = "";

    vector<int> current_set;

    for (char c : s) {
        if (isdigit(c)) {
            num_str += c;
        }
        else {
            if (!num_str.empty()) {
                current_set.push_back(stoi(num_str));
                num_str = "";
            }

            if (c == '}') {
                if (!current_set.empty()) {
                    sets.push_back(current_set);
                    current_set.clear();
                }
            }
        }
    }

    sort(sets.begin(), sets.end(),
        [](const vector<int>& a, const vector<int>& b) -> bool {return a.size() < b.size();
        });
    set<int> added;

    for (auto& set_vec : sets) {
        for (auto num : set_vec) {
            if (added.find(num) == added.end()) {
                answer.push_back(num);
                added.insert(num);
            }
        }
    }


    return answer;
}