//
// Created by zhouhan on 2021/2/8.
//

#include "../common.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// 链表 哈希表
// 思路：
// 从头结点开始遍历 肯定是先复制一个头结点，那么肯定要设置它的next的指针和random指针
// 如果我们直接生成一个复制结点，那么后面再要去设置这个复制结点的next指针和random指针就找不到了
// 所以得想个办法找到前面生成的结点
// 因为我们设置结点的next指针和random指针是按照head链表的顺序来设置的
// 所以刚好可以用head结点作为key，副本结点作为value，这样就能通过哈希表找到之前使用过的结点了
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;
        Node *cur = head;
        while(cur != nullptr){
            mp.insert(make_pair(cur, new Node(cur->val)));
            cur = cur->next;
        }
        Node *newHead = mp[head];
        cur = newHead;
        while(cur != nullptr){
            cur->next = mp[head->next];
            cur->random = mp[head->random];
            head = head->next;
            cur = mp[head];
        }
        return newHead;
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        // 给每个结点后面加上一个副本
        Node *cur = head;
        while(cur != nullptr){
            Node *next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        // 设置副本的random结点
        cur = head;
        while(cur != nullptr){
            Node *copyNode = cur->next;
            copyNode->random = cur->random == nullptr ? nullptr : cur->random->next;
            cur = cur->next->next;
        }
        // split 将原链表与副本分离开
        cur = head;
        Node *newHead = head->next;
        while(cur != nullptr){
            Node *copyNode = cur->next;
            cur->next = copyNode->next;
            copyNode->next = copyNode->next == nullptr? nullptr : copyNode->next->next;
            cur = cur->next;
        }
        return newHead;
    }
};