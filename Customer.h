#pragma once
#include <iostream>
#include "Account.h"
#include "Transport.h"
using namespace std;

class Customer : public Account
{
private:
    double ID_ticket_month = 2008;
public:
    Customer();
    Customer(string, string, string, double);
    virtual bool SigIn(string, string);
    virtual void SigUp(string, string, string, double);
    bool setID_T_M(double);
    double getSurplus()const;
    double getID_ticket_month()const;
    bool buy_ticket_month();
    void addMoney(double);
    void subtractionMoney(Transport *, double);
    ~Customer();
};

Customer::Customer()
{
}

Customer::Customer(string name, string username, string password, double surplus)
{
    this->ID = ++counter;
    this->NAME = name;
    this->USERNAME = username;
    this->PASSWORD = password;
    this->Surplus = surplus;
}

void Customer::SigUp(string name, string username, string password, double surplus)
{
    Customer(name, username, password, surplus);
}

bool Customer::SigIn(string username, string password)
{
    if ((this->USERNAME == username) && (this->PASSWORD == password))
        return true;
    return false;
}

bool Customer::setID_T_M(double id_t_m)
{
    if (this->ID_ticket_month == id_t_m)
        return true;
    return false;
}

double Customer::getSurplus()const
{
    return this->Surplus;
}

bool Customer::buy_ticket_month()
{
    if (this->Surplus >= 200000)
    {
        this->Surplus = this->Surplus - 200000;
        return true;
    }
    return false;
}

double Customer::getID_ticket_month()const
{
    return this->ID_ticket_month;
}

void Customer::addMoney(double money)
{
    this->Surplus = this->Surplus + money;
}

void Customer::subtractionMoney(Transport *A, double id_t_m)
{
    if (setID_T_M(id_t_m)==true)
        this->Surplus = this->Surplus - 0;
    else
        this->Surplus = this->Surplus - A->Price();
}

Customer::~Customer()
{
}