#include "header.h"


vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    map<string, int> yn;

    int temp = 0;

    for (int i = 0; i < name.size(); i++)
        yn[name[i]] = yearning[i];

    for (auto ps : photo) {
        for (auto p : ps) {
            for (int i = 0; i < name.size(); i++) {
                if (p == name[i]) {
                    temp = temp + yn[name[i]];

                    break;
                }
            }
        }
        answer.push_back(temp);
        temp = 0;
    }

    return answer;
}
int main() {

    vector<string> name { "may", "kein", "kain", "radi" };
    vector<int> yearning { 5, 10, 1, 3 };
    vector<vector<string>> photo {{"may", "kein", "kain", "radi"},{"may", "kein", "brin", "deny" }, { "kon", "kain", "may", "coni" }};
    


    for (auto& t : solution(name, yearning, photo)) {
        std::cout << t << std::endl;
    }
    return 0;
}
 