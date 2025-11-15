#include <iostream>
#include <string>
using namespace std;

// ========== 1. ОСНОВЫ СПИСКА ИНИЦИАЛИЗАЦИИ ==========

class Point
{
public:
    int x, y;

    // ОБЫЧНЫЙ конструктор (так делать НЕ рекомендуется)
    Point(int xVal, int yVal)
    {
        x = xVal; // Это ПРИСВАИВАНИЕ, а не инициализация!
        y = yVal; // Поля уже созданы, теперь мы им присваиваем значения
        cout << "Обычный конструктор: (" << x << ", " << y << ")" << endl;
    }
};

class PointBetter
{
public:
    int x, y;

    // Конструктор со списком инициализации (ПРАВИЛЬНЫЙ способ)
    PointBetter(int xVal, int yVal) : x(xVal), y(yVal)
    {
        // Здесь x и y УЖЕ инициализированы!
        cout << "Конструктор со списком: (" << x << ", " << y << ")" << endl;
    }
};

// ========== 2. КАК ЭТО РАБОТАЕТ ПОШАГОВО ==========

class StepByStep
{
private:
    int a, b, c;

public:
    // Конструктор со списком инициализации
    StepByStep(int x, int y, int z) : a(x), b(y), c(z)
    {
        /*
        ПОШАГОВОЕ ВЫПОЛНЕНИЕ:
        1. Выделяется память для объекта StepByStep
        2. ВЫПОЛНЯЕТСЯ список инициализации: a(x), b(y), c(z)
           - Поля a, b, c создаются и сразу инициализируются значениями
        3. Выполняется тело конструктора (то что в фигурных скобках {})
        */
        cout << "Объект создан! a=" << a << ", b=" << b << ", c=" << c << endl;
    }
};

// ========== 3. ПАРАМЕТРЫ ПО УМОЛЧАНИЮ ==========

class PointWithDefaults
{
public:
    int x, y;

    // Параметры по умолчанию в конструкторе
    PointWithDefaults(int xVal = 0, int yVal = 0) : x(xVal), y(yVal)
    {
        cout << "Точка создана: (" << x << ", " << y << ")" << endl;
    }
};

// ========== 4. РАЗНИЦА МЕЖДУ ИНИЦИАЛИЗАЦИЕЙ И ПРИСВАИВАНИЕМ ==========

class DifferenceDemo
{
private:
    int value1;
    int value2;
    const int constValue; // Должна быть инициализирована при создании
    int &referenceValue;  // Должна быть инициализирована при создании

public:
    // ТАК НЕЛЬЗЯ - будет ОШИБКА компиляции!
    // DifferenceDemo(int v1, int v2, int cv, int& rv) {
    //     value1 = v1;        // OK - обычное поле
    //     value2 = v2;        // OK - обычное поле
    //     constValue = cv;    // ОШИБКА! const нельзя присвоить
    //     referenceValue = rv;// ОШИБКА! ссылку нельзя присвоить
    // }

    // ТАК ПРАВИЛЬНО - используем список инициализации
    DifferenceDemo(int v1, int v2, int cv, int &rv)
        : value1(v1), value2(v2), constValue(cv), referenceValue(rv)
    {
        // Все поля УЖЕ корректно инициализированы!
        cout << "constValue = " << constValue << ", referenceValue = " << referenceValue << endl;
    }
};

// ========== 5. КЛАССЫ С НЕСТАНДАРТНЫМИ ЧЛЕНАМИ ==========

class ComplexMember
{
private:
    string name;       // Объект класса string
    int *dynamicArray; // Указатель
    const int id;      // Константа

public:
    // Список инициализации позволяет передавать параметры конструкторам членов
    ComplexMember(const string &n, int size, int identifier)
        : name(n),                     // Вызывается конструктор string(const string&)
          dynamicArray(new int[size]), // Динамическое выделение памяти
          id(identifier)               // Инициализация константы
    {
        // Инициализируем массив
        for (int i = 0; i < size; i++)
        {
            dynamicArray[i] = i * 10;
        }
        cout << "ComplexMember создан: " << name << ", id=" << id << endl;
    }

    ~ComplexMember()
    {
        delete[] dynamicArray; // Не забываем освободить память!
    }

    void display()
    {
        cout << name << " [id:" << id << "]: ";
        for (int i = 0; i < 3; i++)
        { // предположим размер = 3 для примера
            cout << dynamicArray[i] << " ";
        }
        cout << endl;
    }
};

// ========== 6. ПОРЯДОК ИНИЦИАЛИЗАЦИИ ==========

class OrderDemo
{
private:
    int a;
    int b;
    int c;

public:
    // ВАЖНО: порядок инициализации определяется ПОРЯДКОМ ОБЪЯВЛЕНИЯ в классе,
    // а не порядком в списке инициализации!

    OrderDemo(int val) : c(val), b(c * 2), a(b * 2)
    {
        // ОПАСНО! Порядок инициализации: a, b, c (по порядку объявления)
        // b инициализируется ДО c, но использует значение c - это НЕОПРЕДЕЛЕННОЕ ПОВЕДЕНИЕ!
        cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    }
};

class CorrectOrder
{
private:
    int a;
    int b;
    int c;

public:
    // ПРАВИЛЬНО: инициализируем в порядке зависимостей
    CorrectOrder(int val) : c(val), b(val * 2), a(b * 2)
    {
        // Теперь все корректно: c -> b -> a
        cout << "Правильный порядок: a=" << a << ", b=" << b << ", c=" << c << endl;
    }
};

// ========== 7. НАСЛЕДОВАНИЕ И КОМПОЗИЦИЯ ==========

