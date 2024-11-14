#include <stdio.h>
#include <math.h>



// ü�� �µ� ��� �Լ�
float calculateFeelsLikeTemp(float temperature, float windSpeed) {
    return 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);
}

// � ��õ �Լ�
void recommendActivity(float tempFeel) {
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

// ������ ��õ �Լ�
void recommendClothing(float tempFeel) {
    if (tempFeel < -15) {
        printf("ü���µ��� �ſ� �����ϴ�. �β��� ��Ʈ�� ������ �尩, �񵵸�, ���ڰ� �ʿ��մϴ�.\n");
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("ü���µ��� ����ϴ�. ������ ������ �尩�� �����ϼ���.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("ü���µ��� �ҽ��մϴ�. ������ ������ ��Ŷ�� �����ϼ���.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("ü���µ��� �����ϴ�. ������ ���̳� Ƽ������ �����մϴ�.\n");
    }
    else {
        printf("ü���µ��� �����ϴ�. ��⼺�� ���� ���� �԰�, �޺��� ���ϼ���.\n");
    }
}

// ����ڷκ��� �Է��� �޴� �Լ�
void inputTemperature(float* temperature, float* windSpeed) {
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%f", temperature);
    printf("ǳ���� km/h�� �Է��ϼ���: ");
    scanf_s("%f", windSpeed);
}

void inputSituation(int* choice) {
    printf("������ �´� ������ �����ϼ���:\n");
    printf("1. � ��õ\n");
    printf("2. ��Ÿ�ϸ� ��õ\n");
    printf("3. ������ ��õ\n");
    printf("����: ");
    scanf_s("%d", choice);
}

// ���ÿ� ���� ��õ ������ �����ϴ� �Լ�
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
        printf("�߸��� �Է��Դϴ�.\n");
        break;
    }
}

int main() {
    float temperature, windSpeed, tempFeel;
    int choice;
    int continueChoice;

    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*       ��� �� �� ���� ��õ ���α׷�           *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");
    // ����� �Է� �ޱ�
    inputTemperature(&temperature, &windSpeed);
    inputSituation(&choice);

    // ü�� �µ� ���
    tempFeel = calculateFeelsLikeTemp(temperature, windSpeed);
    printf("ü���µ��� %.2f�� �Դϴ�.\n", tempFeel);

    printf("�߰� ������ ���Ͻø� 1��, ���α׷� ���Ḧ ���Ͻø� 2�� �Է��ϼ���: ");
    scanf_s("%d", &continueChoice);
    // ��õ ���� ����
    if (continueChoice == 1) {
        while (continueChoice == 1) {
            inputSituation(&choice);
            provideRecommendation(tempFeel, choice);

            // �߰� ���� ����
            printf("�߰� ������ ���Ͻø� 1��, ���α׷� ���Ḧ ���Ͻø� 2�� �Է��ϼ���: ");
            scanf_s("%d", &continueChoice);
        }
    }


    printf("���α׷��� �����մϴ�.\n");
    return 0;
}