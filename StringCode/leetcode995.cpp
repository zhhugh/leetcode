//
// Created by zhouhan on 2021/2/18.
//

// 滑动窗口的头即可代表整个滑动窗口
// 用队列来存储滑动窗口的头, 这样就可以保存窗口的移动轨迹
//

#include "../common.h"
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        queue<int> que;
        int ans = 0;
        int l = 0;
        while(l < n){
            while(!que.empty() && l >= que.front() + K){
                que.pop();
            }
            // 需要修改
            if(que.size() % 2 == A[l]){
                if(l + K > n){
                    return -1;
                }
                que.push(l);
                ans++;
            }
            l++;
        }

        return ans;
    }
};
