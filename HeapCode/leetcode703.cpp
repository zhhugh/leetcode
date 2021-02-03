//
// Created by zhouhan on 2021/1/30.
//

#include "../common.h"
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pque;
    int limit;
    int heapSize;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        limit = k;
        heapSize = 0;
        for(int i = 0; i < n; i++){
            add(nums[i]);
        }

    }

    int add(int val) {
        if(heapSize < limit){
            pque.push(val);
            heapSize ++;
        }else if(val > pque.top()){
            pque.pop();
            pque.push(val);
        }
        return pque.top();
    }
};
