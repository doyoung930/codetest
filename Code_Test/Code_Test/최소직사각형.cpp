#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0, h = 0;
    int temp = 0;
    for (int i = 0; i < sizes.size(); i++) {

        if (sizes[i][0] >= sizes[i][1]) {
            if (w < sizes[i][0]) { w = sizes[i][0]; }
            if (h < sizes[i][1]) h = sizes[i][1];
        }
        else {
            if (w < sizes[i][1]) { w = sizes[i][1]; }
            if (h < sizes[i][0]) h = sizes[i][0];
        }

    }
    answer = w * h;
    return answer;
}