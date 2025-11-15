#include <iostream>
#include <string>
using namespace std;

// ========== 1. ОСНОВЫ УКАЗАТЕЛЕЙ ==========

void pointerBasics()
{
    cout << "\n=== ОСНОВЫ УКАЗАТЕЛЕЙ ===" << endl;

    int number = 42;
    cout << "1. Значение number: " << number << endl;
    cout << "2. Адрес number в памяти: " << &number << endl;

    // Указатель - переменная, хранящая адрес другой переменной
    int *ptr = &number; // ptr указывает на number

    cout << "3. Значение ptr (адрес): " << ptr << endl;
    cout << "4. Значение по адресу ptr: " << *ptr << endl;

    // Изменение значения через указатель
    *ptr = 100;
    cout << "5. После *ptr = 100, number: " << number << endl;

    // Размер указателя не зависит от типа данных
    cout << "6. Размер указателя: " << sizeof(ptr) << " байт" << endl;
}

// ========== 2. ТИПЫ УКАЗАТЕЛЕЙ ==========

void pointerTypes()
{
    cout << "\n=== ТИПЫ УКАЗАТЕЛЕЙ ===" << endl;

    int intValue = 10;
    double doubleValue = 3.14;
    char charValue = 'X';
    string stringValue = "Hello";

    // Указатели разных типов
    int *intPtr = &intValue;
    double *doublePtr = &doubleValue;
    char *charPtr = &charValue;
    string *stringPtr = &stringValue;

    cout << "int указатель: " << *intPtr << endl;
    cout << "double указатель: " << *doublePtr << endl;
    cout << "char указатель: " << *charPtr << endl;
    cout << "string указатель: " << *stringPtr << endl;

    // void указатель - может указывать на любой тип
    void *voidPtr = &intValue;
    cout << "void указатель хранит адрес: " << voidPtr << endl;
    // *voidPtr = 20; // ОШИБКА! void* нельзя разыменовать
}

// ========== 3. АРИФМЕТИКА УКАЗАТЕЛЕЙ ==========

void pointerArithmetic()
{
    cout << "\n=== АРИФМЕТИКА УКАЗАТЕЛЕЙ ===" << endl;

    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // ptr указывает на первый элемент массива

    cout << "Массив: ";
    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "ptr указывает на: " << *ptr << " (индекс 0)" << endl;

    ptr++; // Перемещаем указатель на следующий элемент
    cout << "После ptr++: " << *ptr << " (индекс 1)" << endl;

    ptr += 2; // Перемещаем на 2 элемента вперед
    cout << "После ptr += 2: " << *ptr << " (индекс 3)" << endl;

    ptr--; // Назад на один элемент
    cout << "После ptr--: " << *ptr << " (индекс 2)" << endl;

    // Разность указателей
    int *first = &numbers[0];
    int *last = &numbers[4];
    cout << "Разность указателей: " << (last - first) << " элементов" << endl;
}

// ========== 4. УКАЗАТЕЛИ И МАССИВЫ ==========

void pointersAndArrays()
{
    cout << "\n=== УКАЗАТЕЛИ И МАССИВЫ ===" << endl;

    int arr[5] = {1, 2, 3, 4, 5};

    // Имя массива - указатель на первый элемент
    cout << "arr = " << arr << " (адрес первого элемента)" << endl;
    cout << "&arr[0] = " << &arr[0] << " (тот же адрес)" << endl;

    // Разные способы доступа к элементам
    cout << "Доступ к элементам:" << endl;
    cout << "arr[2] = " << arr[2] << " (обычный доступ)" << endl;
    cout << "*(arr + 2) = " << *(arr + 2) << " (через указатель)" << endl;

    // Обход массива через указатель
    cout << "Обход через указатель: ";
    int *ptr = arr;
    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}

// ========== 5. ДИНАМИЧЕСКАЯ ПАМЯТЬ ==========

