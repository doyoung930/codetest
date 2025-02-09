#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>

// 시간을 분으로 변환하는 함수
int calculateMinutes(const std::string& time) {
    int hours = std::stoi(time.substr(0, 2));    // 시 추출
    int minutes = std::stoi(time.substr(3, 2));  // 분 추출
    return hours * 60 + minutes;                  // 총 분 계산
}

// 문자열을 특정 문자로 분할하는 함수
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;             // 결과를 저장할 벡터
    std::string token;                           // 현재 토큰
    std::istringstream tokenStream(s);           // 입력 스트림 생성
    while (std::getline(tokenStream, token, delimiter)) { // 구분자로 분할
        tokens.push_back(token);                 // 벡터에 추가
    }
    return tokens;                               // 분할된 문자열 반환
}

std::vector<int> solution(std::vector<int> fees, std::vector<std::string> records) {
    // 차량별 총 주차 시간을 저장할 맵
    std::map<std::string, int> parkedTime;
    // 차량별 마지막 입차 시간을 저장할 맵
    std::map<std::string, int> lastEntryTime;

    for (const auto& record : records) {
        // 기록을 시각, 차량 번호, 상태로 분할
        std::vector<std::string> tokens = split(record, ' ');
        std::string time = tokens[0];
        std::string carNumber = tokens[1];
        std::string status = tokens[2];

        int totalMinutes = calculateMinutes(time); // 시각을 분으로 변환

        if (status == "IN") {
            // 입차인 경우, 마지막 입차 시간 업데이트
            lastEntryTime[carNumber] = totalMinutes;
        }
        else { // "OUT"
            // 출차인 경우, 주차 시간 계산 후 누적 시간 업데이트
            int parkedDuration = totalMinutes - lastEntryTime[carNumber];
            parkedTime[carNumber] += parkedDuration;
            lastEntryTime.erase(carNumber); // 출차했으므로 입차 시간 제거
        }
    }

    // 출차 기록이 없는 차량에 대해 23:59에 출차 처리
    for (const auto& entry : lastEntryTime) {
        std::string carNumber = entry.first;
        int parkedDuration = calculateMinutes("23:59") - entry.second;
        parkedTime[carNumber] += parkedDuration;
    }

    // 차량 번호 순으로 정렬하기 위해 벡터로 변환
    std::vector<std::pair<std::string, int>> cars(parkedTime.begin(), parkedTime.end());
    std::sort(cars.begin(), cars.end());

    std::vector<int> feesResult; // 결과를 저장할 벡터

    for (const auto& car : cars) {
        int totalTime = car.second;
        int fee = fees[1]; // 기본 요금

        if (totalTime > fees[0]) {
            // 기본 시간을 초과한 경우 추가 요금 계산
            int excessTime = totalTime - fees[0];
            int additionalUnits = std::ceil((double)excessTime / fees[2]);
            fee += additionalUnits * fees[3];
        }

        feesResult.push_back(fee); // 요금 추가
    }

    return feesResult; // 최종 요금 반환
}
