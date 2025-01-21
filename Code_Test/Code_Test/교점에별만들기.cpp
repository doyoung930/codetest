// 프로그래머스 lv.2
// 교점에 별 만들기
// ---

// 다시 풀어보기 

#include <string>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> meet;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;



    long long maxX = LLONG_MIN;
    long long maxY = LLONG_MIN;
    long long minX = LLONG_MAX;
    long long minY = LLONG_MAX;

    for (int i = 0; i < line.size(); i++)
    {
        //직선
        long long A = line[i][0];
        long long B = line[i][1];
        long long C = line[i][2];
        for (int j = i + 1; j < line.size(); j++)
        {
            //직선 2 
            long long L = line[j][0];
            long long M = line[j][1];
            long long N = line[j][2];

            //분모
            long long d = (A * M) - (B * L);

            //분자 x 좌표
            long long mX = (B * N) - (C * M);

            //분자 y 좌표
            long long mY = (C * L) - (A * N);

            // 분모가 0 - 평행
            if (d == 0) continue;

            //교점이 정수가 아님 
            if (mX % d || mY % d) continue;

            int X = mX / d;
            int Y = mY / d;

            meet.push_back(make_pair(X, Y));

            maxX = max(maxX, (long long)X);
            minX = min(minX, (long long)X);

            maxY = max(maxY, (long long)Y);
            minY = min(minY, (long long)Y);
        }
        long long r = maxX - minX + 1;
        long long c = maxY - minY + 1;
        string tmp(r, '.');
        answer.assign(c, tmp);

        for (int i = 0; i < meet.size(); i++)
        {
            long long y = meet[i].second;
            long long x = meet[i].first;

            answer[maxY - y][x - minX] = '*';
        }


    }





    return answer;
}