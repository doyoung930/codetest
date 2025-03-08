// �Ǻ���ġ ?

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cctype>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'fibonacci' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

unsigned long long fibonacci(int n) {
    if (n <= 0) return 0;  // n�� 0 ������ ��� 0 ��ȯ
    if (n == 1) return 1;  // n�� 1�� ��� 1 ��ȯ

    unsigned long long a = 0, b = 1;
    unsigned long long result;

    for (int i = 2; i <= n; i++) {
        result = a + b;  // ���� �Ǻ���ġ ���� ���� �� ���� ��
        a = b;          // ���� �� ������Ʈ
        b = result;     // ���� �� ������Ʈ
    }

    return result;  // n��° �Ǻ���ġ �� ��ȯ
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    unsigned long long result = fibonacci(n);  // ��ȯ Ÿ���� unsigned long long���� ����

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}