#include "header.h"



//vector<string> solution(vector<string> players, vector<string> callings)
//{
//    vector<string> answer;
//    map<int, string> m1;
//    map<string, int> m2;
//    for (int i = 0; i < players.size(); i++)
//    {
//        m1[i] = players[i];
//        m2[players[i]] = i;
//    }
//    for (int i = 0; i < callings.size(); i++)
//    {
//        int cur_idx = m2[callings[i]];//호출 선수 이름, 순위
//        string change = m1[cur_idx - 1];//앞선 선수 이름, 순위
//        m1[cur_idx - 1] = callings[i];
//        m1[cur_idx] = change;
//        m2[callings[i]] = cur_idx - 1;
//        m2[change] = cur_idx;
//    }
//    for (auto c : m1) answer.push_back(c.second);
//    return answer;
//}

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<int, string> ranking_name;
    map<string, int> name_ranking;

    for (int i = 0; i < players.size(); i++) {
        ranking_name[i] = players[i];
        name_ranking[players[i]] = i;
    }
    for (int i = 0; i < callings.size(); i++)
    {
        int ranking = name_ranking[callings[i]]; // 부른선수
        string name = ranking_name[ranking - 1]; // 앞에 선수 이름, 순위

        ranking_name[ranking - 1] = callings[i];
        ranking_name[ranking] = name;

        name_ranking[callings[i]] = ranking - 1;
        name_ranking[name] = ranking;
    }

    for (auto a : ranking_name)
        answer.push_back(a.second);


    return answer;
}

int main() {

    vector<string> player{ "mumu", "soe", "poe", "kai", "mine" };
    vector<string> calling{ "kai", "kai", "mine", "mine" };

    vector<string> answers;
    answers = solution(player, calling);
    for (auto& t : solution(player, calling)) {
        std::cout << t << std::endl;
    }
    return 0;
}
 