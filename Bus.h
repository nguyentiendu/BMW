#pragma once
#include <iostream>
#include "Transport.h"
#include "Account.h"
using namespace std;

class Bus : public Transport
{
private:
    
public:
    Bus();
    Bus(double);
    virtual double Price()const;
    ~Bus();
};

Bus::Bus()
{
    this->SinglePrice=0;
    this->Distance=0;
}

Bus::Bus(double distance)
{
    this->SinglePrice = 7000;
    this->Distance = distance;
}

double Bus::Price()const
{
    return (this->SinglePrice * this->Distance);
}

Bus::~Bus()
{
}