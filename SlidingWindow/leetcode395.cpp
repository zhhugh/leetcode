//
// Created by zhouhan on 2021/2/27.
//
#include "../common.h"
// [0, ind - 1] 满足条件
// [ind, n - 1] 待定
class Solution {
public:
    int longestSubstring(string s, int k) {
        return dfs(s, k, 0, s.size() - 1);
    }

    // [l, r]上的至少含有K个字符的最长子串
    int dfs(string s, int k, int l, int r){
        if(l > r){
            return 0;
        }
        int mp[26];
        fill(mp, mp + 26, 0);
        for(int i = l; i <= r; i++){
            mp[s[i] - 'a']++;
        }
        int cur = -1;
        for(int i = l; i <= r; i++){
            if(mp[s[i] - 'a'] < k){
                cur = i;
                break;
            }
        }
        if(cur == -1){
            return r - l + 1;
        }else{
            return max(dfs(s, k, l, cur - 1), dfs(s, k, cur + 1, r));
        }
    }

};