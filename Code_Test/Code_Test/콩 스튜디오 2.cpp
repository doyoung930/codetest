//두개의 정렬 된 배열 nums1 과 nums2 가 주어지면 nums2를 nums1로 병합하여 하나의 정렬 된 배열을 만듭니다.
//nums1 nums2의 추가 요소를 보관할 수 있는 충분한 공간 m + n이상인 크기가 있다고 가정할 수 있다.num1과 num2에서 초기화된 요소의 수 는 각각 m과 n이다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cctype>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'merge' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY nums1
 *  2. INTEGER n
 *  3. INTEGER_ARRAY nums2
 *  4. INTEGER m
 */

vector<int> merge(vector<int> nums1, int n, vector<int> nums2, int m) {

    //vector<int> answer{m+n,0};
    int i = n - 1;
    int j = m - 1;

    int k = n + m - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];

            i--;
        }
        else {
            nums1[k] = nums2[j];

            j--;
        }

        k--;
    }

    while (j >= 0) {
        nums1[k] = nums2[j];

        j--;
        k--;
    }

    return nums1;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nums1_count_temp;
    getline(cin, nums1_count_temp);

    int nums1_count = stoi(ltrim(rtrim(nums1_count_temp)));

    vector<int> nums1(nums1_count);

    for (int i = 0; i < nums1_count; i++) {
        string nums1_item_temp;
        getline(cin, nums1_item_temp);

        int nums1_item = stoi(ltrim(rtrim(nums1_item_temp)));

        nums1[i] = nums1_item;
    }

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string nums2_count_temp;
    getline(cin, nums2_count_temp);

    int nums2_count = stoi(ltrim(rtrim(nums2_count_temp)));

    vector<int> nums2(nums2_count);

    for (int i = 0; i < nums2_count; i++) {
        string nums2_item_temp;
        getline(cin, nums2_item_temp);

        int nums2_item = stoi(ltrim(rtrim(nums2_item_temp)));

        nums2[i] = nums2_item;
    }

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<int> result = merge(nums1, n, nums2, m);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
