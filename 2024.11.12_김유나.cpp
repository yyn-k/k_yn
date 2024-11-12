#include <stdio.h>
#include <math.h>



double calculateWindChill(double T, double V) {
    return 13.12 + 0.6215 * T - 11.37 * pow(V, 0.16) + 0.3965 * T * pow(V, 0.16);
}

void recommendOutfit(double windChill) {
    if (windChill >= 30) {
        printf("추천 옷차림: 반팔과 반바지\n");
    }
    else if (windChill >= 20) {
        printf("추천 옷차림: 긴팔과 얇은 바지\n");
    }
    else if (windChill >= 10) {
        printf("추천 옷차림: 얇은 코트나 가디건\n");
    }
    else if (windChill >= 0) {
        printf("추천 옷차림: 두꺼운 코트와 스웨터\n");
    }
    else {
        printf("추천 옷차림: 패딩과 겨울 장갑\n");
    }
}

int main() {
    double temperature, windSpeed;

    printf("기온을 입력하세요 (°C): ");
    scanf_s("%lf", &temperature);

    printf("풍속을 입력하세요 (m/s): ");
    scanf_s("%lf", &windSpeed);

    double windChill = calculateWindChill(temperature, windSpeed);

    printf("체감 온도: %.2f°C\n", windChill);

    recommendOutfit(windChill);

    return 0;
}