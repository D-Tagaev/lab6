#include <iostream>
using namespace std;

const int N = 50; // Максимальний розмір масиву

// Оголошення функцій
void inputArray(double A[], int& N); // Введення масиву та його розміру
bool validateSize(int N); // Перевірка коректності розміру масиву
void printArrayAscending(const double A[], int N); // Виведення масиву у порядку зростання індексів
void printArrayCustomOrder(const double A[], int N); // Виведення масиву у заданому порядку
void task16(); // Завдання 16: операції з масивом

void get_mas(float in_mas[], int& in_n); // Введення масиву для завдання 106
void show_mas(const float out_mas[], const int out_n); // Виведення масиву
void shift_right(float a[], int n, int k, int kk); // Зсув елементів масиву вправо
int find_min(const float in_mas[], int in_n); // Знаходження індексу мінімального елемента
int find_max(const float in_mas[], int in_n); // Знаходження індексу максимального елемента
void add_zero_before_min_max(float arr[], int& n, int i_min, int i_max); // Додавання нуля перед мінімальним і максимальним елементами
void task106(); // Завдання 106: додавання нуля перед мінімумом і максимумом

int main() {
    int menu; // Змінна для вибору дії в меню
    do {
        // Меню для вибору завдання
        cout << "\nMenu:\n";
        cout << "1. Task 16 (Array Operations)\n";
        cout << "2. Task 106 (Add Zero Before Min and Max)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> menu;

        switch (menu) {
        case 1:
            task16(); // Виконання завдання 16
            break;
        case 2:
            task106(); // Виконання завдання 106
            break;
        case 0:
            cout << "Exiting...\n"; // Вихід з програми
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // Повідомлення про некоректний вибір
        }
    } while (menu != 0);

    return 0;
}

// Реалізація завдання 16
void task16() {
    int A; // Розмір масиву
    double N[50]; // Масив для зберігання чисел

    inputArray(N, A); // Введення масиву

    cout << "Array in ascending index order: ";
    printArrayAscending(N, A); // Виведення масиву у порядку зростання індексів

    cout << "Array in the specified order: ";
    printArrayCustomOrder(N, A); // Виведення масиву у заданому порядку

}

// Введення масиву та його розміру
void inputArray(double A[], int& N) {
    do {
        cout << "Enter the size of the array (2-50): ";
        cin >> N; // Введення розміру масиву
        if (!validateSize(N)) {
            cout << "The size of the array must be between 2 and 50. Please try again." << endl;
        }
    } while (!validateSize(N)); // Перевірка коректності розміру

    cout << "Enter " << N << " elements of the array: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Введення елементів масиву
    }
}

// Перевірка коректності розміру масиву
bool validateSize(int N) {
    return N >= 2 && N <= 50;
}

// Виведення масиву у порядку зростання індексів
void printArrayAscending(const double A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " "; // Виведення кожного елемента
    }
    cout << endl;
}

// Виведення масиву у заданому порядку (з початку і кінця)
void printArrayCustomOrder(const double A[], int N) {
    int left = 0, right = N - 1; // Початкові індекси
    while (left <= right) {
        if (left == right) {
            cout << A[left] << " "; // Якщо залишився один елемент
        }
        else {
            cout << A[left] << " " << A[right] << " "; // Виведення пари елементів
        }
        left++; // Зміщення вліво
        right--; // Зміщення вправо
    }
    cout << endl;
}

// Знаходження індексу мінімального елемента масиву
int find_min(const float in_mas[], int in_n) {
    float min = in_mas[0]; // Початкове значення мінімуму
    int i_min = 0; // Індекс мінімального елемента
    for (int i = 1; i < in_n; i++) {
        if (in_mas[i] < min) {
            min = in_mas[i]; // Оновлення мінімального значення
            i_min = i;
        }
    }
    return i_min;
}

// Знаходження індексу максимального елемента масиву
int find_max(const float in_mas[], int in_n) {
    float max = in_mas[0]; // Початкове значення максимуму
    int i_max = 0; // Індекс максимального елемента
    for (int i = 1; i < in_n; i++) {
        if (in_mas[i] >= max) {
            max = in_mas[i]; // Оновлення максимального значення
            i_max = i;
        }
    }
    return i_max;
}

// Зсув елементів масиву вправо
void shift_right(float a[], int n, int k, int kk) {
    for (int i = kk; i > k; i--) {
        a[i] = a[i - 1]; // Копіювання елементів вправо
    }
}

// Додавання нуля перед мінімальним і максимальним елементами
void add_zero_before_min_max(float arr[], int& n, int i_min, int i_max) {
    shift_right(arr, n, i_min, n); // Зсув елементів вправо перед мінімумом
    arr[i_min] = 0; // Вставка нуля
    n++;
    if (i_min < i_max) i_max++; // Корекція індексу максимуму, якщо мінімум був раніше

    shift_right(arr, n, i_max + 1, n); // Зсув елементів вправо перед максимумом
    arr[i_max + 1] = 0; // Вставка нуля
    n++;
}

// Завдання 106
void task106() {
    float arr[N]; // Масив для зберігання елементів
    int n, i_min, i_max; // Кількість елементів, індекси мінімального та максимального елементів
    get_mas(arr, n); // Введення масиву
    show_mas(arr, n); // Виведення масиву
    i_max = find_max(arr, n); // Знаходження індексу максимуму
    i_min = find_min(arr, n); // Знаходження індексу мінімуму
    add_zero_before_min_max(arr, n, i_min, i_max); // Додавання нулів
    show_mas(arr, n); // Виведення масиву після змін
}

// Введення масиву для завдання 106
void get_mas(float in_mas[], int& in_n) {
    do {
        cout << "Enter the number of elements (1-50): ";
        cin >> in_n; // Введення кількості елементів
        if (in_n < 1 || in_n > N) {
            cout << "Error: The number of elements must be between 1 and 50." << endl;
        }
    } while (in_n < 1 || in_n > N); // Перевірка коректності кількості елементів

    cout << "Enter the array elements (range -1000 to 1000): " << endl;
    for (int i = 0; i < in_n; i++) {
        do {
            cout << "Element [" << i + 1 << "]: ";
            cin >> in_mas[i]; // Введення елемента масиву
            if (in_mas[i] < -1000 || in_mas[i] > 1000) {
                cout << "Error: The value must be between -1000 and 1000." << endl;
            }
        } while (in_mas[i] < -1000 || in_mas[i] > 1000); // Перевірка коректності значення
    }
}

// Виведення масиву
void show_mas(const float out_mas[], const int out_n) {
    cout << "Array elements: ";
    for (int i = 0; i < out_n; i++) {
        cout << out_mas[i] << " "; // Виведення кожного елемента
    }
    cout << endl;
}