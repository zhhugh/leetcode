//// Created by zhouhan on 2021/3/18.//#include <istream>using namespace std;struct ListNode {    int val;    ListNode *next;    ListNode() : val(0), next(nullptr) {}    ListNode(int x) : val(x), next(nullptr) {}    ListNode(int x, ListNode *next) : val(x), next(next) {}};// 方法1:尾插法class Solution {public:    ListNode* reverseBetween(ListNode* head, int left, int right) {        ListNode *dummHead = new ListNode(-1, head);        ListNode *first = head;        ListNode *second = head;        ListNode *pre = dummHead;        for(int i = 0; i < left - 1; i++){            first = first->next;            pre = pre->next;        }        for(int i = 0; i < right - 1; i++){            second = second->next;        }        ListNode *newHead = second->next;        ListNode *end = second->next;        while(first != end){            ListNode *next = first->next;            first->next = newHead;            newHead = first;            first = next;        }        pre->next = newHead;        return dummHead->next;    }};class Solution2 {public:    ListNode* reverseBetween(ListNode* head, int left, int right) {        ListNode *dummyHead = new ListNode(-1, head);        ListNode *prev = dummyHead;        ListNode *first = head;        for(int i = 0; i < left - 1; i++){            first = first->next;            prev =  prev->next;        }        ListNode *succ = first->next;        for(int i = 0; i < right - left; i++){            first = succ;            succ = first->next;            ListNode *next = prev->next;            next->next = first->next;            prev->next = first;            first->next = next;        }        return dummyHead->next;    }};