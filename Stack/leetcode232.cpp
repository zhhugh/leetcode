//
// Created by zhouhan on 2021/3/5.
//
#include "../common.h"
class MyQueue {
public:
    stack<int> stk1;
    stack<int> stk2;
    /** Initialize your data structure here. */

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 栈1的数进入栈2的数， 一定要一次性倒完， 不然先进的在底部没倒出来, 这样就不是先进先出了
        // 保证栈2是不空的
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int tmp = stk2.top();
        stk2.pop();
        return tmp;
    }

    /** Get the front element. */
    int peek() {
        if(stk2.empty()){
            while(!stk1.empty()){
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        return stk2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

