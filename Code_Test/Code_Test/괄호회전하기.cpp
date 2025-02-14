#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); ++i) {
        vector<char> check;

        bool isCorrect = true;

        for (int j = i; j < i + s.size(); ++j) {
            int idx = j % s.size();

            if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[')
                check.push_back(s[idx]);
            else {
                if (check.empty() ||
                    (s[idx] == ')' && check.back() != '(') ||
                    (s[idx] == '}' && check.back() != '{') ||
                    (s[idx] == ']' && check.back() != '[')) {
                    isCorrect = false;
                    break;
                }

                check.pop_back();
            }
        }

        if (isCorrect && check.empty()) answer++;
    }

    return answer;
}