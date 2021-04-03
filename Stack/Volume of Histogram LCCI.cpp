//
// Created by zhouhan on 2021/4/2.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        stack<int> stk;
        for(int i = 0; i < height.size(); i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int popI = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int h = min(height[i], height[stk.top()]) - height[popI];
                    int width = i - stk.top() - 1;
                    total += h * width;
                }
            }
            stk.push(i);
        }
        return total;
    }
};


class Solution2 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2){
            return 0;
        }
        int leftMax = height[0];
        int rightMax = height[n - 1];
        int left = 1;
        int right = n - 2;
        int ans = 0;
        while(left <= right){
            if(leftMax < rightMax){
                ans += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left++;
            }else{
                ans += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        return ans;
    }
};