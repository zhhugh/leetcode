//
// Created by zhouhan on 2021/2/8.
//
#include "../common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLinkList(l1);
        l2 = reverseLinkList(l2);
        ListNode* l3 = new ListNode(-1), *cur = l3;
        int carry = 0;
        while(l1 || l2){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        if(carry){
            cur->next = new ListNode(carry);
            cur = cur->next;
        }
        cur->next = nullptr;
        reverseLinkList(l1);
        reverseLinkList(l2);
        l3 = reverseLinkList(l3->next);
        return l3;
    }

    ListNode* reverseLinkList(ListNode* head){
        ListNode* newHead = nullptr;
        while(head != nullptr){
            ListNode* next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};