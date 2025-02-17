#include <string>
#include <vector>
#include <iostream>
using namespace std;

// �������� ���ڿ� �Ǵ�
bool isBalanced(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else balance--;
    }
    return balance == 0;
}

// �ùٸ� ���ڿ� �Ǵ�
bool isCorrect(const string& s) {
    int balance = 0;
    for (char c : s) {
        if (c == '(') balance++;
        else {
            balance--;
            if (balance < 0) return false; // ')'�� ���� ������ �ùٸ��� ����
        }
    }
    return true;
}

// ��������� ��ȯ�ϴ� �Լ�
string recursiveConvert(const string& w) {
    if (w.empty()) return ""; // �� ���ڿ� ��ȯ

    // u�� v �и�
    string u = "", v = "";
    int balance = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') balance++;
        else balance--;

        u += w[i];

        if (balance == 0) {
            v = w.substr(i + 1); // v�� ������ �κ�
            break;
        }
    }

    if (isCorrect(u)) {
        // u�� �ùٸ� ���ڿ��̸� v�� ���� ��������� ����
        return u + recursiveConvert(v);
    }
    else {
        // u�� �ùٸ� ���ڿ��� �ƴ� ���
        string result = "("; // '(' �߰�
        result += recursiveConvert(v); // v�� ���� ��� ȣ��
        result += ")"; // ')' �߰�

        // u�� ù ��°�� ������ ���ڸ� �����ϰ� ������ ���ڿ��� ��ȣ�� ������
        for (int j = 1; j < u.size() - 1; j++) {
            if (u[j] == '(') result += ')';
            else result += '(';
        }

        return result; // ���� ��� ��ȯ
    }
}

string solution(string p) {
    return recursiveConvert(p); // ��ȯ �Լ� ȣ��
}

// �׽�Ʈ �ڵ�
int main() {
    cout << solution("(()())()") << endl; // "(()())()"
    cout << solution(")(") << endl;       // "()"
    cout << solution("()))((()") << endl; // "()(())()"
    return 0;
}
