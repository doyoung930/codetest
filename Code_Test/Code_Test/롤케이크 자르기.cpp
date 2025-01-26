#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    int m[10001] = { 0 }; // m �迭 �ʱ�ȭ
    int b[10001] = { 0 }; // b �迭 �ʱ�ȭ
    int bSize = 0; // b�� ������ ���� ����

    // b �迭�� topping�� ������ ����, bSize�� ���
    for (int i = 0; i < topping.size(); i++) {
        if (b[topping[i]] == 0) {
            bSize++; // ���ο� ���� �߰�
        }
        b[topping[i]]++;
    }

    int mSize = 0; // m�� ������ ���� ����

    for (int i = 0; i < topping.size(); i++) {
        // m�� topping[i] �߰�
        if (m[topping[i]] == 0) {
            mSize++; // ���ο� ���� �߰�
        }
        m[topping[i]]++;

        // b���� topping[i] ����
        b[topping[i]]--;
        if (b[topping[i]] == 0) {
            bSize--; // ���� ����
        }

        // mSize�� bSize ��
        if (mSize == bSize) {
            answer++;
        }
    }

    return answer;
}
