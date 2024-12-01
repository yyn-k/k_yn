// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"  // functions.h ���� ����

int main() {
    struct weatherInfo w;
    struct userChoice u;

    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*       ��� �� � ��õ ���α׷�              *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");

    w.tempFeel = inputTemperature(&w.temperature, &w.windSpeed);
    w.raining = isRaining();
    inputSituation(&u.choice);

    provideRecommendation(w.tempFeel, w.raining, u.choice);

    // �߰� ������ ���ϴ��� ����
    printf("\n�߰� ������ ���Ͻø� 1��, ���α׷� ���Ḧ ���Ͻø� 2�� �Է��ϼ���: ");
    scanf_s("%d", &u.continueChoice);

    while (u.continueChoice == 1) {
        inputSituation(&u.choice);
        provideRecommendation(w.tempFeel, w.raining, u.choice);

        printf("\n�߰� ������ ���Ͻø� 1��, ���α׷� ���Ḧ ���Ͻø� 2�� �Է��ϼ���: ");
        scanf_s("%d", &u.continueChoice);
    }

    printf("\n*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*              ���α׷��� �����մϴ�.           *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");
    return 0;
}