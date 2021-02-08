//
// Created by zhouhan on 2021/2/8.




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
            return head;
        }
        ListNode *e = head;
        int len = 1;
        while(e->next != nullptr){
            e = e->next;
            len ++;
        }
        k = k % len;
        ListNode *slow = head, *fast = head;
        for(int i = 0; i < k; i++){
            fast = fast->next;
        }
        while(fast ->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        if(newHead == nullptr){
            return head;
        }
        e->next = head;
        return newHead;
    }
};
