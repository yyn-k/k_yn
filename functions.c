// functions.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "functions.h"  // ��� ���� ����

// ü�� �µ� ��� �Լ�
float calculateFeelsLikeTemp(float temperature, float windSpeed) {
    return 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
}

// � ��õ �Լ�
void recommendActivity(float tempFeel, bool raining) {
    if (raining) {
        recommendRainyActivity();
        return;
    }

    if (tempFeel < -15) {
        printf("������ �ſ� ����ϴ�. �ǳ� � �Ǵ� ��Ʈ��Ī�� ��õ�մϴ�.\n");
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("������ ����ϴ�. �ǿ� ��� ���Ͻø� �غ� ��, �ܿ� �������� ��õ�մϴ�.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("������ �ҽ��մϴ�. �߿� �����̳� ������ Ÿ�� ���� ��õ�մϴ�.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("������ �����ϴ�. �߿� ��̳� ��å�� �ϴ� ���� ��õ�մϴ�.\n");
    }
    else {
        printf("������ �����ϴ�. ������ ����� �����ϸ� ������ ��̳� �ǳ� ��� ��õ�մϴ�.\n");
    }
}

// ��Ÿ�ϸ� ��õ �Լ�
void recommendStyling(float tempFeel, bool raining) {
    if (raining) {
        printf("�� ���� ������ ��� ��Ŷ�̳� ���, ��� �Ź��� �����ϼ���. �߰��� �Ʒ��� �����ϼ���:\n");
    }

    const char* veryCold[3][3] = {
        {"���е�", "�ٿ� ��Ŷ", "�β��� �ø���"},
        {"�ڵ���� ����", "��� û����", "�� ��ĿƮ"},
        {"����", "������ �񵵸�", "��Ʈ ���"}
    };

    const char* cold[3][3] = {
        {"�� ��Ʈ", "������", "���е�"},
        {"����Ʈ ����", "��� û����", "�� ��ĿƮ"},
        {"�� ����", "��Ʈ �尩", "����"}
    };

    const char* chilly[3][3] = {
        {"�ٶ�����", "���� ��Ŷ", "Ʈ��ġ ��Ʈ"},
        {"û����", "Ʈ���̴� ����", "�� ����"},
        {"������ �� ��ī��", "������ ���", "����"}
    };

    const char* nice[3][3] = {
        {"�ĵ� Ƽ����", "������ ��Ŷ", "���� �����"},
        {"û����", "���� ����", "���� �� ����"},
        {"���� �ð�", "���� �Ȱ�", "�����"}
    };

    const char* hot[3][3] = {
        {"���� ������ �ݼҸ� Ƽ����", "�Ͽ��̾� ����", "���� ����"},
        {"Ʈ���̴� �ݹ���", "���� ����", "�̴� ��ĿƮ"},
        {"ĸ ����", "��Ż ��Ʈ�� �ð�", "����"}
    };

    int upper = rand() % 3;      // 0~2 ������ ���� ����
    int lower = rand() % 3;
    int accessory = rand() % 3;

    if (tempFeel < -15) {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", veryCold[upper][0], veryCold[lower][1], veryCold[accessory][2]);
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", cold[upper][0], cold[lower][1], cold[accessory][2]);
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("%s %s %s ��(��) ���� �������� Ȱ���Ͽ� �ϱ����� ������ �� �ִ� �ѿʰ� ������ �β��� �����Ǹ� ��ġ�ϴ� �ڵ� ��õ�մϴ�.\n", chilly[upper][0], chilly[lower][1], chilly[accessory][2]);
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("%s %s %s ��(��) ���� ���������� ������ �ʵ�� �׼������� ����Ʈ�� �־� ���� ������ �´� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", nice[upper][0], nice[lower][1], nice[accessory][2]);
    }
    else {
        printf("%s %s %s ��(��) ���� �������� ��ġ�Ͽ� ������ �������� ��� ���� �Ϸ縦 ���� �� �ִ� �ڵ� ��õ�մϴ�.\n", hot[upper][0], hot[lower][1], hot[accessory][2]);
    }
}

// ������ ��õ �Լ�
void recommendClothing(float tempFeel) {
    if (tempFeel < -15) {
        printf("ü���µ��� %.2f���� �ſ� �����ϴ�. �β��� ��Ʈ�� ������ �尩, �񵵸�, ���ڰ� �ʿ��մϴ�.\n", tempFeel);
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("ü���µ��� %.2f���� ����ϴ�. ������ ������ �尩�� �����ϼ���.\n", tempFeel);
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("ü���µ��� %.2f���� �ҽ��մϴ�. ������ ������ ��Ŷ�� �����ϼ���.\n", tempFeel);
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("ü���µ��� %.2f���� �����ϴ�. ������ ���̳� Ƽ������ �����մϴ�.\n", tempFeel);
    }
    else {
        printf("ü���µ��� %.2f���� �����ϴ�. ��⼺�� ���� ���� �԰�, �޺��� ���ϼ���.\n", tempFeel);
    }
}

// ����ڷκ��� ��°� ǳ�� �Է� �޾� ü�� �µ� ��� 
float inputTemperature(float* temperature, float* windSpeed) {
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%f", temperature);
    printf("ǳ���� km/h�� �Է��ϼ���: ");
    scanf_s("%f", windSpeed);

    return calculateFeelsLikeTemp(*temperature, *windSpeed);
}

// ����ڷκ��� ���ϴ� ����� �Է� �޴� �Լ�
void inputSituation(int* choice) {
    while (1) {
        printf("\n�˰���� ������ �����ϼ���:\n");
        printf("1. � ��õ\n");
        printf("2. ��Ÿ�ϸ� ��õ\n");
        printf("3. ������ ��õ\n");
        printf("����: ");
        scanf_s("%d", choice);

        if (*choice >= 1 && *choice <= 3) {
            break;
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.\n");
        }
    }
}

// ���ÿ� ���� ��õ ������ �����ϴ� �Լ�
void provideRecommendation(float tempFeel, bool raining, int choice) {
    printf("\n���� ü���µ��� %.2f���Դϴ�.\n\n", tempFeel);

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
        printf("�߸��� �Է��Դϴ�.\n");
        break;
    }
}

// �� ������ ���� �Լ�
bool isRaining() {
    int rainChoice;
    while (1) {
        printf("\n�� ������? (1: ��, 2: �ƴϿ�): ");
        scanf_s("%d", &rainChoice);

        if (rainChoice == 1) {
            return true;
        }
        else if (rainChoice == 2) {
            return false;
        }
        else {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }
}

// �� �� �� � ��õ �Լ�
void recommendRainyActivity() {
    printf("�� ���� ������ �ǳ� ��� ��õ�մϴ�. (�䰡, �ʶ��׽�, Ȩ Ʈ���̴�)\n");
}

// �� �� �� ������ ��õ �Լ�
void recommendRainyClothing() {
    printf("�� ���� ������ ��� ��Ŷ�̳� ���, ��� �Ź��� �����ϼ���. ��굵 �� ì�⼼��!\n");
}