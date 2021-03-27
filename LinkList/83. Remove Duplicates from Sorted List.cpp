//
// Created by zhouhan on 2021/3/26.
//

#include <iostream>
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
        auto *dummyHead = new ListNode(-101, head);
        auto pre = dummyHead;
        while(head != nullptr){
            if(head->val == pre->val){
                pre->next = head->next;
                head = head->next;
            }else{
                pre = pre->next;
                head = head->next;
            }
        }
        return dummyHead->next;
    }
};