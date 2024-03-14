#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

// Звичайна функція
tuple<int, double, int> calculateStats(int a, int b, int c) {
    // Знайдемо мінімальне та максимальне значення
    int minVal = min({a, b, c});
    int maxVal = max({a, b, c});
    
    // Обчислимо середнє арифметичне
    double avg = static_cast<double>(a + b + c) / 3;

    // Повернемо результати
    return make_tuple(minVal, avg, maxVal);
}

// Шаблон функції
template<typename T>
tuple<T, double, T> calculateStatsTemplate(T a, T b, T c) {
    // Знайдемо мінімальне та максимальне значення
    T minVal = min({a, b, c});
    T maxVal = max({a, b, c});
    
    // Обчислимо середнє арифметичне
    double avg = static_cast<double>(a + b + c) / 3;

    // Повернемо результати
    return make_tuple(minVal, avg, maxVal);
}

int main() {
    int num1, num2, num3;
    cout << "Введіть три числа:ggggg ";
    cin >> num1 >> num2 >> num3;

    // Викликаємо звичайну функцію та отримуємо результати
    auto result = calculateStats(num1, num2, num3);

    // Виводимо результати звичайної функції
    cout<< "Звичайна функція:" << endl;
    cout << "Мінімальне: " << get<0>(result) << endl;
    cout << "Середнє арифметичне: " << get<1>(result) << endl;
    cout << "Максимальне: " << get<2>(result) << endl;

    // Викликаємо шаблон функції та отримуємо результати
    auto resultTemplate = calculateStatsTemplate(num1, num2, num3);

    // Виводимо результати шаблонної функції
    cout << "Шаблон функції:" << endl;
    cout << "Мінімальне: " << get<0>(resultTemplate) << endl;
    cout << "Середнє арифметичне: " << get<1>(resultTemplate) << endl;
    cout << "Максимальне: " << get<2>(resultTemplate) << endl;

    return 0;
}
