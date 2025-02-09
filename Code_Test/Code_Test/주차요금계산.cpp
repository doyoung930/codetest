#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>

// �ð��� ������ ��ȯ�ϴ� �Լ�
int calculateMinutes(const std::string& time) {
    int hours = std::stoi(time.substr(0, 2));    // �� ����
    int minutes = std::stoi(time.substr(3, 2));  // �� ����
    return hours * 60 + minutes;                  // �� �� ���
}

// ���ڿ��� Ư�� ���ڷ� �����ϴ� �Լ�
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;             // ����� ������ ����
    std::string token;                           // ���� ��ū
    std::istringstream tokenStream(s);           // �Է� ��Ʈ�� ����
    while (std::getline(tokenStream, token, delimiter)) { // �����ڷ� ����
        tokens.push_back(token);                 // ���Ϳ� �߰�
    }
    return tokens;                               // ���ҵ� ���ڿ� ��ȯ
}

std::vector<int> solution(std::vector<int> fees, std::vector<std::string> records) {
    // ������ �� ���� �ð��� ������ ��
    std::map<std::string, int> parkedTime;
    // ������ ������ ���� �ð��� ������ ��
    std::map<std::string, int> lastEntryTime;

    for (const auto& record : records) {
        // ����� �ð�, ���� ��ȣ, ���·� ����
        std::vector<std::string> tokens = split(record, ' ');
        std::string time = tokens[0];
        std::string carNumber = tokens[1];
        std::string status = tokens[2];

        int totalMinutes = calculateMinutes(time); // �ð��� ������ ��ȯ

        if (status == "IN") {
            // ������ ���, ������ ���� �ð� ������Ʈ
            lastEntryTime[carNumber] = totalMinutes;
        }
        else { // "OUT"
            // ������ ���, ���� �ð� ��� �� ���� �ð� ������Ʈ
            int parkedDuration = totalMinutes - lastEntryTime[carNumber];
            parkedTime[carNumber] += parkedDuration;
            lastEntryTime.erase(carNumber); // ���������Ƿ� ���� �ð� ����
        }
    }

    // ���� ����� ���� ������ ���� 23:59�� ���� ó��
    for (const auto& entry : lastEntryTime) {
        std::string carNumber = entry.first;
        int parkedDuration = calculateMinutes("23:59") - entry.second;
        parkedTime[carNumber] += parkedDuration;
    }

    // ���� ��ȣ ������ �����ϱ� ���� ���ͷ� ��ȯ
    std::vector<std::pair<std::string, int>> cars(parkedTime.begin(), parkedTime.end());
    std::sort(cars.begin(), cars.end());

    std::vector<int> feesResult; // ����� ������ ����

    for (const auto& car : cars) {
        int totalTime = car.second;
        int fee = fees[1]; // �⺻ ���

        if (totalTime > fees[0]) {
            // �⺻ �ð��� �ʰ��� ��� �߰� ��� ���
            int excessTime = totalTime - fees[0];
            int additionalUnits = std::ceil((double)excessTime / fees[2]);
            fee += additionalUnits * fees[3];
        }

        feesResult.push_back(fee); // ��� �߰�
    }

    return feesResult; // ���� ��� ��ȯ
}
