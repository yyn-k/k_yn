#include <stdio.h>
#include <math.h>

void recommendActivity(float tempFeel) {
    if (tempFeel < -10) {
        printf("������ �ſ� �߿���. �ǳ� ��� ��õ�մϴ�. �Ǵ� ������ ��ҿ��� ��Ʈ��Ī�� �ϼ���.\n");
    }
    else if (tempFeel >= -10 && tempFeel < 5) {
        printf("�߿� �����Դϴ�. �ǿ� ��� ���Ͻø� �غ� ��, �ܿ� �������� ��õ�մϴ�.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("�ణ �ҽ��� �����Դϴ�. �߿� �����̳� ������ Ÿ�⿡ �����մϴ�.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("���� �����Դϴ�. �߿� ��̳� ��å�� �ϱ⿡ �̻����� �����Դϴ�.\n");
    }
    else {
        printf("�����ϴ�. ������ ����� �����ϸ� ������ ��̳� �ǳ� ��� ��õ�մϴ�.\n");
    }
}

void recommendStyling(float tempFeel) {
    if (tempFeel < -10) {
        printf("�ſ� �߿� �����Դϴ�. �β��� ������ �尩, ���� ������ �����ϰ� �ٹ̼���.\n");
    }
    else if (tempFeel >= -10 && tempFeel < 5) {
        printf("�߿� �����Դϴ�. ������ ������ �񵵸�, �尩�� �����ϼ���.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("�ҽ��� �����Դϴ�. ������ ��Ŷ�� ��ī���� ��õ�մϴ�.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("���� �����Դϴ�. ������ ���̳� Ƽ������ �԰� �����ϼ���.\n");
    }
    else {
        printf("�����ϴ�. ������ �ʰ� ����, ��ũ���� �غ��ϼ���.\n");
    }
}

void recommendClothing(float tempFeel) {
    if (tempFeel < -10) {
        printf("ü���µ��� �ſ� �����ϴ�. �β��� ��Ʈ�� ������ �尩, �񵵸�, ���ڰ� �ʿ��մϴ�.\n");
    }
    else if (tempFeel >= -10 && tempFeel < 5) {
        printf("ü���µ��� ����ϴ�. ������ ������ �尩�� �����ϼ���.\n");
    }
    else if (tempFeel >= 5 && tempFeel < 15) {
        printf("ü���µ��� �ణ �ҽ��մϴ�. ������ ������ ��Ŷ�� �����ϼ���.\n");
    }
    else if (tempFeel >= 15 && tempFeel < 25) {
        printf("ü���µ��� �����ϴ�. ������ ���̳� Ƽ������ �����մϴ�.\n");
    }
    else {
        printf("ü���µ��� �����ϴ�. ��⼺�� ���� ���� �԰�, �޺��� ���ϼ���.\n");
    }
}

int main() 
{

    float temperature, windSpeed, tempFeel;
    int choice;

    // ����ڷκ��� ��°� ǳ���� �Է� ����
    printf("����� ������ �Է��ϼ���: ");
    scanf_s("%f", &temperature);
    printf("ǳ���� km/h�� �Է��ϼ���: ");
    scanf_s("%f", &windSpeed);

    // ü���µ� ���
    tempFeel = 13.12 + 0.6215 * temperature - 11.37 * pow(windSpeed, 0.16) + 0.3965 * temperature * pow(windSpeed, 0.16);

    // ü���µ� ���
    printf("ü���µ��� %.2f�� �Դϴ�.\n", tempFeel);

    // ����ڿ��� ������ ����
    printf("�˰���� ������ �����ϼ���:\n");
    printf("1. � ��õ\n");
    printf("2. ��Ÿ�ϸ� ��õ\n");
    printf("3. ������ ��õ\n");
    printf("����: ");
    scanf_s("%d", &choice);

    // ������ �ɼǿ� ���� ��õ ���� ����
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

    return 0;
}
