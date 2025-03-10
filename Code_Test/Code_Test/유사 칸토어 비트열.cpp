#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int GetCantorianBitValue(long long idx, int level)
{
    if (level == 0)
        return 1;

    long long size = pow(5, level);
    if (size / 5 * 2 <= idx && idx < size / 5 * 3)
        return 0;

    return GetCantorianBitValue(idx % (size / 5), level - 1);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    for (long long i = l - 1; i < r; i++)
        answer += GetCantorianBitValue(i, n);

    return answer;
}