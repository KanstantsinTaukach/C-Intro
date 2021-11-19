/******************************************************************************
Brest C++ Software Development Introduction
Friendly functions
Kanstantsin Taukach
*******************************************************************************/
/*Тема: дружественные функции.

Цель работы: изучить назначение и принципы работы дружественных функций и классов.

Задание:
    1. Разработать класс «массив» (двумерный динамический массив). Методы класса:
    конструктор (выполняет ввод размерности массива, динамическое выделение памяти
    и ввод элементов массива), деструктор (освобождает динамически выделенную под
    массив память), метод печати (выполняет форматный вывод элементов массива в виде
    таблицы) и friend-метод, выполняющий решение задачи по варианту (если задачу
    решить нельзя, то сообщить об этом).*/

#include <iostream>
#include <cassert>

constexpr int ROWS = 3;
constexpr int COLS = 4;

template <typename T = int>
class Matrix
{
private:
    int _rows;
    int _cols;
    T** _data = nullptr;
public:
    Matrix() : _rows(0), _cols(0)
    {

    }
    Matrix(int rows_, int cols_)
    {
        _rows = rows_;
        _cols = cols_;
        if (_rows != 0 && _cols != 0)
        {
            _data = new T * [_rows];
            for (int i = 0; i < _rows; ++i)
            {
                _data[i] = new T[_cols];
            }
        }
    }
    ~Matrix()
    {
        if (_data)
        {
            for (int i = 0; i < _rows; ++i)
            {
                delete[] _data[i];
            }
            delete[] _data;
        }
    }
    //use for access to array indexes (overload [][])
    T& operator() (int row, int col) const
    {
        assert(row >= 0 && row < _rows);
        assert(col >= 0 && col < _cols);
        return _data[row][col];
    }
    void addElements()
    {
        for (int i = 0; i < _rows; ++i)
        {
            for (int j = 0; j < _cols; ++j)
            {
                std::cout << "Enter the " << j + 1 << " element of the " << i + 1 << " array: ";
                std::cin >> _data[i][j];
            }
            std::cout << std::endl;
        }
    }
    friend std::ostream& operator << (std::ostream& out, const Matrix <T>& m)
    {
        for (int i = 0; i < m._rows; ++i)
        {
            for (int j = 0; j < m._cols; ++j)
            {
                out << m(i, j) << " ";
            }
            out << std::endl;
        }
        return out;
    }
    template <class U>
    friend void taskFunction(const Matrix <U>& m);
};

//Определить сумму элементов в тех строках, которые содержат хотя бы один 
 //отрицательный элемент

template <typename T>
void taskFunction(const Matrix <T>& m)
{
    T sumGeneral = T();
    T sumInRow = T();
    bool flag = false;
    for (int i = 0; i < m._rows; ++i)
    {
        for (int j = 0; j < m._cols; ++j)
        {
            sumInRow += m._data[i][j];
            if (m._data[i][j] < 0) {
                flag = true;
            }
        }
        if (flag)
        {
            std::cout << "Sum in row " << i + 1 << " is: " << sumInRow << std::endl;
            sumGeneral += sumInRow;
        }
        else
        {
            std::cout << "No negative numbers in " << i + 1 << " row" << std::endl;
        }
        sumInRow = 0;
        flag = false;
    }
    std::cout << "General sum in rows of matrix, that contains negative numbers is: " << sumGeneral;
}

int main()
{
    Matrix<> matrix(ROWS, COLS);
    matrix.addElements();
    std::cout << "Currently matrix is: " << std::endl << matrix << std::endl;
    taskFunction(matrix);
}
