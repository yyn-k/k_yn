#include <stdio.h>
#include <math.h>


float calculateFeelsLikeTemp(float temperature, float windSpeed);
void recommendActivity(float tempFeel);
void recommendStyling(float tempFeel);
void recommendClothing(float tempFeel);
float inputTemperature(float* temperature, float* windSpeed);
void inputSituation(int* choice);
void provideRecommendation(float tempFeel, int choice);



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




    // �� ī�װ����� �������� �ϳ��� ������ ����
    int upper = rand() % 3;      // 0~2 ������ ���� ����
    int lower = rand() % 3;
    int accessory = rand() % 3;



    if (tempFeel < -15) {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", veryCold[0][upper], veryCold[1][lower], veryCold[2][accessory]);
    }
    else if (tempFeel >= -15 && tempFeel < 5) {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", cold[0][upper], cold[1][lower], cold[2][accessory]);
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", chilly[0][upper], chilly[1][lower], chilly[2][accessory]);
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", nice[0][upper], nice[1][lower], nice[2][accessory]);
    }
    else {
        printf("%s %s %s ��(��) ���� �������� ��ġ�ϴ� �����ϰ� ��Ÿ�ϸ����� �ڵ� ��õ�մϴ�.\n", hot[0][upper], hot[1][lower], hot[2][accessory]);
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

// ����ڷκ��� ��°� ǳ�� �Է� �޾� ü�� �µ� ��� 
float inputTemperature(float* temperature, float* windSpeed) {
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%f", temperature);
    printf("ǳ���� km/h�� �Է��ϼ���: ");
    scanf_s("%f", windSpeed);

    return calculateFeelsLikeTemp(*temperature, *windSpeed);
}

void inputSituation(int* choice) {
    printf("�˰���� ������ �����ϼ���:\n");
    printf("1. � ��õ\n");
    printf("2. ��Ÿ�ϸ� ��õ\n");
    printf("3. ������ ��õ\n");
    printf("����: ");
    scanf_s("%d", choice);
}

// ���ÿ� ���� ��õ ������ �����ϴ� �Լ�
void provideRecommendation(float tempFeel, int choice) {

    printf("���� ü���µ��� %.2f���Դϴ�.\n", tempFeel);

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

int main() 
{
    float temperature, windSpeed, tempFeel;
    int choice;
    int continueChoice = 1;

    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("*                                               *\n");
    printf("*       ��� �� �� ���� ��õ ���α׷�           *\n");
    printf("*                                               *\n");
    printf("*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *\n\n\n");

    // ü���µ� ���� 
    tempFeel = inputTemperature(&temperature, &windSpeed);
    inputSituation(&choice); // ���� ���� 


    // ��õ ���� ����
    while (continueChoice == 1) {
        provideRecommendation(tempFeel, choice);

        // �߰� ���� ����
        printf("�߰� ������ ���Ͻø� 1��, ���α׷� ���Ḧ ���Ͻø� 2�� �Է��ϼ���: ");
        scanf_s("%d", &continueChoice);
        if (continueChoice == 1) {
            inputSituation(&choice); // ���ο� ���� ����
        }

    }

    printf("���α׷��� �����մϴ�.\n");
    return 0;
}