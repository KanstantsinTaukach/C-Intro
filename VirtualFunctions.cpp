/******************************************************************************
Brest C++ Software Development Introduction
Task 5? - Virtual function and abstract classes
Kanstantsin Taukach
*******************************************************************************/

/**Тема: виртуальные функции, абстрактные классы. 
 
Цель работы: изучить принципы использования виртуальных функций и абстрактных 
классов. 
Задание: 
Реализовать 3-уровневую иерархию классов. Вариант выбрать в зависимости от 
остатка деления числа букв в вашей фамилии на 5: 
остаток = 0 – вариант 1; 
остаток = 1 – вариант 2; 
остаток = 2 – вариант 3; 
остаток = 3 – вариант 4;
остаток = 4 – вариант 5. 
Базовый класс 1 уровня – абстрактный, содержащий чисто виртуальные функции. 
Классы 2 уровня – абстрактные, содержащие поля, конструкторы, методы и чисто 
виртуальные функции. Производные классы 3 уровня – конкретные классы, содержащие 
реализацию виртуальных методов.**/

#include <iostream>

constexpr int MARKSIZE = 3;
constexpr int ARRSIZE = 4;
//------------------------------------------------------------------------------
class EducationalInstitution {
    public:
        virtual void setData() = 0;
        virtual void getData() const = 0;
        virtual float getAverageMarkOfTheCertiticate() = 0;
        virtual int getTotalNumberOfStudents() = 0;
};
//------------------------------------------------------------------------------
class SecondaryEducation : public EducationalInstitution {
    protected:
        int marks[MARKSIZE];
    public:
        SecondaryEducation() : marks{} {
            
        }
        SecondaryEducation(int* arr) {
            for(int i = 0; i < MARKSIZE; ++i) {
                *(marks + i) = *(arr + i);
            }
        }
        
        virtual void setData() {
            std::cout << "\nEnter " << MARKSIZE << " marks: ";
            for(int i = 0; i < MARKSIZE; ++i) {
                std::cin >> marks[i];
            }
        }
        virtual void getData() const {
            std::cout << "\nThe marks are: ";
            for(int i = 0; i < MARKSIZE; ++i) {
                std::cout << marks[i] << " ";
            }
        }
        
        virtual float getAverageMarkOfTheCertiticate() = 0;
        virtual int getTotalNumberOfStudents() = 0;
};
//------------------------------------------------------------------------------
class HigherEducation : public EducationalInstitution {
    protected:
        int numberOfStudents;
    public:
        HigherEducation() : numberOfStudents(0) {
            
        }
        HigherEducation(int num) : numberOfStudents(num) {
            
        }
        
        virtual void setData() {
            std::cout << "\nEnter the number of students: ";
            std::cin >> numberOfStudents;
        }
        virtual void getData() const {
            std::cout << "\nThe number of students is : ";
            std::cout << numberOfStudents;
        }
        
        virtual float getAverageMarkOfTheCertiticate() = 0;
        virtual int getTotalNumberOfStudents() = 0;
};
//------------------------------------------------------------------------------
class School : public SecondaryEducation {
    public:
        School() : SecondaryEducation() {
            
        }
        School(int* arr) : SecondaryEducation(arr) {
            
        }
        
        void setData() {
            SecondaryEducation::setData();
        }
        void getData() const {
            SecondaryEducation::getData();
        }
        
        float getAverageMarkOfTheCertiticate() {
            std::cout << "getAverageMarkOfTheCertiticate ";
            float average = 0;
            for(int i = 0; i < MARKSIZE; ++i) {
                average += marks[i];
            }
            average /= MARKSIZE;
            return average;
        }
        int getTotalNumberOfStudents() {
            std::cout << "getTotalNumberOfStudents ";
            return 0;
        }
};
//------------------------------------------------------------------------------
class Gymnasium : public SecondaryEducation {
    public:
        Gymnasium() : SecondaryEducation() {
            
        }
        Gymnasium(int* arr) : SecondaryEducation(arr) {
            
        }
        
        void setData() {
            SecondaryEducation::setData();
        }
        void getData() const {
            SecondaryEducation::getData();
        }
        
        float getAverageMarkOfTheCertiticate() {
            std::cout << "getAverageMarkOfTheCertiticate ";
            float average = 0;
            for(int i = 0; i < MARKSIZE; ++i) {
               average += marks[i];
            }
            average /= MARKSIZE;
            return average;
        }
        int getTotalNumberOfStudents() {
            std::cout << "getTotalNumberOfStudents ";
            return 0;
        }
};
//------------------------------------------------------------------------------
class University : public HigherEducation {
    public:
        University() : HigherEducation() {
            
        }
        University(int num) : HigherEducation(num) {
            
        }
        
        void setData() {
            HigherEducation::setData();
        }
        void getData() const {
            HigherEducation::getData();
        }
        
        float getAverageMarkOfTheCertiticate() {
            std::cout << "getAverageMarkOfTheCertiticate ";
            return 0;
        }
        int getTotalNumberOfStudents() {
            std::cout << "getTotalNumberOfStudents ";
            return numberOfStudents;
        }
    
};
//------------------------------------------------------------------------------
class Institute : public HigherEducation {
    public:
        Institute() : HigherEducation() {
            
        }
        Institute(int num) : HigherEducation(num) {
            
        }
        
        void setData() {
            HigherEducation::setData();
        }
        void getData() const {
            HigherEducation::getData();
        }
        
        float getAverageMarkOfTheCertiticate() {
            std::cout << "getAverageMarkOfTheCertiticate ";
            return 0;
        }
        int getTotalNumberOfStudents() {
            std::cout << "getTotalNumberOfStudents ";
            return numberOfStudents;
        }
};
//------------------------------------------------------------------------------

int main() {

    EducationalInstitution* prtEduInst[ARRSIZE];
    
    int j = 0;
    prtEduInst[j] = new School;
    std::cout << "\nSchool:";
    prtEduInst[j++] -> setData();
    
    prtEduInst[j] = new Gymnasium;
    std::cout << "\nGymnasium:";
    prtEduInst[j++] -> setData();
    
    prtEduInst[j] = new University;
    std::cout << "\nUniversity:";
    prtEduInst[j++] -> setData();
    
    prtEduInst[j] = new Institute;
    std::cout << "\nInstitute:";
    prtEduInst[j++] -> setData();
    
    std::cout << std::endl;
    
    for(int i = 0; i < j; ++i) {
        std::cout << prtEduInst[i] -> getAverageMarkOfTheCertiticate() << std::endl;
        std::cout << prtEduInst[i] -> getTotalNumberOfStudents() << std::endl;
        
        delete prtEduInst[i];
    }
    
    return 0;
}




