#include "Item.h"
#include<iostream>
using namespace std;

Item::Item(const string& InName, int InPrice)
    :name(InName), price(InPrice)
{
}

void Item::PrintInfo() const
{
    cout << "[이름: " << name << ", 가격: " << price << "G]" << endl;
}
