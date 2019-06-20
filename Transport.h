#pragma once
#include <iostream>
using namespace std;

class Transport
{
protected:
    double SinglePrice;
    double Time;
    double Distance;
public:
    Transport();
    virtual double Price()const=0;
    ~Transport();
};

Transport::Transport()
{
}

Transport::~Transport()
{
}
