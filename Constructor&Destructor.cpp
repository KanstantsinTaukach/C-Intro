/******************************************************************************
Brest C++ Software Development Introduction
Task 3 - Constructor and destructor
Kanstantsin Taukach
*******************************************************************************/

/**Тема: конструктор и деструктор.

Цель работы: рассмотреть принцип работы конструкторов (с параметрами, с 
параметрами по умолчанию) и деструктора при работе с объектами.

Задание:
Разработать класс «вектор» (одномерный динамический массив). Методы класса: 
конструкторы, деструктор и методы преобразования массива в соответствии с 
вариантом. 
Ввести 2 массива по 10 элементов, используя различные конструкторы.
Один из массивов отсортировать (четные варианты – по убыванию, нечетные – по 
возрастанию), найти минимальное, среднее и максимальное значение массива. 
Для второго массива выполнить задание по варианту**/

#include <iostream>
#include <cstdlib>
#include <ctime>

constexpr int ARRAYSIZE = 10;

template <typename T>
class MyVector
{
private:
    int size;
    T* data;
public:
    MyVector() : size(0), data(nullptr)
    {
        
    }
    MyVector(int size_)
    {
        size = size_;
        if (size != 0)
        {
            data = new T[size_];
        }
        else
        {
            data = nullptr;
        }
    }
    ~MyVector()
    {
        if (data)
        {
            delete[] data;
        }
    }

    T& operator[] (int i) const
    {
        return data[i];
    }
    friend std::ostream& operator << (std::ostream& out, const MyVector <T>& x)
    {
        for (int i = 0; i < x.size; ++i)
        {
            out << x[i] << " ";
        }
        return out;
    }
    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (data[i] < data[j]) {
                    std::swap(data[i], data[j]);
                }
            }
        }
    }
    //Найти сумму элементов массива, расположенных после максимального элемента
    void func() {
        T max = 0;
        int pozision = 0;
        for (int i = 0; i < size; ++i)
        {
            if (max < data[i])
            {
                max = data[i];
                pozision = i;
            }
        }
        ++pozision;
        T sum = 0;
        for (pozision; pozision < size; ++pozision)
        {
            sum += data[pozision];
        }
        std::cout << sum << std::endl;
    }
 };


int main()
{
    srand(static_cast<unsigned int>(time(0)));

    MyVector<int> vectorInt(ARRAYSIZE);
    for (int i = 0; i < ARRAYSIZE; ++i)
    {
        vectorInt[i] = rand() % 100;
    }
    std::cout << "Vector of Int: " << vectorInt << std::endl;
    
    vectorInt.sort();
    std::cout << "Sorted vector of Int: " << vectorInt << std::endl;
    std::cout << "Min value in vector of Int is: " << vectorInt[ARRAYSIZE - 1] << std::endl;
    std::cout << "Average value in vector of Int is: " << vectorInt[ARRAYSIZE / 2] << std::endl;
    std::cout << "Max value in vector of Int is: " << vectorInt[0] << std::endl << std::endl;
    
    MyVector<double> vectorDouble(ARRAYSIZE);
    for (int i = 0; i < ARRAYSIZE; ++i)
    {
        vectorDouble[i] = static_cast<double>(rand() % 1000 + 1) / 10;
    }
    std::cout << "Vector of Double: " << vectorDouble << std::endl;

    std::cout << "The sum of elements after max element in vector of Double is: ";
    vectorDouble.func();
}


