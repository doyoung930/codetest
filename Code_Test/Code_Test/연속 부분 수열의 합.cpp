#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


int solution(vector<int> elements) {
    int answer = 0;

    int eSize = elements.size();
    unordered_set<int> sums;
    for (int count = 1; count <= eSize; count++) {
        for (int i = 0; i < eSize; i++) {
            int tmp = 0;
            for (int j = 0; j < count; j++) {
                tmp += elements[(i + j) % eSize];

            }
            sums.insert(tmp);

        }
    }


    return sums.size();
}