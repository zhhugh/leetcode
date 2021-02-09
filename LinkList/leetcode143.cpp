//
// Created by zhouhan on 2021/2/8.
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
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode *slow = head; // x
        ListNode *fast = head; // x 或 x + 1
        // 找到上中点
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p = head, *q = slow->next;
        slow->next = nullptr;
        // 反转链表
        q = reverseLinkList(q);
        // 在链表中插入结点
        while(p && q){
            ListNode *nex = q->next;
            q->next = p->next;
            p->next = q;
            q = nex;
            p = p->next->next;
        }
    }
    ListNode *reverseLinkList(ListNode *head){
        if(head == nullptr){
            return head;
        }
        ListNode *newHead = nullptr;
        while(head != nullptr){
            ListNode *node = head->next;
            head->next = newHead;
            newHead = head;
            head = node;
        }
        return newHead;
    }
};