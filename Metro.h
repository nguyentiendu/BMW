#pragma once
#include <iostream>
#include "Transport.h"
using namespace std;

class Metro : public Transport
{
private:
    
public:
    Metro();
    Metro(double);
    virtual double Price()const;
    ~Metro();
};

Metro::Metro()
{
    this->SinglePrice=0;
    this->Distance=0;
}

Metro::Metro(double distance)
{
    this->SinglePrice=20000;
    this->Distance=distance; 
}

double Metro::Price()const
{
    return (this->SinglePrice * this->Distance);
}

Metro::~Metro()
{
}