void dynamicMemory()
{
    cout << "\n=== ДИНАМИЧЕСКАЯ ПАМЯТЬ ===" << endl;

    // Выделение памяти для одного значения
    int *singleValue = new int(42);
    cout << "Динамическое значение: " << *singleValue << endl;

    // Выделение памяти для массива
    int size = 5;
    int *dynamicArray = new int[size];

    // Заполнение динамического массива
    for (int i = 0; i < size; i++)
    {
        dynamicArray[i] = (i + 1) * 10;
    }

    cout << "Динамический массив: ";
    for (int i = 0; i < size; i++)
    {
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // ОЧЕНЬ ВАЖНО: освобождение памяти
    delete singleValue;    // Для одиночного значения
    delete[] dynamicArray; // Для массива

    cout << "Память освобождена!" << endl;
}

// ========== 6. УКАЗАТЕЛИ НА УКАЗАТЕЛИ ==========

void pointerToPointer()
{
    cout << "\n=== УКАЗАТЕЛИ НА УКАЗАТЕЛИ ===" << endl;

    int value = 100;
    int *ptr = &value;
    int **ptrToPtr = &ptr; // Указатель на указатель

    cout << "value: " << value << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "**ptrToPtr: " << **ptrToPtr << endl;

    cout << "Адреса:" << endl;
    cout << "&value: " << &value << endl;
    cout << "ptr: " << ptr << endl;
    cout << "&ptr: " << &ptr << endl;
    cout << "ptrToPtr: " << ptrToPtr << endl;
}

// ========== 7. УКАЗАТЕЛИ В ФУНКЦИЯХ ==========

// Передача по указателю (можно изменять оригинал)
void swap(int *a, int *b)
{
    int temp = *a; // Сохраняем значение по адресу a
    *a = *b;       // Записываем значение b в a
    *b = temp;     // Записываем сохраненное значение в b
}

// Возврат указателя из функции
int *findMax(int *arr, int size)
{
    int *maxPtr = arr; // Начинаем с первого элемента
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) > *maxPtr)
        {
            maxPtr = arr + i;
        }
    }
    return maxPtr;
}

void pointersInFunctions()
{
    cout << "\n=== УКАЗАТЕЛИ В ФУНКЦИЯХ ===" << endl;

    int x = 5, y = 10;
    cout << "До swap: x = " << x << ", y = " << y << endl;
    swap(&x, &y); // Передаем адреса переменных
    cout << "После swap: x = " << x << ", y = " << y << endl;

    int numbers[] = {3, 7, 2, 9, 1};
    int *maxElement = findMax(numbers, 5);
    cout << "Максимальный элемент: " << *maxElement << endl;
    cout << "Его позиция: " << (maxElement - numbers) << endl;
}

// ========== 8. ОСНОВЫ ССЫЛОК ==========

void referenceBasics()
{
    cout << "\n=== ОСНОВЫ ССЫЛОК ===" << endl;

    int original = 50;
    int &ref = original; // ref - ссылка на original (псевдоним)

    cout << "original: " << original << endl;
    cout << "ref: " << ref << endl;
    cout << "&original: " << &original << endl;
    cout << "&ref: " << &ref << " (тот же адрес!)" << endl;

    // Изменение через ссылку меняет оригинал
    ref = 100;
    cout << "После ref = 100:" << endl;
    cout << "original: " << original << endl;
    cout << "ref: " << ref << endl;

    // Ссылка должна быть инициализирована при объявлении
    // int& badRef; // ОШИБКА! Ссылка должна быть инициализирована
}

// ========== 9. ССЫЛКИ В ФУНКЦИЯХ ==========

// Передача по ссылке - более удобно чем указатели
void increment(int &num)
{
    num++; // Работаем напрямую с оригинальной переменной
}

// Функция может возвращать ссылку
int &getElement(int arr[], int index)
{
    return arr[index]; // Возвращаем ссылку на элемент
}

void referencesInFunctions()
{
    cout << "\n=== ССЫЛКИ В ФУНКЦИЯХ ===" << endl;

    int value = 5;
    cout << "До increment: " << value << endl;
    increment(value); // Просто передаем переменную
    cout << "После increment: " << value << endl;

    int numbers[] = {10, 20, 30, 40, 50};
    cout << "numbers[2] до изменения: " << numbers[2] << endl;
    getElement(numbers, 2) = 999; // Изменяем элемент через ссылку
    cout << "numbers[2] после изменения: " << numbers[2] << endl;
}

// ========== 10. ССЫЛКИ VS УКАЗАТЕЛИ ==========

