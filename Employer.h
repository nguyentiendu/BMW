#pragma once
#include <iostream>
#include "Account.h"
using namespace std;

class Employer : public Account
{
private:
    
public:
    Employer();
    Employer(string, string, string);
    ~Employer();
};

Employer::Employer()
{
}

Employer::Employer(string name, string username, string password)
{
    this->NAME = name;
    this->USERNAME = username;
    this->PASSWORD = password;
}

Employer::~Employer()
{
}
