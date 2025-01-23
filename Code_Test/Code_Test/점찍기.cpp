#include <string>
#include <vector>
#include <cmath>
using namespace std;



long long solution(int k, int d) {
    long long answer = d / k + 1;

    for (long long i = 0; i < d; i += k)
    {
        answer += (long long)sqrt(1LL * d * d - i * i) / k;
    }


    return answer;
}