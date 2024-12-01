// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"  // functions.h 파일 포함

int main() {
    struct weatherInfo w;
    struct userChoice u;

    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*       기온 별 운동 추천 프로그램              *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");

    w.tempFeel = inputTemperature(&w.temperature, &w.windSpeed);
    w.raining = isRaining();
    inputSituation(&u.choice);

    provideRecommendation(w.tempFeel, w.raining, u.choice);

    // 추가 정보를 원하는지 묻기
    printf("\n추가 정보를 원하시면 1을, 프로그램 종료를 원하시면 2를 입력하세요: ");
    scanf_s("%d", &u.continueChoice);

    while (u.continueChoice == 1) {
        inputSituation(&u.choice);
        provideRecommendation(w.tempFeel, w.raining, u.choice);

        printf("\n추가 정보를 원하시면 1을, 프로그램 종료를 원하시면 2를 입력하세요: ");
        scanf_s("%d", &u.continueChoice);
    }

    printf("\n*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*              프로그램을 종료합니다.           *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");
    return 0;
}