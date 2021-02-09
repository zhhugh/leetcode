//
// Created by zhouhan on 2021/2/9.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dummyHead = new ListNode(-1, head);
        ListNode *first = dummyHead, *second = head, *third = head->next;
        while(third != nullptr){
            if(second->val == third->val){
                while(third != nullptr && second->val == third->val){
                    third = third->next;
                }
                first->next = third;
                if(third == nullptr){
                    return dummyHead->next;
                }
                second = third;
            }else{
                first = first->next;
                second = second->next;
            }
            third = third->next;
        }
        return dummyHead->next;
    }
};