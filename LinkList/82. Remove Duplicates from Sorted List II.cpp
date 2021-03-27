//
// Created by zhouhan on 2021/3/25.
//

#include<iostream>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        auto dummyHead = new ListNode(-1, head);
        auto pre = dummyHead;
        auto cur = head;
        while(cur != nullptr && cur->next != nullptr){
            if(cur->val != cur->next->val){
                cur = cur->next;
                pre = pre->next;
            }else{
                while(cur->next != nullptr){
                    if(cur->val == cur->next->val){
                        cur = cur->next;
                    }else{
                        break;
                    }
                }
                pre->next = cur->next;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};