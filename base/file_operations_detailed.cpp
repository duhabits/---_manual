#include <iostream>
#include <fstream> // для работы с файлами
#include <string>
#include <vector>
#include <iomanip> // для форматирования вывода
#include <sstream> // для строковых потоков
using namespace std;

// ========== 1. ОСНОВЫ РАБОТЫ С ФАЙЛАМИ ==========

void basicFileOperations()
{
    cout << "\n=== ОСНОВЫ РАБОТЫ С ФАЙЛАМИ ===" << endl;

    // ========== ЗАПИСЬ В ФАЙЛ ==========
    ofstream outFile("example.txt"); // Создание объекта для записи

    if (outFile.is_open())
    {
        cout << "Файл открыт для записи!" << endl;

        // Запись различных типов данных
        outFile << "Привет, мир!" << endl;
        outFile << "Это пример записи в файл." << endl;
        outFile << 42 << endl;      // целое число
        outFile << 3.14159 << endl; // дробное число
        outFile << true << endl;    // булево значение

        outFile.close();
        cout << "Данные записаны, файл закрыт." << endl;
    }
    else
    {
        cout << "Ошибка открытия файла для записи!" << endl;
    }

    // ========== ЧТЕНИЕ ИЗ ФАЙЛА ==========
    ifstream inFile("example.txt"); // Создание объекта для чтения

    if (inFile.is_open())
    {
        cout << "\nСодержимое файла:" << endl;
        cout << "==================" << endl;

        string line;
        while (getline(inFile, line))
        { // Чтение построчно
            cout << line << endl;
        }

        inFile.close();
    }
    else
    {
        cout << "Ошибка открытия файла для чтения!" << endl;
    }
}

// ========== 2. РАЗНЫЕ РЕЖИМЫ ОТКРЫТИЯ ФАЙЛА ==========

void fileOpeningModes()
{
    cout << "\n=== РЕЖИМЫ ОТКРЫТИЯ ФАЙЛОВ ===" << endl;

    // ios::app - добавление в конец файла
    ofstream appFile("data.txt", ios::app);
    if (appFile.is_open())
    {
        appFile << "Добавленная строка 1" << endl;
        appFile << "Добавленная строка 2" << endl;
        appFile.close();
        cout << "Данные добавлены в конец файла." << endl;
    }

    // ios::trunc - очистка файла перед записью (режим по умолчанию)
    ofstream truncFile("data.txt", ios::trunc);
    if (truncFile.is_open())
    {
        truncFile << "Это перезапишет всё содержимое!" << endl;
        truncFile.close();
        cout << "Файл перезаписан." << endl;
    }

    // ios::binary - бинарный режим
    ofstream binFile("binary.dat", ios::binary);
    if (binFile.is_open())
    {
        int numbers[] = {1, 2, 3, 4, 5};
        binFile.write(reinterpret_cast<char *>(numbers), sizeof(numbers));
        binFile.close();
        cout << "Данные записаны в бинарном режиме." << endl;
    }
}

// ========== 3. РАБОТА С СТРУКТУРАМИ И ФАЙЛАМИ ==========

struct Person
{
    string name;
    int age;
    double salary;

    void display() const
    {
        cout << setw(10) << name << setw(5) << age << setw(10) << salary << endl;
    }
};

void structuresAndFiles()
{
    cout << "\n=== СТРУКТУРЫ И ФАЙЛЫ ===" << endl;

    vector<Person> people = {
        {"Анна", 25, 50000.0},
        {"Иван", 30, 75000.0},
        {"Мария", 28, 60000.0},
        {"Петр", 35, 90000.0}};

    // Запись структур в файл
    ofstream outFile("people.txt");
    if (outFile.is_open())
    {
        for (const auto &person : people)
        {
            outFile << person.name << " " << person.age << " " << person.salary << endl;
        }
        outFile.close();
        cout << "Данные о людях записаны в файл." << endl;
    }

    // Чтение структур из файла
    vector<Person> loadedPeople;
    ifstream inFile("people.txt");

    if (inFile.is_open())
    {
        cout << "\nЗагруженные данные:" << endl;
        cout << setw(10) << "Имя" << setw(5) << "Возраст" << setw(10) << "Зарплата" << endl;
        cout << string(25, '-') << endl;

        Person temp;
        while (inFile >> temp.name >> temp.age >> temp.salary)
        {
            loadedPeople.push_back(temp);
            temp.display();
        }
        inFile.close();
    }
}

// ========== 4. БИНАРНЫЕ ФАЙЛЫ ==========

