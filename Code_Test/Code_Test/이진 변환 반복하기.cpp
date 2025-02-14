#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int count = 0;
    int zero = 0;


    while (true) {
        int size = s.size();
        int p = 0;
        int nextlength = 0;


        for (int i = 0; i < size; i++) {
            if (s[i] == '1') {
                nextlength++;
            }
            else {
                zero++;
            }
        }

        count++;
        if (nextlength == 1) {
            break;
        }

        s.clear();

        while (nextlength > 0) {
            s = to_string(nextlength % 2) + s;
            nextlength /= 2;
        }

        cout << s << endl;
    }

    answer.push_back(count);
    answer.push_back(zero);
    return answer;
}