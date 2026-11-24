#include <iostream>
#include <vector>
#include <cmath>    // для std::abs
#include <cstdlib>  // для setlocale

// ============================================================================
// МОДУЛЬ ЛОГИКИ (logic)
// ============================================================================

// Проверка: содержит ли число ровно одну цифру 5
bool hasExactlyOneFive(int number) {
    int n = std::abs(number); // учитываем отрицательные числа

    if (n == 0) return false; // в нуле нет цифры 5

    int count = 0;
    while (n > 0) {
        if (n % 10 == 5) {
            count++;
        }
        n /= 10;
    }

    return count == 1;
}

// Найти произведение элементов массива, содержащих ровно одну цифру 5
long long productWithOneFive(const std::vector<int>& arr) {
    long long product = 1;
    bool found = false;

    for (int elem : arr) {
        if (hasExactlyOneFive(elem)) {
            product *= elem;
            found = true;
        }
    }

    return found ? product : 0;
}

// ============================================================================
// МОДУЛЬ ВВОДА/ВЫВОДА (io)
// ============================================================================

// Ввод массива с клавиатуры
std::vector<int> readArray() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Введите " << n << " элементов массива:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    return arr;
}

// Вывод результата на экран
void printResult(long long result) {
    if (result == 0) {
        std::cout << "Элементов с ровно одной цифрой 5 не найдено." << std::endl;
    }
    else {
        std::cout << "Произведение элементов с ровно одной цифрой 5: "
            << result << std::endl;
    }
}

// ============================================================================
// ГЛАВНАЯ ФУНКЦИЯ (main) — обязательна по условию задачи
// ============================================================================

int main() {
    setlocale(LC_ALL, "Russian");

    // Ввод данных
    std::vector<int> arr = readArray();

    // Обработка (логика)
    long long result = productWithOneFive(arr);

    // Вывод результата
    printResult(result);

    return 0;
}
