#pragma once
// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//�������� �� ����� �Է� ����ü ����
struct weatherInfo {
    float temperature;   // ���
    float windSpeed;     // ǳ��
    float tempFeel;    // ü�� �µ�
    bool raining;        // �� ������ ����
};

struct userChoice {
    int choice;          // ����ڰ� ������ ���
    int continueChoice;  // �߰� ������ ���ϸ� 1, ���Ḧ ���ϸ� 2
};


// ü�� �µ� ��� �Լ�
float calculateFeelsLikeTemp(float temperature, float windSpeed);

// � ��õ �Լ�
void recommendActivity(float tempFeel, bool raining);

// ��Ÿ�ϸ� ��õ �Լ�
void recommendStyling(float tempFeel, bool raining);

// ������ ��õ �Լ�
void recommendClothing(float tempFeel);

// ����ڷκ��� ��°� ǳ�� �Է� �޴� �Լ�
float inputTemperature(float* temperature, float* windSpeed);

// ����ڷκ��� ���ϴ� ����� �Է� �޴� �Լ�
void inputSituation(int* choice);

// ���ÿ� ���� ��õ ������ �����ϴ� �Լ�
void provideRecommendation(float tempFeel, bool raining, int choice);

// �� ������ ���� �Լ�
bool isRaining();

// �� �� �� � ��õ �Լ�
void recommendRainyActivity();

// �� �� �� ������ ��õ �Լ�
void recommendRainyClothing();

#endif  // FUNCTIONS_H#pragma once