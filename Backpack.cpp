/******************************************************************************
Brest C++ Software Development Introduction
Task Backpack
Kanstantsin Taukach
*******************************************************************************/
//Задача состоит в том, чтобы выбрать, какие предметы, имеющие вес и стоимость, поместить в рюкзак 
//ограниченной ёмкости W, да так, чтобы максимизировать общую ценность его содержимого.

#include <iostream>
#include <string>

constexpr int SIZEOFITEMS = 5;
constexpr int MAXWEIGHTOFBACKPACK = 7;

class Storage
{
private:
    std::string name;
    int weight;
    int cost;
public:
    Storage()
    {
        name = " ";
        weight = 0;
        cost = 0;
    }
    Storage(std::string name_, int weight_, int cost_)
    {
        name = name_;
        weight = weight_;
        cost = cost_;
    }
    Storage(const Storage& st) : name(st.name), weight(st.weight), cost(st.cost)
    {

    }
    Storage& operator=(const Storage& st)
    {
        if (this == &st)
        {
            return *this;
        }

        name = st.name;
        weight = st.weight;
        cost = st.cost;

        return *this;
    }
    std::string getName() const
    {
        return name;
    }
    int getWeight() const
    {
        return weight;
    }
    int getCost() const
    {
        return cost;
    }
    Storage operator+(const Storage& st) const
    {
        std::string n = name + " " + st.name;
        int w = weight + st.weight;
        int c = cost + st.cost;
        return Storage(n, w, c);
    }
};


int main()
{
    Storage items[SIZEOFITEMS] =
    {
    {"apple", 2, 5},
    {"book", 3, 10},
    {"water", 1, 3},
    {"knife", 1, 6},
    {"lemon", 2, 9},
    };

    Storage backpack[SIZEOFITEMS][MAXWEIGHTOFBACKPACK];
    int max;

    //We will use a dynamic programming algorithm. Let's start with table.
    //Rows it's the items and columns it's the backpack capacity.
    //We will start with first row. In any cell we will check if we can add 
    //first item to it. If "yes", we put it to our backpack.
    for (int i = 0; i < MAXWEIGHTOFBACKPACK; ++i)
    {
        if (items[0].getWeight() <= (i))
        {
            backpack[0][i] = items[0];
        }
    }

    //Next we will check other items. Cost of any cell is calculated by formula:
    //cell[i][j] = MAX from:
    //1. Last MAX (value in cell[i - 1][j]
    //OR
    //2. Cost of current value + cost of the remaining space (cell[i - 1][j - current weight])

    for (int i = 1; i < SIZEOFITEMS; ++i)
    {
        for (int j = 0; j < MAXWEIGHTOFBACKPACK; ++j)
        {
            if (items[i].getWeight() > (j))
            {
                backpack[i][j] = backpack[i - 1][j];
            }
            else
            {
                int lastMaxCost = backpack[i - 1][j].getCost();
                int currentCost = items[i].getCost();
                int costOfRemainingSpace = backpack[i - 1][j - items[i].getWeight()].getCost();

                if (lastMaxCost < currentCost)
                {
                    backpack[i][j] = items[i];
                }
                else
                {
                    backpack[i][j] = backpack[i - 1][j];
                }
                if (currentCost + costOfRemainingSpace > lastMaxCost)
                {
                    backpack[i][j] = items[i] + backpack[i - 1][j - items[i].getWeight()];
                }
            }
        }
    }


    std::cout << "Cost table: " << std::endl;
    for (int i = 1; i < SIZEOFITEMS; ++i)
    {
        for (int j = 0; j < MAXWEIGHTOFBACKPACK; ++j)
        {
            std::cout << backpack[i][j].getCost() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    std::cout << "If we have backpack with maximum weight " << MAXWEIGHTOFBACKPACK - 1;
    std::cout << ", we can put to it next things: " << std::endl;
    std::cout << backpack[SIZEOFITEMS - 1][MAXWEIGHTOFBACKPACK - 1].getName() << std::endl;
    std::cout << "Common cost is: ";
    std::cout << backpack[SIZEOFITEMS - 1][MAXWEIGHTOFBACKPACK - 1].getCost() << std::endl;
    std::cout << "Common weight is: ";
    std::cout << backpack[SIZEOFITEMS - 1][MAXWEIGHTOFBACKPACK - 1].getWeight() << std::endl;

    return 0;
}




