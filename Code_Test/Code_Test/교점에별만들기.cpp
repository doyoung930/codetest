// ���α׷��ӽ� lv.2
// ������ �� �����
// ---

// �ٽ� Ǯ��� 

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
        //����
        long long A = line[i][0];
        long long B = line[i][1];
        long long C = line[i][2];
        for (int j = i + 1; j < line.size(); j++)
        {
            //���� 2 
            long long L = line[j][0];
            long long M = line[j][1];
            long long N = line[j][2];

            //�и�
            long long d = (A * M) - (B * L);

            //���� x ��ǥ
            long long mX = (B * N) - (C * M);

            //���� y ��ǥ
            long long mY = (C * L) - (A * N);

            // �и� 0 - ����
            if (d == 0) continue;

            //������ ������ �ƴ� 
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