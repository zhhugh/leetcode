//
// Created by zhouhan on 2021/2/7.
//
#include "../common.h"
#include <stack>
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


// 树的先 根 再左 再右
// 是一种深度优先遍历
// 所以可以模仿树的中序遍历写深度优先遍历

// demo1
class Solution {
public:
    Node* flatten(Node* head) {
       stack<Node *> stk;
       if(head == nullptr){
           return head;
       }
       Node *cur = head;
       Node *popN;
       Node *nex;
       while(true){
               while(cur->child != nullptr){
                   nex = cur->next;
                   if(nex != nullptr){
                       stk.push(nex);
                   }
                   cur->next = cur->child;
                   cur->next->prev = cur;
                   cur->child = nullptr;
                   cur = cur->next;
               }
               if(cur->next != nullptr){
                   cur = cur->next;
                   continue;
               }
               if(!stk.empty()){
                   popN = stk.top();
                   cur->next = popN;
                   popN->prev = cur;
                   cur = cur->next;
                   stk.pop();
               }else{
                   break;
               }
       }
       return head;
    }

};

// demo2
class Solution2 {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }
        stack<Node *> stk;
        stk.push(head);
        Node *cur;
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            if(cur->next != nullptr){
                stk.push(cur->next);
            }
            if(cur->child != nullptr){
                stk.push(cur->child);
            }
            cur->child = nullptr;
            if(stk.empty()){
                break;
            }
            // 当前节点与下一个节点连接
            cur->next = stk.top();
            stk.top()->prev = cur;
        }
        return head;
    }
};




// demo3
class Solution3 {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }
        stack<Node *> stk;
        stk.push(head);
        Node *cur;
        Node *prev = new Node;
        prev->next = head;
        while(!stk.empty()){
            cur = stk.top();
            stk.pop();
            if(cur->next != nullptr){
                stk.push(cur->next);
            }
            if(cur->child != nullptr){
                stk.push(cur->child);
            }
            prev->next = cur;
            prev->child = nullptr;
            cur->prev = prev;
            prev = cur;
        }
        head->prev = nullptr;
        return head;
    }
};

//