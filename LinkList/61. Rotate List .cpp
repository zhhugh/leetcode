//
// Created by zhouhan on 2021/3/27.
//


struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return nullptr;
        }
        int len = 1;
        auto *dummyHead = new ListNode(-1, head);
        auto tail = head;
        // 找到链表的尾部结点
        while(tail->next != nullptr){
            len++;
            tail = tail->next;
        }
        k = k % len;
        auto first = head;
        auto second = head;
        for(int i = 0; i <= k ;i++){
            first = first->next;
        }
        while(first != nullptr){
            second = second->next;
            first = first->next;
        }
        auto newHead = second->next;
        if(newHead == nullptr){
            return head;
        }else{
            second->next = nullptr;
            tail->next = head;
        }
        return newHead;
    }
};