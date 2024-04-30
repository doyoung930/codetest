// 달리기경주
#include"header.h"

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    vector<string> temp;
    
    for (auto c : callings) {
        for (int i = 0; i < size(answer); i++) {
            if (answer[i] == c) {
                if (i != 0) {
                    temp[i - 1] = answer[i];
                    temp[i] = answer[i - 1];
                }
                else
                    temp[i] = answer[i];
            }
            else
                temp[i] = answer[i];
            
        }

    }

    return answer;
}