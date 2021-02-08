//
// Created by zhouhan on 2021/2/8.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *former = head->next, *latter = head;
        ListNode *prev = dummyHead;
        while(former != nullptr){
            ListNode *nex = former->next;
            latter->next = nex;
            former->next = latter;
            prev->next = former;
            if(nex == nullptr){
                break;
            }
            prev = latter;
            latter = nex;
            former = nex->next;
        }
        return dummyHead->next;
    }
};