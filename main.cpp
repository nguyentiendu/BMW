#include <iostream>
#include "Transport.h"
#include "Bus.h"
#include "Metro.h"
#include "Bicycle.h"
#include "Account.h"
#include "Customer.h"
#include "Employer.h"
using namespace std;

void MENU();
void Menu();
void menu_transport();

int main()
{
    Transport *BMW[100];
    for (int i=0; i<5; i++)
    {
        string name, username, password;
        char answer;
        int option1, option2, option3, s_bus, s_metro, t_bicyle;
        double surplus, money, id_ticket_month;
        MENU();
        cin>>option1;
        while (option1 != 0)
        {
            if (option1 == 1)
            {
                Customer A("XXXXX", "A33317", "a33317", 300000);
                cout<<"Moi ban nhap Username: ";
                cin>>username;
                cout<<"Moi ban nhap Password: ";
                cin>>password;
                if (A.SigIn(username, password) == true)
                {
                    cout<<"Dang nhap thanh cong!"<<endl;
                    Menu();
                    cin>>option2;
                    while (option2 != 0)
                    {
                        if (option2 == 1)
                        {
                            cout<<"Gia ve thang la 200000! Ban co chac muon mua khong? (Y/N) ";
                            cin>>answer;
                            if (answer=='Y')
                            {
                                if (A.buy_ticket_month()==true)
                                {
                                    cout<<"Giao dich thanh cong!"<<endl;
                                    cout<<"Ma ve thang cua ban la: "<<A.getID_ticket_month()<<endl;
                                    Menu();
                                    cin>>option2;
                                }
                                else
                                {
                                    cout<<"Giao dich khong thanh cong! Tai khoan cua ban khong du de mua ve thang!"<<endl;
                                    Menu();
                                    cin>>option2;
                                }
                            }
                        }
                        else if (option2 == 2)
                        {
                            cout<<"Tai khoan cua ban hien co: "<<A.getSurplus()<<" dong"<<endl;
                            Menu();
                            cin>>option2;
                        }
                        else if (option2 == 3)
                        {
                            menu_transport();
                            cin>>option3;
                            while (option3 != 0)
                            {
                                if (option3 == 1)
                                {
                                    cout<<"Moi ban nhap ma ve thang: ";
                                    cin>>id_ticket_month;
                                    cout<<"Quang duong ban da di bang xe bus(km): ";
                                    cin>>s_bus;
                                    Bus bus(s_bus);
                                    BMW[0] = &bus;
                                    cout<<"So tien ban phai tra la: "<<bus.Price()<<endl;
                                    A.subtractionMoney(BMW[0], id_ticket_month);
                                    cout<<"So du trong tai khoan con lai: "<<A.getSurplus()<<endl;
                                    menu_transport();
                                    cin>>option3;
                                }
                                else if (option3 == 2)
                                {
                                    cout<<"Moi ban nhap ma ve thang: ";
                                    cin>>id_ticket_month;
                                    cout<<"Quang duong ban da di bang xe dien Metro(km): ";
                                    cin>>s_metro;
                                    Metro metro(s_metro);
                                    BMW[1] = &metro;
                                    cout<<"So tien ban phai tra la: "<<metro.Price()<<endl;
                                    A.subtractionMoney(BMW[1], id_ticket_month);
                                    cout<<"So du trong tai khoan con lai: "<<A.getSurplus()<<endl;
                                    menu_transport();
                                    cin>>option3;
                                }
                                else if (option3 == 3)
                                {
                                    cout<<"Moi ban nhap ma ve thang: ";
                                    cin>>id_ticket_month;
                                    cout<<"Thoi gian ban da di bang xe dap(h): ";
                                    cin>>t_bicyle;
                                    Bicycle bicycle(t_bicyle);
                                    BMW[2] = &bicycle;
                                    cout<<"So tien ban phai tra la: "<<bicycle.Price()<<endl;
                                    A.subtractionMoney(BMW[2], id_ticket_month);
                                    cout<<"So du trong tai khoan con lai: "<<A.getSurplus()<<endl;
                                    menu_transport();
                                    cin>>option3;
                                }
                            }
                            if (option3==0)
                            {
                                Menu();
                                cin>>option2;
                            }
                        }
                        else if (option2 == 4)
                        {
                            cout<<"Nhap so tien ban muon nap: ";
                            cin>>money;
                            A.addMoney(money);
                            cout<<"Nap tien thanh cong!"<<endl;
                            cout<<"Ban co "<<A.getSurplus()<<" trong tai khoan!"<<endl;
                            Menu();
                            cin>>option2;
                        }
                    }
                    if (option2 == 0)
                    {
                        MENU();
                        cin>>option1;
                    }    
                }
                else
                {
                    cout<<"Sai username hoac password! Moi ban nhap lai!"<<endl;
                    MENU();
                    cin>>option1;
                }
            }
            else if(option1 == 2)
            {
                cout<<"Moi ban nhap Ho va Ten: ";
                cin.ignore();
                getline(cin,name);
                cout<<"Moi ban nhap Username: ";
                cin.ignore();
                getline(cin,username);
                cout<<"Moi ban nhap Password: ";
                cin.ignore();
                getline(cin,password);
                cout<<"Moi ban nhap so du: ";
                cin>>surplus;
                Customer B(name, username, password, surplus);
                cout<<"Dang ky thanh cong!"<<endl;
                Menu();
                cin>>option2;
                while (option2 != 0)
                {
                    if (option2 == 1)
                    {
                        cout<<"Gia ve thang la 200000! Ban co chac muon mua khong? (Y/N) ";
                        cin>>answer;
                        cout<<answer<<endl;
                        if (answer=='Y')
                        {
                            if (B.buy_ticket_month()==true)
                            {
                                cout<<"Giao dich thanh cong!"<<endl;
                                cout<<"Ma ve thang cua ban la: "<<B.getID_ticket_month()<<endl;
                                Menu();
                                cin>>option2;
                            }
                            else
                            {
                                cout<<"Giao dich khong thanh cong! Tai khoan cua ban khong du de mua ve thang!"<<endl;
                                Menu();
                                cin>>option2;
                            }
                        }
                        else
                        {
                            Menu();
                            cin>>option2;
                        }
                    }
                    else if (option2 == 2)
                    {
                        cout<<"Tai khoan cua ban co: "<<B.getSurplus()<<" dong"<<endl;
                        Menu();
                        cin>>option2;
                    }
                    else if (option2 == 3)
                    {
                        while (option3 != 0)
                        {
                            menu_transport();
                            cin>>option3;
                            if (option3 == 1)
                            {
                                cout<<"Moi ban nhap ma ve thang: ";
                                cin>>id_ticket_month;
                                cout<<"Quang duong ban da di bang xe bus(km): ";
                                cin>>s_bus;
                                Bus bus(s_bus);
                                BMW[0] = &bus;
                                cout<<"So tien ban phai tra la: "<<bus.Price()<<endl;
                                B.subtractionMoney(BMW[0], id_ticket_month);
                                cout<<"So du trong tai khoan con lai: "<<B.getSurplus()<<endl;
                                menu_transport();
                                cin>>option3;
                            }
                            else if (option3 == 2)
                            {
                                cout<<"Moi ban nhap ma ve thang: ";
                                cin>>id_ticket_month;
                                cout<<"Quang duong ban da di bang xe dien Metro(km): ";
                                cin>>s_metro;
                                Metro metro(s_metro);
                                BMW[1] = &metro;
                                cout<<"So tien ban phai tra la: "<<metro.Price()<<endl;
                                B.subtractionMoney(BMW[1], id_ticket_month);
                                cout<<"So du trong tai khoan con lai: "<<B.getSurplus()<<endl;
                                menu_transport();
                                cin>>option3;
                            }
                            else if (option3 == 3)
                            {
                                cout<<"Moi ban nhap ma ve thang: ";
                                cin>>id_ticket_month;
                                cout<<"Thoi gian ban da di bang xe dap(h): ";
                                cin>>t_bicyle;
                                Bicycle bicycle(t_bicyle);
                                BMW[2] = &bicycle;
                                cout<<"So tien ban phai tra la: "<<bicycle.Price()<<endl;
                                B.subtractionMoney(BMW[2], id_ticket_month);
                                cout<<"So du trong tai khoan con lai: "<<B.getSurplus()<<endl;
                                menu_transport();
                                cin>>option3;
                            }
                        }
                        if (option3 == 0)
                        {
                            Menu();
                            cin>>option2;
                        }
                    }
                    else if (option2 == 4)
                    {
                        cout<<"Nhap so tien ban muon nap: ";
                        cin>>money;
                        B.addMoney(money);
                        cout<<"Nap tien thanh cong!"<<endl;
                        cout<<"Ban co "<<B.getSurplus()<<" trong tai khoan!"<<endl;
                        Menu();
                        cin>>option2;
                    }
                }
                if (option2 == 0)
                {
                    MENU();
                    cin>>option1;
                }
            }
        }
    }
    return 0;
}

void MENU()
{
    cout<<".======================."<<endl;
    cout<<"|1. Dang nhap          |"<<endl;
    cout<<"|2. Dang ky tai khoan  |"<<endl;
    cout<<"|0. Thoat              |"<<endl;
    cout<<".======================."<<endl;
    cout<<"Moi ban chon chuc nang: ";
}

void Menu()
{
    cout<<".====================."<<endl;
    cout<<"|1. Mua ve thang     |"<<endl;
    cout<<"|2. Xem so du        |"<<endl;
    cout<<"|3. Chon phuong tien |"<<endl;
    cout<<"|4. Nap tien         |"<<endl;
    cout<<"|0. Thoat            |"<<endl;
    cout<<".====================."<<endl;
    cout<<"Moi ban nhap lua chon: ";
}

void menu_transport()
{
    cout<<".====================."<<endl;
    cout<<"|1. Xe Bus           |"<<endl;
    cout<<"|2. Xe dien Metro    |"<<endl;
    cout<<"|3. Xe Dap           |"<<endl;
    cout<<"|0. Thoat            |"<<endl;
    cout<<".====================."<<endl;
    cout<<"Moi ban nhap lua chon: ";
}