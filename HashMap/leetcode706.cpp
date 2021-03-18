//
// Created by zhouhan on 2021/3/14.
//
#include "../common.h"
class MyHashMap {
public:
    static struct node{
        int key;
        int val;
        node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    /** Initialize your data structure here. */
    vector<vector<node *>>mp;
    MyHashMap() {
        mp.resize(769);
    }

    int getHashCode(int key){
        return key % 769;
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        node *n = new node(key, value);
        vector<node *> &v = mp[getHashCode(key)];
        for(int i = 0; i < v.size(); i++){
            if(v[i]->key == key){
                v[i]->val = value;
                return;
            }
        }
        v.push_back(n);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(auto x: mp[getHashCode(key)]){
            if(x->key == key){
                return x->val;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        vector<node *> &x = mp[getHashCode(key)];
        for(int i = 0; i < x.size(); i++){
            if(x[i]->key == key){
                x.erase(x.begin() + i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */