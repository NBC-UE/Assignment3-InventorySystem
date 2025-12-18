#pragma once
#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
class Inventory {
public:
    // 복사 생성자
    Inventory(const Inventory<T>& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            pItems_[i] = other.pItems_[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }

    Inventory(int capacity = 10): size_(0){
        capacity_ = capacity < 1 ? 1 : capacity;
        pItems_ = new T[capacity_];
    }

    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    void Assign(Inventory<T>& other) {
        delete[] pItems_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            pItems_[i] = other[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }

    void AddItem(const T& item) {
        if (size_ >= capacity_) {
            cout << "인벤토리가 꽉 찼습니다.! 공간을 자동으로 늘립니다.!\n";
            Resize(capacity_ * 2);
        }

        pItems_[size_++] = item;
    }

    void Resize(int newCapacity) {
        T* newItems = new T[newCapacity];

        for (int i = 0, j = 0; i < newCapacity && j < capacity_; i++, j++) {
            newItems[i] = pItems_[j];
        }

        delete[] pItems_;
        pItems_ = move(newItems);
        capacity_ = newCapacity;
    }

    void SortItems() {
        sort(pItems_, pItems_ + size_);
    }

    void RemoveLastItem() {
        if (size_ == 0) {
            cout << "인벤토리가 비어있습니다.\n";
            return;
        }

        size_--;
    }

    int GetSize() const {
        return size_;
    }

    int GetCapacity() const {
        return capacity_;
    }

    void PrintAllItems() const {
        for (size_t i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
    }

    T& operator[] (int index) {
        if (size_ <= index || index < 0) {
            throw std::runtime_error("잘못된 index 접근!");
        }

        return pItems_[index];
    }
private:
    T* pItems_;
    int capacity_ = 0;
    int size_ = 0;
};