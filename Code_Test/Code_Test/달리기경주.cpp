// �޸������
#include"header.h"

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
        int ranking = name_ranking[callings[i]]; // �θ�����
        string name = ranking_name[ranking - 1]; // �տ� ���� �̸�, ����

        ranking_name[ranking - 1] = callings[i];
        ranking_name[ranking] = name;

        name_ranking[callings[i]] = ranking - 1;
        name_ranking[name] = ranking;
    }

    for (auto a : ranking_name)
        answer.push_back(a.second);


    return answer;
}