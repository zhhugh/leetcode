//
// Created by zhouhan on 2021/3/27.
//

#include <iostream>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    unordered_map<Node *, Node *>mp;
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        auto cur = head;
        while(cur != nullptr){
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur != nullptr){
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return mp[head];
    }
};