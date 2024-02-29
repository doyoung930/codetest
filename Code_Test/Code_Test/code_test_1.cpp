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
		// 그래프는 최소 2개 이상으로 준 것만 2개 이상인 정점이 생성점
		if (temp[0] >= 2 && temp[1] == 0)
			answer[0] = key;
		// 받은 것만 있는 정점의 개수는 막대 그래프의 개수
		else if (temp[0] == 0 && temp[1] > 0)
			answer[2] += 1;
		// 준 것, 받은 것 각각 2개 이상인 점의 개수는 8자 그래프의 개수
		else if (temp[0] >= 2 && temp[1] >= 2)
			answer[3] += 1;
	}

	// 전체 그래프 개수인 생성점의 준 것에서 2종류의 그래프를 빼면 도넛 그래프의 개수
	answer[1] = (temps[answer[0]][0] - answer[2] - answer[3]);

}