void referencesVsPointers()
{
    cout << "\n=== ССЫЛКИ VS УКАЗАТЕЛИ ===" << endl;

    int value = 42;

    // Указатель
    int *ptr = &value;
    *ptr = 100;
    ptr = nullptr; // Может быть перенаправлен

    // Ссылка
    int &ref = value;
    ref = 200;
    // ref = nullptr; // ОШИБКА! Ссылка не может быть перенаправлена

    cout << "Отличия:" << endl;
    cout << "1. Ссылка должна быть инициализирована при объявлении" << endl;
    cout << "2. Ссылка не может быть перенаправлена на другой объект" << endl;
    cout << "3. Ссылка не может быть nullptr" << endl;
    cout << "4. Синтаксис ссылок проще (не нужно использовать * и &)" << endl;
}

// ========== 11. CONST И УКАЗАТЕЛИ/ССЫЛКИ ==========

void constPointersReferences()
{
    cout << "\n=== CONST И УКАЗАТЕЛИ/ССЫЛКИ ===" << endl;

    int value = 10;
    const int constValue = 20;

    // Указатель на константу - можно менять указатель, но не значение
    const int *ptrToConst = &value;
    // *ptrToConst = 30; // ОШИБКА! Значение константное
    ptrToConst = &constValue; // OK - указатель можно менять

    // Константный указатель - нельзя менять указатель, но можно значение
    int *const constPtr = &value;
    *constPtr = 30; // OK - значение можно менять
    // constPtr = &constValue; // ОШИБКА! Указатель константный

    // Константный указатель на константу
    const int *const constPtrToConst = &value;
    // *constPtrToConst = 40; // ОШИБКА!
    // constPtrToConst = &constValue; // ОШИБКА!

    // Ссылки на константу
    const int &constRef = value;
    // constRef = 50; // ОШИБКА!

    cout << "value: " << value << endl;
    cout << "constValue: " << constValue << endl;
}

// ========== 12. УМНЫЕ УКАЗАТЕЛИ (C++11) ==========

#include <memory> // Для умных указателей

void smartPointers()
{
    cout << "\n=== УМНЫЕ УКАЗАТЕЛИ ===" << endl;

    // unique_ptr - эксклюзивное владение
    unique_ptr<int> uniquePtr = make_unique<int>(42);
    cout << "unique_ptr: " << *uniquePtr << endl;
    // Автоматически удаляется при выходе из области видимости

    // shared_ptr - разделяемое владение
    shared_ptr<int> sharedPtr1 = make_shared<int>(100);
    shared_ptr<int> sharedPtr2 = sharedPtr1; // Оба указывают на один объект
    cout << "shared_ptr1: " << *sharedPtr1 << endl;
    cout << "shared_ptr2: " << *sharedPtr2 << endl;
    cout << "Количество ссылок: " << sharedPtr1.use_count() << endl;

    // weak_ptr - слабая ссылка (не увеличивает счетчик ссылок)
    weak_ptr<int> weakPtr = sharedPtr1;
    cout << "weak_ptr expired: " << weakPtr.expired() << endl;
}

// ========== ГЛАВНАЯ ФУНКЦИЯ ДЕМОНСТРАЦИИ ==========

void demonstratePointersReferences()
{
    cout << "=== ПОДРОБНАЯ ДЕМОНСТРАЦИЯ УКАЗАТЕЛЕЙ И ССЫЛОК ===" << endl;

    pointerBasics();
    pointerTypes();
    pointerArithmetic();
    pointersAndArrays();
    dynamicMemory();
    pointerToPointer();
    pointersInFunctions();
    referenceBasics();
    referencesInFunctions();
    referencesVsPointers();
    constPointersReferences();
    smartPointers();

    cout << "\n=== КЛЮЧЕВЫЕ ВЫВОДЫ ===" << endl;
    cout << "✓ Указатели хранят адреса, ссылки - псевдонимы" << endl;
    cout << "✓ Используйте ссылки для параметров функций когда возможно" << endl;
    cout << "✓ Всегда освобождайте динамическую память" << endl;
    cout << "✓ Prefer smart pointers over raw pointers" << endl;
    cout << "✓ const помогает предотвратить случайные изменения" << endl;
}