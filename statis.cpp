#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

// 関数: 平均値を計算する
double calculateMean(const std::vector<int>& scores) {
    return static_cast<double>(std::accumulate(scores.begin(), scores.end(), 0)) / scores.size();
}

// 関数: 標準偏差を計算する
double calculateStandardDeviation(const std::vector<int>& scores, double mean) {
    double variance = 0.0;
    for (int score : scores) {
        variance += std::pow(score - mean, 2);
    }
    variance /= scores.size();
    return std::sqrt(variance);
}

// 関数: 偏差値を計算する
double calculateDeviationValue(int score, double mean, double stdDeviation) {
    return 50 + 10 * ((score - mean) / stdDeviation);
}

int main() {
    std::vector<int> scienceScores = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70}; // 理科の点数
    std::vector<int> englishScores = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84}; // 英語の点数

    // 理科の点数を高い順に並び替え
    std::sort(scienceScores.rbegin(), scienceScores.rend());

    // 平均点を計算
    double scienceMean = calculateMean(scienceScores);
    double englishMean = calculateMean(englishScores);

    // 標準偏差を計算
    double scienceStdDeviation = calculateStandardDeviation(scienceScores, scienceMean);
    double englishStdDeviation = calculateStandardDeviation(englishScores, englishMean);

    // 偏差値を計算
    std::vector<double> scienceDeviationValues;
    std::vector<double> englishDeviationValues;
    for (int score : scienceScores) {
        scienceDeviationValues.push_back(calculateDeviationValue(score, scienceMean, scienceStdDeviation));
    }
    for (int score : englishScores) {
        englishDeviationValues.push_back(calculateDeviationValue(score, englishMean, englishStdDeviation));
    }

    // 結果を出力
    std::cout << "理科の点数（高い順）: ";
    for (int score : scienceScores) {
        std::cout << score << " ";
    }
    std::cout << "\n理科の平均点: " << scienceMean << "\n理科の標準偏差: " << scienceStdDeviation << std::endl;

    std::cout << "\n英語の点数（高い順）: ";
    for (int score : englishScores) {
        std::cout << score << " ";
    }
    std::cout << "\n英語の平均点: " << englishMean << "\n英語の標準偏差: " << englishStdDeviation << std::endl;

    std::cout << "\n理科の偏差値: ";
    for (double deviation : scienceDeviationValues) {
        std::cout << deviation << " ";
    }
    std::cout << "\n英語の偏差値: ";
    for (double deviation : englishDeviationValues) {
        std::cout << deviation << " ";
    }
    std::cout << std::endl;

    return 0;
}
