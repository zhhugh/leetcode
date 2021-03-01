//
// Created by zhouhan on 2021/2/21.
//

#include "../common.h"
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0;
        int r = 0;
        int n = A.size();
        int maxlen = 0;
        queue<int> que;
        while(r < n){
            // 判断r的数如何处理
            if(A[r] == 0){
                if(K > 0){
                    K--;
                    // 保存数值是0，且用掉了修改机会的数组下标
                    que.push(r);
                }else{
                    if(!que.empty()){
                        l = que.front() + 1; // l <= r
                        que.pop();
                        que.push(r);
                    }else{
                        l = r + 1;
                    }
                }
            }
            // 窗口拓展, [l, r)为滑动窗口
            r++;
            if((r - l > maxlen)){
                maxlen = r - l;
            }
        }
        return maxlen;
    }
};