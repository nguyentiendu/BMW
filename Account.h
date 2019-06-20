#pragma once
#include <iostream>
#include "Transport.h"
using namespace std;

class Account
{
protected:
    static int counter;
    int ID;
    string NAME;
    string USERNAME;
    string PASSWORD;
    double Surplus;
public:
    Account();
    Account(string, string, string, double);
    virtual bool SigIn(string, string);
    virtual void SigUp(string, string, string, double);
    ~Account();
};
int Account::counter = 0;
Account::Account()
{
}

Account::Account(string name, string username, string password, double surplus)
{
    this->NAME = name;
    this->USERNAME = username;
    this->PASSWORD = password;
    this->Surplus = surplus;
}

bool Account::SigIn(string username, string password)
{
    if (this->USERNAME == username && this->PASSWORD == password)
            return true;
    return false;
}

void Account::SigUp(string name, string username, string password, double surplus)
{
    Account(name, username, password, surplus);
}

Account::~Account()
{
}