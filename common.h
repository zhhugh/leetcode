//
// Created by zhouhan on 2021/1/16.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
using namespace std;

//string

//马拉车计算最长回文子串

class Manacher {
public:

    string preProcess(string s){
        string t = "^#";
        for(auto c: s){
            t += c;
            t += "#";
        }
        t += "$";
        return t;
    }

    string longestPalindrome(string s) {
        string newS = preProcess(s);
        int maxlen = 0, idx = 0;
        // 当i = 1是， "^#", 显然r = 1, c = 1
        int c = 1, r = 1;
        int len  = newS.size();
        int m[len];
        fill(m, m + len, 0);
        for(int i = 2; i < len; i++){
            int li = 2 * c - i; // 找对称点
            if(i + m[li] < r){
                m[i] = m[li];
            }else{
                //
                // 如果r - i == -1的话， m[i] == - 1, 但是在后面的while循环中会加回到0
                // 如果 r <= i, 那么这个m[i]是当前的最大值， 后面要在此基础上扩展
                m[i] = r - i;
            }
            // mi[i] 为负数， 经过下面这个循环可以m[i] 加到0
            while(newS[i - m[i] - 1] == newS[i + m[i] + 1]){
                m[i]++;
            }
            // 扩展后
            if(i + m[i] > r){
                r = i + m[i];
                c = i;
            }
            if(m[i] > maxlen){
                maxlen = m[i];
                idx = i;
            }
        }

        // 对于非特殊字符，索引为i 要映射到原来字符串，为（i - 2）/ 2
        // 原因是要先减去前面两个字符'^', '#', 每次都是两个字符两个字符的增加，所以除2
        // idx是我们找到的最长回文子串的扩展中心
        // idx - maxlen 是找到最长子串的第一个字符的左边特殊字符'#'的索引
        // 因为如果以idx为中心扩展能到非特殊字符，那么一定能再多扩展一位到特殊字符'#'
        // 原因是每个字符左右都有一个'#'
        // 对于这个特殊字符， 代表的是它右边的第一个字符为开头的子串
        // idx - maxlen = i - 1 (i表示特殊字符右边的第一个字符的索引）
        // （idx - maxlen） / 2 == （i - 1）/ 2 == （i - 2）/ 2（因为是向下取整）
        // 这样就映射到了原来字符串的索引
        // 所以 begin = （idx - maxlen) >> 1
        int begin  = (idx - maxlen) >> 1;
        return s.substr(begin, maxlen);
    }
};


// stack

////单调栈 序列中无重复值
//vector<vector<int>> getNearLessNoRepeat(vector<int> arr){
//    int n = arr.size();
//    // 记录每个数左边最近的比它小的数和右边最近的比它小的数
//    vector<vector<int>> res(n, vector<int>(2, 0));
//    stack<int> stk;
//    for(int i = 0; i < n; i++){
//        while(!stk.empty() && arr[stk.top()] > arr[i]){
//            int idx = stk.top();
//            stk.pop();
//            int leftLessIdx = stk.empty() ? -1 : stk.top();
//            res[idx][0] = leftLessIdx;
//            res[idx][1] = i;
//        }
//        stk.push(i);
//    }
//    while(!stk.empty()){
//        int idx = stk.top();
//        stk.pop();
//        int leftLessIdx = stk.empty() ? -1 : stk.top();
//        res[idx][0] = leftLessIdx;
//        res[idx][1] = -1;
//    }
//    return res;
//}
//
//
//// 单调栈 序列中有重复值
//// 1. aa ->{a, a}， 两个a恰好相邻， 则加入到同一个list
//// 2. a ... a, 中间的被弹走的必然是比a更大的
//vector<vector<int>> getNearLess(vector<int> arr){
//    int n = arr.size();
//    vector<vector<int>> res(n, vector<int>(2, 0));
//    stack<vector<int>> stk;
//    for(int i = 0; i < n; i++){
//        while(!stk.empty() && arr[stk.top()[0]] > arr[i]){
//            vector<int> popIs = stk.top();
//            stk.pop();
//            int leftLessIdx = stk.empty() ? -1 : stk.top().back();
//            for(auto popI: popIs){
//                res[popI][0] = leftLessIdx;
//                res[popI][1] = i;
//            }
//        }
//        if(!stk.empty() && arr[stk.top()[0]] == arr[i]){
//            stk.top().push_back(i);
//        }else{
//            vector<int> pushLs{i};
//            stk.push(pushLs);
//        }
//    }
//    while(!stk.empty()){
//        vector<int> popLs = stk.top();
//        stk.pop();
//        for(auto popI : popLs){
//            int leftLessIdx = stk.empty() ? -1 : stk.top().back();
//            res[popI][0] = leftLessIdx;
//            res[popI][1] = -1;
//        }
//    }
//    return res;
//}


// 链表节点
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

#endif //LEETCODE_COMMON_H