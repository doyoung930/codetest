#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int temp = n;
    int t = 0;
    int p = 0;
    while (true) {
        if (temp < a) break;
        t = temp / a * b;
        answer += t;
        p = temp % a;
        temp = (t + p);


    }

    return answer;
}