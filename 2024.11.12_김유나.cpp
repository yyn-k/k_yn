#include <stdio.h>
#include <math.h>



double calculateWindChill(double T, double V) {
    return 13.12 + 0.6215 * T - 11.37 * pow(V, 0.16) + 0.3965 * T * pow(V, 0.16);
}

void recommendOutfit(double windChill) {
    if (windChill >= 30) {
        printf("��õ ������: ���Ȱ� �ݹ���\n");
    }
    else if (windChill >= 20) {
        printf("��õ ������: ���Ȱ� ���� ����\n");
    }
    else if (windChill >= 10) {
        printf("��õ ������: ���� ��Ʈ�� �����\n");
    }
    else if (windChill >= 0) {
        printf("��õ ������: �β��� ��Ʈ�� ������\n");
    }
    else {
        printf("��õ ������: �е��� �ܿ� �尩\n");
    }
}

int main() {
    double temperature, windSpeed;

    printf("����� �Է��ϼ��� (��C): ");
    scanf_s("%lf", &temperature);

    printf("ǳ���� �Է��ϼ��� (m/s): ");
    scanf_s("%lf", &windSpeed);

    double windChill = calculateWindChill(temperature, windSpeed);

    printf("ü�� �µ�: %.2f��C\n", windChill);

    recommendOutfit(windChill);

    return 0;
}