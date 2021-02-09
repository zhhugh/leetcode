
#include "LinkList//leetcode143.cpp"
#include <iostream>
using namespace std;

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    s.reorderList(head);
    return 0;
}


