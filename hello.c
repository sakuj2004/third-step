#include <stdio.h>
#include <math.h>

// 関数宣言
double calculate_mean(int[], int);
double calculate_standard_deviation(int[], int, double);
void calculate_z_scores(int[], int, double, double[], double, double);
void sort_scores_descending(int[], int);

int main() {
    // データ
    int science_scores[] = {65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70};
    int english_scores[] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84};
    int num_students = sizeof(science_scores) / sizeof(science_scores[0]);

    // 平均点の計算
    double science_mean = calculate_mean(science_scores, num_students);
    double english_mean = calculate_mean(english_scores, num_students);

    // 標準偏差の計算
    double science_std_dev = calculate_standard_deviation(science_scores, num_students, science_mean);
    double english_std_dev = calculate_standard_deviation(english_scores, num_students, english_mean);

    // 合計点の計算
    int science_sum = 0;
    int english_sum = 0;
    for (int i = 0; i < num_students; i++) {
        science_sum += science_scores[i];
        english_sum += english_scores[i];
    }

    // 各生徒の偏差値の計算
    double science_z_scores[num_students];
    double english_z_scores[num_students];
    calculate_z_scores(science_scores, num_students, science_mean, science_z_scores, science_std_dev, 50.0);
    calculate_z_scores(english_scores, num_students, english_mean, english_z_scores, english_std_dev, 50.0);

    // 点数の高い順に並べ替え
    sort_scores_descending(science_scores, num_students);
    sort_scores_descending(english_scores, num_students);

    // 結果の出力
    printf("理科:\n");
    printf("平均点: %.2f\n", science_mean);
    printf("標準偏差: %.2f\n", science_std_dev);
    printf("合計点: %d\n", science_sum);
    printf("偏差値:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %.2f\n", i + 1, science_z_scores[i]);
    }

    printf("\n英語:\n");
    printf("平均点: %.2f\n", english_mean);
    printf("標準偏差: %.2f\n", english_std_dev);
    printf("合計点: %d\n", english_sum);
    printf("偏差値:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %.2f\n", i + 1, english_z_scores[i]);
    }

    printf("\n点数の高い順に並べ替えた結果:\n");
    printf("理科:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %d\n", i + 1, science_scores[i]);
    }

    printf("\n英語:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d: %d\n", i + 1, english_scores[i]);
    }

    return 0;
}

// 平均点の計算
double calculate_mean(int scores[], int num_students) {
    int sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += scores[i];
    }
    return (double)sum / num_students;
}

// 標準偏差の計算
double calculate_standard_deviation(int scores[], int num_students, double mean) {
    double sum_squared_diff = 0.0;
    for (int i = 0; i < num_students; i++) {
        double diff = scores[i] - mean;
        sum_squared_diff += diff * diff;
    }
    return sqrt(sum_squared_diff / num_students);
}

// 偏差値の計算
void calculate_z_scores(int scores[], int num_students, double mean, double z_scores[], double std_dev, double scale) {
    for (int i = 0; i < num_students; i++) {
        z_scores[i] = scale * (scores[i] - mean) / std_dev + 50.0;
    }
}

// 配列を降順にソート
void sort_scores_descending(int scores[], int num_students) {
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                // スワップ
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

