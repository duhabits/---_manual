#include <iostream>
#include <string>
using namespace std;

// ========== КЛАССЫ И ОБЪЕКТЫ ==========

// Базовый класс
class Animal
{
private: // Доступно только внутри класса
    string name;
    int age;

protected: // Доступно внутри класса и наследникам
    string species;

public: // Доступно отовсюду
    // Конструктор - вызывается при создании объекта
    Animal(string n, int a, string s) : name(n), age(a), species(s)
    {
        cout << "Создан объект Animal: " << name << endl;
    }

    // Деструктор - вызывается при уничтожении объекта
    ~Animal()
    {
        cout << "Уничтожен объект Animal: " << name << endl;
    }

    // Методы класса
    void speak()
    {
        cout << name << " издает звук!" << endl;
    }

    void eat()
    {
        cout << name << " ест." << endl;
    }

    // Геттеры и сеттеры для доступа к private полям
    string getName() { return name; }
    void setName(string n) { name = n; }

    int getAge() { return age; }
    void setAge(int a) { age = a; }
};

// Наследование - класс Dog наследует от Animal
class Dog : public Animal
{
private:
    string breed;

public:
    // Конструктор наследника
    Dog(string n, int a, string b) : Animal(n, a, "Собака"), breed(b) {}

    // Переопределение метода (полиморфизм)
    void speak()
    {
        cout << getName() << " говорит: Гав-гав!" << endl;
    }

    // Собственный метод
    void fetch()
    {
        cout << getName() << " приносит палку!" << endl;
    }
};

// Еще один наследник
class Cat : public Animal
{
public:
    Cat(string n, int a) : Animal(n, a, "Кот") {}

    void speak()
    {
        cout << getName() << " говорит: Мяу!" << endl;
    }
};

void oopExamples()
{
    // Создание объектов
    Dog myDog("Бобик", 3, "Овчарка");
    Cat myCat("Мурзик", 2);

    // Вызов методов
    myDog.speak();
    myDog.eat();
    myDog.fetch();

    myCat.speak();
    myCat.eat();

    // Работа с указателями на базовый класс
    Animal *animalPtr = &myDog;
    animalPtr->speak(); // Вызовет метод Dog::speak()
}