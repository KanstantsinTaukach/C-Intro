/******************************************************************************
Brest C++ Software Development Introduction
Task 2 - Class String
Kanstantsin Taukach
*******************************************************************************/

/**Тема: классы и объекты.

Цель работы: изучить структуру класса, атрибуты доступа к компонентам класса, 
принципы работы с объектами.

Задание:
Разработать класс «строка». Методы класса: конструктор, деструктор и метод, 
выполняющий задание в соответствии с вариантом.**/


#include <iostream>
#include <cstring>
//------------------------------------------------------------------------------
class String {
private:
    char* str = nullptr;
    int length = 0;
public:

    //default constructor
    String() :str(nullptr), length(0) {

    }

    //constructor
    String(const char* s) {

        length = strlen(s);
        str = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            str[i] = s[i];
        }
        str[length] = '\0';
    }

    //copy constructor
    String(const String& copyObject) {

        length = copyObject.length;
        str = new char[length + 1];

        for (int i = 0; i < length; ++i) {
            str[i] = copyObject.str[i];
        }
        str[length] = '\0';
    }

    //destructor
    ~String() {

        if (str != nullptr) {
            delete[] str;
        }
        length = 0;
    }

    //overloaded copy assignment
    String& operator=(const String& copyObject) {

        if (str != nullptr) {
            delete[]str;
        }

        length = strlen(copyObject.str);
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = copyObject.str[i];
        }
        str[length] = '\0';
        return *this;
    }

    //overloaded cout << operator
    friend std::ostream& operator<< (std::ostream& out, const String& s) {
        out << s.str;
        return out;
    }

    //Дана строка символов. Удалить первую 1/3 часть строки, если ее длина
    //кратна 3, в противном случае в начало строки вставить символ "+".
    void func1(const String& s) {
        length = strlen(s.str);
        if (length % 3 == 0) {
            int startFrom = length / 3;
            length -= startFrom;
            str = new char[length + 1];

            for (int i = 0; i < length; ++i) {
                str[i] = s.str[startFrom++];
            }
            str[length] = '\0';
        } else {
            length += 1;
            str = new char[length + 1];
            str[0] = '+';

            for (int i = 1, j = 0; i < length; ++i, ++j) {
                str[i] = s.str[j];
            }
            str[length] = '\0';
        }
    }

    //Дана строка символов, среди которых есть хотя бы одна точка. Заменить в ней 
    //знаком "+" все цифры "3" до первой точки, подсчитать количество таких замен.
    void func2(const String& s) {
        length = strlen(s.str);
        str = new char[length + 1];
        int i = 0;
        int count = 0;
        do {
            if (s.str[i] == '3') {
                str[i++] = '+';
                count++;
            } else {
                str[i] = s.str[i++];
            }
        } while (s.str[i] != '.');

        for (; i < length; ++i) {
            str[i] = s.str[i];
        }            
            str[length] = '\0';
    std::cout << "\nIn this string there're " << count << " number 3.";
    }

};
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main() {

    String s1("test1");
    std::cout << "String s1('test1') run: " << s1;

    String s2("test2");
    std::cout << "\nString s2('test2') run: " << s2;

    s2 = s1;
    std::cout << "\ns2 = s1 run: " << s2;

    String s3(s1);
    std::cout << "\nString s3(s1) run : " << s3;
    
    std::cout << "\nTest func1 with 9 letters :";
        
    String s4;
    s4.func1("aaabbbccc");
    std::cout << "\ns4.func1 run : " << s4;

    std::cout << "\nTest func1 with 5 letters :";

    s4.func1("aaabb");
    std::cout << "\ns4.func1 run : " << s4;

    std::cout << "\nTest func2 with 5 number 3 before point:";

    s4.func2("a3aa33as3s3a.d356d");
    std::cout << "\ns4.func2 run : " << s4;

    std::cout << "\nTest func2 with 0 number 3 before point:";

    s4.func2("adfsdfsa.d333d");
    std::cout << "\ns4.func2 run : " << s4;

    return 0;
}