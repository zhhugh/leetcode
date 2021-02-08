//
// Created by zhouhan on 2021/2/6.
//
#include "../common.h"
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *slow = head->next; // 左 x+1
        ListNode *fast = head->next;      // 右 x 或 x + 1
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};