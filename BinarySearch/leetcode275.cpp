//
// Created by zhouhan on 2021/1/17.
//
#include "../common.h"

// 二分搜索的精髓在于 每次都减半搜索范围
// 满足 citations[i] >= n - i 条件的第一个数
// citations[mid] == n - i, 则找到答案
// citations[mid] > n - i, 则答案区间在[l...mid - 1]
// citations[mid] < n - i, 则答案区间在[mid + 1, r]
// 考虑出口条件：
// 1 l = mid + 1， 则l跳到了 r + 1的位置，r+1满足条件， r不满足条件，答案为left
// 2 r = mid - 1,  则r跳到了l - 1 的位置， l - 1不满足条件， l满足条件， 答案为leftS

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int l = 0, r = len - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(citations[mid] == len - mid){
                return len - mid;
            }else if(citations[mid] < len - mid){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return len - l;
    }
};