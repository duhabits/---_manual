#include <iostream>
#include <bitset> // для визуализации битов
#include <iomanip>
using namespace std;

// ========== 1. ОСНОВНЫЕ БИТОВЫЕ ОПЕРАТОРЫ ==========

void printBinary(int num, const string &label = "")
{
    cout << label << setw(3) << num << " = " << bitset<8>(num) << endl;
}

void basicBitOperations()
{
    cout << "\n=== ОСНОВНЫЕ БИТОВЫЕ ОПЕРАТОРЫ ===" << endl;

    unsigned char a = 0b00110101; // 53 в десятичной
    unsigned char b = 0b00001111; // 15 в десятичной

    cout << "Исходные значения:" << endl;
    printBinary(a, "a: ");
    printBinary(b, "b: ");

    // Побитовое И (AND) - общие биты
    unsigned char andResult = a & b;
    printBinary(andResult, "a & b: ");

    // Побитовое ИЛИ (OR) - любой из битов
    unsigned char orResult = a | b;
    printBinary(orResult, "a | b: ");

    // Побитовое исключающее ИЛИ (XOR) - разные биты
    unsigned char xorResult = a ^ b;
    printBinary(xorResult, "a ^ b: ");

    // Побитовое НЕ (NOT) - инверсия битов
    unsigned char notResult = ~a;
    printBinary(notResult, "~a: ");

    // Сдвиг влево (умножение на 2^n)
    unsigned char leftShift = a << 2;
    printBinary(leftShift, "a << 2: ");

    // Сдвиг вправо (деление на 2^n)
    unsigned char rightShift = a >> 2;
    printBinary(rightShift, "a >> 2: ");
}

// ========== 2. ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ БИТОВЫХ ОПЕРАЦИЙ ==========

void practicalApplications()
{
    cout << "\n=== ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ ===" << endl;

    // 1. Проверка четности
    int number = 42;
    bool isEven = (number & 1) == 0;
    cout << number << " является " << (isEven ? "четным" : "нечетным") << endl;

    // 2. Умножение и деление на степени двойки
    int value = 10;
    cout << value << " * 4 = " << (value << 2) << " (сдвиг влево на 2)" << endl;
    cout << value << " / 4 = " << (value >> 2) << " (сдвиг вправо на 2)" << endl;

    // 3. Установка, сброс и проверка битов
    unsigned char flags = 0b00000000; // 8 флагов

    // Установка битов (битовые маски)
    const unsigned char FLAG_A = 0b00000001; // 1 << 0
    const unsigned char FLAG_B = 0b00000010; // 1 << 1
    const unsigned char FLAG_C = 0b00000100; // 1 << 2
    const unsigned char FLAG_D = 0b00001000; // 1 << 3

    // Установка флагов
    flags |= FLAG_A; // Установить флаг A
    flags |= FLAG_C; // Установить флаг C
    printBinary(flags, "После установки A и C: ");

    // Проверка флагов
    cout << "Флаг A установлен: " << ((flags & FLAG_A) != 0) << endl;
    cout << "Флаг B установлен: " << ((flags & FLAG_B) != 0) << endl;

    // Сброс флагов
    flags &= ~FLAG_A; // Сбросить флаг A
    printBinary(flags, "После сброса A: ");

    // Переключение флагов (XOR)
    flags ^= FLAG_B; // Переключить флаг B
    printBinary(flags, "После переключения B: ");
    flags ^= FLAG_B; // Переключить обратно
    printBinary(flags, "После повторного переключения B: ");
}

// ========== 3. БИТОВЫЕ ПОЛЯ В СТРУКТУРАХ ==========

struct BitFieldStruct
{
    // Битные поля - экономят память
    unsigned int isReady : 1;   // 1 бит (0-1)
    unsigned int errorCode : 3; // 3 бита (0-7)
    unsigned int data : 4;      // 4 бита (0-15)
    unsigned int reserved : 24; // 24 бита

    void display()
    {
        cout << "Битовые поля: isReady=" << isReady
             << ", errorCode=" << errorCode
             << ", data=" << data << endl;
        cout << "Размер структуры: " << sizeof(*this) << " байт" << endl;
    }
};

// Битные поля для представления IP-адреса
struct IPAddress
{
    unsigned int part1 : 8;
    unsigned int part2 : 8;
    unsigned int part3 : 8;
    unsigned int part4 : 8;

    void print()
    {
        cout << "IP: " << part1 << "." << part2 << "." << part3 << "." << part4 << endl;
    }
};

void bitFieldsDemo()
{
    cout << "\n=== БИТОВЫЕ ПОЛЯ В СТРУКТУРАХ ===" << endl;

    BitFieldStruct bf;
    bf.isReady = 1;
    bf.errorCode = 5; // 101 в двоичной
    bf.data = 12;     // 1100 в двоичной
    bf.display();

    IPAddress ip;
    ip.part1 = 192;
    ip.part2 = 168;
    ip.part3 = 1;
    ip.part4 = 100;
    ip.print();
    cout << "Размер IPAddress: " << sizeof(ip) << " байт" << endl;
}

// ========== 4. СЛОЖНЫЕ БИТОВЫЕ ОПЕРАЦИИ ==========

