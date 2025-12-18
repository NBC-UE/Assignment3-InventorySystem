#include<iostream>
#include"Inventory.h"
#include "Item.h"
using namespace std;

int main() {
    Inventory<Item> inventory;
    inventory.AddItem(Item("체력 포션", 20));
    inventory.AddItem(Item("마나 포션", 20));
    inventory.AddItem(Item("힘 포션", 20));
    inventory.RemoveLastItem();
    cout << "인벤토리1\n";
    inventory.PrintAllItems();


    cout << "\n\n인벤토리2\n";
    Inventory<Item> inventory2;
    for (int i = 10; i >= 0; i--) {
        inventory2.AddItem(Item("포션", i));
    }
    inventory2.PrintAllItems();
    inventory2.SortItems();
    
    cout << "==== 정렬후 인벤토리2====\n";
    inventory2.PrintAllItems();

    cout << "\n\n==== inventory1 Assign(inventory2) ====\n";
    inventory.Assign(inventory2);
    inventory.PrintAllItems();
    return 0;
}