void binaryFiles()
{
    cout << "\n=== БИНАРНЫЕ ФАЙЛЫ ===" << endl;

    // Запись в бинарный файл
    ofstream binOut("data.bin", ios::binary);
    if (binOut.is_open())
    {
        int numbers[] = {10, 20, 30, 40, 50};
        double pi = 3.14159;
        char message[] = "Hello Binary!";

        // Запись массива чисел
        binOut.write(reinterpret_cast<char *>(numbers), sizeof(numbers));

        // Запись отдельного double
        binOut.write(reinterpret_cast<char *>(&pi), sizeof(pi));

        // Запись строки
        binOut.write(message, sizeof(message));

        binOut.close();
        cout << "Данные записаны в бинарный файл." << endl;
    }

    // Чтение из бинарного файла
    ifstream binIn("data.bin", ios::binary);
    if (binIn.is_open())
    {
        int numbers[5];
        double pi;
        char message[20];

        // Чтение массива чисел
        binIn.read(reinterpret_cast<char *>(numbers), sizeof(numbers));
        cout << "Числа: ";
        for (int i = 0; i < 5; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << endl;

        // Чтение double
        binIn.read(reinterpret_cast<char *>(&pi), sizeof(pi));
        cout << "Pi: " << pi << endl;

        // Чтение строки
        binIn.read(message, sizeof(message));
        cout << "Сообщение: " << message << endl;

        binIn.close();
    }
}

// ========== 5. РАБОТА С ФАЙЛОВЫМИ ПОЗИЦИЯМИ ==========

void filePositions()
{
    cout << "\n=== ПОЗИЦИИ В ФАЙЛЕ ===" << endl;

    ofstream file("positions.txt");
    for (int i = 1; i <= 10; i++)
    {
        file << "Строка " << i << endl;
    }
    file.close();

    fstream ioFile("positions.txt", ios::in | ios::out);
    if (ioFile.is_open())
    {
        // Получение текущей позиции
        streampos start = ioFile.tellg();
        cout << "Начальная позиция: " << start << endl;

        // Переход к 5-й строке
        string line;
        for (int i = 0; i < 4; i++)
        {
            getline(ioFile, line);
        }

        streampos fifthLine = ioFile.tellg();
        cout << "Позиция 5-й строки: " << fifthLine << endl;

        // Чтение с текущей позиции
        getline(ioFile, line);
        cout << "5-я строка: " << line << endl;

        // Переход к началу файла
        ioFile.seekg(0, ios::beg);
        getline(ioFile, line);
        cout << "Первая строка: " << line << endl;

        // Переход к концу файла
        ioFile.seekg(0, ios::end);
        streampos endPos = ioFile.tellg();
        cout << "Конец файла: " << endPos << endl;

        ioFile.close();
    }
}

// ========== 6. ПРОВЕРКИ СОСТОЯНИЯ ФАЙЛА ==========

void fileStateChecks()
{
    cout << "\n=== ПРОВЕРКИ СОСТОЯНИЯ ФАЙЛА ===" << endl;

    ifstream file("nonexistent.txt");

    // Различные проверки состояния
    if (!file)
    {
        cout << "Файл не открыт!" << endl;
    }

    if (file.fail())
    {
        cout << "Операция с файлом завершилась неудачей." << endl;
    }

    if (file.eof())
    {
        cout << "Достигнут конец файла." << endl;
    }

    if (file.bad())
    {
        cout << "Произошла критическая ошибка." << endl;
    }

    // Сброс состояния файла
    file.clear();
}

// ========== 7. CSV ФАЙЛЫ ==========

void csvFiles()
{
    cout << "\n=== РАБОТА С CSV ФАЙЛАМИ ===" << endl;

    // Создание CSV файла
    ofstream csvOut("data.csv");
    if (csvOut.is_open())
    {
        // Заголовок
        csvOut << "Имя,Возраст,Зарплата,Город" << endl;

        // Данные
        csvOut << "Анна,25,50000,Москва" << endl;
        csvOut << "Иван,30,75000,Санкт-Петербург" << endl;
        csvOut << "Мария,28,60000,Казань" << endl;
        csvOut << "Петр,35,90000,Москва" << endl;

        csvOut.close();
        cout << "CSV файл создан." << endl;
    }

    // Чтение CSV файла
    ifstream csvIn("data.csv");
    if (csvIn.is_open())
    {
        string line;
        getline(csvIn, line); // Пропускаем заголовок

        cout << "\nДанные из CSV:" << endl;
        cout << setw(10) << "Имя" << setw(8) << "Возраст"
             << setw(10) << "Зарплата" << setw(15) << "Город" << endl;
        cout << string(43, '-') << endl;

        while (getline(csvIn, line))
        {
            stringstream ss(line);
            string name, ageStr, salaryStr, city;

            getline(ss, name, ',');
            getline(ss, ageStr, ',');
            getline(ss, salaryStr, ',');
            getline(ss, city, ',');

            cout << setw(10) << name << setw(8) << ageStr
                 << setw(10) << salaryStr << setw(15) << city << endl;
        }

        csvIn.close();
    }
}

// ========== 8. КЛАСС ДЛЯ РАБОТЫ С ФАЙЛАМИ ==========

class FileManager
{
private:
    string filename;

public:
    FileManager(const string &fname) : filename(fname) {}

    bool writeData(const vector<string> &data)
    {
        ofstream file(filename);
        if (!file.is_open())
            return false;

        for (const auto &line : data)
        {
            file << line << endl;
        }

        file.close();
        return true;
    }

    vector<string> readData()
    {
        vector<string> result;
        ifstream file(filename);

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                result.push_back(line);
            }
            file.close();
        }

        return result;
    }

    bool appendData(const string &data)
    {
        ofstream file(filename, ios::app);
        if (!file.is_open())
            return false;

        file << data << endl;
        file.close();
        return true;
    }

    void displayFileInfo()
    {
        ifstream file(filename, ios::binary | ios::ate);
        if (file.is_open())
        {
            streampos size = file.tellg();
            cout << "Файл: " << filename << endl;
            cout << "Размер: " << size << " байт" << endl;
            file.close();
        }
        else
        {
            cout << "Не удалось открыть файл для получения информации." << endl;
        }
    }
};

