#include <iostream>
using namespace std;

// تعریف تابع محاسبه معدل وزنی
double calculateWeightedAverage(int grades[], int weights[], int size) {
    double sum = 0; // مجموع نمرات
    double totalWeight = 0; // مجموع وزن ها

    // محاسبه مجموع نمرات با وزن
    for (int i = 0; i < size; ++i) {
        sum += grades[i] * weights[i]; // جمع ضرب هر نمره در وزن مربوطه
        totalWeight += weights[i]; // جمع وزن ها
    }

    // محاسبه و بازگشت معدل وزنی
    return sum / totalWeight;
}

// تعریف تابع برای یافتن بالاترین نمره
int findHighestGrade(int grades[], int size) {
    int highestGrade = grades[0]; // فرض کنید اولین عضو برای بالاترین نمره است
    for (int i = 1; i < size; ++i) {
        if (grades[i] > highestGrade) {
            highestGrade = grades[i]; // اگر عضو بیشتر از حد فعلی بالاتر باشد، جایگزین کنید
        }
    }
    return highestGrade; // بازگشت بالاترین نمره
}

// تعریف تابع برای یافتن نمره‌ای که تاثیر بیشتری دارد
int findMostInfluentialGrade(int grades[], int weights[], int size) {
    int mostInfluentialGradeIndex = 0; // فرض کنید اولین نمره بیشترین تاثیر را دارد
    double highestInfluence = grades[0] * weights[0]; // محاسبه تاثیر اولین نمره
    for (int i = 1; i < size; ++i) {
        double influence = grades[i] * weights[i]; // محاسبه تاثیر هر نمره
        if (influence > highestInfluence) {
            highestInfluence = influence; // اگر تاثیر بیشتر از حد فعلی بالاتر باشد، جایگزین کنید
            mostInfluentialGradeIndex = i; // ایندکس نمره بیشترین تاثیر را به روز کنید
        }
    }
    return grades[mostInfluentialGradeIndex]; // بازگشت نمره با بیشترین تاثیر
}

int main() {
    int grades[10]; // آرایه برای ذخیره نمرات
    int weights[10]; // آرایه برای ذخیره وزن ها

    // دریافت نمرات و وزن ها از کاربر
    for (int i = 0; i < 10; ++i) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> grades[i];
        cout << "Enter weight " << i + 1 << ": ";
        cin >> weights[i];
    }

    // محاسبه معدل وزنی
    double weightedAverage = calculateWeightedAverage(grades, weights, 10);

    // یافتن بالاترین نمره
    int highestGrade = findHighestGrade(grades, 10);

    // یافتن نمره با بیشترین تاثیر
    int mostInfluentialGrade = findMostInfluentialGrade(grades, weights, 10);

    // نمایش نتایج
    cout << "Weighted Average: " << weightedAverage << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Most Influential Grade: " << mostInfluentialGrade << endl;

    return 0;
}
