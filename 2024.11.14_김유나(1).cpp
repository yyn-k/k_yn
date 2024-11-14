#include <stdio.h>
#include <math.h>

void recommendActivity(float tempFeel) {
    if (tempFeel < -10) {
        printf("날씨가 매우 추워요. 실내 운동을 추천합니다. 또는 따뜻한 장소에서 스트레칭을 하세요.\n");
    }
    else if (tempFeel >= -10 && tempFeel < 5) {
        printf("추운 날씨입니다. 실외 운동을 원하시면 준비운동 후, 겨울 스포츠를 추천합니다.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("약간 쌀쌀한 날씨입니다. 야외 조깅이나 자전거 타기에 적합합니다.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("좋은 날씨입니다. 야외 운동이나 산책을 하기에 이상적인 날씨입니다.\n");
    }
    else {
        printf("덥습니다. 수분을 충분히 섭취하며 가벼운 운동이나 실내 운동을 추천합니다.\n");
    }
}

void recommendStyling(float tempFeel) {
    if (tempFeel < -10) {
        printf("매우 추운 날씨입니다. 두꺼운 외투와 장갑, 모자 등으로 따뜻하게 꾸미세요.\n");
    }
    else if (tempFeel >= -10 && tempFeel < 5) {
        printf("추운 날씨입니다. 따뜻한 외투와 목도리, 장갑을 착용하세요.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("쌀쌀한 날씨입니다. 가벼운 재킷과 스카프를 추천합니다.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("좋은 날씨입니다. 가벼운 옷이나 티셔츠를 입고 외출하세요.\n");
    }
    else {
        printf("덥습니다. 가벼운 옷과 모자, 썬크림을 준비하세요.\n");
    }
}

void recommendClothing(float tempFeel) {
    if (tempFeel < -10) {
        printf("체감온도가 매우 낮습니다. 두꺼운 코트와 따뜻한 장갑, 목도리, 모자가 필요합니다.\n");
    }
    else if (tempFeel >= -10 && tempFeel < 5) {
        printf("체감온도가 춥습니다. 따뜻한 외투와 장갑을 착용하세요.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("체감온도가 약간 쌀쌀합니다. 가벼운 외투나 재킷을 착용하세요.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("체감온도가 좋습니다. 가벼운 옷이나 티셔츠가 적합합니다.\n");
    }
    else {
        printf("체감온도가 덥습니다. 통기성이 좋은 옷을 입고, 햇볕을 피하세요.\n");
    }
}

int main() 
{

    float temperature, windSpeed, tempFeel;
    int choice;

    // 사용자로부터 기온과 풍속을 입력 받음
    printf("기온을 섭씨로 입력하세요: ");
    scanf_s("%f", &temperature);
    printf("풍속을 km/h로 입력하세요: ");
    scanf_s("%f", &windSpeed);

    // 체감온도 계산
    tempFeel = 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);

    // 체감온도 출력
    printf("체감온도는 %.2f도 입니다.\n", tempFeel);

    // 사용자에게 선택지 제공
    printf("알고싶은 정보를 선택하세요:\n");
    printf("1. 운동 추천\n");
    printf("2. 스타일링 추천\n");
    printf("3. 옷차림 추천\n");
    printf("선택: ");
    scanf_s("%d", &choice);

    // 선택한 옵션에 따라 추천 정보 제공
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

    return 0;
}
