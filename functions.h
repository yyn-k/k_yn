#pragma once
// functions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//날씨정보 및 사용자 입력 구조체 선언
struct weatherInfo {
    float temperature;   // 기온
    float windSpeed;     // 풍속
    float tempFeel;    // 체감 온도
    bool raining;        // 비가 오는지 여부
};

struct userChoice {
    int choice;          // 사용자가 선택한 기능
    int continueChoice;  // 추가 정보를 원하면 1, 종료를 원하면 2
};


// 체감 온도 계산 함수
float calculateFeelsLikeTemp(float temperature, float windSpeed);

// 운동 추천 함수
void recommendActivity(float tempFeel, bool raining);

// 스타일링 추천 함수
void recommendStyling(float tempFeel, bool raining);

// 옷차림 추천 함수
void recommendClothing(float tempFeel);

// 사용자로부터 기온과 풍속 입력 받는 함수
float inputTemperature(float* temperature, float* windSpeed);

// 사용자로부터 원하는 기능을 입력 받는 함수
void inputSituation(int* choice);

// 선택에 따라 추천 정보를 제공하는 함수
void provideRecommendation(float tempFeel, bool raining, int choice);

// 비가 오는지 묻는 함수
bool isRaining();

// 비가 올 때 운동 추천 함수
void recommendRainyActivity();

// 비가 올 때 옷차림 추천 함수
void recommendRainyClothing();

#endif  // FUNCTIONS_H#pragma once