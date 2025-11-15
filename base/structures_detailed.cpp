#include <iostream>
#include <string>
#include <cstring> // для strcpy
using namespace std;

// ========== 1. ОСНОВЫ СТРУКТУР ==========

// Структура - пользовательский тип данных, объединяющий несколько переменных
struct Person
{
    // Поля структуры (члены)
    string name;
    int age;
    double height;
    bool isStudent;

    // Методы структуры (функции-члены)
    void display()
    {
        cout << "Имя: " << name << ", Возраст: " << age
             << ", Рост: " << height << ", Студент: "
             << (isStudent ? "Да" : "Нет") << endl;
    }

    void birthday()
    {
        age++;
        cout << name << " празднует день рождения! Теперь ему " << age << " лет." << endl;
    }
};

// ========== 2. РАЗНЫЕ СПОСОБЫ СОЗДАНИЯ СТРУКТУР ==========

struct Point
{
    int x, y;

    // Конструктор - специальный метод для инициализации
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal)
    {
        cout << "Создана точка (" << x << ", " << y << ")" << endl;
    }

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
};

struct Rectangle
{
    Point topLeft;
    int width, height;

    // Конструктор с списком инициализации
    Rectangle(Point tl, int w, int h) : topLeft(tl), width(w), height(h) {}

    int area()
    {
        return width * height;
    }

    bool contains(Point p)
    {
        return (p.x >= topLeft.x && p.x <= topLeft.x + width &&
                p.y >= topLeft.y && p.y <= topLeft.y + height);
    }
};

// ========== 3. СТРУКТУРЫ С ДИНАМИЧЕСКОЙ ПАМЯТЬЮ ==========

struct DynamicString
{
    char *data;
    int length;

    // Конструктор
    DynamicString(const char *str)
    {
        length = strlen(str);
        data = new char[length + 1]; // +1 для нулевого терминатора
        strcpy(data, str);
    }

    // Деструктор - освобождает память
    ~DynamicString()
    {
        delete[] data;
        cout << "Память освобождена для: " << data << endl;
    }

    // Конструктор копирования (глубокое копирование)
    DynamicString(const DynamicString &other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
        cout << "Вызван конструктор копирования" << endl;
    }

    void print()
    {
        cout << "Строка: " << data << " (длина: " << length << ")" << endl;
    }
};

// ========== 4. ОБЪЕДИНЕНИЯ (UNION) ==========

// Union - все члены используют одну область памяти (размер = наибольшему члену)
union Data
{
    int intValue;
    double doubleValue;
    char charValue;
    bool boolValue;
};

// Union с тегом для отслеживания активного типа
struct TypedData
{
    enum Type
    {
        INT,
        DOUBLE,
        CHAR,
        BOOL
    } type;
    union
    {
        int intValue;
        double doubleValue;
        char charValue;
        bool boolValue;
    };

    void set(int value)
    {
        intValue = value;
        type = INT;
    }

    void set(double value)
    {
        doubleValue = value;
        type = DOUBLE;
    }

    void set(char value)
    {
        charValue = value;
        type = CHAR;
    }

    void set(bool value)
    {
        boolValue = value;
        type = BOOL;
    }

    void print()
    {
        switch (type)
        {
        case INT:
            cout << "int: " << intValue << endl;
            break;
        case DOUBLE:
            cout << "double: " << doubleValue << endl;
            break;
        case CHAR:
            cout << "char: " << charValue << endl;
            break;
        case BOOL:
            cout << "bool: " << boolValue << endl;
            break;
        }
    }
};

// ========== 5. ВЛОЖЕННЫЕ СТРУКТУРЫ ==========

struct Address
{
    string street;
    string city;
    int zipCode;

    void display()
    {
        cout << street << ", " << city << ", " << zipCode << endl;
    }
};

struct Employee
{
    string name;
    int id;
    double salary;
    Address address; // Вложенная структура

    void raiseSalary(double percentage)
    {
        salary += salary * percentage / 100;
        cout << name << " получил повышение! Новый оклад: " << salary << endl;
    }

    void displayInfo()
    {
        cout << "Сотрудник #" << id << ": " << name << endl;
        cout << "Оклад: " << salary << endl;
        cout << "Адрес: ";
        address.display();
    }
};

// ========== 6. МАССИВЫ СТРУКТУР ==========

