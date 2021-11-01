/******************************************************************************
Brest C++ Software Development Introduction
Task - Converter
Kanstantsin Taukach
*******************************************************************************/
#include <iostream>

constexpr int CURRENCYSIZE = 10;

class Currency
{
protected:
    double usd;
    double eur;
    double rub;
    double byn;
public:
    Currency()
    {
        usd = 0;
        eur = 0;
        rub = 0;
        byn = 0;
    }
    virtual void setData(double value) = 0;
    virtual void getData() const = 0;
};

class USD : public Currency
{
public:
    void setData(double usd_) override
    {
        usd = usd_;
        eur = usd * 0.86;
        rub = usd * 70.5;
        byn = usd * 2.42;
    }
    void getData() const override
    {
        std::cout << usd << " USD = " << eur << " EUR." << std::endl;
        std::cout << usd << " USD = " << rub << " RUB." << std::endl;
        std::cout << usd << " USD = " << byn << " BYN." << std::endl;
    }
};

class EUR : public Currency
{
public:
    void setData(double eur_) override
    {
        eur = eur_;
        usd = eur * 1.17;
        rub = eur * 82.16;
        byn = eur * 2.82;
    }
    void getData() const override
    {
        std::cout << eur << " EUR = " << usd << " USD." << std::endl;
        std::cout << eur << " EUR = " << rub << " RUB." << std::endl;
        std::cout << eur << " EUR = " << byn << " BYN." << std::endl;
    }
};

class RUB : public Currency
{
public:
    void setData(double rub_) override
    {
        rub = rub_;
        eur = rub * 0.0122;
        usd = rub * 0.0142;
        byn = rub * 0.0344;
    }
    void getData() const override
    {
        std::cout << rub << " RUB = " << eur << " EUR." << std::endl;
        std::cout << rub << " RUB = " << usd << " USD." << std::endl;
        std::cout << rub << " RUB = " << byn << " BYN." << std::endl;
    }
};

class BYN : public Currency
{
public:
    void setData(double byn_) override
    {
        byn = byn_;
        eur = byn * 0.3542;
        usd = byn * 0.4128;
        rub = byn * 29.1;
    }
    void getData() const override
    {
        std::cout << byn << " BYN = " << eur << " EUR." << std::endl;
        std::cout << byn << " BYN = " << usd << " USD." << std::endl;
        std::cout << byn << " BYN = " << rub << " RUB." << std::endl;
    }
};

double getAmount(std::string s)
{
    std::cout << "Your choice is " << s << std::endl;
    std::cout << "Enter an amount: " << std::endl;
    double x;
    std::cin >> x;
    std::cout << std::endl;
    return x;
}


int main()
{
    char currency;
    Currency* ptrCurrency[CURRENCYSIZE];
    double amount;
    int i = 0;

    do
    {
        std::cout << "Select the currency: " << std::endl;
        std::cout << "Press 1 to choose USD" << std::endl;
        std::cout << "Press 2 to choose EUR" << std::endl;
        std::cout << "Press 3 to choose RUB" << std::endl;
        std::cout << "Press 4 to choose BYN" << std::endl;
        std::cin >> currency;
        std::cout << std::endl;
        switch (currency)
        {
        case '1':
        {
            amount = getAmount("USD");
            ptrCurrency[i] = new USD();
            ptrCurrency[i]->setData(amount);
            ptrCurrency[i]->getData();
            break;
        }
        case '2':
        {
            amount = getAmount("EUR");
            ptrCurrency[i] = new EUR();
            ptrCurrency[i]->setData(amount);
            ptrCurrency[i]->getData();
            break;
        }
        case '3':
        {
            amount = getAmount("RUB");
            ptrCurrency[i] = new RUB();
            ptrCurrency[i]->setData(amount);
            ptrCurrency[i]->getData();
            break;
        }
        case '4':
        {
            amount = getAmount("BYN");
            ptrCurrency[i] = new BYN();
            ptrCurrency[i]->setData(amount);
            ptrCurrency[i]->getData();
            break;
        }
        default:
            std::cout << "Invalid selection. Please try again." << std::endl;
            std::cout << std::endl;
        }

        ++i;
        if (i == CURRENCYSIZE)
        {
            break;
        }

        std::cout << std::endl;
        std::cout << "Do you want one more process? Press q for quit or " << std::endl;

    } while (currency != 'q');

    for (int j = 0; j < i; ++j)
    {
        delete ptrCurrency[j];
    }

    return 0;
}

