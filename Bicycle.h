#pragma once
#include <iostream>
#include "Transport.h"
using namespace std;

class Bicycle : public Transport
{
private:
    
public:
    Bicycle();
    Bicycle(double);
    virtual double  Price()const;
    ~Bicycle();
};

Bicycle::Bicycle()
{
    this->SinglePrice=0;
    this->Time=0;
}

Bicycle::Bicycle(double time)
{
    this->SinglePrice = 3000;
    this->Time = time;
}

double Bicycle::Price()const
{
    return (this->SinglePrice * this->Time);
}

Bicycle::~Bicycle()
{
}
