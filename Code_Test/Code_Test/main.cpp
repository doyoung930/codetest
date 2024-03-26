#include "header.h"

using namespace std;

// land_rows는 2차원 배열 land의 행 길이, land_cols는 2차원 배열 land의 열 길이입니다.
int solution(int** land, size_t land_rows, size_t land_cols) {
    int answer = 0;
    return answer;
}
int main() {

	vector<int> bandage{ 5,1,5 };
	int health = 30;
	vector<vector<int>> attacks{ {2, 10} ,{9, 15},{10, 5},{11, 5} };

    std::cout << solution(bandage, health, attacks) << std::endl;
    return 0;
}
