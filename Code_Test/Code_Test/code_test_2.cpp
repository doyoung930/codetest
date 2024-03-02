// 카카오 winter intership - 가장많이 받은 선물

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
                   // 준 선물

                   // 이름 있나 탐색 없으면 새로 만들어서 넣고 int에 1 저장

                   // 이름이 있으면 +1
                   if (give_gifts.find(_friend) == give_gifts.end()) {
                       give_gifts[gift] = 1;
                   }
                   else {
                       give_gifts[gift]++;
                   }
               }
               else {
                   // 받은 선물

                   // 이름 있나 탐색 없으면 새로 만들어서 넣고 int에 저장

                   // 이름이 있으면 +1
                   
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

    // 각 이름이 first가 같은것만 뺀후 가장 큰 값을 answer에 저장
    for (const auto& pair : give_gifts) {
        const std::string& name = pair.first;
        int give_count = pair.second;

        if (receive_gifts.find(name) != receive_gifts.end()) {
            int receive_count = receive_gifts[name];
            int diff = give_count - receive_count; // 두 값의 차이 계산
            answer = std::max(answer, diff); // answer에 최댓값 저장
        }
    }

    

    return answer;
}