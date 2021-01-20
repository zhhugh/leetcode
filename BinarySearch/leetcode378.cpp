//
// Created by zhouhan on 2021/1/18.
//
#include "../common.h"

// 最优解法二分搜索：时间复杂度 nlog(r - l)
// l = matrix[0][0], r = matrix[n - 1][n - 1]
// 解必然在[l...r]
// 在[l...r]中，猜一个数 mid
// 通过线性的方法我们可以知道 小于等于mid的数的数量 num
// 如果 num >= k, 说明解区间在 [l...mid]
// 如果 num < k, 说明解区间在 [mid + 1... r]
// 当区间缩小到只有一个数， 则这个数就是答案.


class Solution {
public:
    bool check(vector<vector<int>> matrix, int k, int mid){
        int n = matrix.size();
        int i = n - 1, j = 0, num = 0;
        while(i >= 0 && j <= n - 1){
            if(matrix[i][j] <= mid){
                num += i + 1;
                j++;
            }else{
                i--;
            }
        }
        return num >= k;
    }


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while( l < r){
            int mid = l + ((r - l) >> 1);
            if(check(matrix, k, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};

// 第二种解法 ： 归并排序


class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator> (const point& a) const { return this->val > a.val; }
        };
        priority_queue<point, vector<point>, greater<point>> que;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++) {
            point now = que.top();
            que.pop();
            if (now.y != n - 1) {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return que.top().val;
    }
};

