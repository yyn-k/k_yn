// functions.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "functions.h"  // 헤더 파일 포함

// 체감 온도 계산 함수
float calculateFeelsLikeTemp(float temperature, float windSpeed) {
    return 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
}

// 운동 추천 함수
void recommendActivity(float tempFeel, bool raining) {
    if (raining) {
        recommendRainyActivity();
        return;
    }

    if (tempFeel < -15) {
        printf("날씨가 매우 춥습니다. 실내 운동 또는 스트레칭을 추천합니다.\n");
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("날씨가 춥습니다. 실외 운동을 원하시면 준비운동 후, 겨울 스포츠를 추천합니다.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("날씨가 쌀쌀합니다. 야외 조깅이나 자전거 타는 것을 추천합니다.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("날씨가 덥습니다. 야외 운동이나 산책을 하는 것을 추천합니다.\n");
    }
    else {
        printf("날씨가 덥습니다. 수분을 충분히 섭취하며 가벼운 운동이나 실내 운동을 추천합니다.\n");
    }
}

// 스타일링 추천 함수
void recommendStyling(float tempFeel, bool raining) {
    if (raining) {
        printf("비가 오는 날에는 방수 재킷이나 우비, 방수 신발을 착용하세요. 추가로 아래를 참고하세요:\n");
    }

    const char* veryCold[3][3] = {
        {"롱패딩", "다운 재킷", "두꺼운 플리스"},
        {"코듀로이 팬츠", "기모 청바지", "롱 스커트"},
        {"로퍼", "도톰한 목도리", "니트 비니"}
    };

    const char* cold[3][3] = {
        {"롱 코트", "무스탕", "숏패딩"},
        {"스웨트 팬츠", "기모 청바지", "롱 스커트"},
        {"털 부츠", "니트 장갑", "로퍼"}
    };

    const char* chilly[3][3] = {
        {"바람막이", "레더 재킷", "트렌치 코트"},
        {"청바지", "트레이닝 팬츠", "면 팬츠"},
        {"가벼운 울 스카프", "슬림한 비니", "로퍼"}
    };

    const char* nice[3][3] = {
        {"후드 티셔츠", "슬림핏 재킷", "얇은 가디건"},
        {"청바지", "조거 팬츠", "얇은 면 바지"},
        {"가죽 시계", "뿔테 안경", "블로퍼"}
    };

    const char* hot[3][3] = {
        {"밝은 색상의 반소매 티셔츠", "하와이안 셔츠", "반팔 셔츠"},
        {"트레이닝 반바지", "리넨 팬츠", "미니 스커트"},
        {"캡 모자", "메탈 스트랩 시계", "샌들"}
    };

    int upper = rand() % 3;      // 0~2 범위의 랜덤 숫자
    int lower = rand() % 3;
    int accessory = rand() % 3;

    if (tempFeel < -15) {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", veryCold[upper][0], veryCold[lower][1], veryCold[accessory][2]);
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", cold[upper][0], cold[lower][1], cold[accessory][2]);
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("%s %s %s 와(과) 같은 아이템을 활용하여 일교차를 예방할 수 있는 겉옷과 적당한 두께의 상하의를 매치하는 코디를 추천합니다.\n", chilly[upper][0], chilly[lower][1], chilly[accessory][2]);
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("%s %s %s 와(과) 같은 아이템으로 가벼운 옷들과 액세서리로 포인트를 주어 좋은 날씨에 맞는 스타일리쉬한 코디를 추천합니다.\n", nice[upper][0], nice[lower][1], nice[accessory][2]);
    }
    else {
        printf("%s %s %s 와(과) 같은 아이템을 매치하여 무더운 날씨에도 기분 좋은 하루를 보낼 수 있는 코디를 추천합니다.\n", hot[upper][0], hot[lower][1], hot[accessory][2]);
    }
}

// 옷차림 추천 함수
void recommendClothing(float tempFeel) {
    if (tempFeel < -15) {
        printf("체감온도가 %.2f도로 매우 낮습니다. 두꺼운 코트와 따뜻한 장갑, 목도리, 모자가 필요합니다.\n", tempFeel);
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("체감온도가 %.2f도로 춥습니다. 따뜻한 외투와 장갑을 착용하세요.\n", tempFeel);
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("체감온도가 %.2f도로 쌀쌀합니다. 가벼운 외투나 재킷을 착용하세요.\n", tempFeel);
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("체감온도가 %.2f도로 좋습니다. 가벼운 옷이나 티셔츠가 적합합니다.\n", tempFeel);
    }
    else {
        printf("체감온도가 %.2f도로 덥습니다. 통기성이 좋은 옷을 입고, 햇볕을 피하세요.\n", tempFeel);
    }
}

// 사용자로부터 기온과 풍속 입력 받아 체감 온도 계산 
float inputTemperature(float* temperature, float* windSpeed) {
    printf("기온을 섭씨로 입력하세요: ");
    scanf_s("%f", temperature);
    printf("풍속을 km/h로 입력하세요: ");
    scanf_s("%f", windSpeed);

    return calculateFeelsLikeTemp(*temperature, *windSpeed);
}

// 사용자로부터 원하는 기능을 입력 받는 함수
void inputSituation(int* choice) {
    while (1) {
        printf("\n알고싶은 정보를 선택하세요:\n");
        printf("1. 운동 추천\n");
        printf("2. 스타일링 추천\n");
        printf("3. 옷차림 추천\n");
        printf("선택: ");
        scanf_s("%d", choice);

        if (*choice >= 1 && *choice <= 3) {
            break;
        }
        else {
            printf("잘못된 입력입니다. 다시 선택해주세요.\n");
        }
    }
}

// 선택에 따라 추천 정보를 제공하는 함수
void provideRecommendation(float tempFeel, bool raining, int choice) {
    printf("\n현재 체감온도는 %.2f도입니다.\n\n", tempFeel);

    switch (choice) {
    case 1:
        recommendActivity(tempFeel, raining);
        break;
    case 2:
        recommendStyling(tempFeel, raining);
        break;
    case 3:
        recommendClothing(tempFeel);
        break;
    default:
        printf("잘못된 입력입니다.\n");
        break;
    }
}

// 비가 오는지 묻는 함수
bool isRaining() {
    int rainChoice;
    while (1) {
        printf("\n비가 오나요? (1: 예, 2: 아니오): ");
        scanf_s("%d", &rainChoice);

        if (rainChoice == 1) {
            return true;
        }
        else if (rainChoice == 2) {
            return false;
        }
        else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }
}

// 비가 올 때 운동 추천 함수
void recommendRainyActivity() {
    printf("비가 오는 날에는 실내 운동을 추천합니다. (요가, 필라테스, 홈 트레이닝)\n");
}

// 비가 올 때 옷차림 추천 함수
void recommendRainyClothing() {
    printf("비가 오는 날에는 방수 재킷이나 우비, 방수 신발을 착용하세요. 우산도 꼭 챙기세요!\n");
}