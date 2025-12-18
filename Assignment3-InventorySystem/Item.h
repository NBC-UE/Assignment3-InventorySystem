#pragma once
#include<string>

using namespace std;

class Item {
public:
    Item() {}
    Item(const string& InName, int InPrice);
    void PrintInfo() const;

    bool operator <(const Item& other) {
        return price < other.price;
    }
private:
    string name;
    int price;
};