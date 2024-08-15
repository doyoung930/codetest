#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    int x[10]{};
    int y[10]{};


    for (auto& a : X) x[a - '0']++;
    for (auto& a : Y) y[a - '0']++;

    for (int i = 9; i > -1; i--) {
        //int num = min(x[i], y[i]);
        //for(int j=0; j<num; j++)
            //answer+=to_string(i);
        answer += string(x[i] > y[i] ? y[i] : x[i], i + '0');
    }
    if (answer == "") return "-1";
    else if (answer[0] == '0') return "0";


    return answer;
}