void fileManagerDemo()
{
    cout << "\n=== КЛАСС ДЛЯ УПРАВЛЕНИЯ ФАЙЛАМИ ===" << endl;

    FileManager fm("managed_file.txt");

    // Запись данных
    vector<string> data = {
        "Первая строка",
        "Вторая строка",
        "Третья строка"};

    if (fm.writeData(data))
    {
        cout << "Данные записаны успешно." << endl;
    }

    // Чтение данных
    vector<string> readData = fm.readData();
    cout << "\nПрочитанные данные:" << endl;
    for (const auto &line : readData)
    {
        cout << line << endl;
    }

    // Добавление данных
    fm.appendData("Добавленная строка");

    // Информация о файле
    fm.displayFileInfo();
}

// ========== 9. ОБРАБОТКА ОШИБОК ==========

void errorHandling()
{
    cout << "\n=== ОБРАБОТКА ОШИБОК ===" << endl;

    // Попытка открыть несуществующий файл
    ifstream noFile("non_existent_file.txt");
    if (!noFile)
    {
        cout << "Ошибка: файл не существует!" << endl;
        // Можно выбросить исключение или обработать иначе
    }

    // Попытка записи в защищенный файл
    ofstream protectedFile("/protected/system/file.txt");
    if (protectedFile.fail())
    {
        cout << "Ошибка: нет прав для записи!" << endl;
    }

    // Проверка доступности дискового пространства
    try
    {
        ofstream bigFile("big_file.txt");
        if (!bigFile)
        {
            throw runtime_error("Не удалось создать файл. Возможно, нет места на диске.");
        }

        // Запись большого количества данных
        for (int i = 0; i < 1000000; i++)
        {
            bigFile << "Строка данных " << i << endl;
            if (bigFile.fail())
            {
                throw runtime_error("Ошибка записи. Диск может быть полным.");
            }
        }

        bigFile.close();
    }
    catch (const exception &e)
    {
        cout << "Исключение: " << e.what() << endl;
    }
}

// ========== 10. ПРАКТИЧЕСКИЕ ПРИМЕРЫ ==========

void practicalExamples()
{
    cout << "\n=== ПРАКТИЧЕСКИЕ ПРИМЕРЫ ===" << endl;

    // Пример 1: Логирование
    ofstream logFile("app.log", ios::app);
    if (logFile.is_open())
    {
        logFile << "[" << __TIME__ << "] Запуск приложения" << endl;
        logFile << "[" << __TIME__ << "] Выполнение операции..." << endl;
        logFile << "[" << __TIME__ << "] Ошибка: что-то пошло не так" << endl;
        logFile.close();
        cout << "Лог записан в app.log" << endl;
    }

    // Пример 2: Конфигурационный файл
    ofstream config("config.ini");
    if (config.is_open())
    {
        config << "[Database]" << endl;
        config << "host=localhost" << endl;
        config << "port=5432" << endl;
        config << "username=admin" << endl;
        config << "password=secret" << endl;
        config.close();
        cout << "Конфигурационный файл создан." << endl;
    }

    // Пример 3: Чтение конфигурации
    ifstream configIn("config.ini");
    if (configIn.is_open())
    {
        string line;
        cout << "\nКонфигурация:" << endl;
        while (getline(configIn, line))
        {
            cout << line << endl;
        }
        configIn.close();
    }
}

// ========== ГЛАВНАЯ ФУНКЦИЯ ==========

int main()
{
    cout << "=== ПОДРОБНЫЙ ОБЗОР РАБОТЫ С ФАЙЛАМИ В C++ ===" << endl;

    basicFileOperations();
    fileOpeningModes();
    structuresAndFiles();
    binaryFiles();
    filePositions();
    fileStateChecks();
    csvFiles();
    fileManagerDemo();
    errorHandling();
    practicalExamples();

    cout << "\n=== ШПАРГАЛКА ПО ФАЙЛАМ ===" << endl;
    cout << "#include <fstream>" << endl;
    cout << "ofstream - запись в файл" << endl;
    cout << "ifstream - чтение из файла" << endl;
    cout << "fstream - чтение и запись" << endl;
    cout << "\nРежимы открытия:" << endl;
    cout << "ios::in - чтение" << endl;
    cout << "ios::out - запись" << endl;
    cout << "ios::app - добавление в конец" << endl;
    cout << "ios::trunc - очистка файла" << endl;
    cout << "ios::binary - бинарный режим" << endl;

    return 0;
}