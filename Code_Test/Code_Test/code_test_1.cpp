#include "header.h"

void main() {

	std::vector<vector<int>> edges;
	std::unordered_map<int, vector<int>> temps;
	vector<int> answer(4, 0);

	for (auto& edge : edges) {
		int first = edge[0];
		int second = edge[1];

		if (temps.find(first) == temps.end()) { temps[first] = { 0,0 };	}
		if (temps.find(second) == temps.end()) { temps[second] = { 0,0 };	}

		temps[first][0]++;
		temps[second][0]++;
	}

	for (const auto& [key, temp] : temps) {
		// �׷����� �ּ� 2�� �̻����� �� �͸� 2�� �̻��� ������ ������
		if (temp[0] >= 2 && temp[1] == 0)
			answer[0] = key;
		// ���� �͸� �ִ� ������ ������ ���� �׷����� ����
		else if (temp[0] == 0 && temp[1] > 0)
			answer[2] += 1;
		// �� ��, ���� �� ���� 2�� �̻��� ���� ������ 8�� �׷����� ����
		else if (temp[0] >= 2 && temp[1] >= 2)
			answer[3] += 1;
	}

	// ��ü �׷��� ������ �������� �� �Ϳ��� 2������ �׷����� ���� ���� �׷����� ����
	answer[1] = (temps[answer[0]][0] - answer[2] - answer[3]);

}