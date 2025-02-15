#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <climits>

using namespace std;

// ��� �������� ������ ������ ����
vector<vector<char>> operator_permutations;

// ������ ������ �����ϴ� �Լ�
void generate_permutations(vector<char>& ops, int start) {
    if (start == ops.size()) {
        operator_permutations.emplace_back(ops);
        return;
    }
    for (int i = start; i < ops.size(); ++i) {
        swap(ops[start], ops[i]);
        generate_permutations(ops, start + 1);
        swap(ops[start], ops[i]);
    }
}

// ������ ���ϴ� �Լ�
long long evaluate_expression(vector<long long> numbers, vector<char> operators, vector<char> precedence) {
    for (char op : precedence) {
        vector<long long> temp_numbers;
        vector<char> temp_operators;
        temp_numbers.emplace_back(numbers[0]);
        for (size_t i = 0; i < operators.size(); ++i) {
            if (operators[i] == op) {
                long long a = temp_numbers.back();
                temp_numbers.pop_back();
                long long b = numbers[i + 1];
                long long res = 0;
                if (op == '+') {
                    res = a + b;
                }
                else if (op == '-') {
                    res = a - b;
                }
                else if (op == '*') {
                    res = a * b;
                }
                temp_numbers.emplace_back(res);
            }
            else {
                temp_operators.emplace_back(operators[i]);
                temp_numbers.emplace_back(numbers[i + 1]);
            }
        }
        numbers = temp_numbers;
        operators = temp_operators;
    }
    return abs(numbers[0]);
}

// ���� �ַ�� �Լ�
long long solution(string expression) {
    // ���ڿ� �����ڸ� �и�
    vector<long long> numbers;
    vector<char> operators_list;
    string num = "";
    for (char c : expression) {
        if (isdigit(c)) {
            num += c;
        }
        else {
            numbers.emplace_back(stoll(num));
            operators_list.emplace_back(c);
            num = "";
        }
    }
    numbers.emplace_back(stoll(num));

    // �������� ������ ����
    vector<char> unique_ops;
    for (char c : operators_list) {
        if (find(unique_ops.begin(), unique_ops.end(), c) == unique_ops.end()) {
            unique_ops.emplace_back(c);
        }
    }

    // ��� ������ ���� ����
    generate_permutations(unique_ops, 0);

    long long max_value = 0;

    // �� �������� ������ ��
    for (auto& perm : operator_permutations) {
        long long current = evaluate_expression(numbers, operators_list, perm);
        if (current > max_value) {
            max_value = current;
        }
    }

    return max_value;
}
