/******************************************************************************
Brest C++ Software Development Introduction
Struct Task
Kanstantsin Taukach
*******************************************************************************/

/**Тема: организация ввода / вывода, динамическое выделение памяти.
* 
Цель работы : изучить организацию ввода / вывода и работу с динамической памятью при 
программировании алгоритмов в C++.

Задание :
    Определить комбинированный(структурный) тип, содержащий информацию о студенте: 
    фамилия, имя, массив из 3 - х оценок.
    Определить динамический массив структур, состоящий из N элементов(N >= 5, 
    вводится с клавиатуры).
    Выполнить ввод элементов в массив структур.
    Вывести исходный массив структур на консоль, разработав функцию для форматного 
    вывода элементов массива.
    Разработать функцию для сортировки массива структур :
четные варианты – по возрастанию, нечетные – по убыванию;
в зависимости от остатка деления числа букв в вашей фамилии на 4 выбрать признак для 
сортировки и разработать функцию для его вычисления :
остаток = 0 средний балл по 3 - м предметам;
остаток = 1 наибольший балл из 3 - х предметов;
остаток = 2 наименьший балл из 3 - х предметов;
остаток = 3 суммарный балл по 3 - м предметам.
Вывести измененный массив структур на консоль, используя созданную в п. 4 функцию.
Освободить динамически выделенную память под массив структур.**/


#include <iostream>
#include <string>
#include <algorithm>
constexpr int SIZE = 3;
//------------------------------------------------------------------------------
struct Student {
    std::string lastName;
    std::string firstName;
    int scorePoints[SIZE];
    int lowestScore; // use for sort 
};
//------------------------------------------------------------------------------
void display(Student s[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        std::cout << std::endl << "Student " << i + 1 << ":" << std::endl;

        std::cout << "Last name: " << s[i].lastName << std::endl;
        std::cout << "First name: " << s[i].firstName << std::endl;

        std::cout << "Score points: ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << s[i].scorePoints[j] << " ";
        }
        std::cout << std::endl;
    }
}
//------------------------------------------------------------------------------
//Sort by increase from lowest score point
void Sort(Student s[], int arrSize) {
    for (int i = 0; i < arrSize - 1; ++i) {
        for (int j = i + 1; j < arrSize; ++j) {
            if (s[i].lowestScore > s[j].lowestScore) {
                std::swap(s[i], s[j]);
            }
        }
    }
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int main() {

    int numberOfStudents;
    do {
        std::cout << "Enter the number of students: ";
        std::cin >> numberOfStudents;
    } while (numberOfStudents < 2);

    Student* st = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; ++i) {
        std::cout << "Enter the last name of the student " << i + 1 << ":" << std::endl;
        std::cin >> st[i].lastName;

        std::cout << "Enter the first name of the student " << i + 1 << ":" << std::endl;
        std::cin >> st[i].firstName;

        st[i].lowestScore = 1000;

        std::cout << "Enter the score points of the student " << i + 1 << ":" << std::endl;
        for (int j = 0; j < SIZE; ++j) {
            std::cout << j + 1 << ".";
            std::cin >> st[i].scorePoints[j];
            if (st[i].lowestScore > st[i].scorePoints[j]) {
                st[i].lowestScore = st[i].scorePoints[j];
            }
        }
    }

    std::cout << std::endl << "Students before swap: " << std::endl;
    display(st, numberOfStudents);

    Sort(st, numberOfStudents);

    std::cout << std::endl << "Students after swap: " << std::endl;
    display(st, numberOfStudents);

    delete[] st;

    return 0;
}





