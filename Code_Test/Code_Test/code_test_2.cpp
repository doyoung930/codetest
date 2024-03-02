// īī�� winter intership - ���帹�� ���� ����

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(std::vector<std::string> friends,std::vector<std::string> gifts) {
    
    int answer = 0;
    size_t found = -1;
    unordered_map<string, int> give_gifts;
    unordered_map<string, int> receive_gifts;

    for (auto& _friend : friends) {
        for (auto& gift : gifts) {
           found =  gift.find(_friend);
           if (found != -1) {
               if (found == 0) {
                   // �� ����

                   // �̸� �ֳ� Ž�� ������ ���� ���� �ְ� int�� 1 ����

                   // �̸��� ������ +1
                   if (give_gifts.find(_friend) == give_gifts.end()) {
                       give_gifts[gift] = 1;
                   }
                   else {
                       give_gifts[gift]++;
                   }
               }
               else {
                   // ���� ����

                   // �̸� �ֳ� Ž�� ������ ���� ���� �ְ� int�� ����

                   // �̸��� ������ +1
                   
                   if (receive_gifts.find(_friend) == receive_gifts.end()) {
                       receive_gifts[gift] = 1;
                   }
                   else {
                       receive_gifts[gift]++;
                   }
               }

           }
           else continue;
        }
    }

    // �� �̸��� first�� �����͸� ���� ���� ū ���� answer�� ����
    for (const auto& pair : give_gifts) {
        const std::string& name = pair.first;
        int give_count = pair.second;

        if (receive_gifts.find(name) != receive_gifts.end()) {
            int receive_count = receive_gifts[name];
            int diff = give_count - receive_count; // �� ���� ���� ���
            answer = std::max(answer, diff); // answer�� �ִ� ����
        }
    }

    

    return answer;
}