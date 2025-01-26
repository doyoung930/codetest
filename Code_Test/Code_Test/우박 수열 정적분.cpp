#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<double> tmp;

    while (k != 1) {
        tmp.push_back(k);
        if (k % 2 == 0) {
            k /= 2;
        }
        else {
            k = 3 * k + 1;
        }
    }
    tmp.push_back(1);

    vector<double> tmp2;
    for (int i = 0; i < tmp.size() - 1; i++) {
        tmp2.push_back((tmp[i] + tmp[i + 1]) / 2);
    }

    for (int i = 0; i < ranges.size(); i++) {
        int a = ranges[i][0];
        int b = tmp.size() + ranges[i][1] - 1;
        double rtn = 0;

        if (b < a) {
            answer.push_back(-1.0);
            continue;
        }
        else if (b == a)
        {
            answer.push_back(0.0);
            continue;
        }
        else {

            for (int j = a; j < b; j++) {
                rtn += tmp2[j];
            }
            answer.push_back(rtn);
        }

    }

    return answer;
}