//
// Created by zhouhan on 2021/2/10.
//
#include "../common.h"
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // 判断k是否为奇数
        bool odd = (k % 2 == 1);
        // 记录被删除数字要删除的次数
        unordered_map<int, int>count;
        vector<double> ans;
        // 大顶堆
        priority_queue<int, vector<int>, less<>> big;
        // 小顶堆
        priority_queue<int, vector<int>, greater<>> small;
        int smallSize = 0;
        int bigSize = 0;
        // 前k个数入队列
        for(int i = 0; i < k; i++){
            big.push(nums[i]);
        }
        for(int i = k / 2; i < k; i++){
            small.push(nums[i]);
            smallSize++;
        }
        bigSize = k - smallSize;
        // 滑动窗口[l....r)
        int l = 0, r = k;
        ans.push_back(odd ? small.top() : (small.top() + big.top()) / 2.0);
        int len = nums.size();
        while(r <= len){
            int lnum = nums[l++];
            // 要删除的次数
            count[lnum]++;
            // 哪个队列删除l位置的这个数
            // 从big删除
            if(lnum <= big.top()){
                if(big.top() == lnum){
                    big.pop();
                    count[lnum]--;
                }
                bigSize--;
            }else{
                if(small.top() == lnum){
                    small.pop();
                    count[lnum]--;
                }
                smallSize--;
            }
            // 要加入的数
            int rnum = nums[r++];
            if(rnum <= big.top()){
                big.push(rnum);
                bigSize++;
                if(bigSize - smallSize > 0){
                    small.push(big.top());
                    big.pop();
                }
            }else{
                small.push(rnum);
                smallSize++;
                if(smallSize - bigSize >= 2){
                    big.push(small.top());
                    small.pop();
                }
            }
            if(odd){
                while(count[small.top()] != 0){
                    small.pop();
                }
                ans.push_back(small.top());
            }else{
                while(count[small.top()] != 0){
                    small.pop();
                }
                while(count[big.top()] != 0){
                    big.pop();
                }
                ans.push_back( (big.top() + small.top() ) / 2.0);
            }

        }
        return ans;
    }
};