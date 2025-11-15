#include <iostream>
#include <string> // Для работы со строками
#include <vector> // Для динамических массивов
using namespace std;

void arraysStringsExamples()
{
    // ========== СТАТИЧЕСКИЕ МАССИВЫ ==========
    int numbers[5] = {1, 2, 3, 4, 5}; // Массив из 5 целых чисел

    cout << "Элементы массива: ";
    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " "; // Обращение по индексу
    }
    cout << endl;

    // Двумерный массив (матрица)
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    // ========== ВЕКТОРЫ (динамические массивы) ==========
    vector<int> vec = {10, 20, 30}; // Создание вектора

    // Добавление элементов
    vec.push_back(40);               // Добавить в конец
    vec.insert(vec.begin() + 1, 15); // Вставить на позицию 1

    // Удаление элементов
    vec.pop_back(); // Удалить последний элемент

    cout << "Элементы вектора: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // ========== СТРОКИ ==========
    string str1 = "Hello";
    string str2 = "World";

    // Конкатенация (сложение строк)
    string greeting = str1 + " " + str2;
    cout << "Строка: " << greeting << endl;

    // Длина строки
    cout << "Длина строки: " << greeting.length() << endl;

    // Доступ к символам
    cout << "Первый символ: " << greeting[0] << endl;

    // Подстрока
    string sub = greeting.substr(0, 5); // С 0 позиции 5 символов
    cout << "Подстрока: " << sub << endl;

    // Поиск в строке
    size_t pos = greeting.find("World");
    if (pos != string::npos)
    {
        cout << "'World' найдено на позиции: " << pos << endl;
    }
}