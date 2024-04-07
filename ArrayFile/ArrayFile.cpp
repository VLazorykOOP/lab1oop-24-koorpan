#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <locale>

using namespace std;
// Task 1
void task1() {
    int N;
    //введення
    cout << "Введіть розмір масиву N: ";
    cin >> N;
    int A[100];
    cout << "Введіть елементи масиву A:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "A[" << i << "]: ";
        cin >> A[i];
    }
    int B[100] = { 0 }; //робим масив B нулями
    //вивід масиву В
    int j = 0; // індекс для масиву B
    for (int i = 0; i < N; ++i) {
        if (A[i] > 10) {
            B[j] = A[i];
            j++;
        }
    }
    cout << "Масив B:" << endl;
    for (int i = 0; i < j; i++) {
        cout << B[i] << " ";
    }
}

// Task 2
void task2() {//(номер останнього мін ел серед ел, менших Т1 і розташованих до першого елемента, більшого Т2)
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, T1, T2;
    int minIndex = -1;
    //введення розміру масиву та значень T1 та T2
    cout << "Введіть розмір масиву: ";
    cin >> size;
    cout << "Введіть значення T1: ";
    cin >> T1;
    cout << "Введіть значення T2: ";
    cin >> T2;
    //введення ел масиву
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    //пошук номера останнього мін ел
    for (int i = 0; i < size; ++i) {
        if (arr[i] < T1 && (minIndex == -1 || arr[i] < arr[minIndex])) {
            minIndex = i;
        }
        if (arr[i] > T2) {
            break;
        }
    }
    //виведення номера останнього мін ел(числення не з 0)
    if (minIndex != -1) {
        cout << "Номер останнього мінімального елемента: " << minIndex << endl;
    }
    else {
        cout << "Мінімальний елемент не знайдено." << endl;
    }
}

// Task 3
void task3() {
    const int MAX_SIZE = 300;
    int n;
    cout << "Введіть розмір масивів (n <= 300): ";
    cin >> n;
    int X[MAX_SIZE];
    int Y[MAX_SIZE];
    cout << "Введіть елементи масиву X:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "X[" << i << "]: ";
        cin >> X[i];
    }
    cout << "Введіть елементи масиву Y:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Y[" << i << "]: ";
        cin >> Y[i];
    }
    int merged[MAX_SIZE * 2];   // об'єднаний масив
    int mergedSize = 0;         // розмір об'єднаного масиву
    // додавання ел масиву X до об'єднаного масиву
    for (int i = 0; i < n; i++) {
        merged[mergedSize] = X[i];
        mergedSize++;
    }
    // додавання ел масиву Y до об'єднаного масиву
    for (int i = 0; i < n; i++) {
        merged[mergedSize] = Y[i];
        mergedSize++;
    }
    //виведення  та обчислення добутку
    long long dobutok = 1;
    cout << "Елементи об'єднаного масиву:" << endl;
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " ";
        dobutok *= merged[i];
    }
    cout << endl;
    cout << "Добуток елементів об'єднаного масиву: " << dobutok << endl;
}

int main() {
    setlocale(LC_CTYPE, "Ukr");
    int task;
    cout << "Введіть номер завдання (1, 2, або 3): ";
    cin >> task;
    switch (task) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    default:
        cout << "Невірний номер завдання." << endl;
    }
    return 0;
}