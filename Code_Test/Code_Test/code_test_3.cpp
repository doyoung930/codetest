// [PCCP ���⹮��] 1��/ �ش밨��
#include"header.h"
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
	int answer{ 0 };

	int time{ 0 };
	int endtime{ attacks[attacks.size() - 1][0] };
	//�����ð�
	int casting_time{ bandage[0] };

	// �ʴ� ȸ����
	int recovery_per_second{ bandage[1] };
	// �߰� ȸ����
	int additional_recovery{ bandage[2] };

	// �ִ� ü��
	int hp{ health };

	// ���� ���ݽð�
	int attack_time{ 0 };

	// ���� ���ط�
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