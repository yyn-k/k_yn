#include <stdio.h>
#include <math.h>



// 체감 온도 계산 함수
float calculateFeelsLikeTemp(float temperature, float windSpeed) {
    return 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
}

// 운동 추천 함수
void recommendActivity(float tempFeel) {
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
void recommendStyling(float tempFeel) {

    if (tempFeel < -15) {
        printf("\n");
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("\n");
    }
    else {
        printf("\n");
    }
}

// 옷차림 추천 함수
void recommendClothing(float tempFeel) {
    if (tempFeel < -15) {
        printf("체감온도가 매우 낮습니다. 두꺼운 코트와 따뜻한 장갑, 목도리, 모자가 필요합니다.\n");
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("체감온도가 춥습니다. 따뜻한 외투와 장갑을 착용하세요.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("체감온도가 쌀쌀합니다. 가벼운 외투나 재킷을 착용하세요.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("체감온도가 좋습니다. 가벼운 옷이나 티셔츠가 적합합니다.\n");
    }
    else {
        printf("체감온도가 덥습니다. 통기성이 좋은 옷을 입고, 햇볕을 피하세요.\n");
    }
}

// 사용자로부터 입력을 받는 함수
void inputTemperature(float* temperature, float* windSpeed) {
    printf("기온을 섭씨로 입력하세요: ");
    scanf_s("%f", temperature);
    printf("풍속을 km/h로 입력하세요: ");
    scanf_s("%f", windSpeed);
}

void inputSituation(int* choice) {
    printf("날씨에 맞는 정보를 선택하세요:\n");
    printf("1. 운동 추천\n");
    printf("2. 스타일링 추천\n");
    printf("3. 옷차림 추천\n");
    printf("선택: ");
    scanf_s("%d", choice);
}

// 선택에 따라 추천 정보를 제공하는 함수
void provideRecommendation(float tempFeel, int choice) {
    switch (choice) {
    case 1:
        recommendActivity(tempFeel);
        break;
    case 2:
        recommendStyling(tempFeel);
        break;
    case 3:
        recommendClothing(tempFeel);
        break;
    default:
        printf("잘못된 입력입니다.\n");
        break;
    }
}

int main() {
    float temperature, windSpeed, tempFeel;
    int choice;
    int continueChoice;

    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*       기온 별 옷 차림 추천 프로그램           *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");
    // 사용자 입력 받기
    inputTemperature(&temperature, &windSpeed);
    inputSituation(&choice);

    // 체감 온도 계산
    tempFeel = calculateFeelsLikeTemp(temperature, windSpeed);
    printf("체감온도는 %.2f도 입니다.\n", tempFeel);

    printf("추가 정보를 원하시면 1을, 프로그램 종료를 원하시면 2를 입력하세요: ");
    scanf_s("%d", &continueChoice);
    // 추천 정보 제공
    if (continueChoice == 1) {
        while (continueChoice == 1) {
            inputSituation(&choice);
            provideRecommendation(tempFeel, choice);

            // 추가 정보 선택
            printf("추가 정보를 원하시면 1을, 프로그램 종료를 원하시면 2를 입력하세요: ");
            scanf_s("%d", &continueChoice);
        }
    }


    printf("프로그램을 종료합니다.\n");
    return 0;
}