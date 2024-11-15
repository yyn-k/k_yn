#include <stdio.h>
#include <math.h>


float calculateFeelsLikeTemp(float temperature, float windSpeed);
void recommendActivity(float tempFeel);
void recommendStyling(float tempFeel);
void recommendClothing(float tempFeel);
float inputTemperature(float* temperature, float* windSpeed);
void inputSituation(int* choice);
void provideRecommendation(float tempFeel, int choice);



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




    // 각 카테고리에서 랜덤으로 하나의 아이템 선택
    int upper = rand() % 3;      // 0~2 범위의 랜덤 숫자
    int lower = rand() % 3;
    int accessory = rand() % 3;



    if (tempFeel < -15) {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", veryCold[0][upper], veryCold[1][lower], veryCold[2][accessory]);
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", cold[0][upper], cold[1][lower], cold[2][accessory]);
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", chilly[0][upper], chilly[1][lower], chilly[2][accessory]);
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", nice[0][upper], nice[1][lower], nice[2][accessory]);
    }
    else {
        printf("%s %s %s 와(과) 같은 아이템을 매치하는 따뜻하고 스타일리쉬한 코디를 추천합니다.\n", hot[0][upper], hot[1][lower], hot[2][accessory]);
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

// 사용자로부터 기온과 풍속 입력 받아 체감 온도 계산 
float inputTemperature(float* temperature, float* windSpeed) {
    printf("기온을 섭씨로 입력하세요: ");
    scanf_s("%f", temperature);
    printf("풍속을 km/h로 입력하세요: ");
    scanf_s("%f", windSpeed);

    return calculateFeelsLikeTemp(*temperature, *windSpeed);
}

void inputSituation(int* choice) {
    printf("알고싶은 정보를 선택하세요:\n");
    printf("1. 운동 추천\n");
    printf("2. 스타일링 추천\n");
    printf("3. 옷차림 추천\n");
    printf("선택: ");
    scanf_s("%d", choice);
}

// 선택에 따라 추천 정보를 제공하는 함수
void provideRecommendation(float tempFeel, int choice) {

    printf("현재 체감온도는 %.2f도입니다.\n", tempFeel);

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

int main() 
{
    float temperature, windSpeed, tempFeel;
    int choice;
    int continueChoice = 1;

    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*       기온 별 옷 차림 추천 프로그램           *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");

    // 체감온도 저장 
    tempFeel = inputTemperature(&temperature, &windSpeed);
    inputSituation(&choice); // 정보 선택 


    // 추천 정보 제공
    while (continueChoice == 1) {
        provideRecommendation(tempFeel, choice);

        // 추가 정보 선택
        printf("추가 정보를 원하시면 1을, 프로그램 종료를 원하시면 2를 입력하세요: ");
        scanf_s("%d", &continueChoice);
        if (continueChoice == 1) {
            inputSituation(&choice); // 새로운 정보 선택
        }

    }

    printf("프로그램을 종료합니다.\n");
    return 0;
}