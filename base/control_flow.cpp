#include <iostream>
using namespace std;

void controlFlowExamples()
{
    int number = 15;

    // ========== УСЛОВНЫЕ ОПЕРАТОРЫ ==========

    // if-else if-else
    if (number > 0)
    {
        cout << "Число положительное" << endl;
    }
    else if (number < 0)
    {
        cout << "Число отрицательное" << endl;
    }
    else
    {
        cout << "Число равно нулю" << endl;
    }

    // Тернарный оператор (сокращенная форма if-else)
    string result = (number % 2 == 0) ? "четное" : "нечетное";
    cout << "Число " << number << " - " << result << endl;

    // switch-case (для дискретных значений)
    int day = 3;
    switch (day)
    {
    case 1:
        cout << "Понедельник" << endl;
        break; // Важно! Без break выполнение пойдет дальше
    case 2:
        cout << "Вторник" << endl;
        break;
    case 3:
        cout << "Среда" << endl;
        break;
    default: // Выполняется если ни один case не подошел
        cout << "Другой день" << endl;
    }

    // ========== ЦИКЛЫ ==========

    // Цикл for - когда известно количество итераций
    cout << "Цикл for: ";
    for (int i = 0; i < 5; i++)
    { // i++ то же что i = i + 1
        cout << i << " ";
    }
    cout << endl;

    // Цикл while - когда условие может измениться неизвестно когда
    cout << "Цикл while: ";
    int counter = 0;
    while (counter < 3)
    {
        cout << counter << " ";
        counter++;
    }
    cout << endl;

    // Цикл do-while - выполняется минимум один раз
    cout << "Цикл do-while: ";
    int x = 5;
    do
    {
        cout << x << " ";
        x++;
    } while (x < 8);
    cout << endl;

    // Ключевые слова для управления циклами
    for (int i = 0; i < 10; i++)
    {
        if (i == 2)
        {
            continue; // Пропускает текущую итерацию
        }
        if (i == 7)
        {
            break; // Полностью выходит из цикла
        }
        cout << i << " ";
    }
    cout << endl;
}