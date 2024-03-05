// [PCCP 기출문제] 1번/ 붕대감기
#include"header.h"
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int answer{ 0 };

	int time{ 0 };
	int endtime{ attacks[attacks.size() - 1][0] };
	//시전시간
	int casting_time{ bandage[0] };

	// 초당 회복량
	int recovery_per_second{ bandage[1] };
	// 추가 회복량
	int additional_recovery{ bandage[2] };

	// 최대 체력
	int hp{ health };

	// 몬스터 공격시간
	int attack_time{ 0 };

	// 몬스터 피해량
	int dmg{ 0 };

	int dmg_time{ 0 };


	for (int i = 1; i <= endtime; i++) {
		attack_time = attacks[dmg_time][0];
		dmg = attacks[dmg_time][1];
		if (attack_time == i) {
			hp = hp - dmg;
			dmg_time++;
			if (hp < 1)
				return -1;
			time = 0;

			continue;
		}
		else {
			time++;
			if (hp < health) {
				hp += recovery_per_second;
			}
			if (time == casting_time) {
				hp += additional_recovery;
				time = 0;
			}

		}
		if (hp > health)
			hp = health;

	}


	answer = hp;
	return answer;
}