struct Student
{
    string name;
    int grades[5];
    double average;

    void calculateAverage()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += grades[i];
        }
        average = sum / 5;
    }

    void display()
    {
        cout << name << ": средний балл = " << average << " (";
        for (int i = 0; i < 5; i++)
        {
            cout << grades[i];
            if (i < 4)
                cout << ", ";
        }
        cout << ")" << endl;
    }
};

// ========== 7. УКАЗАТЕЛИ НА СТРУКТУРЫ ==========

void demonstrateStructures()
{
    cout << "\n=== ПОДРОБНО О СТРУКТУРАХ ===" << endl;

    // 1. Создание и использование структур
    cout << "\n1. БАЗОВЫЕ СТРУКТУРЫ:" << endl;
    Person person1;
    person1.name = "Анна Иванова";
    person1.age = 25;
    person1.height = 165.5;
    person1.isStudent = false;
    person1.display();
    person1.birthday();

    // Инициализация при создании (C++11)
    Person person2 = {"Петр Сидоров", 20, 180.0, true};
    person2.display();

    // 2. Структуры с конструкторами
    cout << "\n2. СТРУКТУРЫ С КОНСТРУКТОРАМИ:" << endl;
    Point p1(10, 20);
    Point p2; // Использует значения по умолчанию
    p1.move(5, -3);
    cout << "Точка p1 после move: (" << p1.x << ", " << p1.y << ")" << endl;

    Rectangle rect(Point(0, 0), 100, 50);
    cout << "Площадь прямоугольника: " << rect.area() << endl;
    cout << "Точка p1 в прямоугольнике: " << rect.contains(p1) << endl;

    // 3. Структуры с динамической памятью
    cout << "\n3. ДИНАМИЧЕСКАЯ ПАМЯТЬ В СТРУКТУРАХ:" << endl;
    {
        DynamicString str1("Hello World");
        str1.print();

        DynamicString str2 = str1; // Вызывает конструктор копирования
        str2.print();
    } // Деструкторы вызываются автоматически

    // 4. Объединения
    cout << "\n4. ОБЪЕДИНЕНИЯ (UNION):" << endl;
    Data data;
    data.intValue = 42;
    cout << "data как int: " << data.intValue << endl;

    data.doubleValue = 3.14159;
    cout << "data как double: " << data.doubleValue << endl;
    // ВНИМАНИЕ: intValue теперь содержит мусор!

    TypedData safeData;
    safeData.set(100);
    safeData.print();
    safeData.set('X');
    safeData.print();

    // 5. Вложенные структуры
    cout << "\n5. ВЛОЖЕННЫЕ СТРУКТУРЫ:" << endl;
    Employee emp;
    emp.name = "Мария Петрова";
    emp.id = 12345;
    emp.salary = 50000;
    emp.address.street = "ул. Ленина, 123";
    emp.address.city = "Москва";
    emp.address.zipCode = 101000;

    emp.displayInfo();
    emp.raiseSalary(10);

    // 6. Массивы структур
    cout << "\n6. МАССИВЫ СТРУКТУР:" << endl;
    Student students[3] = {
        {"Алиса", {85, 90, 78, 92, 88}},
        {"Борис", {75, 80, 85, 79, 82}},
        {"Виктория", {95, 92, 98, 96, 94}}};

    for (int i = 0; i < 3; i++)
    {
        students[i].calculateAverage();
        students[i].display();
    }

    // 7. Указатели на структуры
    cout << "\n7. УКАЗАТЕЛИ НА СТРУКТУРЫ:" << endl;
    Person *personPtr = &person1;
    cout << "Доступ через указатель: " << personPtr->name << endl;
    personPtr->birthday();

    // Динамическое создание структуры
    Person *dynamicPerson = new Person{"Динамический", 30, 175.0, false};
    dynamicPerson->display();
    delete dynamicPerson; // Не забываем освободить память!

    // 8. Размеры структур
    cout << "\n8. РАЗМЕРЫ СТРУКТУР:" << endl;
    cout << "sizeof(Person): " << sizeof(Person) << " байт" << endl;
    cout << "sizeof(Point): " << sizeof(Point) << " байт" << endl;
    cout << "sizeof(Data): " << sizeof(Data) << " байт" << endl;
    cout << "sizeof(TypedData): " << sizeof(TypedData) << " байт" << endl;
}