void advancedBitOperations()
{
    cout << "\n=== СЛОЖНЫЕ БИТОВЫЕ ОПЕРАЦИИ ===" << endl;

    // 1. Подсчет установленных битов
    unsigned int x = 0b11010101;
    int count = 0;
    unsigned int temp = x;

    while (temp)
    {
        count += temp & 1; // Проверяем младший бит
        temp >>= 1;        // Сдвигаем вправо
    }
    cout << "Количество установленных битов в " << bitset<8>(x) << ": " << count << endl;

    // 2. Извлечение определенных битов
    unsigned int data = 0b10110110;
    unsigned int extracted = (data >> 2) & 0b1111; // Извлекаем биты 2-5
    printBinary(extracted, "Извлеченные биты 2-5: ");

    // 3. Установка диапазона битов
    unsigned int base = 0b00000000;
    unsigned int pattern = 0b1101; // Паттерн для установки
    unsigned int position = 2;     // Позиция для установки

    // Очищаем область и устанавливаем паттерн
    base &= ~(0b1111 << position); // Очищаем 4 бита начиная с позиции 2
    base |= (pattern << position); // Устанавливаем паттерн
    printBinary(base, "После установки паттерна: ");

    // 4. Быстрое определение степени двойки
    unsigned int n = 16;
    bool isPowerOfTwo = (n & (n - 1)) == 0 && n != 0;
    cout << n << (isPowerOfTwo ? " является" : " не является") << " степенью двойки" << endl;
}

// ========== 5. БИТОВЫЕ МАСКИ И ФЛАГИ ==========

// Битовые маски для прав доступа
enum Permissions
{
    READ = 1 << 0,    // 00000001
    WRITE = 1 << 1,   // 00000010
    EXECUTE = 1 << 2, // 00000100
    DELETE = 1 << 3,  // 00001000
    ALL = READ | WRITE | EXECUTE | DELETE
};

class FileAccess
{
private:
    unsigned char permissions;

public:
    FileAccess() : permissions(0) {}

    void grant(Permissions p)
    {
        permissions |= p;
    }

    void revoke(Permissions p)
    {
        permissions &= ~p;
    }

    bool hasPermission(Permissions p)
    {
        return (permissions & p) != 0;
    }

    void displayPermissions()
    {
        cout << "Права доступа: ";
        cout << (hasPermission(READ) ? "R" : "-");
        cout << (hasPermission(WRITE) ? "W" : "-");
        cout << (hasPermission(EXECUTE) ? "X" : "-");
        cout << (hasPermission(DELETE) ? "D" : "-");
        cout << " (биты: " << bitset<8>(permissions) << ")" << endl;
    }
};

void bitMasksDemo()
{
    cout << "\n=== БИТОВЫЕ МАСКИ И ФЛАГИ ===" << endl;

    FileAccess file;
    file.displayPermissions();

    file.grant(READ);
    file.grant(WRITE);
    file.displayPermissions();

    file.grant(ALL);
    file.displayPermissions();

    file.revoke(DELETE);
    file.displayPermissions();

    cout << "Может читать: " << file.hasPermission(READ) << endl;
    cout << "Может выполнять: " << file.hasPermission(EXECUTE) << endl;
}

// ========== 6. БИТОВЫЕ ОПЕРАЦИИ ДЛЯ ОПТИМИЗАЦИИ ==========

void optimizationExamples()
{
    cout << "\n=== ОПТИМИЗАЦИЯ С БИТОВЫМИ ОПЕРАЦИЯМИ ===" << endl;

    // 1. Быстрый обмен значений без временной переменной
    int a = 5, b = 10;
    cout << "До обмена: a=" << a << ", b=" << b << endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "После обмена: a=" << a << ", b=" << b << endl;

    // 2. Проверка знака числа
    int num = -42;
    bool isNegative = (num >> 31) & 1; // Для 32-битных integers
    cout << num << " является " << (isNegative ? "отрицательным" : "положительным") << endl;

    // 3. Округление до следующей степени двойки
    unsigned int v = 17;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    cout << "Следующая степень двойки после 17: " << v << endl;
}

// ========== ГЛАВНАЯ ФУНКЦИЯ ДЕМОНСТРАЦИИ ==========

void demonstrateBitOperations()
{
    cout << "=== ПОДРОБНАЯ ДЕМОНСТРАЦИЯ БИТОВЫХ ОПЕРАЦИЙ ===" << endl;

    basicBitOperations();
    practicalApplications();
    bitFieldsDemo();
    advancedBitOperations();
    bitMasksDemo();
    optimizationExamples();

    cout << "\n=== ШПАРГАЛКА ПО БИТОВЫМ ОПЕРАТОРАМ ===" << endl;
    cout << "&  - И: оба бита = 1" << endl;
    cout << "|  - ИЛИ: хотя бы один бит = 1" << endl;
    cout << "^  - XOR: биты разные" << endl;
    cout << "~  - НЕ: инверсия битов" << endl;
    cout << "<< - сдвиг влево: умножение на 2^n" << endl;
    cout << ">> - сдвиг вправо: деление на 2^n" << endl;
    cout << "\nПРАКТИЧЕСКОЕ ИСПОЛЬЗОВАНИЕ:" << endl;
    cout << "x & 1        - проверка четности" << endl;
    cout << "x | mask     - установка битов" << endl;
    cout << "x & ~mask    - сброс битов" << endl;
    cout << "x ^ mask     - переключение битов" << endl;
}