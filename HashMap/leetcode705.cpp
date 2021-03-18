//
// Created by zhouhan on 2021/3/13.
//
#include "../common.h"
class MyHashSet {
public:
    long long flag;
    static const int base = 769;
    static int hash(int key){
        return key % base;
    }

    MyHashSet() {
        flag = 0;
    }


    void add(int key) {
        flag |= (1LL << key);
    }

    void remove(int key) {
        flag &= ~(1LL << key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return flag & (1LL << key);
    }
};