class Base
{
private:
    int baseValue;

public:
    Base(int val) : baseValue(val)
    {
        cout << "Base создан: " << baseValue << endl;
    }
};

class Member
{
private:
    int memberValue;

public:
    Member(int val) : memberValue(val)
    {
        cout << "Member создан: " << memberValue << endl;
    }
};

class Derived : public Base
{
private:
    Member member1;
    Member member2;
    int derivedValue;

public:
    // Порядок инициализации:
    // 1. Базовые классы (Base)
    // 2. Члены класса (member1, member2) в порядке объявления
    // 3. Тело конструктора Derived
    Derived(int b, int m1, int m2, int d)
        : Base(b),        // Инициализация базового класса
          member1(m1),    // Инициализация члена
          member2(m2),    // Инициализация другого члена
          derivedValue(d) // Инициализация собственного поля
    {
        cout << "Derived создан: " << derivedValue << endl;
    }
};

// ========== 8. ДЕЛЕГИРОВАНИЕ КОНСТРУКТОРОВ ==========

class DelegatingConstructor
{
private:
    int x, y, z;

public:
    // Основной конструктор
    DelegatingConstructor(int xVal, int yVal, int zVal)
        : x(xVal), y(yVal), z(zVal)
    {
        cout << "Основной конструктор: (" << x << "," << y << "," << z << ")" << endl;
    }

    // Конструктор делегирует основному
    DelegatingConstructor(int xVal) : DelegatingConstructor(xVal, 0, 0)
    {
        cout << "Делегирующий конструктор с одним параметром" << endl;
    }

    // Еще один делегирующий конструктор
    DelegatingConstructor() : DelegatingConstructor(0, 0, 0)
    {
        cout << "Конструктор по умолчанию" << endl;
    }
};

// ========== ДЕМОНСТРАЦИЯ ==========

void demonstrateInitialization()
{
    cout << "=== ПОДРОБНОЕ ОБЪЯСНЕНИЕ СПИСКА ИНИЦИАЛИЗАЦИИ ===" << endl;

    // 1. Разница между обычным конструктором и списком инициализации
    cout << "\n1. ОБЫЧНЫЙ КОНСТРУКТОР:" << endl;
    Point p1(10, 20);

    cout << "\n2. КОНСТРУКТОР СО СПИСКОМ ИНИЦИАЛИЗАЦИИ:" << endl;
    PointBetter p2(10, 20);

    // 2. Пошаговое выполнение
    cout << "\n3. ПОШАГОВОЕ ВЫПОЛНЕНИЕ:" << endl;
    StepByStep sbs(1, 2, 3);

    // 3. Параметры по умолчанию
    cout << "\n4. ПАРАМЕТРЫ ПО УМОЛЧАНИЮ:" << endl;
    PointWithDefaults pd1;        // Использует значения по умолчанию
    PointWithDefaults pd2(5);     // x=5, y=0 (по умолчанию)
    PointWithDefaults pd3(7, 12); // x=7, y=12

    // 4. Константы и ссылки
    cout << "\n5. КОНСТАНТЫ И ССЫЛКИ:" << endl;
    int externalValue = 100;
    DifferenceDemo dd(1, 2, 42, externalValue);

    // 5. Сложные члены
    cout << "\n6. СЛОЖНЫЕ ЧЛЕНЫ КЛАССА:" << endl;
    ComplexMember cm("Объект", 3, 123);
    cm.display();

    // 6. Порядок инициализации
    cout << "\n7. ПОРЯДОК ИНИЦИАЛИЗАЦИИ:" << endl;
    cout << "НЕПРАВИЛЬНЫЙ порядок (неопределенное поведение):" << endl;
    OrderDemo od(10); // Может вывести мусор!

    cout << "ПРАВИЛЬНЫЙ порядок:" << endl;
    CorrectOrder co(10);

    // 7. Наследование и композиция
    cout << "\n8. НАСЛЕДОВАНИЕ И КОМПОЗИЦИЯ:" << endl;
    Derived derived(1, 2, 3, 4);

    // 8. Делегирование конструкторов
    cout << "\n9. ДЕЛЕГИРОВАНИЕ КОНСТРУКТОРОВ:" << endl;
    DelegatingConstructor dc1;          // Конструктор по умолчанию
    DelegatingConstructor dc2(5);       // Конструктор с одним параметром
    DelegatingConstructor dc3(1, 2, 3); // Основной конструктор
}

// ========== 9. ПРОИЗВОДИТЕЛЬНОСТЬ ==========

class PerformanceTest
{
private:
    string name;
    int value;

public:
    // Медленная версия (присваивание)
    PerformanceTest(const string &n, int v)
    {
        name = n;  // Присваивание - вызывает operator=
        value = v; // Присваивание
    }

    // Быстрая версия (инициализация)
    PerformanceTest(const string &n, int v)
        : name(n), // Инициализация - вызывает конструктор копирования
          value(v) // Прямая инициализация
    {
    }
};

int main()
{
    demonstrateInitialization();

    cout << "\n=== КЛЮЧЕВЫЕ ВЫВОДЫ ===" << endl;
    cout << "✓ Список инициализации: : x(val), y(val) {}" << endl;
    cout << "✓ ЭФФЕКТИВНОСТЬ: инициализация быстрее присваивания" << endl;
    cout << "✓ НЕОБХОДИМО для: const членов, ссылок, объектов без конструктора по умолчанию" << endl;
    cout << "✓ ПОРЯДОК: определяется порядком объявления в классе" << endl;
    cout << "✓ СИНТАКСИС: после параметров конструктора, перед телом {}" << endl;

    return 0;
}