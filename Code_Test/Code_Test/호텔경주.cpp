#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> book_time)
{
    int answer = 0, room[2410] = { 0, };
    int n = book_time.size();
    for (int i = 0; i < n; i++)
    {
        int hour = stoi(book_time[i][0].substr(0, 2)) * 100 + stoi(book_time[i][0].substr(3));
        int minute = stoi(book_time[i][1].substr(0, 2)) * 100 + stoi(book_time[i][1].substr(3)) + 10;
        if (minute % 100 >= 60) minute += 40;
        for (int j = hour; j < minute; j++) room[j]++;
    }
    for (int i = 0; i < 2400; i++) answer = max(answer, room[i]);
    return answer;
}